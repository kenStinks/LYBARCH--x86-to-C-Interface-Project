// Template C to x86 call
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// extern void asmhello();
extern void sdot_asm(int n, double A[30], double B[30], double* result);

double sdot_c(int n, double A[30], double B[30]){
    double result = 0;
    for(int i=0;i<n;i++){
        result += A[i]*B[i];
    }
    return result;
};

int main(int argc, char *argv[]) {
// asmhello();
    //initialize variables
    int n = 10;
    double A[30], B[30];
    for(int i=0;i<n;i++){
        A[i] = (float)(i+1);
        B[i] = (float)(n-i);
    }

    double result_c = sdot_c(n, A, B);
    printf("\nResult in C: %f", result_c);

    double result_asm;
    sdot_asm(n, A, B, &result_asm);

    printf("\nResult in ASM: %f", result_asm);

    return 0;
}