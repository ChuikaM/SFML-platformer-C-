#include <SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
#include <sstream>
#include<Windows.h>
#include<vector>
#include"SomeClasses.h"

using namespace sf;
int main()
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	float coordE[NUM_OF_ENEMYES * 2];
	float xB, yB;
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	view.reset(sf::FloatRect(0, 0, 400, 300));
	posMap2(coordE,'K');
	posMap(&xP,&yP,'P');
	textMap = "bossMap";
	posMap(&xB,&yB,'B');
	textMap = "map3";
	//-************************MUSIC*****************************************-
	Music lobby;
	lobby.openFromFile("Sounds/lobby.wav");
	
	//lobby.setLoop(true);
	//lobby.play();
	Texture texwall;
	texwall.loadFromFile("Images/wall.png");
	Player p(xP,yP,36,56, "Images/player.png");
	//Enemy en(xE, yE, 32, 32, Color::Red);
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
	//Boss b(xB,yB,64,64);
	int h = 0;
	//eN[0].setEnemy(coordE[h++], coordE[h], 32, 32, Color::Red);
	int w = 0;
	//int h = 0;
	/*for (int i = 0; i < NUM_OF_ENEMYES; i++) {
		std::cout << "\nH\n";
		eN[i].setEnemy(coordE[h++], coordE[h],32,32,Color::Red);
		++h;
		std::cout << "\nH\n";
	}
	h = 0;*/
	//en[1](xE,yE,32,32,Color::Red);
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

	Texture texButtonPlay;
	texButtonPlay.loadFromFile("Images/play.png");
	Texture texButtonShop;
	texButtonShop.loadFromFile("Images/shop.png");
	Texture texButtonSettings;
	texButtonSettings.loadFromFile("Images/settings.png");
	Texture texButtonPlayToMap;
	texButtonPlayToMap.loadFromFile("Images/playToMap.png");
	Texture texButtonOn;
	texButtonOn.loadFromFile("Images/bOn.png");
	Texture texButtonOff;
	texButtonOff.loadFromFile("Images/bOff.png");

	Texture Ltexture[8];
	//std::vector <Texture> Ltexture;
	/*Ltexture.push_back(texwall);
	Ltexture.push_back(texbox);
	Ltexture.push_back(texbuff);
	Ltexture.push_back(texgrass);
	Ltexture.push_back(texcoin);
	Ltexture.push_back(texlestnitsa);
	Ltexture.push_back(texzemly);*/
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
	Font font;//����� 
	font.loadFromFile("CyrilicOld.ttf");//�������� ������ ������ ���� ������
	Text Text2("", font, 20);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
	Text2.setFillColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
	Text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Text tFPS("",font,20);
	tFPS.setFillColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
	tFPS.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Text textFps("show fps", font, 30);
	textFps.setFillColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
	textFps.setPosition(300,320);
	textFps.setStyle(sf::Text::Bold);
//******************************************************************************//
	//Button goBack(0,0,64,64,Color::Red);
	Button play(0.f,0.f,210.f,210.f,&texButtonPlay,true);
	Button shop(0.f,200.f,210.f,210.f,&texButtonShop, true);
	Button settings(0.f,400.f,210.f,210.f,&texButtonSettings, true);
	Button map21(560.f,500.f,240.f,100.f,&texButtonPlayToMap, true);
//******************************************************************************//
	//Button buyS1(200.f,300.f,100.f,150.f,Color::Yellow);
	//Button buyS2(500.f, 300.f, 100.f, 150.f, Color::Yellow);
//******************************************************************************//
	Button showFPS(600.f, 300.f, 150.f, 100.f, &texButtonOff, false);
	Button volumeMS(600.f, 500.f, 60.f, 60.f, &texButtonOff, false);
