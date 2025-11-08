#pragma once
#include "ientity.hpp"

class Player : public IEntity
{
private:  
	float health;
	float CurrentFrame = 0;
	sf::SoundBuffer jumpBuffer;
	sf::SoundBuffer peekBuffer;
	sf::Sound peek;
	sf::Sound jumpM;

public:
	float score;
	float x, y;
	enum { left, right, up, down, jump, stay,climb } state;
	bool isMove, onGround;
	bool isLife;
	float w, h, dx, dy, speed;
	float dxT, dyT;
	int dir = 0;
	sf::Texture t;
	sf::Sprite player;
	Player(float X, float Y, float W, float H, String f) {
		
		jumpBuffer.loadFromFile("Sounds/jump.ogg");
		jumpM.setBuffer(jumpBuffer);
		
		peekBuffer.loadFromFile("Sounds/pick.ogg");
		
		peek.setBuffer(peekBuffer);
		health = 10;
		isLife = true;
		isMove = false; onGround = false;
		dir = 0; speed = 0;  dx = 0; dy = 0;
		score = 0;
		dxT = 0; dyT = 0;
		w = W; h = H;
		t.loadFromFile(f);
		player.setTexture(t);
		player.setTextureRect(sf::IntRect(0,0,w,h));
		x = X; y = Y;
		player.setPosition(x, y);
	}
	void control(float time) {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			state = left;
			speed = 0.3;
			
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			player.setTextureRect(sf::IntRect(w * int(CurrentFrame) + w, 0, -w, h));
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			state = right;
			speed = 0.3;
			
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			player.setTextureRect(sf::IntRect(w * int(CurrentFrame), 0, w, h));
			
		}
	
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (onGround)) {
			jumpM.play();
			state = jump; dy = -0.5; onGround = false;
		}
		if ((Keyboard::isKeyPressed(sf::Keyboard::Up)) && (state == climb)) {
			speed = 0.3;
			y -= 3; dy = -speed;
		}
		if ((sf::Keyboard::isKeyPressed(Keyboard::Down)) && (state == climb)) {
			speed = 0.3;
			y += 3; dy = speed;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && goDown) {
			goDownAway = false;
			textMap = "map4";
			posMap(&x,&y,'P');
			goDown = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && goToLobby) {
			goToLobby = false;
			text = "Lobby";
			textMap = "map2";
			posMap(&xP, &yP, 'P');
			textMap = "k";
			x = xP; y = yP;
		}
		if (goToMap3) {
			restartGame = true;
			textMap = "map3";
			posMap(&x, &y, 'I');
			goToMap3 = false;
		}
		if (goToMap2) {
			restartGame = true;
			textMap = "map2";
			posMap(&x, &y, 'P');
			goToMap2 = false;
		}
		if (goToMap1) {
			textMap = "map";
			posMap(&x, &y, 'P');
			goToMap1 = false;
		}
		getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
	}
	void checkCollisionWithMap(float Dx, float Dy)
	{
		if (textMap == "map") {
			for (int i = y / 32; i < (y + h) / 32; i++)
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map[i][j] == '0')
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
						if (Dx > 0) { x = j * 32 - w; }
						if (Dx < 0) { x = j * 32 + 32; }
					}
					if (map[i][j] == 'U') {
						state = climb; onGround = false;
						dx = 0;
					}
					if (map[i][j] == 'F') {
						state = stay;
					}
					if (map[i][j] == 'C') {
						peek.play();
						texMap[i][j] = ' ';
						map[i][j] = ' ';
						++score;
					}
					if (map[i][j] == 'X' && state == jump) {
						dy = -0.7;
					}
					if (map[i][j] == 'E') {
						text = "Play";
						textMap = "map3";
						posMap(&xP, &yP, 'P');
						x = xP; y = yP;
					}
				}
		}
		else if (textMap == "map2") {
			for (int i = y / 32; i < (y + h) / 32; i++)
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map2[i][j] == '0')
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
						if (Dx > 0) { x = j * 32 - w; }
						if (Dx < 0) { x = j * 32 + 32; }
					}
					if (map2[i][j] == 'U') {
						state = climb; onGround = false;
						dx = 0;
					}
					if (map2[i][j] == 'F') {
						state = stay;
					}
					if (map2[i][j] == 'X' && state == jump) {
						dy = -0.7;
					}
					if (map2[i][j] == 'O') {
						isOpen = true;
						texMap2[i][j] = ' ';
					}
					if (map2[i][j] == 'D' && !isOpen) {
						if (Dx > 0) { x = j * 32 - w; }
						if (Dx < 0) { x = j * 32 + 32; }
					}
					if (map2[i][j] == 'C') {
						peek.play();
						map2[i][j] = ' ';
						texMap2[i][j] = ' ';
						++score;
					}
					if (map2[i][j] == 'S') {
						goToMap1 = true;
					}
					if (map2[i][j] == 'O') {
						map2[i][j] = ' ';
					}
				}
		}
		else if (textMap == "map3") {
			for (int i = y / 32; i < (y + h) / 32; i++)
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map3[i][j] == '0')
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
						if (Dx > 0) { x = j * 32 - w; }
						if (Dx < 0) { x = j * 32 + 32; }
					}
					if (map3[i][j] == 'G' && goDownAway)
					{
						goDown = true;
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
						if (Dx > 0) { x = j * 32 - w; }
						if (Dx < 0) { x = j * 32 + 32; }
					}
					else {
						goDown = false;
					}
					if (map3[i][j] == 'U') {
						state = climb; onGround = false;
						dx = 0;
					}
					if (map3[i][j] == 'F') {
						state = stay;
					}
					if (map3[i][j] == 'X' && state == jump) {
						dy = -0.7;
					}
					if (map3[i][j] == 'C') {
						peek.play();
						map3[i][j] = ' ';
						texMap3[i][j] = ' ';
						++score;
					}
					if (map3[i][j] == 'S') {
						goToMap2 = true;
					}
				}
		}
		else if (textMap == "map4") {
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (map4[i][j] == '0')
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
					if (Dx > 0) { x = j * 32 - w; }
					if (Dx < 0) { x = j * 32 + 32; }
				}
				if (map4[i][j] == 'G')
				{
					goToMap3 = true;
				}
				if (map4[i][j] == 'C') {
					peek.play();
					map4[i][j] = ' ';
					++score;
				}
			}
		}
	}
	void update(float time)
	{
		control(time);
		switch (state)
		{
		case right: dx = speed; dxT = speed; 
			break;
		case left: dx = -speed;  dxT = -speed; 
			
			break;
		case up: break;
		case down: break;
		case jump:  break;
		case stay: dx = 0; CurrentFrame = 0; break;
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0);
		if(state != climb)
			y += dy * time;
		checkCollisionWithMap(0, dy);
		if (!isMove) {
			speed = 0;
		}
		player.setPosition(x, y);
		if (state != climb) {
			dy = dy + 0.0015*time;
		}
	}

	float getplayercoordinateX() {	
		return x;
	}
	float getplayercoordinateY() {
		return y;
	}
    
    void draw(const sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(player, states);
    }
};