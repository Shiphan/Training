#include <iostream>

int main(){
    int a;
    int b;
    int c;
    char str[20];
    char dtr[20];


    std::cin >> a >> b;
    std::cin.getline(str, 20);
    // std::cin >> a >> b;
    strcpy(dtr, str);
    std::cout << str << std::endl << dtr;

    system("pause");
}
