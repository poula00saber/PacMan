#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class FoodType { Dot, Skill, Fruit };

class Food {
protected:
    Vector2f position;
    float size;
    int foodValue;
    bool isEaten;
    FoodType type;
    Texture texture;
    Sprite image;

public:
    Food(FoodType type, int value);
    virtual void draw(RenderWindow& window) = 0;

    void setEaten();
    bool eaten() const;
    int getValueScore() const;
    FoodType getType() const;
    Vector2f getPosition() const;
    void setPosition( Vector2f pos);
};

class Dot : public Food {
public:
    Dot();
    void draw(RenderWindow& window) override;
};

class Skill : public Food {
public:
    Skill();
    void draw(RenderWindow& window) override;
};

class Fruit : public Food {
public:
    Fruit();
    void draw(RenderWindow& window) override;
};
