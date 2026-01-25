#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " non-negative integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "Enter key difference K: ";
    cin >> k;
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int diff = arr[i] - arr[j];
            if(diff < 0) diff = -diff;
            if(diff == k) {
                count++;
                cout << "Pair: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }
    cout << "Total pairs with difference " << k << ": " << count << endl;
    return 0;
}
