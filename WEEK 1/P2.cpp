#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comparisons) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " sorted positive integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    int comparisons = 0;
    int result = binarySearch(arr, n, key, comparisons);
    if(result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
