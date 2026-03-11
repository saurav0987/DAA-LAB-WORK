#include<iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter size of first sorted array: ";
    cin >> m;
    int arr1[m];
    cout << "Enter " << m << " sorted integers: ";
    for(int i = 0; i < m; i++)
        cin >> arr1[i];
    cout << "Enter size of second sorted array: ";
    cin >> n;
    int arr2[n];
    cout << "Enter " << n << " sorted integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr2[i];
    cout << "Common elements: ";
    int i = 0, j = 0;
    bool found = false;
    while(i < m && j < n) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            found = true;
            i++;
            j++;
        } else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    if(!found)
        cout << "None";
    cout << endl;
    return 0;
}
