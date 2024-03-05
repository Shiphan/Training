#include <iostream>
using namespace std;

int main() {
    int money;
    cout << "Please type in how much money you have:" << endl;
    cin >> money;

    /*
    int a[] = { 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 1 };
    int n = 0;
    cout << endl << "The way to exchange money with minimum number of coins or bills is..." << endl;
    for (int i = 0; i < 10; i++) {
        n = money / a[i];
        money = money - n * a[i];
        cout << a[i] << " doller(s) x " << n <<endl;
    }
    */

    int n,value = 0;
    cout << endl << "The way to exchange money with minimum number of coins or bills is..." << endl;
    
    value = 2000;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 1000;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 500;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 200;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 100;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 50;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 20;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 10;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 5;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
    value = 1;
    n = money / value;
    money = money - n * value;
    cout << value << " doller(s) x" << n << endl;
}
