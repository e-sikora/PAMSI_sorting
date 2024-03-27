#pragma once

template<typename T>
void Merge(T* vec, int left, int middle, int right){
    int i = left;         // Index of the beginning of the first subarray
    int j = middle + 1;   // Index of the beginning of the second subarray
    int k = 0;            // Index of the auxiliary temporary array

    T* tmp = new T[right - left + 1];  // Creating a temporary auxiliary array

    // Merging two sorted subarrays into the temporary array
    while (i <= middle && j <= right) {
        if (vec[j] < vec[i]) {
            tmp[k++] = vec[j++];  // Assigning an element from the second subarray to the temporary array
        } else{
            tmp[k++] = vec[i++];  // Assigning an element from the first subarray to the temporary array
        }
    }

    // Adding remaining elements from the first subarray, if any
    if (i <= middle) {
        while (i <= middle){
            tmp[k++] = vec[i++];
        }
    } else {  // Adding remaining elements from the second subarray, if any
        while (j <= right) {
            tmp[k++] = vec[j++];
        }
    }

    // Copying the sorted temporary array back to the original array
    for (int t = 0; t <= right - left; t++) {
        vec[left + t] = tmp[t];
    }

    delete[] tmp;  // Freeing memory occupied by the temporary array
}

template<typename T>
void Mergesort(T* vec, int left, int right){
    if (left >= 0 && left < right) {
        int middle = (left + right) / 2;  // Calculating the middle of the array

        // Recursively calling Mergesort for the left and right halves of the array
        Mergesort(vec, left, middle);
        Mergesort(vec, middle + 1, right);

        // Merging sorted subarrays
        Merge(vec, left, middle, right);
    }
}