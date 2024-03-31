//Jeanne Eugenie Arguelles    XX22
//John Kirsten Espiritu       XX22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
typedef unsigned char boolean;

struct test_result{
    double average_time;
    boolean sanity;
};

extern void sdot_asm(double A, double B, double* result);

void sdot_c(double A, double B, double* result){
    (*result) += A*B;
}

struct test_result test(int n, void (*sdot)(double, double, double*), void (*sdot_sanity)(double, double, double*)){
    clock_t start, end;
        
    double expected_result = 0;
    boolean sanity = TRUE;

    for(int j=0;j<n;j++){
        double a = (double)((j%100)+1); //numbers 1 to 100, wrapping
        double b = (double)(100-(j%100)); //numbers 100 to 1, wrapping
        sdot_sanity(a,b,&expected_result);
    }

    double average_time = 0.;

    for (int i=0; i<30;i++){
        start = clock(); //start time

        double result = 0;
        for(int j=0;j<n;j++){
            double a = (double)((j%100)+1); //numbers 1 to 100, wrapping
            double b = (double)(100-(j%100)); //numbers 100 to 1, wrapping
            sdot(a,b,&result);
        }

        //check if result is consistent with expected
        sanity = (result == expected_result) && sanity; 
        
        end = clock(); //end time
        double time = ((double)(end - start) / CLOCKS_PER_SEC);
        average_time += time;
    }

    average_time /= 30.;

    struct test_result test_result = {average_time, sanity};

    return test_result;
}

void full_test(int n){
    struct test_result C_res = test(pow(2,n), sdot_c, sdot_asm);
    printf("C\t(n=2^%d) Average Time: %fs | Sanity: ", n, C_res.average_time);
    if(C_res.sanity) printf("Yes\n");
    else printf("No\n");

    struct test_result ASM_res = test(pow(2,n), sdot_asm, sdot_c);
    printf("ASM\t(n=2^%d) Average Time: %fs | Sanity: ", n, ASM_res.average_time);
    if(ASM_res.sanity) printf("Yes\n");
    else printf("No\n");

    double time_diff = fabs(C_res.average_time-ASM_res.average_time);
    if(C_res.average_time < ASM_res.average_time) printf("C was faster than ASM by %fs\n\n", time_diff);
    else printf("ASM was faster than C by %fs!\n\n", time_diff);
}

int main(int argc, char *argv[]) {

    full_test(20);
    full_test(24);
    full_test(28);

    return 0;
}