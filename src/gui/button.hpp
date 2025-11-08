#pragma once

class Button 
{
private:
	bool isSelect;
	sf::Color c;
	sf::Texture t;
	bool isC;
	float xZ;

public:
	float x, y, w, h;
	float vol;
	sf::Sprite button;
	Button(float X, float Y, float W, float H,sf::Texture* tex,bool issf::Color) {
		isSelect = false;
		w = W; h = H; x = X; y = Y; t = *tex;
		xZ = x; vol = 50;
		isC = issf::Color;
		button.setTexture(t);
		button.setTextureRect(sf::IntRect(0,0,w,h));
		button.setPosition(x,y);
	}
	void isPressed(sf::Vector2i mousePoz, sf::Event sf::Event, std::string text, std::string* txt) {
		if (button.getGlobalBounds().contains(mousePoz.x,mousePoz.y)) {
			if (isC) 		
			button.setsf::Color(sf::Color::Blue);

			if (sf::Event.type == sf::Event::MouseButtonPressed) {
				if (sf::Event.key.code == sf::Mouse::Left) {
					std::cout << "Pressed";
				}
			}
			if (sf::Event.type == sf::Event::MouseButtonReleased) {
				if (sf::Event.key.code == sf::Mouse::Left) {
					if (text == "goToPlay") {
						std::cout << "\nButton goToPlay is pressed!\n";
						*txt = "goToPlay";
					}
					if (text == "goToShop") {
						std::cout << "\nButton goToShop is pressed!\n";
						*txt = "goToShop";
					}
					if (text == "goToSettigs") {
						std::cout << "\nButton goToSettigs is pressed!\n";
						*txt = "goToSettigs";
					}
					if (text == "showFPS") {
						std::cout << "\nButton showFPS is pressed!\n";
						*txt = "showFPS";
					}
					if (text == "goToMap2") {
						issetViewAtGame = true;
						std::cout << "\nButton goToMap2 is pressed!\n";
						*txt = "goToMap2";
					}
				}
			}
		}
		else {
			button.setColor(sf::Color::White);
		}
	}
	void moveButton(sf::Vector2i mousePoz, sf::Event sf::Event) {
		if (button.getGlobalBounds().contains(mousePoz.x,mousePoz.y)) {
			if (sf::Event.type == sf::Event::MouseButtonPressed) {
				if (sf::Event.key.code == sf::Mouse::Left) {
					isSelect = true;
				}
				else {
					isSelect = false;
				}
				
			}
		}
		
		
	}
	void update(float time, sf::Vector2i mousePoz, float size, char c) {
		if (isSelect) {
			if (xZ + size > mousePoz.x && xZ < mousePoz.x) {
				x = mousePoz.x;
				button.setPosition(x,y);
			}
			if (c = 'v') {
				vol = x - xZ;
			}
		}
	}
};