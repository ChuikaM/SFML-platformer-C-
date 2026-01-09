#pragma once
#include <imaploader.hpp> 
#include <vector>
#include <map>

class Enemy;

class TextMapLoader : public IMapLoader
{
public:
    explicit TextMapLoader();
    ~TextMapLoader() override;

    void load(const std::filesystem::path& filename) override;
    void doCollision() override;

    void draw(sf::RenderTarget& target,
                         sf::RenderStates states) const override;

private:
    std::vector<std::unique_ptr<Enemy>> m_enemies;
    std::map<char, sf::Texture> m_textures;
    std::string m_map;

};