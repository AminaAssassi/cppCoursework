#include "character.hpp"

Player::Player(const std::string& name, int health):Character(name,health){
    location=nullptr;
}

void Character::TakeDamage(int damage)
{
    std::cout<<"this is where the player takes damage"<<std::endl;
}

void Player::setLocation(Room *location)
{
    //std::cout <<"This is where the players location is set"<<std::endl;
    this->location=location;
}

Room* Player::GetLocation()
{
    //std::cout<<"this is where the players location is printed"<<std::endl;
    return location;
}
