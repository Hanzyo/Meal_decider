#include "../lib/Resturants.cpp"
#include "../lib/Users.cpp"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

Users* initialize_user(){
    string name;
    cout << "Please enter your name:" << endl;
    cin >> name;
    Users* newuser = new Users(name);
    return newuser;
}

int main(){
    
    Users* newuser = initialize_user();
    cout << newuser->getName() << endl;
    
}