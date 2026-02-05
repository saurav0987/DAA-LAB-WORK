#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " positive integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    bool hasDuplicate = false;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] == arr[i + 1]) {
            hasDuplicate = true;
            break;
        }
    }
    if(hasDuplicate)
        cout << "Array contains duplicate elements" << endl;
    else
        cout << "Array does not contain duplicate elements" << endl;
    return 0;
}
