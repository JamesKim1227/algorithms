#include <iostream>

class Qsort {
public:
  static void qsort(int *arr, int left, int right);
};

static void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static int partition(int *arr, int left, int right) {
  int pivot = arr[left];
  int l = left;

  left++;

  while (left <= right) {
    while (arr[left] < pivot && left < right)
      left++;

    while (arr[right] > pivot && left <= right)
      right--;

    if (left < right) {
      swap(&arr[left], &arr[right]);
      left++;right--;
    } else {
      break;
    }
  }

  swap(&arr[l], &arr[right]);

  return right;
}

void Qsort::qsort(int *arr, int left, int right) {

  if (left < right) {
    int index = partition(arr, left, right);

    qsort(arr, left, index-1);
    qsort(arr, index+1, right);
  }
};

int main() {
  int arr[] = { 6, 4, 6, 2, 5, 3, 1 };
  int size = sizeof(arr)/sizeof(arr[0]);

  Qsort::qsort(arr, 0, size-1);

  for (int i=0; i<size; i++)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;

  return 0;
}
