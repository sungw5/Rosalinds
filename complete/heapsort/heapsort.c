#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SWAP(x, y) {int temp; temp=x; x=y; y=temp;}
//#define parent(v) ((v-1)/2)

void heapify(int *arr, int size, int root){
    int last = root; //save root to last
    int left = root*2+1; // last parent node's left child
    int right = root*2+2; // last parent node's right child

    // check left and right child
    if(left<size && arr[left] > arr[last]){
        last = left;
    }
    if(right<size && arr[right] > arr[last]){
        last = right;
    }
    if(last != root){
        SWAP(arr[last], arr[root]);
        heapify(arr, size, last);
    }
    // if a subtree completes heapify, getout
}

void buildheap(int *arr, int size){
    int root = (size/2)-1;
    //find next last parent node if heapify is complete for very last parent node
    for(int i= root; i>=0; i--){ 
        heapify(arr, size, i);
    }
}

int main(){
    FILE *inputP, *outputP;
    int i;
    int *arr;
    int size;

    inputP = fopen("rosalind_heap.txt", "r");
    assert(inputP !=NULL);
    // get size of array
    fscanf(inputP, "%d\n", &size);

    arr = (int *)malloc(sizeof(int) * size);
    assert(arr != NULL);

    // initialize the array to zero
    for(i=0; i<size; i++){
        arr[i] = 0;
    }

    // get values into the array
    for(i=0; i<size; i++){
        fscanf(inputP, "%d ", &arr[i]);
    }
    fclose(inputP);
    
    // create heap
    buildheap(arr, size);
    for(int i=size-1; i>0; i--){
        SWAP(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    outputP = fopen("heapsortOutput.txt", "w");
    
    //print result
    for(i=0; i<size; i++){
        //printf("%d ", arr[i]);
        fprintf(outputP, "%d ", arr[i]);
    }
    fprintf(outputP, "\n");

    // close and free    
    fclose(outputP);
    free(arr);

    return 0;
}