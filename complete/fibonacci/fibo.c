#include <stdio.h>
#include <stdlib.h>


int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    else return fib(n-1) + fib(n-2);

}

int main(){

    FILE *inputF = fopen("rosalind_fibo.txt", "r");
    int n;
    fscanf(inputF, "%d\n", &n);
    printf("n: %d\n", n);
    fclose(inputF);

    FILE *outputF = fopen("fiboutput.txt", "w");
    fprintf(outputF, "%d\n", fib(n));

    fclose(outputF);
    return 0;
}