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


bool islandExplorer(int x, int y);


int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Rows, &Columns));
    for(i=0; i<Rows; i++)
        for (j=0; j<Columns; j++)
            assert(1 == scanf("%d", &M[i][j]));




    // insert your code here
    for (int x = 0; x < Rows; x++) {
        for (int y = 0; y < Columns; y++) {
            if(M[x][y] && !isVisited[x][y]) {
                if(islandExplorer(x, y)) //If explored Island is not a Peninsula
                    nIslands++;
            }
        }
    }
    



    printf("%d\n", nIslands); // print the result
    return 0;
}

/**
 * @brief Marks all neighbors as visited
 */
bool islandExplorer(int x, int y) {
    bool isIsland = true;

	if (x < 0 || y < 0 || x >= Rows || y >= Columns) //if out of Boundaries
        return true;
    
    if (isVisited[x][y] || M[x][y] == 0) // if already visited or not an Island
        return true;

    if (x == 0 || y == 0 || x == Rows-1 || y == Columns-1)
        isIsland = false;

    isVisited[x][y] = true;

    if (!islandExplorer(x, y-1))
		isIsland = false;

	if (!islandExplorer(x-1, y))
		isIsland = false;

	if (!islandExplorer(x+1, y))
		isIsland = false;

	if (!islandExplorer(x, y+1))
		isIsland = false;
    
	return isIsland;
}