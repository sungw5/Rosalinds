#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int binarySearch(int *array, int k, int left, int right){
    if(left>right) return -1;
    
    int mid = (left+right)/2;
    if(array[mid] == k) return mid+1;
    else if(k < array[mid]) return binarySearch(array, k, left, mid-1);
    else return binarySearch(array, k, mid+1, right);

    return -1;
}

int main()
{   
    FILE *inputP = fopen("rosalind_bins.txt", "r");
    assert(inputP != NULL);
    // get n and m
    int n,m;
    fscanf(inputP, "%d\n", &n);
    printf("n: %d\n", n);
    fscanf(inputP, "%d\n", &m);
    printf("m: %d\n", m);

    // initialization
    int *array;
    array = (int *)malloc(sizeof(int) * n);
    int *vals;
    vals = (int *)malloc(sizeof(int) * m);
    assert(array != NULL);
    assert(vals != NULL);
    for(int i=0; i<n; i++){
        array[i] = 0;
    } 
    for(int i=0; i<m; i++){
        vals[i] = 0;
    } 

    // get sorted array inputs
    for(int i=0; i<n; i++){
        int in;
        fscanf(inputP, "%d ", &in);
        array[i] = in;
    }
    fprintf(inputP, "\n");
    //get value inputs
    for(int j=0; j<m; j++){
        int val;
        fscanf(inputP, "%d", &val);
        vals[j] = val;
    }
    fclose(inputP);

    //output begins
    FILE *outputP = fopen("binoutput.txt", "w");
    for(int i=0; i<=n; i++){
        printf("%d ", binarySearch(array, vals[i], 0, n-1));
        fprintf(outputP, "%d ", binarySearch(array, vals[i], 0, n-1));
    }
    fprintf(outputP, "\n");

    //close and free
    fclose(outputP);
    free(array);
    free(vals);

    

    return 0;
}