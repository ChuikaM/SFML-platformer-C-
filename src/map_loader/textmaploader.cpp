#include <textmaploader.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>


TextMapLoader::TextMapLoader()
{
    // Init our map
}
TextMapLoader::~TextMapLoader()
{
    // Delete entities & map
}

void TextMapLoader::load(const std::filesystem::path& filename)
{
    // Load map from the fileName
}

void TextMapLoader::doCollision()
{
    // Doing collision here
}

void TextMapLoader::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const
{
    // Draw entities & map
}