#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>

using namespace sf;

int main()
{
	float coordE[NUM_OF_ENEMYES * 2];
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	view.reset(sf::FloatRect(0, 0, 400, 300));
	posMap2(coordE,'K');
	posMap(&xP,&yP,'P');
	textMap = "map3";

	Texture texwall;
	texwall.loadFromFile("Images/wall.png");
	Player p(xP,yP,36,56, "Images/player.png");
	Enemy en1("Images/goastE2.png");
	Enemy en2("Images/goastE2.png");
	Enemy en3("Images/goastE2.png");
	Enemy en4("Images/goastE2.png");
	Enemy en5("Images/goastE2.png");
	Enemy eN[NUM_OF_ENEMYES];
	eN[0] = en1;
	eN[1] = en2;
	eN[2] = en3;
	eN[3] = en4;
	eN[4] = en5;
	int h = 0;
	int w = 0;

	Texture texGoastEnemy;
	texGoastEnemy.loadFromFile("Images/goastE.png");
	Texture texbox;
	texbox.loadFromFile("Images/box.png");
	Texture texbuff;
	texbuff.loadFromFile("Images/buff.png");
	Texture texgrass;
	texgrass.loadFromFile("Images/grass.png");
	Texture texcoin;
	texcoin.loadFromFile("Images/coin.png");
	Texture texlestnitsa;
	texlestnitsa.loadFromFile("Images/lestnitsa.png");
	Texture texzemly;
	texzemly.loadFromFile("Images/zemly.png");
	Texture texkey;
	texkey.loadFromFile("Images/key.png");

	Texture Ltexture[8];
	Ltexture[0] = texwall;
	Ltexture[1] = texbox;
	Ltexture[2] = texbuff;
	Ltexture[3] = texgrass;
	Ltexture[4] = texcoin;
	Ltexture[5] = texlestnitsa;
	Ltexture[6] = texzemly;
	Ltexture[7] = texkey;

	RectangleShape wall;
	wall.setSize(Vector2f(32.f,32.f));
	wall.setFillColor(Color::Green);
	RectangleShape buff;
	buff.setSize(Vector2f(32.f, 32.f));
	buff.setFillColor(Color::Magenta);
	RectangleShape goUp;
	goUp.setSize(Vector2f(32.f, 32.f));
	goUp.setFillColor(Color::Red);

	Font font;
	font.loadFromFile("fonts/Tiny5-Regular.ttf");
	Text Text2("", font, 20);
	Text2.setFillColor(Color::Red);
	Text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Text tFPS("",font,20);
	tFPS.setFillColor(Color::Red);
	tFPS.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Text textFps("show fps", font, 30);
	textFps.setFillColor(Color::Red);
	textFps.setPosition(300,320);
	textFps.setStyle(sf::Text::Bold);
	
	Clock c;
	Clock c2;
	int fps;
	float currentTime;
	float lastTime = 0;
	bool isPlay = true;
	while (window.isOpen())
	{
		currentTime = c2.getElapsedTime().asSeconds();
		Vector2i mousePoz = Mouse::getPosition(window);
		float time = c.getElapsedTime().asMicroseconds();
		c.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		if (isShowFPS) {
			fps = 1.f / (currentTime - lastTime);
			lastTime = currentTime;
		}
		window.clear(sf::Color::Blue);
		if (issetViewAtGame) {
			view.setSize(400,300);
			issetViewAtGame = false;
		}
		if (text == "Map2") {	
			p.update(time);
			isView = false;
			issetViewAtGame = false;
			drawMap2(&window, Ltexture, p.x, p.y);
			window.draw(p.player);
			if (restartGame) {
				continue;
			}
			isView = false;
			issetViewAtGame = false;
		}
		if (text == "Map2") {
			lobby.stop();
			std::ostringstream playerScoreString;
			playerScoreString << p.score;
			Text2.setString("SCORE: " + playerScoreString.str());
			if (isShowFPS) {
				std::ostringstream playerFps;
				playerFps << fps;
				tFPS.setString("FPS: " + playerFps.str());
				tFPS.setPosition(view.getCenter().x, view.getCenter().y - 150);
				window.draw(tFPS);
			}

			Text2.setPosition(view.getCenter().x - 170, view.getCenter().y - 150);
			window.draw(Text2);
			/*if (textMap != "map" || textMap != "map4") {
				for (int i = 0; i < NUM_OF_ENEMYES; i++) {
					//std::cout << "\nHell\n";
					eN[i].update(time);
					interrect(&p, &eN[i]);
					window.draw(eN[i].en);
				}
			}*/
		}
		if (isView) {
			setDoors(isOpenAtMap);
			view.reset(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
			view.setCenter(400,300);
			p.score = 0;
		}
	
		window.setView(view);
		window.display();
	}

	return 0;
}