//******************************************************************************//
	
	Clock c;
	Clock c2;
	Clock timerStop;
	int fps;
	float currentTime;
	float lastTime = 0;
	bool isShowContext = true;
	bool isPlay = true;
	//lobby.setLoop(true);
	while (window.isOpen())
	{
		///lobby.play();
		if (restartGame) {//���������� ����
			changeMap(map,MAPC,WIDTH,HEIGHT,'C');
			changeMap(texMap, texMapC, WIDTH, HEIGHT, 'C');

			changeMap(map2, MAP2C, WIDTH2, HEIGHT2, 'C');
			changeMap(texMap2, texMap2C, WIDTH2, HEIGHT2, 'C');
			changeMap(texMap2, texMap2C, WIDTH2, HEIGHT2, 'K');
			changeMap(map2, MAP2C, WIDTH2, HEIGHT2, 'O');

			changeMap(map3, MAP3C, WIDTH3, HEIGHT3, 'C');
			changeMap(texMap3, texMap3C, WIDTH3, HEIGHT3, 'C');

			changeMap(map4, MAP4C, WIDTH4, HEIGHT4, 'C');
			goDownAway = true;
			posMap2(coordE, 'K');
			for (int i = 0; i < NUM_OF_ENEMYES; i++) {
				eN[i].setEnemy(coordE[h++], coordE[h], 32, 32, Color::Red);
				++h;
			}
			h = 0;
			isView = true;
			restartGame = false;
		}
		currentTime = c2.getElapsedTime().asSeconds();
		Vector2i mousePoz = Mouse::getPosition(window);
		float time = c.getElapsedTime().asMicroseconds();
		c.restart();
		time = time / 800;
		//timeTimer = timerStop.getElapsedTime().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			
			if (text == "Play") {
				
				restartGame = true;
				timerStop.restart();
				timeTimer = 0;
				//isTime = true;
			//	std::cout << "HHH";
				play.isPressed(mousePoz, event, "goToPlay", &text);
				shop.isPressed(mousePoz, event, "goToShop", &text);
				settings.isPressed(mousePoz, event, "goToSettigs", &text);
				map21.isPressed(mousePoz, event, "goToMap2", &text);
				whatIGo(&text,&p);
			}
			if (text == "Shop") {
				play.isPressed(mousePoz, event, "goToPlay", &text);
				shop.isPressed(mousePoz, event, "goToShop", &text);
				settings.isPressed(mousePoz, event, "goToSettigs", &text);
			//	buyS1.isPressed(mousePoz, event, "buyS1", &text);
				//buyS2.isPressed(mousePoz, event, "buyS2", &text);
				whatIGo(&text, &p);
			}
			if (text == "Settings") {
				
				play.isPressed(mousePoz, event, "goToPlay", &text);
				shop.isPressed(mousePoz, event, "goToShop", &text);
				settings.isPressed(mousePoz, event, "goToSettigs", &text);
				showFPS.isPressed(mousePoz, event, "showFPS", &text);
				volumeMS.moveButton(mousePoz, event);
				whatIGo(&text, &p);
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (isShowFPS) {
			showFPS.button.setTexture(texButtonOn);
		}
		else {
			showFPS.button.setTexture(texButtonOff);
		}
		if (text == "Play" || text == "Shop" || text == "Settings") {
			if (lobby.getStatus() == false) {
				lobby.play();
				
			}
			if (isPlay == true) {
				lobby.setLoop(true);
				isPlay = false;
			}
		}
		if (isShowFPS) {
			fps = 1.f / (currentTime - lastTime);
			lastTime = currentTime;
		}
		window.clear(sf::Color::Blue);
		if (text == "Play") {
			//window.draw(goBack.button);
			//lobby.play();
			p.x = xP; p.y = yP;
			window.draw(play.button);
			window.draw(shop.button);
			window.draw(settings.button);
			window.draw(map21.button);
		}
		if (text == "Shop") {
			//lobby.play();
			//window.draw(goBack.button);
			window.draw(play.button);
			window.draw(shop.button);
			window.draw(settings.button);
			//window.draw(buyS1.button);
			//window.draw(buyS2.button);
		}
		if (text == "Settings") {
			//lobby.play();
			//window.draw(goBack.button);
			window.draw(play.button);
			window.draw(shop.button);
			window.draw(settings.button);
			window.draw(showFPS.button);
			volumeMS.update(time,mousePoz,100,'v');
			lobby.setVolume(volumeMS.vol);
			window.draw(volumeMS.button);
			window.draw(textFps);
		}
		/*if (text == "Map2") {
			isView = false;
			drawMap(&window, wall, buff, goUp);
			p.update(time);
			window.draw(p.player);
		}*/
		if (issetViewAtGame) {
			view.setSize(400,300);
			issetViewAtGame = false;
		}
		if (text == "Map2") {
			//std::cout << timeTimer << " ";
		
			//pause.x = p.x - 200;
			//pause.y = p.y - 200;
			
			
			//drawMap2(&window, Ltexture, p.x, p.y);
			//window.draw(p.player);
			
				p.update(time);
				//timeTimer = 0;
				isView = false;
				issetViewAtGame = false;
				drawMap2(&window, Ltexture, p.x, p.y);
				window.draw(p.player);
				
				//drawMap(&window, wall, buff, goUp,p.x,p.y);
				//drawMap2(&window, Ltexture, p.x, p.y);
				//if (restartGame) {
				//	//std::cout << "v" << restartGame;
				//	continue;
				//}
			
			if (restartGame) {
				//std::cout << "v" << restartGame;
				continue;
			}
			isView = false;
			issetViewAtGame = false;
			//isView = false;
			//issetViewAtGame = false;
			////drawMap(&window, wall, buff, goUp,p.x,p.y);
			//drawMap2(&window, Ltexture, p.x, p.y);
			//p.update(time);
			//if (restartGame) {
			//	//std::cout << "v" << restartGame;
			//	continue;
			//}
			//window.draw(p.player);
		}
		if (text == "Map2") {
			lobby.stop();
				std::ostringstream playerScoreString;    // �������� ����������
				playerScoreString << p.score;		//������� � ��� ����� �����, �� ���� ��������� ������
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
				if (textMap != "map" || textMap != "map4") {
					for (int i = 0; i < NUM_OF_ENEMYES; i++) {
						//std::cout << "\nHell\n";
						eN[i].update(time);
						interrect(&p, &eN[i]);
						window.draw(eN[i].en);
					}
				}
			
			//en.update(time);
			/*interrect(&p,&en);*/
			/*window.draw(en.enemy);*/
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