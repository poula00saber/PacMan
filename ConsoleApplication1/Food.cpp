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


// ======================= DOT =======================
Dot::Dot(Vector2f pos) : Food(FoodType::Dot, 10, pos, sf::Vector2f(8, 8)) {
    if (!texture.loadFromFile("Assets/Textures/Pellet24.png")) {
        std::cerr << "Error loading texture for Dot!" << std::endl;
    }
    image.setTexture(texture);
}

void Dot::draw(RenderWindow& window) {
    image.setPosition(position);
    window.draw(image);
}


// ======================= SKILL =======================
Skill::Skill(sf::Vector2f pos) : Food(FoodType::Skill, 50, pos, sf::Vector2f(8, 8)) {
    if (!texture.loadFromFile("Assets/Textures/Energizer24.png")) {
        std::cerr << "Error loading texture for Skill!" << std::endl;
    }
    image.setTexture(texture);
}

void Skill::draw(RenderWindow& window) {
    image.setPosition(position);
    window.draw(image);
}


// ======================= FRUIT =======================
Fruit::Fruit(Vector2f pos)
    : Food(FoodType::Fruit, 100, pos, sf::Vector2f(8, 8))
{
    if (!texture.loadFromFile("Assets/Textures/Fruit32.png")) {
        std::cerr << "Error loading texture for Fruit!" << std::endl;
    }
    image.setTexture(texture);

    fruitImageIndex = rand() % 8;  // 8 sprite frames
    image.setTextureRect(sf::IntRect(fruitImageIndex * 32, 0, 32, 32));
}

void Fruit::draw(RenderWindow& window) {
    image.setPosition(position);
    window.draw(image);
}
