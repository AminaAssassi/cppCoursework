#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "character.hpp"

class Inventory{
private:
    std::vector<Item*> items; //use pointers for polymorphic behaviour
    int capacity;

public:

    Inventory(int maxCapacity) : capacity(maxCapacity){}
    void addItem(Item* item);

    void displayItems() const;

    void removeItem(Item* item);

    void useItem(Item* item);

};
