#pragma once
#include <ientity.hpp>

class Enemy : public IEntity
{
public:
	~Enemy() override = default;
	void update(float time) override;

private:
	float CurrentFrame { 0 };

	float dx, dy;
	float speed { 0.1f };
	enum { LEFT, RIGHT } state { LEFT };

};