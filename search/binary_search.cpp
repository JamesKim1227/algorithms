#include <iostream>

int binary_search(int *arr, int size, int target) {

  int left =0;
  int right = size-1; 
  int mid = size/2;

  while (left <= right) {
    mid = left + (right-left)/2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid -1;
    }
  }

  return -1;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5, 6};

  int size = sizeof(arr)/sizeof(arr[0]);

  std::cout << binary_search(arr, size, 1) << std::endl;
  std::cout << binary_search(arr, size, 2) << std::endl;
  std::cout << binary_search(arr, size, 3) << std::endl;
  std::cout << binary_search(arr, size, 4) << std::endl;
  std::cout << binary_search(arr, size, 5) << std::endl;
  std::cout << binary_search(arr, size, 6) << std::endl;

  return 0;
}
