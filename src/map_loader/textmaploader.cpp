#include <textmaploader.hpp>
#include <enemy.hpp> 

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <fstream>

TextMapLoader::TextMapLoader()
{
    sf::Texture wall("../img/wall.png");
    m_textures.emplace('0', std::move(wall));
    sf::Texture ladder("../img/ladder.png");
    m_textures.emplace('U', std::move(ladder));
}
TextMapLoader::~TextMapLoader()
{
    // Delete entities & map
}

void TextMapLoader::load(const std::filesystem::path& filename)
{
    std::ifstream is;
    is.exceptions(std::ios::failbit | std::ios::badbit);
    try
    {
        is.open(filename);
        m_map = { 
            std::istreambuf_iterator<char>(is), 
            std::istreambuf_iterator<char>()
        };
    }
    catch(const std::exception &e)
    {
        
    }
    is.close();
}

void TextMapLoader::doCollision()
{
    // Doing collision here
}

void TextMapLoader::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const
{
    sf::Sprite block{ m_textures.begin()->second };
    for (const auto& ch : m_map) {
        auto it = m_textures.find(ch);
        if (it != m_textures.end()) {
            block.setTexture(it->second);
            target.draw(block, states);
        }
    }

    for(const auto& enemy : m_enemies)
    {
        target.draw(*enemy, states);
    }
}