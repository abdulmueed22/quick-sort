#include <iostream>
using namespace std;

// Function to perform quicksort on an array
void quicksort(int arr[], int low, int high) {
    // Base case: if the array has one element or is empty, it is already sorted
    if (low < high) {
        // Choose the pivot (for simplicity, we choose the element at the high index)
        int pivot = arr[high];

        // Partition the array and get the index of the pivot
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap arr[i+1] and arr[high] to place the pivot in its correct position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Recursively apply quicksort on the left and right partitions
        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

int main() {
    const int size = 11;
    int q[size] = {0, 2, 7, 1, 3, 9, 5, 8, 7, 6, 4};

    // Call the quicksort function to sort the array
    quicksort(q, 0, size - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int k = 0; k < size; ++k) {
        cout << q[k] << " ";
    }

    return 0;
}

