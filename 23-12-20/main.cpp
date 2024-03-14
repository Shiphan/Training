#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int randomNum(int *log) {
    int num = rand()%52;
    for (int i = 0; i < 52; i++) {
        if (num == log[i]) {
        	num = randomNum(log);
        }
    }
    return num;
}

int main() {
    int log[52] = {};
    for (int i = 0; i < 52; i++) {
        log[i] = -1;
    }
    
	bool cardLog[52] = {};
	
    srand(time(NULL));
    int n = 52;
    int cardIndex = 0;
    for (int i = 0; i < n; i++) {
        cardIndex = randomNum(log);
        log[i] = cardIndex;
        
        
        if (cardLog[cardIndex] == true) {
        	cout << "重複了!!!"; 
		}
        cardLog[cardIndex] = true;
        
        
        cout << cardIndex << endl;
    }
  
}
