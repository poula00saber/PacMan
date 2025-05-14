#include "Food.h"
#include <iostream>  
#include <cstdlib>  


Food::Food(FoodType type, int value, Vector2f pos, Vector2f sz)
    : type(type), foodValue(value), isEaten(false), position(pos), size(sz) {}


void Food::setEaten() {
    isEaten = true;
}


bool Food::eaten() const {
    return isEaten;
}


int Food::getValueScore() const {
    return foodValue;
}


FoodType Food::getType() const {
    return type;
}


Vector2f Food::getPosition() const {
    return position;
}


void Food::setPosition(Vector2f pos) {
    position = pos;
}


Dot::Dot(Vector2f pos) : Food(FoodType::Dot, 10, pos, sf::Vector2f(8, 8)) {}


void Dot::draw(RenderWindow& window) {
    if (!texture.loadFromFile("Assets/Textures/Pellet24.png")) {
        std::cerr << "Error loading texture for Dot!" << std::endl;
    }
    image.setTexture(texture);
    image.setPosition(position);
    window.draw(image);
}


Skill::Skill(sf::Vector2f position) : Food(FoodType::Skill, 50, position, sf::Vector2f(8, 8)) {
    setPosition(position); 
}

void Skill::draw(RenderWindow& window) {
    if (!texture.loadFromFile("Assets/Textures/Energizer24.png")) {
        std::cerr << "Error loading texture for Skill!" << std::endl;
    }
    image.setTexture(texture);
    image.setPosition(position);
    window.draw(image);
}
Fruit::Fruit(Vector2f pos)
    : Food(FoodType::Fruit, 100, pos, sf::Vector2f(8, 8))
{
    // Load texture only once in the constructor
    if (!texture.loadFromFile("Assets/Textures/Fruit32.png")) {
        std::cerr << "Error loading texture for Fruit!" << std::endl;
    }
    image.setTexture(texture);

    // Randomly select a fruit type ONCE when created
    fruitImageIndex = rand() % 8;  // Assuming 8 fruits in the sprite sheet
    image.setTextureRect(sf::IntRect(fruitImageIndex * 32, 0, 32, 32));
}

void Fruit::draw(RenderWindow& window) {
    // No need to reload the texture here!
    image.setPosition(position);
    window.draw(image);
}