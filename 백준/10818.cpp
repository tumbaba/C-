#include <iostream>
using namespace std;

int main() 
{
    int b;
    cin >> b;

    if (b > 1000000) {
        cout << "Input size too large";
        return 1;
    }

    int* a = new int[b]; 

    for (int i = 0; i < b; i++) {
        cin >> a[i];
    }

    int min = a[0];  
    int max = a[0];  

    for (int i = 1; i < b; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }

    cout << min << " " << max;

    return 0;
}