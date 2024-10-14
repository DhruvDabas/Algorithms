#include <iostream>
using namespace std;

void merge(int arr[], int s, int m, int e) {
    int len1 = m - s + 1;
    int len2 = e - m;

    int* first = new int[len1];
    int* second = new int[len2];

    for (int i = 0; i < len1; i++) {
        first[i] = arr[s + i];
    }

    for (int j = 0; j < len2; j++) {
        second[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = s;

    while (i < len1 && j < len2) {
        if (first[i] <= second[j]) {
            arr[k] = first[i];
            i++;
        } else {
            arr[k] = second[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = first[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = second[j];
        j++;
        k++;
    }

    delete[] first; // Free allocated memory
    delete[] second; // Free allocated memory
}

void merge_sort(int arr[], int s, int e) {
    if (s < e) {
        int m = s + (e - s) / 2;

        merge_sort(arr, s, m);
        merge_sort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}