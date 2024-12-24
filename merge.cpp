#include <iostream>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(int array[], int left_index, int mid_index, int right_index) {
    // Sizes of the left and right subarrays
    int leftarray_size = mid_index - left_index + 1;
    int rightarray_size = right_index - mid_index;

    // Temporary arrays to hold the elements of left and right subarrays
    int leftarray[leftarray_size];
    int rightarray[rightarray_size];

    // Copying data into left and right subarrays
    for (int i = 0; i < leftarray_size; i++) {
        leftarray[i] = array[left_index + i];
    }
    for (int j = 0; j < rightarray_size; j++) {
        rightarray[j] = array[mid_index + 1 + j];
    }

    // Merging the two subarrays back into the main array
    int i = 0;       // Index for left subarray
    int j = 0;       // Index for right subarray
    int index = left_index; // Starting index for the main array

    // Compare elements from both subarrays and merge them in sorted order
    while (i < leftarray_size && j < rightarray_size) {
        if (leftarray[i] <= rightarray[j]) {
            array[index] = leftarray[i];
            i++;
        } else {
            array[index] = rightarray[j];
            j++;
        }
        index++;
    }

    // Copy any remaining elements from the left subarray (if any)
    while (i < leftarray_size) {
        array[index] = leftarray[i];
        i++;
        index++;
    }

    // Copy any remaining elements from the right subarray (if any)
    while (j < rightarray_size) {
        array[index] = rightarray[j];
        j++;
        index++;
    }
}

// Function to implement merge sort
void MergeSOrt(int array[], int left_index, int right_index) {
    // Base case: If the subarray has one or no element, return
    if (left_index >= right_index) return;

    // Find the midpoint of the current subarray
    int mid_index = left_index + (right_index - left_index) / 2;

    // Recursively sort the left and right subarrays
    MergeSOrt(array, left_index, mid_index);
    MergeSOrt(array, mid_index + 1, right_index);

    // Merge the two sorted subarrays
    merge(array, left_index, mid_index, right_index);
}

int main() {
    // Define and initialize the array to be sorted
    int myArray[] = {10, 20, 8, 17, 5, 13, 4};

    // Calculate the size of the array
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;           // Starting index of the array
    int rightIndex = size - 1;   // Ending index of the array

    // Call the merge sort function
    MergeSOrt(myArray, leftIndex, rightIndex);

    // Print the sorted array
    for (auto value : myArray) {
        cout << value << " ";
    }

    return 0;
}
