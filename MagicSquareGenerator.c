#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[argc + 1]){
    

    int n = atoi(argv[1]);

    if (n%2 == 0) {
        printf("error\n");
        return 0;
    }
    
    int** arr;
    arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    int num = 2;


    //Step 1)
    arr[0][n/2] = 1;
    int row = 0;
    int col = n/2;
    
    while (num <= n*n) {
        //Step 2)
        int up = row-1;
        int right = col+1;
        if (up < 0) up = n-1;
        if (right > n-1) right = 0;
        if (arr[up][right] == 0) {
            arr[up][right] = num;
            num++;
            row = up;
            col = right;
        }
        //Step 3)
        else {
            int down = row+1;
            if (down > n-1) down = 0;
            arr[down][col] = num;
            num++;
            row = down;
        }

    }
    
    
    //print arr
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n-1) printf("%d\t", arr[i][j]);
            else printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);

	return EXIT_SUCCESS;
}