#include "../Resturants.h"
#include <string.h>
#include <iostream>

int main(){
    Resturant a("SG", 0);
    Resturant b("Chipolet", 3);
    std::string name1 = a.getName();
    std::string name2 = b.getName();
    uint8_t weight1 = a.getWeight();
    std::cout << name1 << "'s weight is "<< weight1<<std::endl;
}