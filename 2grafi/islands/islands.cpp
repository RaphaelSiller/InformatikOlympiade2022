/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

void newIsland(int x, int y);
void isPeninsula(int x, int y);
// constraints
#define MAXN 1000

// input data
int R, C, i, j, nIslands = 0;
int M[MAXN][MAXN];
int FieldIspartOfIsland[MAXN][MAXN];
bool thisIslandIsPeninsula = false;
int main() {
    
//  uncomment the following lines if you want to read/write from files
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    //
    



    for (i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            FieldIspartOfIsland[i][j] = -1;
        }
    }


    // fprintf(stderr, "TestBevor\n");
    for (i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // fprintf(stderr, "Test %i %i\n", i, j);
            if(M[i][j] && FieldIspartOfIsland[i][j] == -1) {
                // fprintf(stderr, "_______Test %i %i\n", i, j);
                newIsland(i, j);
                nIslands++;
                thisIslandIsPeninsula = false;
            }
        }
    }





    printf("%d\n", nIslands); // print the result
    return 0;
}

void newIsland(int x, int y) {
    if (x < R-1 && y < C-1 && x> 0 && y>0 && FieldIspartOfIsland[x][y] == -1 && !thisIslandIsPeninsula) {
        // fprintf(stderr, "\tTest %i %i\n", x, y);
        FieldIspartOfIsland[x][y] = nIslands+1;
        if(x > 0 && M[x-1][y] && FieldIspartOfIsland[x-1][y] < 0) {
            newIsland(x-1, y);
        }
    
        if(M[x+1][y] && FieldIspartOfIsland[x+1][y] < 0) {
            newIsland(x+1, y);
        }
    
        if(y > 0 && M[x][y-1] && FieldIspartOfIsland[x][y-1] < 0) {
            newIsland(x, y-1);
        }
    
        if(M[x][y+1] && FieldIspartOfIsland[x][y+1] < 0) {
            newIsland(x, y+1);
        }
    } else if ((x == R-1 || y == C-1 || x == 0 || y == 0) && !thisIslandIsPeninsula) {
        thisIslandIsPeninsula = true;
        isPeninsula(x, y);
        nIslands--;
    }
    
}

void isPeninsula(int x, int y) {
    if (x >= 0 && y >= 0 && x <= R && y <= C) {
        FieldIspartOfIsland[x][y] = -2;
        if(x > 0 && M[x-1][y] && FieldIspartOfIsland[x-1][y] != -2) {
            isPeninsula(x-1, y);
        }
    
        if(M[x+1][y] && FieldIspartOfIsland[x+1][y] != -2) {
            isPeninsula(x+1, y);
        }
    
        if(y > 0 && M[x][y-1] && FieldIspartOfIsland[x][y-1] != -2) {
            isPeninsula(x, y-1);
        }
    
        if(M[x][y+1] && FieldIspartOfIsland[x][y+1] != -2) {
            isPeninsula(x, y+1);
        }
    }
}