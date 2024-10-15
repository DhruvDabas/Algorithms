#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {3, 5, 2, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int result = linear_search(arr, n, key);

    if(result != -1){
        cout << "Element " << key << " found at: " << result << endl;
    } 
    else{
        cout << "Element " << key << " not found." << endl;
    }
}