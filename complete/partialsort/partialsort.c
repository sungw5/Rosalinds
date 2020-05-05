#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SWAP(x,y) {int temp; temp=x; x=y; y=temp;} // swap without using temp -> using XOR

// 참교육장 (pivot on the right)
int divide(int *arr, int first, int last){
    int pivot = arr[last]; 
    int i; // counts how many elements are smaller than pivot
    int index = first;

    for(i=first; i<last; i++){
        // if arr[i] is bigger than pivot, then increment only i
        // if arr[i] is smaller than pivot, then increment both i and index
        // swap arr[i] with one in index
        if(arr[i] <= pivot){
            SWAP(arr[i], arr[index]); // i 에있는애가 머리끄댕이 잡혀서 index 있는곳으로 끌려옴
            index++;
        }
    }
    SWAP(arr[last], arr[index]); // 그럼 pivot에 있던애 왼쪽에는 얘보다 다 작고 원래 얘가 있던 pivot 자리에 index 에있는애를 보냄
    return index; // currently in pivot 자리 
}

void quicksort(int *arr, int first, int last){

    int p;

    // check if there's only one element (false to if condition)
    if(first < last){ 
        p = divide(arr, first, last);
        quicksort(arr, first,p-1);
        quicksort(arr, p+1, last);
    }
    else{
        return ;
    }
}

int main(){
    FILE *inputP, *outputP;
    int *arr;
    int i,size;
    int k;
    
    inputP = fopen("rosalind_partialsort.txt", "r");
    assert(inputP != NULL);
    // get size from input file
    fscanf(inputP, "%d\n", &size);

    // allocate memory for array and check
    arr = (int *)malloc(sizeof(int) * size);
    assert(arr != NULL);
    for(i=0; i<size; i++){
        arr[i] = 0;
    }

    // get input values
    for(i=0; i<size; i++){
        fscanf(inputP, "%d ", &arr[i]);
    }
    fscanf(inputP, "%d ", &k);

    fclose(inputP);
//////////////////////////////////////////////////////
    // quicksort
    quicksort(arr, 0, size-1);


//////////////////////////////////////////////////////
    outputP = fopen("partialsortOutput.txt", "w");
    //print output
    for(i=0; i<k; i++){
        fprintf(outputP, "%d ", arr[i]);
    }
    //close and free
    fclose(outputP);
    free(arr);

    return 0;
}