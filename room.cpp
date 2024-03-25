#include "room.hpp"

void Room::AddItem(const Item& item)
{
    items.push_back(item); //inserts 'item' object to the end of the vector 'items'
    std::cout << "Added item: "<< item.GetName()<< " to the room" << std::endl;
}

void Room::removeItem(const Item& item)
{
    std::cout << "I removed an item" << std::endl;
}

void Room::AddExit(std::string compassDirection, Room *pRoom)
{
    std::cout<<"adding an exit to the room"<<std::endl;
    exits[compassDirection]=pRoom; //adding an exit from current room to another room in the specified compass direction by updating the 'exits' map accordingly
}

std::string Room::GetDescription()
{
    return description; //returns the description of the room as a string
}

std::vector<Item> Room::GetItems()const
{
    return items; //returns all of the items that are present in the room
}

Room* Room::GetExit(const std:: string& compassDirection)const {
    auto it = exits.find(compassDirection);
    if (it != exits.end()){
        return it ->second; //returns the pointer to the exit room
    }else{
        return nullptr; //No exit in the given direction
    }
}