#include "../lib/Resturants.cpp"
#include "../lib/Users.cpp"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

Users* initialize_user(){
    string name;
    cout << "Please enter your name:" << endl;
    char input[100];
    cin.getline(input, sizeof(input));
    name = input;
    Users* newuser = new Users(name);
    do{
        cout << "Enter your favorite resturants: (no space bwteen letters, enter finish to end input)" << endl;
        string rest;
        cin >> rest;
        if(rest == "finish"){
            break;
        }
        uint8_t weight;
        cout << "On a scale from 1 to 5, how much do you like " << rest << "?" << endl;
        cin >> weight;
        Resturants * newres = new Resturants(rest, weight);
        newuser->favorites.insert(newres);
    }while(1);
    return newuser;
}

void login_for_user(){
    Users* loginUser = initialize_user();
    ofstream data;
    data.open("local/data.txt");
    data << "Hello, " << loginUser->getName() << endl;
    data.close(); 
}

int main(){
    Users* user = initialize_user();
    cout << user->getName() << "'s favorite resturants are: " ;
    for(auto i : user->favorites){
        cout << i->getName() << " ";
    }
    cout << endl;
    
}