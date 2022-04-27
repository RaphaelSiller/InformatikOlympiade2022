#include <iostream>
#include <fstream>
using namespace std;

// Declaring functions
void inizia(int N, int M);
void sposta(int a, int b);
int controlla(int a, int i);

int main() {
    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    ios::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    inizia(N, M);

    for (int i = 0; i < Q; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == 's') {
            sposta(a, b);
        } else {
            cout << controlla(a, b) << '\n';
        }
    }

    return 0;
}






static int cestini[10][10];
static int highestObject[10];

void inizia(int N, int M) {
	//Defining space
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cestini[M][N] = -1;
		}
	}
	//Defining Index of highestObject
	highestObject[0] = N-1;
	for (int i = 1; i < M; i++) {
		highestObject[i] = -1;
	}
	
	//Filling with objects
	for (int i = 0; i < N; i++) {
		cestini[0][i] = i;
	}
}

void sposta(int a, int b) {
	int indexToBePlaced = (highestObject[b]<0) ? 0 : highestObject[b]+1;
    cestini[b][indexToBePlaced] = cestini[a][highestObject[a]];
	cestini[a][highestObject[a]] = -1;
	highestObject[a]--;
    highestObject[b]++;
}

int controlla(int a, int i) {
	if (i <= highestObject[a] ) {
		return cestini[a][i];
	} else {
		return -1;
	}
}