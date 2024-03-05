#pragma once
#include <iostream>
#include <string>


class Item {
private:
    std::string Name;
    std::string Description;

public:
    Item(const std::string& name, const std::string& desc){
        Name=name;
        Description=desc;
    };
    //void Interact();
    std::string GetName()const;
    std::string GetDescription()const;
};
