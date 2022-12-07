#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void free_subarr(int n, int** arr) {
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return;
}


int det_calc(int n, int** arr) {
    
    int det = 0;

    if (n == 1) {
        det = arr[0][0];
        return det;
    }
    if (n == 2) {
        det = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
        return det;
    }

    for (int i = 0; i < n; i++) {
        //allocate subarray M_1,i
        int** subarr;
        subarr = malloc((n-1) * sizeof(int*));
        for (int i = 0; i < n-1; i++) {
            subarr[i] = malloc((n-1) * sizeof(int));
        }

        //set subarr to correct values
        for (int j = 1; j < n; j++) {
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    subarr[j-1][count] = arr[j][k];
                    count++;
                }
            }
        }

        //calculate determinant
        if (i%2 == 0) det+= arr[0][i] * det_calc(n-1, subarr);
        else det+= -arr[0][i] * det_calc(n-1, subarr);

        for (int i = 0; i < n-1; i++) free(subarr[i]);
        free(subarr);

    }

    return det;

}




int main(int argc, char** argv){
    
    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("error\n");
        exit(0);
        return 0;
    }

    //create and allocate 2D array
    int n, num = 0;
    fscanf(fp, "%d", &n);
    
    int** arr;
    arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &num);
            arr[i][j] = num;
        }
    }
 
    printf("%d\n", det_calc(n,arr));
    
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);

	return 0;
}