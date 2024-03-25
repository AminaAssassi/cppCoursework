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
    auto it=std::find(items.begin(), items.end(), item); //change code to lok for the object and not the pointer
    if (it != items.end()){ //if the item is found
        items.erase(it); //removes the item from the items vector
        std::cout<<"Removed "<<item->GetName()<<"from the inventory"<<std::endl;
    }else{
        std::cout<<"Item not found in inventory "<<std::endl;
    }
    //implement code to remove an item from inventory
}

void Inventory::useItem(Item* item){
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()){
        std::cout<< "using " <<item->GetName() <<" ...."<<std::endl;

        items.erase(it);
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
    //implement code to use an item on a target object
}

void Inventory::setCapacity(int maxCapacity){
    capacity = maxCapacity;
}

int Inventory::getCapacity() {
    return capacity;
}

std::vector<Item*>& Inventory::getItems(){
    return items;
}
