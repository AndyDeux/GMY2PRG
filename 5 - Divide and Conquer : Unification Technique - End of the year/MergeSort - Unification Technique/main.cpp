#include <iostream>
#include <vector>

// Function to merge two sorted halves of an array
void merge(std::vector<int>& array, int left, int mid, int right) {
    // Determine the sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors for the left and right halves
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Fill the temporary vectors
    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[mid + 1 + j];

    // Indices for current positions in the temporary vectors
    int i = 0;
    int j = 0;
    int k = left;

    // Merge the temporary vectors back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            ++i;
        } else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy any remaining elements from the left vector, if any
    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    // Copy any remaining elements from the right vector, if any
    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }
}

// Recursive function to sort an array using MergeSort
void mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        // Find the middle index
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}

// Function to print an array
void printArray(const std::vector<int>& array) {
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example array to be sorted
    std::vector<int> array = {12, 11, 13, 5, 6, 7};

    std::cout << "Array before sorting: ";
    printArray(array);

    // Call the mergeSort function to sort the array
    mergeSort(array, 0, array.size() - 1);

    std::cout << "Array after sorting: ";
    printArray(array);

    return 0;
}
