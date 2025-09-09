#include"Map.h"
#include"texMap.h"
#include<iostream>
#include<string>
//std::string textMap = "map";
std::string textMap = "map3";
void drawMap(RenderWindow* window,RectangleShape wall, RectangleShape buff, RectangleShape goUp,float x,float y) {
	bool isWall = false;
	bool isBuff = false;
	bool isGoUp = false;
	int t = y / 32;
	int l = x / 32;
	if (textMap == "map") {
		for (int i = t - 8; i < t+ 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (map[i][j] == '0') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (map[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (map[i][j] == 'U') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (isWall)
					wall.setPosition(j * 32, i * 32);
				else if (isBuff)
					buff.setPosition(j * 32, i * 32);
				else if (isGoUp) {
					goUp.setPosition(j * 32, i * 32);
				}
				window->draw(wall);
				window->draw(buff);
				window->draw(goUp);
			}
	}
	else if (textMap == "map2") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (map2[i][j] == '0') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (map2[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (map2[i][j] == 'U') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (isWall)
					wall.setPosition(j * 32, i * 32);
				else if (isBuff)
					buff.setPosition(j * 32, i * 32);
				else if (isGoUp) {
					goUp.setPosition(j * 32, i * 32);
				}
				window->draw(wall);
				window->draw(buff);
				window->draw(goUp);
			}
	}
	else if (textMap == "map3") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (map3[i][j] == '0') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (map3[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (map3[i][j] == 'U') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (isWall)
					wall.setPosition(j * 32, i * 32);
				else if (isBuff)
					buff.setPosition(j * 32, i * 32);
				else if (isGoUp) {
					goUp.setPosition(j * 32, i * 32);
				}
				window->draw(wall);
				window->draw(buff);
				window->draw(goUp);
			}
	}
	else if (textMap == "map4") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (map4[i][j] == '0') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (map4[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (map3[i][j] == 'U') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (isWall)
					wall.setPosition(j * 32, i * 32);
				else if (isBuff)
					buff.setPosition(j * 32, i * 32);
				else if (isGoUp) {
					goUp.setPosition(j * 32, i * 32);
				}
				window->draw(wall);
				window->draw(buff);
				window->draw(goUp);
			}
	}
}
void drawMap2(RenderWindow* window, Texture* tex, float x, float y) {
	Sprite s;
	bool isZemly = false;
	bool isGrass = false;
	bool isWall = false;
	bool isBox = false;
	bool isBuff = false;
	bool isGoUp = false;
	bool isCoin = false;
	bool isKey = false;
	int t = y / 32;
	int l = x / 32;
	if (textMap == "map") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (texMap[i][j] == 'K') {
					isKey = true;
				}
				else {
					isKey = false;
				}
				if (texMap[i][j] == 'G') {
					isGrass = true;
				}
				else {
					isGrass = false;
				}
				if (texMap[i][j] == '0') {
					isZemly = true;
				}
				else {
					isZemly = false;
				}
				if (texMap[i][j] == 'B') {
					isBox = true;
				}
				else {
					isBox = false;
				}
				if (texMap[i][j] == 'W') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (texMap[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (texMap[i][j] == 'L') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (texMap[i][j] == 'C') {
					isCoin = true;
				}
				else {
					isCoin = false;
				}
				if (isWall) {
					s.setTexture(tex[0]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGrass) {
					s.setTexture(tex[3]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isZemly) {
					s.setTexture(tex[6]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isKey) {
					s.setTexture(tex[7]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBox) {
					s.setTexture(tex[1]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBuff)
				{
					s.setTexture(tex[2]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGoUp) {
					s.setTexture(tex[5]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isCoin) {
					s.setTexture(tex[4]);
					s.setPosition(j * 32, i * 32);
				}
				window->draw(s);
			}
	}
	if (textMap == "map2") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (texMap2[i][j] == 'K') {
					isKey = true;
				}
				else {
					isKey = false;
				}
				if (texMap2[i][j] == 'G') {
					isGrass = true;
				}
				else {
					isGrass = false;
				}
				if (texMap2[i][j] == '0') {
					isZemly = true;
				}
				else {
					isZemly = false;
				}
				if (texMap2[i][j] == 'B') {
					isBox = true;
				}
				else {
					isBox = false;
				}
				if (texMap2[i][j] == 'W') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (texMap2[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (texMap2[i][j] == 'L') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (texMap2[i][j] == 'C') {
					isCoin = true;
				}
				else {
					isCoin = false;
				}
				if (isWall) {
					s.setTexture(tex[0]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGrass) {
					s.setTexture(tex[3]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isZemly) {
					s.setTexture(tex[6]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isKey) {
					s.setTexture(tex[7]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBox) {
					s.setTexture(tex[1]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBuff)
				{
					s.setTexture(tex[2]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGoUp) {
					s.setTexture(tex[5]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isCoin) {
					s.setTexture(tex[4]);
					s.setPosition(j * 32, i * 32);
				}
				window->draw(s);
			}
	}
	if (textMap == "map3") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (texMap3[i][j] == 'G') {
					isGrass = true;
				}
				else {
					isGrass = false;
				}
				if (texMap3[i][j] == '0') {
					isZemly = true;
				}
				else {
					isZemly = false;
				}
				if (texMap3[i][j] == 'B') {
					isBox = true;
				}
				else {
					isBox = false;
				}
				if (texMap3[i][j] == 'W') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (texMap3[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (texMap3[i][j] == 'L') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (texMap3[i][j] == 'C') {
					isCoin = true;
				}
				else {
					isCoin = false;
				}
				if (isWall) {
					s.setTexture(tex[0]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGrass) {
					s.setTexture(tex[3]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isZemly) {
					s.setTexture(tex[6]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBox) {
					s.setTexture(tex[1]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBuff)
				{
					s.setTexture(tex[2]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGoUp) {
					s.setTexture(tex[5]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isCoin) {
					s.setTexture(tex[4]);
					s.setPosition(j * 32, i * 32);
				}
				window->draw(s);
			}
	}
	if (textMap == "map4") {
		for (int i = t - 8; i < t + 8; i++)
			for (int j = l - 8; j < l + 8; j++) {
				if (map4[i][j] == '0') {
					isWall = true;
				}
				else {
					isWall = false;
				}
				if (map4[i][j] == 'X') {
					isBuff = true;
				}
				else {
					isBuff = false;
				}
				if (map4[i][j] == 'C') {
					isCoin = true;
				}
				else {
					isCoin = false;
				}
				if (map4[i][j] == 'U') {
					isGoUp = true;
				}
				else {
					isGoUp = false;
				}
				if (isWall) {
					s.setTexture(tex[0]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isBuff)
				{
					s.setTexture(tex[2]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isGoUp) {
					s.setTexture(tex[5]);
					s.setPosition(j * 32, i * 32);
				}
				else if (isCoin) {
					s.setTexture(tex[4]);
					s.setPosition(j * 32, i * 32);
				}
				window->draw(s);
			}
	}
}
void posMap(float* x, float* y,char ch) {
	if (textMap == "map") {
		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++)
			{
				if (map[i][j] == ch) {
					*x = j * 32;
					*y = i * 32;
					break;
				}
			}
	}
	else if (textMap == "map2") {
		for (int i = 0; i < HEIGHT2; i++)
			for (int j = 0; j < WIDTH2; j++)
			{
				if (map2[i][j] == ch) {
					*x = j * 32;
					*y = i * 32;
					break;
				}
			}
	}
	else if (textMap == "map3") {
		for (int i = 0; i < HEIGHT3; i++)
			for (int j = 0; j < WIDTH3; j++)
			{
				if (map3[i][j] == ch) {
					*x = j * 32;
					*y = i * 32;
					break;
				}
			}
	}
	else if (textMap == "map4") {
		for (int i = 0; i < HEIGHT4; i++)
			for (int j = 0; j < WIDTH4; j++)
			{
				if (map4[i][j] == ch) {
					*x = j * 32;
					*y = i * 32;
					break;
				}
			}
	}
}
void posMap2(float* coordE, char ch) {
	int h = 0;
	//int w = 0;
		if (textMap == "map") {
			for (int i = 0; i < HEIGHT; i++)
				for (int j = 0; j < WIDTH; j++)
				{
					if (map[i][j] == ch) {
						coordE[h++] = 32 * j;
						coordE[h] = 32 * i;
						++h;
					}
				}
		}
		else if (textMap == "map2") {
			for (int i = 0; i < HEIGHT2; i++)
				for (int j = 0; j < WIDTH2; j++)
				{
					if (map2[i][j] == ch) {
						coordE[h++] = 32 * j;
						coordE[h] = 32 * i;
						++h;
					}
				}
		}
		else if (textMap == "map3") {
			//std::cout << "\nH: " << h << "\n";
			for (int i = 0; i < HEIGHT3; i++)
				for (int j = 0; j < WIDTH3; j++)
				{
					if (map3[i][j] == ch) {
						coordE[h++] = 32 * j;
						coordE[h] = 32 * i;
						++h;
					}
				}
		}
		else if (textMap == "map4") {
			///std::cout << "\nH: " << h << "\n";
			for (int i = 0; i < HEIGHT4; i++)
				for (int j = 0; j < WIDTH4; j++)
				{
					if (map4[i][j] == ch) {
						coordE[h++] = 32 * j;
						coordE[h] = 32 * i;
						++h;
					}
				}
		}
	//	std::cout << "\nH: " << h << "\n";
}

void changeMap(String* Map1, String* Map2, const int WIDTHCs, const int HEIGHTCs,char ch) {
	for (int i = 0; i < HEIGHTCs; i++)
		for (int j = 0; j < WIDTHCs; j++)
		{
			if (Map2[i][j] == ch) {
				Map1[i][j] = ch;
			}
		}
}
void setDoors(bool* isOpenAtMap) {
	for (int i = 0; i < 5; i++) {
		isOpenAtMap[i] = false;
	}
}
