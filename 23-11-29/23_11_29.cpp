#include <cstdlib>
#include <iostream>
using namespace std;

float pi(int);
void pi_process(int, int);

int main()
{
    int a, b;
    cin >> a;
    cout << pi(a) << "\n";
    cin >> a >> b;
    pi_process(a, b);
}

float pi(int a)
{
    float sum = 0;
    int k = 0;
    for (int i = 1; i <= a; i++)
    {
        if (i % 2 == 1)
        {
            sum = sum + 4.0 / (i + k);
        }
        else
        {
            sum = sum - 4.0 / (i + k);
        }
        k++;
    }
    return sum;
}

void pi_process(int a, int b)
{
    int k, i, j;
    cout << "Ranges:" << a << " " << b << "\n";
    for (a; a <= b; a++)
    {
        j = 3;
        i = 1;
        k = a;
        cout << a << ":pi= 4 ";
        while (k != 1)
        {
            if (i % 2 == 0)
            {
                cout << "+ 4/" << j << " ";
            }
            else
            {
                cout << "- 4/" << j << " ";
            }
            i++;
            k--;
            j = j + 2;
        }
        cout << " = " << pi(a) << "\n";
    }
}