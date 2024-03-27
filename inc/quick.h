#pragma once
template <typename T>
int Partition(T* array, int start, int end) {
    T temp, pivot = array[(start + end) / 2];  // Middle element
    int l = start, r = end;                    // Iterators for left and right subarrays

    while (1) {
        while (array[l] < pivot) l++;  // While elements to the left are smaller than pivot
        while (array[r] > pivot) r--;  // While elements to the right are greater than pivot

        if (l >= r)
            return r;  // Pivot element

        // Swap elements - smaller to the left, greater to the right
        temp = array[l];
        array[l++] = array[r];
        array[r--] = temp;
    }
}

template <typename T>
void Quicksort(T* array, int start, int end) {
    // Recursively divide into 2 subarrays until single elements are obtained
    if (start >= 0 && start < end) {
        int pivot = Partition(array, start, end);  // Pivot element
        Quicksort(array, start, pivot);            // Left subarray
        Quicksort(array, pivot + 1, end);          // Right subarray
    }
}