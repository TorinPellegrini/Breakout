#include <sstream>

#include "UI.h"
#include "GameManager.h"
#include <iomanip>

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) 
	: _window(window), _gameManager(gameManager)
{
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(sf::Color::Red);	
		newLife.setOutlineColor(sf::Color::Cyan);
		newLife.setOutlineThickness(4.0f);
		newLife.setRadius(LIFE_RADIUS);
		newLife.setPosition((LIFE_RADIUS*2 + LIFE_PADDING) * i, LIFE_PADDING);
		_lives.push_back(newLife);
	}
	_powerupText.setCharacterSize(30);
	_powerupText.setPosition(800, 10);
	_powerupText.setFillColor(sf::Color::Cyan);
	_font.loadFromFile("font/montS.ttf");
	_powerupText.setFont(_font);

	//Initialize Powerup Bar:
	powerupBarWidth = 10.f;
	powerupBarHeight = 3.f;
	powerupBarBox.setOutlineColor(sf::Color::White);
	powerupBarBox.setOutlineThickness(1.f);
	powerupBarBox.setPosition(200, 40);
}

UI::~UI()
{
}


void UI::updatePowerupText(std::pair<POWERUPS, float> powerup)
{
	std::ostringstream oss;

	switch (powerup.first)
	{
	case bigPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("big " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		powerupBarBox.setFillColor(paddleEffectsColour);
		powerupBarBox.setSize(sf::Vector2f(powerup.second * 20, 20));
		break;
	case smallPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("small " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		powerupBarBox.setFillColor(paddleEffectsColour);
		powerupBarBox.setSize(sf::Vector2f(powerup.second * 20, 20));

		break;
	case slowBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("slow " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		powerupBarBox.setFillColor(ballEffectsColour);
		powerupBarBox.setSize(sf::Vector2f(powerup.second * 20, 20));

		break;
	case fastBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fast " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		powerupBarBox.setFillColor(ballEffectsColour);
		powerupBarBox.setSize(sf::Vector2f(powerup.second * 20, 20));

		break;
	case fireBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fire " + oss.str());
		_powerupText.setFillColor(extraBallEffectsColour);
		powerupBarBox.setFillColor(extraBallEffectsColour);
		powerupBarBox.setSize(sf::Vector2f(powerup.second * 20, 20));

		break;
	case none:
		_powerupText.setString("");
		
		break;
	}
}

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
}

void UI::render()
{
	_window->draw(_powerupText);
	_window->draw(powerupBarBox);
	for (sf::CircleShape life : _lives)
	{
		_window->draw(life);
	}
}