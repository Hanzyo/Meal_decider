#pragma once
#include "Resturants.cpp"
#include <string.h>
#include <iostream>
#include <set>

class Users{
    private:
    std::string _username;
    public:
    std::set<Resturants*> favorites;
    Users(std::string name)
    : _username(name){}

    std::string getName(){
        return _username;
    }
};