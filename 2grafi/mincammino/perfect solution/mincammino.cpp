#include <vector>

#include<utility>

#include<algorithm>

#include<climits>

#include<queue>

#define INT_MAX 2147483647

using namespace std;

struct paths{
    int targets;
    int price;
};

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    vector<paths> listOfPaths[N];
    D.resize(N);

    //Sets all Paths starting from the node
    for(int i = 0; i < M; i++){
        paths in;
        in.targets = Y[i];
        in.price = P[i];
        listOfPaths[X[i]].push_back(in);
        D[in.targets] = INT_MAX;
        D[X[i]] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> howToWriteQueu;
    howToWriteQueu.push(make_pair(0, 0));
    D[0] = 0; //Set cost to Startpoint to Null

    while(!howToWriteQueu.empty()){
        int node = howToWriteQueu.top().second;
        howToWriteQueu.pop();

        for(paths pross : listOfPaths[node]){ //For every path in this node
            if(D[pross.targets] > D[node] + pross.price){
                D[pross.targets] = D[node] + pross.price;
                howToWriteQueu.push(make_pair(D[pross.targets], pross.targets));
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(D[i] == INT_MAX) D[i] = -1;
    }
}