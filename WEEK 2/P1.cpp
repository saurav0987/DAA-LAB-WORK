#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " sorted positive integers (may have duplicates): ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    int low = 0, high = n - 1, comparisons = 0;
    int first = -1, last = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if(arr[mid] == key) {
            first = mid;
            high = mid - 1;
        } else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    low = 0; high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if(arr[mid] == key) {
            last = mid;
            low = mid + 1;
        } else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(first == -1)
        cout << "Element not found" << endl;
    else {
        cout << "Element found at index " << first << endl;
        cout << "Frequency (count of copies): " << last - first + 1 << endl;
    }
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
