#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Functions.h"
#include"View.h"
using namespace sf;
//#pragma comment(lib)
//using namespace std;
float xP, yP;
bool issetViewAtGame = true;
bool isOpen = false;
bool isOpenAtMap[5];
bool isAchivement = false;
bool isSkin = false;
bool goToLobby = false;
//std::string text = "Home";
std::string text = "Play";
class Button {
private:
	bool isSelect;
	Color c;
	Texture t;
	bool isC;
	float xZ;
public:
	float x, y, w, h;
	float vol;
	Sprite button;
	//RectangleShape button;
	Button(float X, float Y, float W, float H,Texture* tex,bool isColor) {
		isSelect = false;
		w = W; h = H; x = X; y = Y; t = *tex;
		xZ = x; vol = 50;
		isC = isColor;
		//button.setSize(Vector2f(w,h));
		//button.setFillColor(c);
		button.setTexture(t);
		button.setTextureRect(IntRect(0,0,w,h));
		button.setPosition(x,y);
	}
	void isPressed(Vector2i mousePoz, Event event, std::string text, std::string* txt) {
		if (button.getGlobalBounds().contains(mousePoz.x,mousePoz.y)) {
			if (isC) 		
			button.setColor(Color::Blue);

			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					std::cout << "Pressed";
				}
			}
			if (event.type == Event::MouseButtonReleased) {
				if (event.key.code == Mouse::Left) {
					/*if (text == "goToHome") {
						issetViewAtGame = true;
						std::cout << "\nButton goToHome is pressed!\n";
						*txt = "goToHome";
					}*/
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
			button.setColor(Color::White);
		}
	}
	void moveButton(Vector2i mousePoz, Event event) {
		if (button.getGlobalBounds().contains(mousePoz.x,mousePoz.y)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					//std::cout << "PressedA";
					isSelect = true;
				}
				else {
					isSelect = false;
				}
				
			}
		}
		
		
	}
	void update(float time, Vector2i mousePoz, float size, char c) {
		if (isSelect) {
			if (xZ + size > mousePoz.x && xZ < mousePoz.x) {
				//std::cout << "MoveA";
				x = mousePoz.x;
				button.setPosition(x,y);
			}
			if (c = 'v') {
				vol = x - xZ;
			}
		}
	}
};
bool doDamageToBoss = false;


