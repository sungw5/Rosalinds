#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void merge(int *arr1, int *arr2, int first, int last1, int last2, int *dest){
    int i = first; // arr1 first index
    int j = first; // arr2 first index
    int k = 0; // index for destination array


    while(i <= last1+1 && j <= last2+1){ 
        if(arr1[i] <= arr2[j]){ // if arr1 element is smaller, store it to the dest
            if(i == last1+1){ // if arr1 reaches end, store arr2 element
                dest[k] = arr2[j];
                k++; j++;
            }
            else{
                dest[k] = arr1[i];
                k++; i++;
            }
            
        }
        else{ // if arr2 element is smaller, store it to the dest
            if(j == last2+1){ // if arr2 reaches end, store arr1 element
                dest[k] = arr1[i];
                k++; i++;
            }
            else{
                dest[k] = arr2[j];
                k++; j++;
            }
        }
    } 
}


int main(){
    FILE *inputP, *outputP;
    int *arr1, *arr2, *dest;
    int i,size1,size2, totalsize;
    
    inputP = fopen("rosalind_merge2arr.txt", "r");
    assert(inputP != NULL);

    /********** first array ***********/
    fscanf(inputP, "%d\n", &size1);
    arr1 = (int *)malloc(sizeof(int) * size1);
    assert(arr1 != NULL);    
    for(i=0; i<size1; i++){
        arr1[i] = 0;
    }
    // get input values
    for(i=0; i<size1; i++){
        fscanf(inputP, "%d ", &arr1[i]);
    }
    /********** second array **********/
    fscanf(inputP, "%d\n", &size2);
    arr2 = (int *)malloc(sizeof(int) * size2);
    assert(arr2 != NULL);
    for(i=0; i<size2; i++){
        arr2[i] = 0;
    }
    // get input values
    for(i=0; i<size2; i++){
        fscanf(inputP, "%d ", &arr2[i]);
    }
    fclose(inputP);

    /********** dest array ************/
    totalsize = size1+size2;
    dest = (int *)malloc(sizeof(int) * totalsize);
    for(i=0; i<totalsize; i++){
        dest[i] = 0;
    }
//////////////////////////////////////////////////////
        
    // merge
    merge(arr1, arr2, 0, size1-1, size2-1, dest);
    

//////////////////////////////////////////////////////
    outputP = fopen("merge2arrOutput.txt", "w");
    //print output
    for(i=0; i<totalsize; i++){
        fprintf(outputP, "%d ", dest[i]);
    }
    //close and free
    fclose(outputP);
    free(arr1);
    free(arr2);
    free(dest);


    return 0;
}