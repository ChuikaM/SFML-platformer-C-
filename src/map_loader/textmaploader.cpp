#include <textmaploader.hpp>
#include <enemy.hpp> 

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <fstream>
#include <iostream>

TextMapLoader::TextMapLoader()
{
    m_block_textures.emplace('0', "../img/wall.png");
    m_block_textures.emplace('U', "../img/ladder.png");

    m_enemies_textures.emplace('K', "../img/ghost.png");
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

        int row = 0;
        int col = 0;
        for(const auto& ch : m_map)
        {
            if(ch == '\n')
            {
                row++;
                col = 0;
                continue;
            }
            auto it = m_enemies_textures.find(ch);
            if(it != m_enemies_textures.end())
            {
                auto enemy = std::make_unique<Enemy>(it->second);
                enemy->setPosition({col * BLOCK_SIZE, row * BLOCK_SIZE});
                m_enemies.push_back(std::move(enemy));
            }
            col++;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "[ERORR][TextMapLoader::load] " << e.what() << std::endl;
    }
    is.close();
}

void TextMapLoader::doCollision()
{
    // Doing collision here
}

void TextMapLoader::update(float time)
{
    for(const auto& enemy : m_enemies)
    {
        enemy->update(time);
    }
}

void TextMapLoader::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const
{
    sf::Sprite block{ m_block_textures.begin()->second };
    for (const auto& ch : m_map) {
        auto it = m_block_textures.find(ch);
        if (it != m_block_textures.end()) {
            block.setTexture(it->second);
            target.draw(block, states);
        }
    }

    for(const auto& enemy : m_enemies)
    {
        target.draw(*enemy, states);
    }
}