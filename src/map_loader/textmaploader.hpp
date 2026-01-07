#pragma once
#include <imaploader.hpp> 

class TextMapLoader : public IMapLoader
{
public:
    explicit TextMapLoader();
    ~TextMapLoader() override;

    void load(const char* fileName);
    void doCollision();

    void TextMapLoader::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const override;
                         
};