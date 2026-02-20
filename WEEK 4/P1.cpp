#include<iostream>
using namespace std;

int partition(int arr[], int low, int high, int &comparisons, int &swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        comparisons++;
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swaps++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    swaps++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int &comparisons, int &swaps) {
    if(low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int comparisons = 0, swaps = 0;
    quickSort(arr, 0, n - 1, comparisons, swaps);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;
    return 0;
}
