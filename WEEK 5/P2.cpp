#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Enter key (sum to find): ";
    cin >> key;
    bool found = false;
    for(int i = 0; i < n - 1 && !found; i++) {
        for(int j = i + 1; j < n && !found; j++) {
            if(arr[i] + arr[j] == key) {
                cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << key << endl;
                found = true;
            }
        }
    }
    if(!found)
        cout << "No pair found with sum " << key << endl;
    return 0;
}
