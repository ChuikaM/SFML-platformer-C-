#pragma once
#include <imaploader.hpp> 
#include <vector>
#include <map>

class Enemy;

class TextMapLoader : public IMapLoader
{
public:
    explicit TextMapLoader();
    ~TextMapLoader() override = default;

    void load(const std::filesystem::path& filename) override;
    void doCollision() override;
    void update(float time) override;

    void draw(sf::RenderTarget& target,
                         sf::RenderStates states) const override;

private:
    std::vector<std::unique_ptr<Enemy>> m_enemies;
    std::map<char, sf::Texture> m_block_textures;
    std::map<char, sf::Texture> m_enemies_textures;
    std::string m_map;

};