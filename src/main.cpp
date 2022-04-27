#include "../lib/Resturants.cpp"
#include "../lib/Users.cpp"
#include <string.h>
#include <iostream>
#include <vector.h>
#include <fstream>
using namespace std;

Users* rebuild_user(string info){
    vector<string> v;
    stringstream ss(info);
    while (ss.good()) {
        string substr;
        getline(ss, substr, '-');
        v.push_back(substr);
    }
    Users* newuser = new Users(v[0]);
    auto it = v.begin();
    ++it;
    while(it != v.end()){
        string Rname = *it; ++it;
        int weight = (int)*it; ++it;
        Resturants* res = new Resturants(Rname, weight);
        newuser->favorites.insert(res);
    }
    return newuser;
}

Users* initialize_user(){
    string name;
    cout << "Please enter your name:" << endl;
    char input[50];
    cin.getline(input, sizeof(input));
    name = input;
    string filename("local/data.txt");
    vector<string> lines;
    string line;
    bool found_name = 0;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }
    int idx;
    for(idx = 0; idx < lines.size(); ++idx){
        char cmpname[50];
        for(int j = 0; j < strlen(lines[idx]); ++j){
            if(c != "-"){
                cmpname[j] = lines[idx][j];
            }
        }
        if(strcmp(name, cmpname) == 0){
            found_name = 1;
            break;
        }
    }
    input_file.close();
    Users* newuser;
    if(found_name){
        newuser = rebuild_user(lines[idx]);
        cout << "Welcome back, " << newuser->getName() << " !" << endl;
    }
    else 
        newuser = new Users(name);
    
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

// return 1 if file exists, 0 otherwise
bool is_file_exist(const char *fileName){
    std::ifstream infile(fileName);
    return infile.good();
}

void save_user_info(Users* user){
    ofstream data;
    data.open("local/data.txt", ios::app);
    data << user->getName() << "-";
    for(auto i : user->favorites){
        data << i->getName() << "-" << i->getWeight() << "-";
    }
    data << endl;
    data.close(); 
}

int main(){

    Users* user = initialize_user();
    save_user_info(user);
    cout << user->getName() << "'s favorite resturants are: " ;
    for(auto i : user->favorites){
        cout << i->getName() << " ";
    }
    cout << endl;
    return 0;

}