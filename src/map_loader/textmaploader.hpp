#pragma once
#include <imaploader.hpp> 
#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

class TextMapLoader : public IMapLoader
{
public:
    explicit TextMapLoader();
    ~TextMapLoader() override = default;

    void load(const std::filesystem::path& filename) override;
    void draw(sf::RenderTarget& target,
                         sf::RenderStates states) const override;

private:
    std::map<char, sf::Texture> m_block_textures;
    std::string m_map;

};