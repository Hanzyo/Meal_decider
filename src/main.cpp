#include "../lib/Resturants.cpp"
#include "../lib/Users.cpp"
#include <string.h>
#include <iostream>
using namespace std;

Users* initialize_user(){
    string name;
    cout << "Please enter your name:" << endl;
    cin >> name;
    Users* newuser = new Users(name);
    return newuser;
}

int main(){
    Resturants a("SG", 0);
    Resturants b("Chipolet", 3);
    string name1 = a.getName();
    string name2 = b.getName();
    uint8_t weight1 = a.getWeight();
    uint8_t weight2 = b.getWeight();
    cout << name1 << "'s weight is "<< (int)weight2 <<endl;

    Users* newuser = initialize_user();
    cout << newuser->getName() << endl;
    
}