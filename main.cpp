#include <iostream>
#include <vector>
//#include <map>
//#include "room.hpp"
//#include "Item.hpp"
#include "character.hpp"


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

    //Add items to rooms
    startRoom.AddItem(key);
    treasureRoom.AddItem(sword);

    //create a player
    //int player;
    Player player("Alice", 100);
    player.setLocation(&startRoom);


    //Game loop (basic interaction)
    while(true){
        std::cout<<"current Location: "<< player.GetLocation()->GetDescription() << std::endl;
        std::cout<<"Items in the room: "<<std::endl;
        /*for (const Item& item : player.GetLocation() -> GetItems()) {
            std::cout<<"-"<<item.GetName() << ": " <<item.GetDescription() << std::endl;
        }*/

        for (int i= i=0; i<player.GetLocation() ->GetItems().size();i++){
           std::cout<<"-"<<player.GetLocation()->GetItems()[i].GetName() << ":" << player.GetLocation()->GetItems()[i].GetDescription() <<std::endl;

        }
        std::cout << "options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Quit" << std::endl;

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
                    //item.Interact();
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
        } else if (choice == 4){
            //Quit the game
            std::cout<<"Goodbye! " <<std::endl;
            break;
        } else{
            std::cout << "Invalid choice. Try again" << std::endl;
        }
    }
    return 0;
}