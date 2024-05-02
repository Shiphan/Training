#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Car{
    string name;
    int displacement;
    Car(){};
};
struct Personinfo{
    string name;
    Car* owncar;
    Personinfo(){
        this->owncar = new Car();
    };
};
int main(){
    // vector<Personinfo*> vec;
    Personinfo* vec[3];

    for (int i = 0; i < 2; i++){
        Personinfo* person = new Personinfo();
        cin.ignore('\n');
        std::getline(std::cin, person->name);
        cin.ignore('\n');
        std::getline(std::cin, person->owncar->name);
        cin >> person->owncar->displacement;
        //vec.push_back(person);
        vec[i] = person;

        cout << "1\n";
    }
    cout << endl;
    for (int i = 0; i < 2; i++){
        cout << vec[i]->name << endl << vec[i]->owncar->name << endl << vec[i]->owncar->displacement;
        cout << endl << endl;

        cout << "2\n";
    }
}
