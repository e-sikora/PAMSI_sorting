#include <cmath>

#include "quick.h"

// Function to heapify a subtree rooted with node i which is an index in arr[]
template<typename T>
void Heapify(T* arr, int start, int end){
    int largest = end;  // Node with the largest value
    int left = 2 * end + 1;  // Left child
    int right = 2 * end + 2;  // Right child

    // Check if left child is larger than root
    if (left < start && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than root
    if (right < start && arr[right] > arr[largest])
        largest = right;

    // If root is not the largest, swap with the largest child
    if (largest != end) {
        std::swap(arr[end], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, start, largest);
    }
}

// Function to perform heap sort on array arr[]
template<typename T>
void HeapSort(T* arr, int size){
    int n = size;

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}

// Function to perform insertion sort on array arr[]
template<typename T>
void InsertionSort(T* arr, int size){
    int n = size;

    for (int i = 1; i < n; i++) {
        T key = arr[i];  // Current element to be inserted into the proper position
        int j = i - 1;  // Index of the previous element

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Move element to the right
            j--;  // Move to the previous element
        }

        arr[j + 1] = key;  // Insert the element into the proper position in the sorted sequence
    }
}

// Function to perform introSort on array arr[] with specified maximum depth of recursion
template <typename T>
void IntroSort(T* array, int start, int end, int maxdepth){
    // If maximum depth of recursion is reached, switch to heap sort
    if (maxdepth <= 0) {
        HeapSort(array, end - start);
        return;
    }
    
    // Partition the array around a pivot
    int i = Partition(array, start, end);
    
    // Recursively call IntroSort for the left part of the array if it's larger than 9 elements
    if (i > 9)
        IntroSort(array, start, i, maxdepth - 1);
    
    // Recursively call IntroSort for the right part of the array if it's larger than 9 elements
    if (end - i > 9)
        IntroSort(array, i + 1, end, maxdepth - 1);
}

// Function to perform hybrid IntroSort on array arr[]
template <typename T>
void HybridIntroSort(T* array, int start, int end){
    // Call hybrid IntroSort with maximum depth equal to twice the logarithm of the size of the array slice
    IntroSort(array, start, end, (2 * log(end - start)));

    // Perform insertion sort on small subarrays
    InsertionSort(array, end - start);
}