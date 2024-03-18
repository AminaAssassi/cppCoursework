#include "room.hpp"

void Room::AddItem(const Item& item)
{
    items.push_back(item);
    std::cout << "Added item: "<< item.GetName()<< " to the room" << std::endl;
    //std::cout << " i added an item" << std::endl;

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
    //std::cout<<"returns the room description"<<std::endl;
    return description;
}

std::vector<Item> Room::GetItems()const
{
    //std::cout<<"returns the items in the room"<<std::endl;
    //print each item in the vector
    //for (const auto& item : items) {
    //    std::cout << item << std::endl;
    //}
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