bool restartGame = true;
bool goDown = false;
bool goDownAway = true;
bool goToMap3 = false;
bool goToMap2 = false;
bool goToMap1 = false;
bool goToBoss = false;
class Player {
private:  
	float health;
	float CurrentFrame = 0;
	SoundBuffer jumpBuffer;//создаём буфер для звука
	SoundBuffer peekBuffer;//создаём буфер для звука
	Sound peek;
	Sound jumpM;
public:
	float score;
	float x, y;
	enum { left, right, up, down, jump, stay,climb } state;
	bool isMove, onGround;
	bool isLife;
	float w, h, dx, dy, speed;
	float dxT, dyT;
	int dir = 0;
	Texture t;
	Sprite player;
	//RectangleShape player;
	//String File;
	//Image image;
	//Texture texture;
	//Sprite sprite;
	Player(float X, float Y, float W, float H,String f) {
		
		jumpBuffer.loadFromFile("Sounds/jump.ogg");//загружаем в него звук
		//Sound jump(jumpBuffer);
		jumpM.setBuffer(jumpBuffer);
		
		peekBuffer.loadFromFile("Sounds/pick.ogg");//загружаем в него звук
		
		//Sound peek(peekBuffer);
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
		player.setTextureRect(IntRect(0,0,w,h));
		//player.setTextureRect(IntRect(0,0,w,h));
		//player.setSize(Vector2f(w,h));
		//player.setFillColor(Color::Blue);
		//File = F;
	//	image.loadFromFile("images/" + File);
		//image.createMaskFromColor(Color(41, 33, 59));
		//texture.loadFromImage(image);
		//sprite.setTexture(texture);
		x = X; y = Y;
		player.setPosition(x, y);
		//sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void control(float time) {
		
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			state = left;
			speed = 0.3;
			
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			player.setTextureRect(IntRect(w * int(CurrentFrame) + w, 0, -w, h));
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			state = right;
			speed = 0.3;
			
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			player.setTextureRect(IntRect(w * int(CurrentFrame), 0, w, h));
			
		}
	
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {
			jumpM.play();
			state = jump; dy = -0.5; onGround = false;//то состояние равно прыжок,прыгнули и сообщили, что мы не на земле
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (state == climb)) {
			speed = 0.3;
			y -= 3; dy = -speed;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && (state == climb)) {
			speed = 0.3;
			y += 3; dy = speed;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && goDown) {
			goDownAway = false;
			textMap = "map4";
			posMap(&x,&y,'P');
			goDown = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::G) && goToLobby) {
			goToLobby = false;
			text = "Lobby";
			//std::cout << "\n: " << x << " " << y << std::endl;
			textMap = "map2";
			posMap(&xP, &yP, 'P');
			//std::cout << "\n: " << x << " " << y << std::endl;
			textMap = "k";
			//player.setPosition(xP,yP);
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
		/*if (Keyboard::isKeyPressed(Keyboard::Down)) {
			state = down;
			speed = 0.1;
		}*/
		getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
	}
	void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
	{
		//int i2 = (y / 32) + 1;
		//int j2 = (x / 32)-1;
		if (textMap == "map") {
			for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map[i][j] == '0')//если элемент наш тайлик земли? то
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
						if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
						if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
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
						//std::cout << "\n: " << x << " " << y << std::endl;
						textMap = "map3";
						posMap(&xP, &yP, 'P');
						//std::cout << "\n: " << x << " " << y << std::endl;
						//textMap = "k";
						//player.setPosition(xP,yP);
						x = xP; y = yP;
					}
				}
		}
		else if (textMap == "map2") {
			for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map2[i][j] == '0')//если элемент наш тайлик земли? то
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
						if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
						if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
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
			for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map3[i][j] == '0')//если элемент наш тайлик земли? то
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
						if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
						if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
					}
					/*if (map3[i2][j2] == '0'  && state != climb) {
						onGround = true;
					}
					if (map3[i][j] == ' ' && map3[i2][j2] == ' ') {
						onGround = false;
					}*/
					if (map3[i][j] == 'G' && goDownAway)//если элемент наш тайлик земли? то
					{
						goDown = true;
						if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
						if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
						if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
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
		for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (map4[i][j] == '0')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				if (map4[i][j] == 'G')//если элемент наш тайлик земли? то
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
		switch (state)//тут делаются различные действия в зависимости от состояния
		{
		case right: dx = speed; dxT = speed; 
			break;//состояние идти вправо
		case left: dx = -speed;  dxT = -speed; 
			
			break;//состояние идти влево
		case up: break;//будет состояние поднятия наверх (например по лестнице)
		case down: break;//будет состояние во время спуска персонажа (например по лестнице)
		case jump:  break;//здесь может быть вызов анимации
		case stay: dx = 0; CurrentFrame = 0;	 break;//и здесь тоже		
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
		if(state != climb)
			y += dy * time;
		checkCollisionWithMap(0, dy);//обрабатываем столкновение по Y
		if (!isMove) {
			speed = 0;
		}
		player.setPosition(x, y); //задаем позицию спрайта в место его центра
		if (state != climb) {
			dy = dy + 0.0015*time;//делаем притяжение к земле
		}
	}

	float getplayercoordinateX() {	//этим методом будем забирать координату Х	
		return x;
	}
	float getplayercoordinateY() {	//этим методом будем забирать координату Y 	
		return y;
	}

};
class Enemy {
private:
	float CurrentFrame = 0;
	float w, h;
public:
	float x, y;
	enum { left, right, up, down, jump, stay, climb } state;
	float dx, dy, speed;
	int dir = 0;
	String F;
	Texture t; 
	Sprite en;
	//RectangleShape en;
	Enemy() {
	}
	Enemy(String f) {
		t.loadFromFile(f);
		en.setTexture(t);
		en.setTextureRect(IntRect(0,0,12,16));
		en.setScale(2,2);
	}
	/*Enemy(float X, float Y, float H, float W, Color c): x(X), y(Y),w(W), h(H)
	{
		speed = 0.1;
		dy = speed;
		state = left;
		enemy.setSize(Vector2f(w,h));
		enemy.setFillColor(c);
		enemy.setPosition(x,y);
	}*/
	void setEnemy(float X, float Y, float H, float W,Color c) {
		x = X; y = Y; w = W; h = H;
		//F = f;
		//t.loadFromFile("Images/" + F);
		//en.setTexture(t);
		//en.setTextureRect(IntRect(0,0,w,h));
		//en.setTexture(*t);
		//en.setTextureRect(IntRect(0,0,w,h));

		speed = 0.1;
		dy = speed;
		state = left;
		//en.setSize(Vector2f(w, h));
		//en.setFillColor(c);
	}
	void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
	{
		if (textMap == "map2") {
			for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map2[i][j] == '0')//если элемент наш тайлик земли? то
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
						if (Dx > 0) { x = j * 32 - w; state = left; }//с правым краем карты
						if (Dx < 0) { x = j * 32 + 32; state = right; }// с левым краем карты
					}
				}
		}
		if (textMap == "map3") {
			for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
				for (int j = x / 32; j < (x + w) / 32; j++)
				{
					if (map3[i][j] == '0')//если элемент наш тайлик земли? то
					{
						if (Dy > 0) { y = i * 32 - h;  dy = 0; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
						if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
						if (Dx > 0) { x = j * 32 - w; state = left; }//с правым краем карты
						if (Dx < 0) { x = j * 32 + 32; state = right; }// с левым краем карты
					}
				}
		}
	}
	void update(float time)
	{
		switch (state)//тут делаются различные действия в зависимости от состояния
		{
		case right: 
			dx = speed;  
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			en.setTextureRect(IntRect(13 * int(CurrentFrame) + 13, 0, -13, 16));
			break;//состояние идти вправо
		case left: 
			dx = -speed;  
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			en.setTextureRect(IntRect(13 * int(CurrentFrame), 0, 13, 16));
			break;//состояние идти влево
		case up: break;//будет состояние поднятия наверх (например по лестнице)
		case down: break;//будет состояние во время спуска персонажа (например по лестнице)
		case jump: break;//здесь может быть вызов анимации
		case stay: break;//и здесь тоже		
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
		y += dy * time;
		checkCollisionWithMap(0, dy);//обрабатываем столкновение по Y
		en.setPosition(x, y); //задаем позицию спрайта в место его центра
		dy = dy + 0.0015*time;//делаем притяжение к земле
	}
};
bool isView = false;
bool isShowFPS = false;
float timeTimer = 0;
//bool isTime = true;
void whatIGo(std::string* txt, Player* p) {
	/*if (*txt == "goToHome") {
		textMap = "map";
		posMap(&xP, &yP, 'P');
		p->x = xP; p->y = yP;
		*txt = "Home";
	}*/
	if (*txt == "goToPlay") {
		*txt = "Play";
	}
	if (*txt == "goToShop") {
		*txt = "Shop";
	}
	if (*txt == "goToSettigs") {
		*txt = "Settings";
	}
	if (*txt == "showFPS") {
		isShowFPS = !isShowFPS;
		*txt = "Settings";
	}
	if (*txt == "goToMap2") {
		textMap = "map3";
		*txt = "Map2";
	}

}
const int NUM_OF_ENEMYES = 5;
void interrect(Player* p, Enemy* ene) {
	for (int i = 0; i < 3; i++) {
		if (p->player.getGlobalBounds().intersects(ene[i].en.getGlobalBounds())) {
			text = "Play";
			break;
		}
	}
}