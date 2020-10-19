#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1390, 820), "Bird of shit");
	////// Circle
		sf::CircleShape collision1(50.f);
		collision1.setPosition({ 60.f, 50.f });
		collision1.setFillColor(sf::Color::Cyan);
		
	//background
		sf::Texture background;
		if (!background.loadFromFile("background/gg.png"))
		{
			std::cout << "Load failed" << std::endl;
		}
	
	////// Texture player
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("monster/kk.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	// rock
	sf::Texture playerTexture1;
	if (!playerTexture1.loadFromFile("hinder/rock.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	//rock2
	sf::Texture playerTexture2;
	if (!playerTexture2.loadFromFile("hinder/rock.png"))
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
	
	//rock
	sf::Sprite shapeSprite1;
	shapeSprite1.setTexture(playerTexture1);
	sf::Vector2f spawnPoint1 = { 1000.f, 350.f };
	shapeSprite1.setPosition(spawnPoint1);

	int spriteSizeX1 = playerTexture1.getSize().x / 8;
	int spriteSizeY1 = playerTexture1.getSize().y / 8;

	shapeSprite1.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));
	
	//rock2
	sf::Sprite shapeSprite2;
	shapeSprite2.setTexture(playerTexture2);
	sf::Vector2f spawnPoint2 = { 900.f, 50.f };
	shapeSprite2.setPosition(spawnPoint2);

	int spriteSizeX2 = playerTexture2.getSize().x / 8;
	int spriteSizeY2 = playerTexture2.getSize().y / 8;

	shapeSprite2.setTextureRect(sf::IntRect(640, 0, spriteSizeX2, spriteSizeY2));
	
	//background
	sf::Sprite backg;
	backg.setTexture(background);
	sf::Vector2f spawnPoint3 = { 0.f, 0.f };
	backg.setPosition(spawnPoint3);

	int spriteSizeX3 = background.getSize().x/1;
	int spriteSizeY3 = background.getSize().y/1;

	backg.setTextureRect(sf::IntRect(0, 0, spriteSizeX3, spriteSizeY3));

	float totalTime = 0;
	float speed = 400.0f;
	float deltaTime = 0.0f;
	sf::Clock clock;
	while (window.isOpen())
	{
		window.draw(backg);
		window.draw(collision1);
		window.draw(shapeSprite);
		window.draw(shapeSprite1);
		window.draw(shapeSprite2);
		window.display();
		deltaTime = clock.restart().asSeconds();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(speed* deltaTime, speed*0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shapeSprite.move(-speed * deltaTime, speed * 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			shapeSprite.move(speed * 0.f, -speed * deltaTime);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
			if (animationFrame >= 4) {
				animationFrame = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			shapeSprite.move(speed * 0.f, speed * deltaTime);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
			if (animationFrame >= 4) {
				animationFrame = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		totalTime += deltaTime;
		if (totalTime >= 0.1)
		{
			totalTime -= 0.1;
			animationFrame++;
		}

		if (animationFrame >= 5) {
			animationFrame = 0;
		}
		//rock
		if (shapeSprite1.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			shapeSprite.setPosition({60.f,50.f});
		}
		//rock2
		if (shapeSprite2.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			shapeSprite.setPosition({ 60.f,50.f });
		}
		window.clear();
	}	

	return 0;
}