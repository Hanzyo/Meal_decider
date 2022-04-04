#pragma once
#include "Resturants.cpp"
#include <string.h>
#include <iostream>
#include <set>

class Users{
    private:
    std::string _username;
    std::set<Resturants> _favorites;
    public:
    Users(std::string name)
    : _username(name){}

    std::string getName(){
        return _username;
    }
};