#include "character.hpp"

Player::Player(const std::string& name, int health):Character(name,health){
    location=nullptr; //sets the players initial location to nullptr
}

void Character::TakeDamage(int damage)
{
    std::cout<<"this is where the player takes damage"<<std::endl;
}

void Player::setLocation(Room *location)
{
    this->location=location; //updates the players location to the room specified by the location argument
}

Room* Player::GetLocation()
{
    return location; //returns a pointer to the room where the player is currently located
}