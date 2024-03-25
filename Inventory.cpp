#include "Inventory.hpp"

int capacity;


void Inventory::addItem(Item* item){
    if(items.size()<capacity) { //if the inventory isn't at maximum capacity
        items.push_back(item); //add the item to the inventory
        std::cout << "Added " << item->GetName() << " to the inventory. " << std::endl;
    }else {
        std::cout << "Inventory is full. Cannot add " << item->GetName() << "." << std::endl;
    }
}

void Inventory::displayInventory() const{
    std::cout<<"Player inventory: "<<std::endl;
    for (const Item* item : items){ //for all of the items in the inventory
        std::cout <<"-"<< item->GetName()<<std::endl; //print out the items name
    }
}

void Inventory::removeItem(Item* item){
    auto it=std::find(items.begin(), items.end(), item); //change code to lok for the object and not the pointer
    if (it != items.end()){ //if the item is found
        items.erase(it); //removes the item from the items vector
        std::cout<<"Removed "<<item->GetName()<<"from the inventory"<<std::endl;
    }else{
        std::cout<<"Item not found in inventory "<<std::endl;
    }
}

void Inventory::useItem(Item* item){
    auto it = std::find(items.begin(), items.end(), item); //looks for the item in the inventory
    if (it != items.end()){ //if the item is part of the inventory
        std::cout<< "using " <<item->GetName() <<" ...."<<std::endl;

        items.erase(it); //removes the item from the inventory
        if (item->GetName()=="key") {
            std::cout << "you used your " << item->GetName() << " to unlock a door which has a monster behind it." << std::endl;
        }else if (item-> GetName()=="sword"){
            std::cout << " you used your " << item->GetName() << " to protect yourself from the monster that was running towards you. " <<std::endl;
        }else{
            std::cout << " you used your " << item->GetName() << " to break the wall to escape " <<std::endl;
        }
        std::cout<<"you used " <<item->GetName()<<"."<<std::endl;
    }else{
        std::cout<< "item not found in inventory." << std::endl;
    }
}

void Inventory::setCapacity(int maxCapacity){
    capacity = maxCapacity; //sets the capacity for the inventory
}

int Inventory::getCapacity() {
    return capacity; //gets the capacity for the inventory
}

std::vector<Item*>& Inventory::getItems(){
    return items; //returns the items in the inventory
}
