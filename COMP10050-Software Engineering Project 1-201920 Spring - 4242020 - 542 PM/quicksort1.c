#include <stdio.h>

swap(int array [], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


int partition(int array[], int first, int last) {
    swap(array, first, (first + last) / 2); // swap middle value into first pos
    int pivot = array[first]; 	 // remember pivot

    int index1 = first + 1; // index of first unknown value
    int index2 = last;    // index of last unknown value
    while (index1 <= index2) { // while some values still unknown
        if (array[index1] <= pivot)
            index1++;
        else if (array[index2] > pivot)
            index2--;
        else {
            swap(array, index1, index2);
            index1++;
            index2--;
        }
    }
    swap(array, first, index2); // put the pivot value between the two
    // sublists and return its index
    return index2;
}



void quicksort(int array[], int first, int last){

    //if the size of the array is equal to 0 or 1, the array is sorted by definition
    if(first < last){
        int pivotindex = partition(array, first, last);
        quicksort(array, first, pivotindex-1);
        quicksort(array, pivotindex+1, last);
    }

}



int main() {
    int i, count, number[25];

    printf("How many elements would you like to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);

    for (i =0; i < count; i++)
        scanf("%d", &number[i]);

    quicksort(number, 0, count-1);

    printf("Sorted Array:\n");
    for (i =0; i < count; i++)
        printf("%d ", number[i]);
}
