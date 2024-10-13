#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomPivot(int s, int e) {
    return s + rand() % (e - s + 1);
}

int partition(int arr[], int s, int e) {
    int pivotidx = getRandomPivot(s, e);
    swap(arr[s], arr[pivotidx]);

    int pivot = arr[s];
    int i = s + 1;
    
    for (int j = s + 1; j <= e; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[s], arr[i - 1]);
    return i - 1;
}

void RandomisedQuickSort(int arr[], int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e);
        RandomisedQuickSort(arr, s, p - 1);
        RandomisedQuickSort(arr, p + 1, e);
    }
}

int main() {
    srand(time(0));

    const int SIZE = 10;
    int arr[SIZE] = {5, 3, 8, 6, 2, 7, 4, 1, 10, 9};

    RandomisedQuickSort(arr, 0, SIZE - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

}