#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;//�������� sfml ������ "���", ������� � �������� �������
float vX, vY;
void getplayercoordinateforview(float x, float y) { //������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����
	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 

}
