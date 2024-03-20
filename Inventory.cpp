#include "Inventory.hpp"

int capacity;

//Implement ihe addItem function
//Implement logic to add an item to the players inventory
//Implement logic to use an item on a target object
void Inventory::addItem(Item* item){
    if(items.size()<capacity) {
        items.push_back(item);
        std::cout << "Added " << item->GetName() << " to the inventory. " << std::endl;
    }else {
        std::cout << "Inventory is full. Cannot add " << item->GetName() << "." << std::endl;
    }
}

void Inventory::displayInventory() const{
    std::cout<<"Player inventory: "<<std::endl;
    for (const Item* item : items){
        std::cout <<"-"<< item->GetName()<<std::endl;
    }
    //implement logic to display the items in the inventory
}
void Inventory::removeItem(Item* item){
    auto it=std::find(items.begin(), items.end(), item);
    if (it != items.end()){
        items.erase(it);
        std::cout<<"Removed "<<item->GetName()<<"from the inventory"<<std::endl;
    }else{
        std::cout<<"Item not found in inventory "<<std::endl;
    }
    //implement code to remove an item from inventory
}

void Inventory::useItem(Item* item){
    //implement code to use an item on a target object
}

void Inventory::setCapacity(int maxCapacity){
    capacity = maxCapacity;
}

int Inventory::getCapacity() {
    return capacity;
}
