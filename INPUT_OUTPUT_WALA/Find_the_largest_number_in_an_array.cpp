//Find the smallest number in an array
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;
    
    int small = x;

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x < small) {
            small = x;
        }
    }

    cout << small;

    return 0;
}
