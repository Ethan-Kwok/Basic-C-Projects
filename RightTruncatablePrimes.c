#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int checkPrime(long num) {
    if (num == 0) return 0;
    
    while (num != 0) {
        if (num < 2) {
            return 0;
        }
        
        for (long i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                return 0;
            }
        }
        num /= 10;
    }
    return 1;
}

int main(int argc, char* argv[argc + 1]) {
    
    FILE *fp;
    fp = fopen(argv[1], "r");

    long num = 0;
    long arraySize = 0;

    if(fp == NULL) {
        printf("ERROR");
        exit(0);
        return 0;
    }

    fscanf(fp, "%ld\n", &arraySize);

    for (int i = 0; i < arraySize-1; i++) {

        fscanf(fp, "%ld\n", &num);
        if (checkPrime(num)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }

    }

    fscanf(fp, "%ld\n", &num);
    if (checkPrime(num)) {
        printf("yes");
    }
    else {
        printf("no");
    }


    fclose(fp);
    return EXIT_SUCCESS;

}