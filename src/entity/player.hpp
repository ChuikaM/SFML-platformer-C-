#pragma once
#include <ientity.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Player : public IEntity
{
public:
	~Player() override = default;
	void update(float time) override;

private:  
	float score;
	enum { LEFT, RIGHT, UP, DOWN, JUMP, STAY, CLIMB } state { STAY };
	bool isMove {};
	bool onGround {};
	float dx {};
	float dy {};
	float speed { 0.3f };
	int dir {};

	float CurrentFrame {};
	sf::SoundBuffer jumpBuffer;
	sf::SoundBuffer peekBuffer;
	sf::Sound peek;
	sf::Sound jumpM;

};