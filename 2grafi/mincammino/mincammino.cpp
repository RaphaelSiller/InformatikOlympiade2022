#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Declaring functions
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D);
bool everythingTrue(vector<bool> vect);

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    vector<bool> visitedPoint;
    visitedPoint.assign(N, false);
    D[0] = 0;
    //Setting cost for startPoint to Null, the other to maximum
    for (int i = 1; i < D.size(); i++)
        D[i] = 10000001;
    
    //While there are still knots not visited
    int currentLocation = 0;
    while(!everythingTrue(visitedPoint) && currentLocation != -1) {
        int nextLocation = -1;
        //set this place as visited
        visitedPoint[currentLocation] = true;
        //Setting currently cost to other points
        for (int j = 0; j < N; j++) {
            //If starts from currentLocation
            if(X[j] == currentLocation) {
                //change price if less than before
                int price = D[X[j]] + P[j];
                if (price < D[Y[j]]) {
                    D[Y[j]] = price;
                    //If this point is cheaper than the one before
                    if(!visitedPoint[Y[j]] && (nextLocation < 1 || (P[Y[j]] < D[nextLocation])))
                        nextLocation = Y[j];
                }
            }
        }
        currentLocation = nextLocation;
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