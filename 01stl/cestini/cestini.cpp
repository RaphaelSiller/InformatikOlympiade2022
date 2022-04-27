int cestini[100000][100000];
int highestObject[100000];

void inizia(int N, int M) {
	//Defining space
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cestini[M][N] = -1;
		}
	}
	//Defining highestObject
	highestObject[0] = N-1;
	for (int i = 1; i < M; i++) {
		highestObject[i] = 0;
	}
	
	//Filling with objects
	for (int i = 0; i < N; i++) {
		cestini[N][i] = i;
	}
}

void sposta(int a, int b) {
	cestini[b][highestObject[b]] = cestini[a][highestObject[a]];
	cestini[a][highestObject[a]] = -1;
	highestObject[a]--;
	highestObject[b]++;
}

int controlla(int a, int i) {
	if (i > highestObject[a]) {
		return cestini[a][i];
	} else {
		return -1;
	}
}