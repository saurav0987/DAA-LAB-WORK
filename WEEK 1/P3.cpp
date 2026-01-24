#include<iostream>
#include<cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key, int &comparisons) {
    int step = sqrt(n);
    int prev = 0;
    while(arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if(prev >= n)
            return -1;
    }
    while(arr[prev] < key) {
        comparisons++;
        prev++;
        if(prev == min(step, n))
            return -1;
    }
    comparisons++;
    if(arr[prev] == key)
        return prev;
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
    int result = jumpSearch(arr, n, key, comparisons);
    if(result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
