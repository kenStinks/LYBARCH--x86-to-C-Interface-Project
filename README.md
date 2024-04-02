
# Performance Analysis for SDOT Kernel

This repository contains C and x86-64 assembly implementations for the SDOT kernel. The purpose of this README is to provide an analysis of the performance of these implementations in both debug and release modes.


## Deployment

To run the this repository:
1. Install the required compilers:
    * [NASM](https://www.nasm.us/)
    * [GCC](https://www.youtube.com/watch?v=0HD0pqVtsmw)
2. Make sure the compiler paths are included in your system machine variables.
3. Open your terminal in this folder and run the `build.bat` file by inputting the following script:
```
build
```
4. The program should compile and run as `main.exe`

## Methodology

For each experiment, vectors A and B of size n are used. A is an array containing a repeating sequence of 1 to 100. B is an array containing a repeating sequence of 100 to 1. The chosen kernel is then applied to every pair of values to compute the Scalar Dot Product (SDOT) of A and B.

Both kernels take in the same inputs: (double) A, (double) B, and (pointer) result. The kernels multiply A and B, then add the output to the value stored in result. 

Each experiment is ran 30 times so that an average time can be computed. Each time, the results are validated by comparing it with the answer of the other kernel. (So C is used to check x86, and vice versa.) If at any point there is an inconsistency with the results, the program will print with `Sanity: No`

Sizes of n tested are 2^20, 2^24, 2^28.

## Results
![C and x86-64 Implentations](output.png)

In the first set of experiments, n is 2^20. C had an average time of 0.0041s while ASM had 0.002933s. ASM was faster than C by 0.001167s.

Next, n is 2^24. C had an average time of 0.0661 while ASM had 0.04657. ASM was faster by 0.019553s.

Lastly, n is 2^28. C had an average time of 1.048167s while ASM had an average time of 0.750100s. ASM was faster by 0.298067s.

## Conclusion
Based on the performance analysis, it can be observed that the assembly implementation consistently outperforms the C across different input sizes. This suggests that optimizing critical sections of code through assembly language can significantly improve performance, especially in computationally intensive tasks like running the SDOT kernel millions of times.

