/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int Rows, Columns, i, j;
int M[MAXN][MAXN];

//
bool isVisited[MAXN][MAXN];
int nIslands = 0;
bool thisIslandIsPeninsula = false;


void islandExplorer(int x, int y);


int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Rows, &Columns));
    for(i=0; i<Rows; i++)
        for (j=0; j<Columns; j++)
            assert(1 == scanf("%d", &M[i][j]));




    // insert your code here
    for (int y = 0; y < Rows; y++) {
        for (int x = 0; x < Columns; x++) {
            if(M[x][y] && !isVisited[x][y]) {
                islandExplorer(x, y);

                if(!thisIslandIsPeninsula) //If explored Island is not a Peninsula
                    nIslands++;
                else
                    thisIslandIsPeninsula = false;
            }
        }
    }
    



    printf("%d\n", nIslands); // print the result
    return 0;
}

/**
 * @brief Marks all neighbors as visited
 */
void islandExplorer(int x, int y) {
    if (x < 0 || y < 0 || x >= Columns || y >= Rows) //if out of Boundaries
        return;
    
    if (isVisited[x][y] || M[x][y] == 0) // if already visited or not an Island
        return;

    if (x == 0 || y == 0 || x == Columns-1 || y == Rows-1)
        thisIslandIsPeninsula = true;

    isVisited[x][y] = true;

    islandExplorer(x, y-1);
    islandExplorer(x-1, y);
    islandExplorer(x+1, y);
    islandExplorer(x, y+1);
}