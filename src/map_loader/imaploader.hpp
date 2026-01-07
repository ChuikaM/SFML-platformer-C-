#pragma once
#include <SFML/Graphics/Drawable.hpp>

class IMapLoader : public sf::Drawable
{
public:
    virtual ~IMapLoader() = 0;

    virtual void load(const char* fileName) = 0;
    virtual void doCollision() = 0;

};