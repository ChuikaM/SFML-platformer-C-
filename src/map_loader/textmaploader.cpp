#include <textmaploader.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <unordered_set>
#include <fstream>
#include <iostream>

TextMapLoader::TextMapLoader()
{
    m_block_textures.emplace('0', "../img/wall.png");
    m_block_textures.emplace('U', "../img/ladder.png");
}

void TextMapLoader::load(const std::filesystem::path& filename)
{
    std::ifstream is;
    is.exceptions(std::ios::failbit | std::ios::badbit);
    try
    {
        is.open(filename);
        m_map.assign( 
            std::istreambuf_iterator<char>(is), 
            std::istreambuf_iterator<char>()
        );

        static const std::unordered_set<char> enemySymbols { 'K' };
        static const std::unordered_set<char> playerSymbols { 'P' };

        std::size_t row = 0;
        std::size_t col = 0;
        for(const auto& ch : m_map)
        {
            if(ch == '\n')
            {
                row++;
                col = 0;
                continue;
            }
            if(enemySymbols.count(ch))
            {
                pushBackEnemyPosition({ch, {col * BLOCK_SIZE, row * BLOCK_SIZE}});
            }
            if(playerSymbols.count(ch))
            {
                pushBackPlayerPosition({ch, {col * BLOCK_SIZE, row * BLOCK_SIZE}});
            }
            col++;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "[ERORR][TextMapLoader::load] " << e.what() << std::endl;
    }
}

void TextMapLoader::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const
{
    sf::Sprite block{ m_block_textures.begin()->second };
    std::size_t y = 0;
    std::size_t x = 0;
    for (const auto& ch : m_map) {
        if(ch == '\n')
        {
            y++;
            x = 0;
            continue;
        }

        auto it = m_block_textures.find(ch);
        if (it != m_block_textures.end()) {
            block.setTexture(it->second);
            auto size = it->second.getSize();
            block.setPosition({x * size.x, y * size.y});
            target.draw(block, states);
        }

        x++;
    }
}