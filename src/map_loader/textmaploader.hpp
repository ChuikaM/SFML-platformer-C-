#pragma once
#include <imaploader.hpp> 

class TextMapLoader : public IMapLoader
{
public:
    explicit TextMapLoader();
    ~TextMapLoader() override;

    void load(const std::filesystem::path& filename);
    void doCollision();

    void draw(sf::RenderTarget& target,
                         sf::RenderStates states) const override;

};