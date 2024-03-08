// COP3502 Nicole Walsh
// Date: 3/8/2024

#include <stdio.h>

// Function Prototypes
void swap (int *xp, int *yp);
void bubbleSort(int arr[], int n, int arrSwaps[]);
void selectionSort(int arr[], int n, int arrSwaps[]);
void printArray(int arr[], int size);

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}


// A function to implement bubble sort (counting swaps)
void bubbleSort(int arr[], int n, int arrSwaps[]) {
  int swaps = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);

        // increment swaps
        arrSwaps[arr[j]]++;
        arrSwaps[arr[j + 1]]++;
        swaps++;
      }
    }
  }
  // Print swap counts for each value
  for (int i = 0; i < n; i++) {
    printf("%d: %d times swapped\n", arr[i], arrSwaps[arr[i]]); }
  printf("Total number of swaps: %d\n\n", swaps);
}


void selectionSort(int arr[], int n, int arrSwaps[]) {
  int swaps = 0;

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      // Swap elements
      swap(&arr[i], &arr[minIndex]);

      // increment swaps
      arrSwaps[arr[i]]++;
      arrSwaps[arr[minIndex]]++;
      swaps++;
    }
  }

  // Print swap counts for each value
  for (int i = 0; i < n; i++) {
    printf("%d: %d times swapped\n", arr[i], arrSwaps[arr[i]]); }
  printf("Total number of swaps: %d\n\n", swaps);
}

  
// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
    printf("\n");
  }
}


// Test above functions
int main() {
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  int n1 = sizeof(array1) / sizeof(array1[0]); //size of the array 1
  int n2 = sizeof(array2) / sizeof(array2[0]); //size of the array 2

  // Arrays to store swap count for array1 and array 2 with Bubble Sort
  int swapCount1_bubble[100] = {0};
  int swapCount2_bubble[100] = {0};

  // Array to store swap count for array1 and array2 with Selection Sort
  int swapCount1_selection[100] = {0}; 
  int swapCount2_selection[100] = {0};
  
  printf("Bubble Sort:\n");
  printf("array1:\n");
  bubbleSort(array1, n1, swapCount1_bubble);
  printf("array2:\n");
  bubbleSort(array2, n2, swapCount2_bubble);

  // reset values
  int array1_ss[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2_ss[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  printf("\nSelection Sort:\n");
  printf("array1:\n");
  selectionSort(array1_ss, n1, swapCount1_selection);
  printf("array2:\n");
  selectionSort(array2_ss, n2, swapCount2_selection);

  // Total number of swaps is not equal to the sum of the swaps for each value because if you swap index 1 and 2, each element has been moved and thus swapped but the overall swap operation happened once.
}


