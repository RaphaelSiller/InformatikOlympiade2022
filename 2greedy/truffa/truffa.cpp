#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <array>


#define MAXN 100000

int sfangate(int N, int V[]) {
    int netLossWin = 0;
    //Calculate Net loss/win
    for (int i = 0; i < N; i++) {
        netLossWin += V[i];
    }
    
    //sort array
    if(netLossWin<=0)
        std::sort(V, V + sizeof(V));
    
    int nNegations = 0;
    while (netLossWin <= 0) {
        netLossWin += V[nNegations] * -2;
        nNegations++;
    }
    

    return nNegations;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}