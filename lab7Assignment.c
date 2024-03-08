#include <stdio.h>

typedef struct {
    int value;
    int swaps;
} Element;

void bubbleSort1(Element arr[], int n)
{ 
   int i, j;
   for (i = 0; i < n-1; i++)
   {
       for (j = 0; j < n-i-1; j++)
       {
           if (arr[j].value > arr[j+1].value)
           {
              Element temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
              arr[j].swaps++;
              arr[j+1].swaps++;
           }
       }
   }
   
   for (i = 0; i < n; i++){
      printf("%d : Number of times %d is swapped\n", arr[i].swaps, arr[i].value);
   }
   
}

// Selection sort function to sort arr in increasing order using selection sort algorithm and print the number of swaps for each element
void selectionSort1(Element arr[], int n)
{
   int i, j, minIndex;
   for (i = 0; i < n-1; i++)
   {
       minIndex = i;
       for (j = i+1; j < n; j++)
       {
           if (arr[j].value < arr[minIndex].value)
           {
              minIndex = j;
           }
       }
       if (minIndex != i) {
           Element temp = arr[minIndex];
           arr[minIndex] = arr[i];
           arr[i] = temp;
           arr[minIndex].swaps++; // Update swaps count for the minimum element
           arr[i].swaps++; // Update swaps count for the current element
       }
   }
   
  
   for (i = 0; i < n; i++){
      printf("%d : Number of times %d is swapped\n", arr[i].swaps, arr[i].value);
   }
}

int main()
{   
    // Array 1
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Element arr1_copy_bubble[n1], arr1_copy_selection[n1];

    // Copying arr1 to arr1_copy_bubble and arr1_copy_selection
    for (int i = 0; i < n1; i++) {
        arr1_copy_bubble[i].value = arr1[i];
        arr1_copy_bubble[i].swaps = 0;
        arr1_copy_selection[i].value = arr1[i];
        arr1_copy_selection[i].swaps = 0;
    }

    printf("Sorting array1 using bubble sort:\n");
    bubbleSort1(arr1_copy_bubble, n1); // Bubble sort for array1

    printf("\nSorting array1 using selection sort:\n");
    selectionSort1(arr1_copy_selection, n1); // Selection sort for array1

    // Array 2
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Element arr2_copy_bubble[n2], arr2_copy_selection[n2];

    // Copying arr2 to arr2_copy_bubble and arr2_copy_selection
    for (int i = 0; i < n2; i++) {
        arr2_copy_bubble[i].value = arr2[i];
        arr2_copy_bubble[i].swaps = 0;
        arr2_copy_selection[i].value = arr2[i];
        arr2_copy_selection[i].swaps = 0;
    }

    printf("\nSorting array2 using bubble sort:\n");
    bubbleSort1(arr2_copy_bubble, n2); // Bubble sort for array2

    printf("\nSorting array2 using selection sort:\n");
    selectionSort1(arr2_copy_selection, n2); // Selection sort for array2

    return 0;
}

