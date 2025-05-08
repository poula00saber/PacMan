#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace sf;


sf::RenderWindow window(sf::VideoMode(1680, 1050), "SFML works!");
sf::CircleShape shape(100.f);
sf::RectangleShape shapeRect(sf::Vector2f(300.f, 300.f));


int pacManSize = 135;


struct Pacman {
public:
	int x;
	int y;
	int size;
	int speed;
	bool alive;
    sf::Texture texture;
    sf::Event playerEvent;
	sf::Sprite sprite;

    Pacman(int x, int y, int size, int speed) {
		this->x = x;
		this->y = y;
		this->speed = speed;
		this->alive = true;
		if (!texture.loadFromFile("images/Pacman.png")) {
			std::cout << "Error loading texture" << std::endl;
		}
		sprite.setTexture(texture);
    }

	void move(int dx, int dy) {
       
	}
}player(1000,200, 0, 10);

bool collide(sf::CircleShape circle, sf::RectangleShape rect)
{
    if (circle.getPosition().y + 2 * circle.getRadius() >= rect.getPosition().y)
        return true;
    return false;
}




void Update();
void Start();
void Draw();
float deltaTime;
int main()
{
    Start();
    Clock clock;
    
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Update();
        Draw();
    }
    return 0;
}
void Start()
{
    // code here is only executed at the start of the program

    shape.setFillColor(sf::Color::Green);
	shapeRect.setFillColor(sf::Color::Red);
	shapeRect.setPosition(0, 600);
}
void Update()
{
	 // move the circle down by 0.1 pixels every frame

    if (!collide(shape, shapeRect))
    {
        shape.move(0, 0.5f);
    }

}
void Draw()
{
    // code here is executed every frame since the start of the program

    window.clear(); //clear every pixel on the screen

    //Draw your sprites here

    window.draw(shape);
    window.draw(shapeRect);
    window.draw(player.sprite);
    
    window.display(); //Display sprites on screen
}

