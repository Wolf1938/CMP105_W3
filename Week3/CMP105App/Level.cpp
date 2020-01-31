#include "Level.h"

int directionX = -1;
int directionY = -1;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circles[0].setRadius(20);
	circles[0].setPosition(sf::Vector2f(1200 / 2 - 50, 675 / 2 - 50));
	circles[0].setFillColor(sf::Color::Blue);
	circles[0].setOutlineColor(sf::Color::Red);

	circles[1].setRadius(30);
	circles[1].setPosition(sf::Vector2f(50,50));
	circles[1].setFillColor(sf::Color::Green);
	circles[1].setOutlineColor(sf::Color::Red);	
	
	circles[2].setRadius(20);
	circles[2].setPosition(sf::Vector2f(300,300));
	circles[2].setFillColor(sf::Color::Black);
	circles[2].setOutlineColor(sf::Color::Red);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		circles[1].move(0, -1000 * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		circles[1].move(0, 1000 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		circles[1].move(1000 * dt, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		circles[1].move(-1000 * dt, 0);
	}
	circles[1].setPosition(sf::Vector2f(circles[1].getPosition().x < 0 ? 0 : circles[1].getPosition().x >= window->getSize().x - circles[1].getRadius() * 2 ? window->getSize().x - circles[1].getRadius() * 2 : circles[1].getPosition().x, circles[1].getPosition().y < 0 ? 0 : circles[1].getPosition().y >= window->getSize().y - circles[1].getRadius() * 2 ? window->getSize().y - circles[1].getRadius() * 2 : circles[1].getPosition().y));
}

// Update game objects
void Level::update(float dt)
{
	/*directionX = circles[0].getPosition().x >= window->getSize().x ? -1 : circles[0].getPosition().x <= 0 ? 1 : directionX;
	circles[0].move(1000 * dt * directionX, 0);*/

	directionX = circles[2].getPosition().x <= 0 ? 1 : circles[2].getPosition().x >= window->getSize().x - circles[2].getRadius() * 2 ? -1 : directionX;
	directionY = circles[2].getPosition().y <= 0 ? 1 : circles[2].getPosition().y >= window->getSize().y - circles[2].getRadius() * 2 ? -1 : directionY;
	circles[2].move(500 * dt * directionX, 250 * dt * directionY);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circles[0]);
	window->draw(circles[1]);
	window->draw(circles[2]);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}