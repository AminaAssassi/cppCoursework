#include "room.hpp"

void Room::AddItem(const Item& item)
{
    std::cout << " i added an item" << std::endl;
}

void Room::removeItem(const Item& item)
{
    std::cout << "I removed an item" << std::endl;
}

void Room::AddExit(std::string compassDirection, Room *pRoom)
{
    std::cout<<"adding an exit to the room"<<std::endl;
    exits[compassDirection]=pRoom;
}

std::string Room::GetDescription()
{
    std::cout<<"returns the room description"<<std::endl;
    return description;
}

std::vector<Item> Room::GetItems()
{
    std::cout<<"returns the items in the room"<<std::endl;
    return items;
}

Room* Room::GetExit(const std:: string& compassDirection)const {
    auto it = exits.find(compassDirection);
    if (it != exits.end()){
        return it ->second; //returns the pointer to the exit room
    }else{
        return nullptr; //No exit in the given direction
    }
}