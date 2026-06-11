#pragma once
#include <SFML/Graphics.hpp>

namespace Entity
{
	class Entity
	{
	public:
		Entity(float startX, float startY, float radius);

		virtual void Update(float deltaTime) = 0;
		void Move(float offsetX, float offsetY);
	protected:
		sf::CircleShape shape{};
	};

	class Player
	{
	public:
	private:
	};

	class Enemy
	{
	public:
	private:
	};
}