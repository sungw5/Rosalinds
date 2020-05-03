#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void merge(int *arr, int first, int mid, int last, int *buf){
    int i = first; // smallest of left side
    int j = mid +1; // smallest of right sie
    int k = 0; // index

    // fight until one side is destoryed completely
    while(i <= mid && j <= last){ //smallest of left -> mid && smallest of right -> last 
        if(arr[i] <= arr[j]){ // if left hand side element is smaller, store left one
            buf[k] = arr[i];
            k++; i++;
        }
        else{ // if right hand side element is smaller, store right one
            buf[k] = arr[j];
            k++; j++;
        }
    } 
    // if one of the left hand side is alive (bigger than any of right side so alive) store it to buf
    while(i <= mid){
        buf[k] = arr[i];
        k++; i++;
    }
    // if one of the right hand side is alive (bigger than any of left side so alive) store it to buf
    while(j <= last){
        buf[k] = arr[j];
        k++; j++;
    }
    k--; // if don't then index is out of array (currently pointing to last element)

    // move stuff in buf to array
    while(k >= 0){
        arr[first+k] = buf[k]; // put largest first
        k--; // move to next largest element 
    }

}

void divide(int *arr, int first, int last, int *buf) {

    // check if there's only one element (false to if condition)
    if(first < last){
        int mid = (first+last-1)/2; // subtract 1 in case of overflow

        // divide (continue until there's only one element left)
        divide(arr, first, mid, buf); // left side 
        divide(arr, mid+1, last, buf); // right side (to the end from one next to mid)

        // conquer!!!
        merge(arr, first, mid, last, buf);
    }
    else{
        return; // no more to divide
    }
}

int main(){
    FILE *inputP, *outputP;
    int *arr, *buf;
    int i,size;
    
    inputP = fopen("rosalind_mergesort.txt", "r");
    assert(inputP != NULL);
    // get size from input file
    fscanf(inputP, "%d\n", &size);

    // allocate memory for array and check
    arr = (int *)malloc(sizeof(int) * size);
    buf = (int *)malloc(sizeof(int) * size);
    assert(arr != NULL);
    assert(buf != NULL);
    for(i=0; i<size; i++){
        arr[i] = 0;
        buf[i] = 0;
    }

    // get input values
    for(i=0; i<size; i++){
        fscanf(inputP, "%d ", &arr[i]);
    }

    fclose(inputP);
//////////////////////////////////////////////////////
        
    //mergesort
    divide(arr, 0, size-1, buf);
    

//////////////////////////////////////////////////////
    outputP = fopen("mergesortOutput.txt", "w");
    //print output
    for(i=0; i<size; i++){
        fprintf(outputP, "%d ", arr[i]);
    }
    //close and free
    fclose(outputP);
    free(arr);
    free(buf);

    return 0;
}