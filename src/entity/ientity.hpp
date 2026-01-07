#pragma once
#include <SFML/Graphics.hpp>

class IEntity : public sf::Sprite
{
public:
    virtual ~IEntity() = default;
    virtual void update(float time) = 0;

};