#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 820), "Bird of shit");
	
	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("monster/kk.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	////// Sprite
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);
	sf::Vector2f spawnPoint = { 500.f, 300.f };
	shapeSprite.setPosition(spawnPoint);

	int spriteSizeX = playerTexture.getSize().x / 5;
	int spriteSizeY = playerTexture.getSize().y / 3;

	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	int animationFrame = 0;

	while (window.isOpen())
	{
		window.draw(shapeSprite);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(.6f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shapeSprite.move(-.6f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			shapeSprite.move(0.f, -.6f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			shapeSprite.move(0.f, .6f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;

		if (animationFrame >= 5) {
			animationFrame = 0;
		}
		window.clear();
	}
	return 0;
}