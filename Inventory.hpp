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

    void displayInventory() const;

    void removeItem(Item* item);

    void useItem(Item* item);

    void setCapacity(int maxCapacity);

    int getCapacity();

    std::vector<Item*>& getItems();

};
