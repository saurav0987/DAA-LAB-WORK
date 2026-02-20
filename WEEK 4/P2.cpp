#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int randomPartition(int arr[], int low, int high, int &comparisons, int &swaps) {
    srand(time(0));
    int randIdx = low + rand() % (high - low + 1);
    int temp = arr[randIdx];
    arr[randIdx] = arr[high];
    arr[high] = temp;
    swaps++;
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        comparisons++;
        if(arr[j] <= pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            swaps++;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    swaps++;
    return i + 1;
}

void randomQuickSort(int arr[], int low, int high, int &comparisons, int &swaps) {
    if(low < high) {
        int pi = randomPartition(arr, low, high, comparisons, swaps);
        randomQuickSort(arr, low, pi - 1, comparisons, swaps);
        randomQuickSort(arr, pi + 1, high, comparisons, swaps);
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
    randomQuickSort(arr, 0, n - 1, comparisons, swaps);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;
    return 0;
}
