#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <filesystem>

class IMapLoader : public sf::Drawable
{
public:
    virtual ~IMapLoader() = default;

    virtual void load(const std::filesystem::path& filename) = 0;
    virtual void doCollision() = 0;

};