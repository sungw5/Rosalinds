#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SWAP(x, y) {int temp; temp=x; x=y; y=temp;}
//#define parent(v) ((v-1)/2)


void heapify(int *arr, int size, int root){
    int last = root;
    int left = root*2+1;
    int right = root*2+2;

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
}
void buildheap(int *arr, int size){
    int root = (size/2)-1;
    for(int i= root; i>=0; i--){
        heapify(arr, size, i);
    }
}


int main(){
    FILE *inputP, *outputP;
    int i;
    int *arr;
    int size;

    
    inputP = fopen("rosalind_bheap.txt", "r");
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

    outputP = fopen("buildheapOutput.txt", "w");
    
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