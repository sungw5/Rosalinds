#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SWAP(x, y) {int temp; temp=x; x=y; y=temp;}
#define parent(v) ((v-1)/2)

void heap(int *arr, int size){
    int child, root;

    for (int i=1; i<size; i++){
        child = i;
        while(child > 0){
            root = parent(child);
            if(arr[root] < arr[child]){ //if child is bigger than the root, swap
                SWAP(arr[root], arr[child]);
            }
            child = root; // change the index also
        }
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
    heap(arr, size);

    // swap root with very last element
    for(i=size-1; i>=0; i--){
        SWAP(arr[i], arr[0]);
        heap(arr, i); //create heap except the very last element(largest element)
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