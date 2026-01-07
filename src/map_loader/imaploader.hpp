#pragma once
#include <SFML/Graphics/Drawable.hpp>

class IMapLoader : public sf::Drawable
{
public:
    virtual ~IMapLoader() = default;

    virtual void load(const char* fileName) = 0;
    virtual void doCollision() = 0;

};