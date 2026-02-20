#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    if(low <= high) {
        int pi = partition(arr, low, high);
        if(pi == k - 1)
            return arr[pi];
        else if(pi > k - 1)
            return kthSmallest(arr, low, pi - 1, k);
        else
            return kthSmallest(arr, pi + 1, high, k);
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "Enter K: ";
    cin >> k;
    int choice;
    cout << "Find (1) Kth Smallest or (2) Kth Largest? ";
    cin >> choice;
    int arrCopy[n];
    for(int i = 0; i < n; i++)
        arrCopy[i] = arr[i];
    if(choice == 1) {
        int result = kthSmallest(arrCopy, 0, n - 1, k);
        cout << k << "th Smallest element: " << result << endl;
    } else {
        int result = kthSmallest(arrCopy, 0, n - 1, n - k + 1);
        cout << k << "th Largest element: " << result << endl;
    }
    return 0;
}
