#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


int main(){
    FILE *inputP, *outputP;
    int i,j,temp;
    int size;
    int *arr;
    int swapnum=0;
    int val;
    
    inputP = fopen("rosalind_insertion.txt", "r");
    assert(inputP !=NULL);
    
    // get input (array size), and allocate
    fscanf(inputP, "%d\n", &size);
    arr = (int *)malloc(sizeof(int) * size);
    assert(arr != NULL);
    // initialize the array to zero
    for(i=0; i<size; i++){
        arr[i] = 0;
    }
    // put values in the array
    for(i=0; i<size; i++){
        fscanf(inputP, "%d ", &val);
        arr[i] = val;
    }

    //insertion sort 
    for(i=1; i<size; i++){
        j = i; // save i (inserting element )

        //swap(insert) condition check
        while(j > 0 && arr[j] < arr[j-1]){  // inserting element < first item
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            swapnum++;
            j--; 
        }
        for(int k =0; k<size; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    
    //put #of swap number into the file
    outputP = fopen("insertionOutput.txt", "w");
    fprintf(outputP, "%d\n", swapnum);
    

    
    
    fclose(inputP);
    fclose(outputP);
    free(arr);
    return 0;
}