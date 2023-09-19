#include <iostream>

void removeBlock(int* arr, int& size, int startIndex, int blockSize) {
    if (startIndex < 0 || startIndex >= size || blockSize <= 0) {
        std::cout << "Invalid start index or block size." << std::endl;
        return;
    }

    if (startIndex + blockSize > size)
        blockSize = size - startIndex;  // Adjust block size if exceeding array size

    for (int i = startIndex; i < size - blockSize; ++i)
        arr[i] = arr[i + blockSize];

    size -= blockSize;
}

int main() {
    const int arrSize = 10;
    int arr[arrSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int newSize = arrSize;

    std::cout << "Original array: ";
    for (int i = 0; i < newSize; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    int startIndex = 3;  // Starting index of the block to remove
    int blockSize = 4;   // Number of elements to remove

    removeBlock(arr, newSize, startIndex, blockSize);

    std::cout << "Array after removing a block: ";
    for (int i = 0; i < newSize; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
