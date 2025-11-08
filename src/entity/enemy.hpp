#pragma once
#include "ientity.hpp"

class Enemy : public IEntity
{
private:
	float CurrentFrame = 0;
	float w, h;

public:
	float x, y;
	enum { left, right, up, down, jump, stay, climb } state;
	float dx, dy, speed;
	int dir = 0;
	sf::String F;
	sf::Texture t; 
	sf::Sprite en;
	Enemy() {
	}
	Enemy(String f) {
		t.loadFromFile(f);
		en.setTexture(t);
		en.setTextureRect(sf::IntRect(0,0,12,16));
		en.setScale(2,2);
	}
	void setEnemy(float X, float Y, float H, float W,sf::Color c) {
		x = X; y = Y; w = W; h = H;

		speed = 0.1;
		dy = speed;
		state = left;
	}
	void checkCollisionWithMap(float Dx, float Dy)
	{
		if (textMap == "map2") {
			for (int i = y / 32; i < (y + h) / 32; i++)
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map2[i][j] == '0')
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; }
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
						if (Dx > 0) { x = j * 32 - w; state = left; }
						if (Dx < 0) { x = j * 32 + 32; state = right; }
					}
				}
		}
		if (textMap == "map3") {
			for (int i = y / 32; i < (y + h) / 32; i++)
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map3[i][j] == '0')
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; }
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
						if (Dx > 0) { x = j * 32 - w; state = left; }
						if (Dx < 0) { x = j * 32 + 32; state = right; }
					}
				}
		}
	}
	void update(float time)
	{
		switch (state)
		{
		case right: 
			dx = speed;  
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			en.setTextureRect(sf::IntRect(13 * int(CurrentFrame) + 13, 0, -13, 16));
			break;
		case left: 
			dx = -speed;  
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			en.setTextureRect(sf::IntRect(13 * int(CurrentFrame), 0, 13, 16));
			break;
		case up: break;
		case down: break;
		case jump: break;
		case stay: break;
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0);
		y += dy * time;
		checkCollisionWithMap(0, dy);
		en.setPosition(x, y);
		dy = dy + 0.0015*time;
	}

    virtual void draw(const sf::RenderTarget &target, sf::RenderStates states) const
    {
        //target.draw(,states);
    }
};