#include <stdio.h>
#include "my_mat.h"

int mat [SIZE][SIZE]; // initializing the matrix (size = 10x0):

/* Helper method for calc_shortest_path function */
int min(int l, int r) {
    if (l == 0) {
        return r;
    }
    if (r == 0)
        return l;

    if (l < r) {
        return l;
    } else {
        return r;
    }
}
/* This function calculates the shortest path between two integers using the 'Floyd algorithm. */

void calc_shortest_path() 
{
    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++){
                if (i == j)
                {
                    mat[i][i] = 0;
                }
                else if (i == k || j == k)
                {
                    mat[i][j] = mat[i][j];
                }
                else
                {
                    int value = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0)
                    {
                        value = 0;
                    }
                    mat[i][j] = min(mat[i][j], value);
                }
            }
        }
    }
}

/* function A */

void input() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    calc_shortest_path();
}

/*function B*/

void hasPath()
{
    int i=0, j=0;
    scanf("%d%d", &i, &j);
    if (mat[i][j] != 0)
    {

        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
/* function C */

void print_shortest()
{
    int i=0, j=0;
    scanf("%d%d", &i, &j);
    if (mat[i][j] == 0 || i == j)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", mat[i][j]);
    }
}

