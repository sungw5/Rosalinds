#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b); 
}


int main(int argc, char **argv){
    FILE *inputP, *outputP;
    char *infilename;
    int k; // # of arrays
    int n; // size of array (# of elements)
    int *arr;

    if(argc ==2){
        infilename = argv[1];
        inputP = fopen(infilename, "r");
    }
    else{
        inputP = fopen("rosalind_2sum.txt", "r");
    }
    assert(inputP != NULL);

    // get k (# of arrays)  and n (size of array)
    fscanf(inputP, "%d ", &k);
    fscanf(inputP, "%d ", &n);

    fprintf(stderr, "k: %d, n: %d\n", k, n);

    // allocate and initialize
    arr = (int *)malloc(sizeof(int) * 2 * n);
    assert(arr != NULL);
    //store value along with the index
    for(int i=0; i<n; i++){
        arr[2*i] = 0;  //store value
        arr[2*i+1] = i;  //store index
    }

    outputP = fopen("2sum_output.txt", "w");
    //get input values
    int ki;
    for(ki =0; ki<k; ki++){

        for(int i =0; i<n; i++){
            fscanf(inputP, "%d ", &arr[2*i]); 
            arr[2*i+1] = i;
        }
        //sort
        qsort(arr, n, 2*sizeof(int), compare);

        // find the indices
        int ind1 = -1;
        int ind2 = -1;
        int pos1 = 0;
        int pos2 = n-1;

        while( (pos1 < pos2) && (arr[2*pos1] <=0) && (arr[2*pos2] >=0) ){
            if((arr[2*pos1] + arr[2*pos2]) == 0){
                ind1 = arr[2*pos1 + 1];
                ind2 = arr[2*pos2 + 1];
                break;  
            }
            else{
                if((arr[2*pos1] + arr[2*pos2]) < 0){
                    pos1++;
                }
                else{
                    pos2--;
                }
            }
        }

        // write to file
        if(ind1 == -1){
            fprintf(outputP, "-1\n");
        }
        else{
            if(ind1 < ind2){
                fprintf(outputP, "%d %d\n", ind1 + 1, ind2 + 1);
            }
            else{
                fprintf(outputP, "%d %d\n", ind2 + 1, ind1 + 1);
            }
        }

    }

    fclose(inputP);
    fclose(outputP);
    free(arr);
    

    return 0;
}