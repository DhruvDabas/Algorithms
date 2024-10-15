#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int s, int e, int key) {
    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] == key) {
            return m;
        }
        if (key > arr[m]) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;
    int result = binary_search(arr, 0, arr.size() - 1, key);

    if(result != -1) {
        cout<< "Element " << key << " found at: " << result << endl;
    } 
    else{
        cout<< "Element " << key << " not found." << endl;
    }
}
