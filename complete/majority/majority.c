#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int majority(int *arr, int size){
    int max =0;
    int count =0;
    
    // find majority
    for(int i=0; i<size; i++){
        // if counter is not zero, increment/decrement the counter
        count = (arr[i] == arr[max]) ? count+1 : count-1; 

        // if counter is zero, set max to the current element, and set count to 1.
        if(count == 0){
            max = i; // follow index
            count = 1; // put it back to 1 to prevent count goes below zero
        }
    }

    count = 0;
    // we have max element saved, now count how many of them are there
    for(int i=0; i<size; i++){
        if(arr[i] == arr[max]){
            count++;
        }
    }
    //check majority rule, then return majority or -1
    if(count > size/2){
        return arr[max];
    }
    else{
        return -1;
    }
    
}

int main(){
    FILE *inputP, *outputP;
    int *arr;
    int i,arrnum,size;
    
    inputP = fopen("rosalind_majority.txt", "r");
    assert(inputP != NULL);
    // get size from input file
    fscanf(inputP, "%d %d\n", &arrnum, &size);

    // allocate memory for array and check

    arr = (int *)malloc(sizeof(int) * size);
    assert(arr != NULL);
    for(i=0; i<size; i++){
        arr[i] = 0;
    }


    outputP = fopen("majorityOutput.txt", "w");
//////////////////////////////////////////////////////
    
    for(int k=0; k<arrnum; k++){ // loop for reusing array
        
        // get input values
        for(i=0; i<size; i++){
            fscanf(inputP, "%d ", &arr[i]);
        }
        fprintf(outputP, "%d ", majority(arr, size));

    }    
//////////////////////////////////////////////////////
    //close and free
    fclose(inputP);
    fclose(outputP);
    free(arr);

    return 0;
}