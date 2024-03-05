#include <iostream>
using namespace std;

int factorial(int n) {
	int s = 1;
	for(int i=1; i<=n; i++) {
		s = s * i;
	}
	return s;
}

int c(int m, int n) {
    if (n > m || n < 0 || m < 0) {
        return 0;
    } else {
        return factorial(m)/(factorial(n)*factorial(m-n));
    }
}

int main() {
    int n = 0, num = 0;
    cout << "請輸入n" << endl;
    cin >> n;
    for (int i=0; i <= n/2; i++) {
        num += c(n-i,n-2*i);
    }
    cout << num;
}