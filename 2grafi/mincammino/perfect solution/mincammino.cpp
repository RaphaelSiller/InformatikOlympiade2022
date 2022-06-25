#include <vector>

#include<utility>

#include<algorithm>

#include<climits>

#include<queue>

using namespace std;

typedef
struct paths_s {
    int targets;
    int price;
} paths_t;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    vector<paths_t> listOfPaths[N];
    D.resize(N);

    //Sets all Paths starting from node
    for(int i = 0; i < M; i++){
        paths_t in;
        in.targets = Y[i];
        in.price = P[i];
        listOfPaths[X[i]].push_back(in);
        D[in.targets] = __INT32_MAX__;
        D[X[i]] = __INT32_MAX__;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> howToWriteQueu;
    howToWriteQueu.push(make_pair(0, 0));
    D[0] = 0; //Set cost of start node to Zero

    while(!howToWriteQueu.empty()){
        int node = howToWriteQueu.top().second;
        howToWriteQueu.pop();

        for(paths_t pross : listOfPaths[node]){ //For every path in this node
            if(D[pross.targets] > D[node] + pross.price){
                D[pross.targets] = D[node] + pross.price;
                howToWriteQueu.push(make_pair(D[pross.targets], pross.targets));
            }
        }
    }
    //If any nodes are unreachable, set -1
    for(int i = 0; i < N; i++) {
        if(D[i] == __INT32_MAX__) D[i] = -1;
    }
}