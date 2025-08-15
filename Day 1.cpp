#include <iostream>
#include <vector>
#include <algorithm>
/**
 *Sorts an array of 0s, 1s, and 2s in-place using the Dutch National Flag Algorithm.
 *
 * This algorithm partitions the array into three sections: 0s, 1s, and 2s,
 * by maintaining three pointers: low, mid, and high.
 *
 * @param arr A reference to a std::vector of integers to be sorted.
 */
void sort012(std::vector<int>& arr) {
    // Initialize three pointers.
    // 'low' tracks the boundary between 0s and 1s.
    // 'mid' is the current element under consideration.
    // 'high' tracks the boundary between 1s and 2s.
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    // Iterate through the array with the 'mid' pointer.
    // The loop continues as long as 'mid' is within the high boundary.
    while (mid <= high) {
        switch (arr[mid]) {
            // Case 0: The element belongs in the 'low' section.
            case 0:
                // Swap the element at 'mid' with the element at 'low'.
                std::swap(arr[low], arr[mid]);
                // Move both 'low' and 'mid' pointers forward.
                low++;
                mid++;
                break;
            
            // Case 1: The element is already in the correct "middle" partition.
            case 1:
                // Simply move the 'mid' pointer forward to process the next element.
                mid++;
                break;
            
            // Case 2: The element belongs in the 'high' section.
            case 2:
                // Swap the element at 'mid' with the element at 'high'.
                std::swap(arr[mid], arr[high]);
                // Only decrement the 'high' pointer. The new element at 'mid'
                // needs to be re-evaluated, so 'mid' is not incremented.
                high--;
                break;
        }
    }
}

// Function to print the elements of the vector.
void printVector(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    std::cout << "]";
}

int main() {
    // Test Cases
    std::vector<std::vector<int>> test_cases = {
        {0, 1, 2, 1, 0, 2, 1, 0},
        {2, 2, 2, 2},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {2, 0, 1},
        {},
        {0, 1, 2},
        {2, 1, 0}
    };
    
    std::cout << "Running Test Cases for Dutch National Flag Algorithm:\n";
    std::cout << "---------------------------------------------------\n";

    for (auto& arr : test_cases) {
        std::cout << "Input:  ";
        printVector(arr);
        
        sort012(arr);
        
        std::cout << "\nOutput: ";
        printVector(arr);
        std::cout << "\n---------------------------------------------------\n";
    }

    return 0;
}
