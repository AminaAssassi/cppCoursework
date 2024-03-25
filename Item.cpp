#include "Item.hpp"

void Item::Interact()
{

    std::cout << "Something about an interaction"<<std::endl;

}

std::string Item::GetName()const
{
    return Name; //returns the items name
}

std::string  Item::GetDescription()const
{
    return Description; //returns the items description
}

