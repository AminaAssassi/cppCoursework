#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "room.hpp"

class Character {
private:
    std::string Name;
    int Health;
    std::vector<Item> inventory;

public:
    Character (const std::string& name, int health){
        Name=name;
        Health=health;

    };
    void TakeDamage(int damage);
};

class Player : public Character {
private:
    Room* location;

public:
    Player(const std::string& name, int health);
    void setLocation(Room *location);
    Room* GetLocation(); //need to return a value
};