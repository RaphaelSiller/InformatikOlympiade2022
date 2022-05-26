#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include<utility>
#include<climits>
#include<queue>

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

    while(!howToWriteQueu.empty()) {
        int node = howToWriteQueu.top().second;
        howToWriteQueu.pop();

        for(paths pross : listOfPaths[node]){ //For every path in this node
            if(D[pross.targets] > D[node] + pross.price){
                D[pross.targets] = D[node] + pross.price;
                howToWriteQueu.push(make_pair(D[pross.targets], pross.targets));
            }
        }
    }
    //If no path to a node was found
    for(int i = 0; i < N; i++){
        if(D[i] == INT_MAX) D[i] = -1;
    }
}
bool everythingTrue(vector<bool> vect) {
    for (int i = 0; i < vect.size(); i++) {
        if(!vect[i])
            return false;
    }
    return true;
    
}

int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    // Reading input
    int N, M;
    cin >> N >> M;

    vector<int> X(M), Y(M), P(M), D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    // Calling functions
    mincammino(N, M, move(X), move(Y), move(P), D);

    // Writing output
    for(int d : D) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}