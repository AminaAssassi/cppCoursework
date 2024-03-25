#include <iostream>
#include <vector>
//#include <map>
//#include "room.hpp"
//#include "Item.hpp"
#include "character.hpp"
#include "Inventory.hpp"


int main() {
    //create rooms
    Room startRoom("You are in a dimly lit room.");
    Room hallway("you are in a hallway");
    Room treasureRoom("You are in a treasure room!");

    //define exits between rooms
    startRoom.AddExit("north", &hallway);
    hallway.AddExit("south", &startRoom);
    hallway.AddExit("north", &treasureRoom);
    treasureRoom.AddExit("south", &hallway);

    //create Items
    Item key("key", "A shiny key that looks important");
    Item sword("sword", "A sharp sword");
    Item rock("rock","a small pebble");

    //Add items to rooms
    startRoom.AddItem(key);
    hallway.AddItem(rock);
    treasureRoom.AddItem(sword);

    //create a player
    //int player;
    Player player("Alice", 100);
    player.setLocation(&startRoom);

    //creating an instance of the inventory class
    Inventory playerInventory(10);

    //Game loop (basic interaction)
    while(true){
        std::cout<<"current Location: "<< player.GetLocation()->GetDescription() << std::endl;
        std::cout<<"Items in the room: "<<std::endl;
        for (const Item& item : player.GetLocation()-> GetItems()){
            //std::cout<<"entered the loop"<<std::endl;
            std::cout << "-"<<item.GetName() <<":" << item.GetDescription()<<std::endl;

        }
        /*for (const Item& item : player.GetLocation() -> GetItems()) {
            std::cout<<"-"<<item.GetName() << ": " <<item.GetDescription() << std::endl;
        }*/

        //for (int i= i=0; i<player.GetLocation() ->GetItems().size();i++){
        //   std::cout<<"-"<<player.GetLocation()->GetItems()[i].GetName() << ":" << player.GetLocation()->GetItems()[i].GetDescription() <<std::endl;

        //}
        std::cout << "options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Inventory options | " ;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            //player looks around( no action required
            std::cout <<"you look around the room. " << std::endl;
        } else if (choice==2){
            //player interacts with an item in the room
            std::cout << "Enter the name of the item you want to interact with";
            std::string itemName;
            std::cin>>itemName;

            for (Item& item : player.GetLocation() -> GetItems()) {
                if (item.GetName() == itemName) {
                    item.Interact();
                    break;
                }
            }
        } else if (choice == 3) {
            //player moves to another room
            std::cout<< "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::cin >>direction;

            Room* nextRoom = player.GetLocation() ->GetExit(direction);
            if (nextRoom != nullptr){
                player.setLocation(nextRoom);
                std::cout<<"You move to the next room." << std::endl;
            } else {
                std::cout<< "You can't go that way. " << std::endl;
            }
        } else if (choice == 4) {
            //display inventory options
            //display inventory items
            //add item
            //remove item
            // use item
            std::cout << "options: ";
            std::cout << "1. Display inventory | ";
            std::cout << "2. Add an item | ";
            std::cout << "3. Remove an item | ";
            std::cout << "4. Use an item | "<<std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 1){
                std::cout<<"code to display the inventory"<<std::endl;
                playerInventory.displayInventory();

            }else if (choice==2){
                std::cout<<"enter the name of the item you want to add to your inventory: ";
                std::string itemName;
                std::cin>>itemName;

                //search for the item in the current room's inventory
                Item thing;
                Item* currentItem=nullptr;
                for (Item& item : player.GetLocation()->GetItems()){
                    if (item.GetName() == itemName){
                        currentItem=&item;
                        thing=*currentItem;
                        break;
                    }
                }
                std::cout<<thing.GetName()<<std::endl;
                currentItem=&thing;
                if (currentItem != nullptr){
                    playerInventory.addItem(currentItem);
                    //std::cout<<"Added "<<currentItem->GetName()<<" to your inventory."<<std::endl; just a testing command
                    //a feature could be added where when an item is added to the inventory it is removed from the room
                }else {
                    std::cout<<"Item not found in the room. " <<std::endl;
                }

                std::cout<<"code to add an item to the inventory"<<std::endl;

            }else if (choice ==3){
                std::cout<<"code to remove an item from the inventory"<<std::endl;
                std::cout<<"enter the name of the item you want to remove from your inventory: ";
                std::string itemName;
                std::cin>>itemName;

                /*Item thing;
                Item* itemToRemove = nullptr;
                for (Item& item : player.GetLocation()->GetItems()){
                    if (item.GetName()==itemName){
                        itemToRemove = &item;
                        thing= *itemToRemove;
                        break;
                    }
                 }
                std::cout<<thing.GetName()<<std::endl;
                itemToRemove=&thing;
                if (itemToRemove != nullptr){
                    playerInventory.removeItem(itemToRemove);
                }else{
                    std::cout<<"Item not found in inventory"<<std::endl;
                }*/
                Item* itemToRemove = nullptr;
                for (Item* item : playerInventory.getItems()){
                    if (item->GetName()==itemName){
                        itemToRemove=item;
                        break;
                    }
                }
                if (itemToRemove != nullptr){
                    playerInventory.removeItem(itemToRemove);
                }else{
                    std::cout <<"Item not found in inventory"<<std::endl;
                }



            }else if (choice == 4){
                std::cout<<"calls function to use the item"<<std::endl;
                std::cout<<"enter the name of the item you want to use from your inventory: ";
                std::string itemName;
                std::cin>>itemName;

                //use the rest of the code from remove item to finish
                Item* itemToUse = nullptr;
                for (Item* item : playerInventory.getItems()){
                    if (item->GetName()==itemName){
                        itemToUse=item;
                        break;
                    }
                }
                if (itemToUse != nullptr){
                    playerInventory.useItem(itemToUse);
                }else{
                    std::cout <<"Item not found in inventory"<<std::endl;
                }
            }else{
                std::cout<<"invalid choice. try again"<<std::endl;

            }

        }else if (choice == 5){
            //Quit the game
            std::cout<<"Goodbye! " <<std::endl;
            break;
        } else{
            std::cout << "Invalid choice. Try again" << std::endl;
        }
    }
    return 0;
}