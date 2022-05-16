/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>

typedef struct coordinate_s {
    int x;
    int y;
    int partOfIsland;
} coord_t;

std::vector<coord_t> isSurrounded(int x, int y);

// constraints
#define MAXN 1000

// input data
int R, C, i, j, nIslands = 0;
int M[MAXN][MAXN];
int FieldIspartOfIsland[MAXN][MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    //
    
    for (i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            FieldIspartOfIsland[i][j] = -1;
        }
    }
    
    for (i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(M[i][j]) {
                std::vector<coord_t> neighbourIslands = isSurrounded(i, j);
                for (int k = 0; k < neighbourIslands.size(); k++) {
                    //Already Explored Island
                    if (neighbourIslands[k].partOfIsland >=0)
                    {
                        /* code */
                    }
                    
                }
                
            }
        }
    }



    printf("%d\n", 42); // print the result
    return 0;
}

std::vector<coord_t> isSurrounded(int x, int y) {
    std::vector<coord_t> neighbourIsland;

    if(M[x-1][y]) {
        neighbourIsland.push_back({x+0, y-1, FieldIspartOfIsland[x+0][y-1]});
    }

    if(M[x+1][y+0]) {
        neighbourIsland.push_back({x-1, y+0, FieldIspartOfIsland[x-1][y+0]});
    }

    if(M[x][y-1]) {
        neighbourIsland.push_back({x+0, y+1, FieldIspartOfIsland[x+0][y+1]});
    }

    if(M[x][y+1]) {
        neighbourIsland.push_back({x+1, y+1, FieldIspartOfIsland[x+1][y+1]});
    }

    return neighbourIsland;
}