#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SWAP(x,y) {int temp; temp=x; x=y; y=temp;}

// 참교육장 (pivot on the left)
void divide(int *arr, int first, int last){
    int pivot = arr[first]; 
    int i; // counts how many elements are smaller than pivot
    int index = last;

    for(i=last; i>=first; i--){
        if(arr[i] > pivot){
            SWAP(arr[i], arr[index]); // i 에있는애가 머리끄댕이 잡혀서 index 있는곳으로 끌려옴
            index--;
        }
    }
    SWAP(arr[first], arr[index]); // 그럼 pivot에 있던애 왼쪽에는 얘보다 다 작고 원래 얘가 있던 pivot 자리에 index 에있는애를 보냄
}


int main(){
    FILE *inputP, *outputP;
    int *arr;
    int i,size;
    
    inputP = fopen("rosalind_2way.txt", "r");
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

    fclose(inputP);
//////////////////////////////////////////////////////
    divide(arr, 0, size-1);

//////////////////////////////////////////////////////
    outputP = fopen("2wayOutput.txt", "w");
    //print output
    for(i=0; i<size; i++){
        fprintf(outputP, "%d ", arr[i]);
    }
    //close and free
    fclose(outputP);
    free(arr);

    return 0;
}