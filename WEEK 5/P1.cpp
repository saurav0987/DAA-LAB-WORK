#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of alphabets: ";
    cin >> n;
    char arr[n];
    cout << "Enter " << n << " alphabets: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int freq[26] = {0};
    for(int i = 0; i < n; i++) {
        char c = arr[i];
        if(c >= 'a' && c <= 'z')
            freq[c - 'a']++;
        else if(c >= 'A' && c <= 'Z')
            freq[c - 'A']++;
    }
    int maxFreq = 0;
    char maxChar = ' ';
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }
    cout << "Alphabet with maximum occurrences: " << maxChar << endl;
    cout << "Frequency: " << maxFreq << endl;
    return 0;
}
