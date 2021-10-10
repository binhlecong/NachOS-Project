#include "syscall.h"

int A[100];

int main() {
    int i, j, temp, n;
    char isAsc;
    PrintString("Enter number of elements n = ");
    n = ReadNum();

    if (n < 1 || n > 100) {
        PrintString(" n mush be in range [1, 100]\n");
        Halt();
    }


    PrintString("Enter array = ");
    for (i = 0; i < n; ++i)
        A[i] = ReadNum();
    
    PrintString("Ascending/Descending enter [0/1]: ");
    isAsc = ReadChar() == '0';

    /*  sort integer array using Bubble sort algorithm
        order by function pointer compare
    */
    for (i = 0; i < n; ++i) {
        for (j = n - 1; j > i; --j) 
            if (isAsc ? A[j - 1] > A[j] : A[j - 1] < A[j]) {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
    }   

    PrintString("Array after sorting: ");
    for (i = 0; i < n; ++i) {
        PrintNum(A[i]);
        PrintChar(' ');
    }
    PrintChar('\n');
    Halt();
}