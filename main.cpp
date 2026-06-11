#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Silly Cat", sf::State::Fullscreen);
    sf::CircleShape shape(100.f);
    sf::CircleShape enemy(100.f);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition({ 1500.f, 0.f });

    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        sf::Vector2f playerPos = shape.getPosition();
        sf::Vector2f enemyPos = enemy.getPosition();
        float dx = playerPos.x - enemyPos.x;
        float dy = playerPos.y - enemyPos.y;
        float distance = std::sqrt(dx * dx + dy * dy);
        if (distance < shape.getRadius() + enemy.getRadius()) {
            // Столкновение!
            shape.setFillColor(sf::Color::Yellow); // Игрок пожелтел от укуса
        }
        enemy.move({-0.1f, 0.f});


        window.clear();
        window.draw(shape);
        window.draw(enemy);
        window.display();
    }
}