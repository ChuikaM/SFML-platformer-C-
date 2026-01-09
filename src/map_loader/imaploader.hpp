#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <vector>

using SymbolPosition = std::pair<char, sf::Vector2f>;

class IMapLoader : public sf::Drawable
{
public:
    virtual ~IMapLoader() = default;

    virtual void load(const std::filesystem::path& filename) = 0;

    [[nodiscard]] const std::vector<SymbolPosition>& getEnemyPositions() const
    {
        return m_enemy_positions; 
    };
    [[nodiscard]] const std::vector<SymbolPosition>& getPlayerPositions() const
    { 
        return m_player_positions; 
    };

    static const int BLOCK_SIZE { 32 };

protected: 
    void pushBackEnemyPosition(SymbolPosition position) noexcept
    {
        m_enemy_positions.push_back(std::move(position));
    }
    void pushBackPlayerPosition(SymbolPosition position) noexcept
    {
        m_player_positions.push_back(std::move(position));
    }

private:
    std::vector<SymbolPosition> m_enemy_positions;
    std::vector<SymbolPosition> m_player_positions;

};