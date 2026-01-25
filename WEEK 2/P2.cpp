#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " sorted positive integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        int low = i + 1, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[i] + arr[mid] < arr[n - 1]) {
                int target = arr[n - 1] - arr[i] - arr[mid];
                int l = mid + 1, h = n - 1;
                while(l <= h) {
                    int m = (l + h) / 2;
                    if(arr[m] == target) {
                        cout << "Found: arr[" << i << "] + arr[" << mid << "] + arr[" << m << "] = "
                             << arr[i] << " + " << arr[mid] << " + " << arr[m] << " = " << arr[n-1] << endl;
                        found = true;
                        break;
                    } else if(arr[m] < target)
                        l = m + 1;
                    else
                        h = m - 1;
                }
            }
            low++;
            if(found) break;
        }
        if(found) break;
    }
    if(!found) {
        int target = arr[n - 1];
        bool foundAny = false;
        for(int i = 0; i < n && !foundAny; i++) {
            int low = i + 1, high = n - 1;
            while(low <= high && !foundAny) {
                int mid = (low + high) / 2;
                int k = low + (high - low) / 2;
                if(arr[i] + arr[k] == target) {
                    foundAny = true;
                } else if(arr[i] + arr[k] < target)
                    low = k + 1;
                else
                    high = k - 1;
            }
        }
        for(int i = 0; i < n && !found; i++) {
            for(int j = i + 1; j < n && !found; j++) {
                int rem = arr[n - 1] - arr[i] - arr[j];
                if(rem < 0) break;
                int low = j + 1, high = n - 1;
                while(low <= high) {
                    int mid = (low + high) / 2;
                    if(arr[mid] == rem) {
                        cout << "Found: arr[" << i << "] + arr[" << j << "] + arr[" << mid << "] = "
                             << arr[i] << " + " << arr[j] << " + " << arr[mid] << " = " << arr[n - 1] << endl;
                        found = true;
                        break;
                    } else if(arr[mid] < rem)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
    }
    if(!found)
        cout << "No such triplet found" << endl;
    return 0;
}
