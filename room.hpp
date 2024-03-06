#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.hpp"

class Room {
private:
    std::string description;
    std::map<std::string, Room*>exits;
    std::vector<Item> items;


public:
    Room(const std::string& desc){
        description=desc;
    };
    void AddItem(const Item& item);
    void removeItem(const Item& item);
    void AddExit(std::string compassDirection, Room *pRoom);
    std::string GetDescription();
    std::vector<Item> GetItems();
    Room* GetExit(const std::string& compassDirection)const;

};
