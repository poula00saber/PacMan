#include "Food.h"

Food::Food(FoodType type, int value)
    : type(type), foodValue(value), isEaten(false), size(16.0f) {}

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
    image.setPosition(position);
}


Dot::Dot() : Food(FoodType::Dot, 10) {}

void Dot::draw(RenderWindow& window) {
    texture.loadFromFile("Assets/Texture/Pellet24.png");
    image.setTexture(texture);
    image.setPosition(position);
    window.draw(image);
}

// SKILL
Skill::Skill() : Food(FoodType::Skill, 50) {}

void Skill::draw(RenderWindow& window) {
    texture.loadFromFile("Assets/image/Fruit32.png");
    image.setTexture(texture);
    image.setPosition(position);
    window.draw(image);
}

// FRUIT
Fruit::Fruit() : Food(FoodType::Fruit, 100) {}

void Fruit::draw(RenderWindow& window) {
    int fruitImageIndex = rand() % 6;
    texture.loadFromFile("Assets/images/Fruit32.png");
    image.setTexture(texture);
    image.setTextureRect(IntRect(fruitImageIndex * 32, 0, 32, 32));
    image.setPosition(position);
    window.draw(image);
}
