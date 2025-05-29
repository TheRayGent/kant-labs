#include <SFML/Graphics.hpp>

void main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!", sf::Style::Close, settings);


    sf::RectangleShape rect(sf::Vector2f(100,100));
    rect.setRotation(45);
    rect.setPosition(200,400);
    sf::RectangleShape rect2(sf::Vector2f(100,100));
    rect2.setRotation(45);
    rect2.setPosition(300,400);
    sf::RectangleShape rect3(sf::Vector2f(100,100));
    rect3.setRotation(45);
    rect3.setPosition(400,400);
    sf::RectangleShape rect4(sf::Vector2f(100,100));
    rect4.setRotation(45);
    rect4.setPosition(200,600);
    sf::RectangleShape rect5(sf::Vector2f(100,100));
    rect5.setRotation(45);
    rect5.setPosition(300,600);
    sf::RectangleShape rect6(sf::Vector2f(100,100));
    rect6.setRotation(45);
    rect6.setPosition(400,600);

    sf::RectangleShape rect1(sf::Vector2f(500,100));
    rect1.setPosition(100,370);
    rect1.setFillColor(sf::Color::Black);

    sf::RectangleShape rect12(sf::Vector2f(500,100));
    rect12.setPosition(100,670);
    rect12.setFillColor(sf::Color::Black);

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(100,350);

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Red);
    shape1.setPosition(390,350);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString(":)");
    text.setCharacterSize(50);
    text.setPosition(700,400);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rect);
        window.draw(rect6);
        window.draw(rect2);
        window.draw(rect3);
        window.draw(rect4);
        window.draw(rect5);
        window.draw(rect1);
        window.draw(rect12);
        window.draw(shape);
        window.draw(shape1);
        window.draw(text);
        window.display();
    }
}
