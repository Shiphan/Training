#include <iostream>
using namespace std;

void p(int b) {
	b = b + 1;
}

int main() {
	int a = 0;
	
	p(a);
	cout << a;
}
