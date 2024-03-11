#include "Item.hpp"

//void Item::Interact()
//{
//    std::cout << "Something about an interaction"<<std::endl;
//}

std::string Item::GetName()const
{
    //std::cout << "prints the items name"<<std::endl;
    return Name;
}

std::string  Item::GetDescription()const
{
    //std::cout <<"prints the items description"<<std::endl;
    return Description;
}

