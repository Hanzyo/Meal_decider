#pragma once
#include <string>
#include <iostream>

class Resturants{
    private:
    std::string _name;
    uint8_t _weight;
    uint8_t _suggested;
    public:
    Resturants(std::string name, uint8_t weight)
    :_name(name), _weight(weight), _suggested(0){}

    void suggested(){
        _suggested ++;
    }

    std::string getName(){
        return _name;
    }

    uint8_t getWeight(){
        return _weight;
    }
};

