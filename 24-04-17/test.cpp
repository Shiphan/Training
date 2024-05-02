#include <iostream>

void stuavg(double x[][2], int n){

    double avg = 0;
    for (int i = 0; i < n; i++){
        avg = (x[i][0] + x[i][1])/2;
        std::cout << "student #" << i << ": " << avg << std::endl;
    }

}

int main(){
    int num;
    std::cin >> num;
    double x[num][2];
    for (int i = 0; i < num; i++){
         std::cin >> x[i][0] >> x[i][1];
    }
    stuavg(x, num);
}
