#include <vector>
#include <stdio.h>

int sum(std::vector<int> *tree, int i);
void add(std::vector<int> *tree, int i, int k);
void make(std::vector<int> *tree, int N, std::vector<int> data);
long long paletta_sort(int N, int V[]);

int sum(std::vector<int> *tree, int i) {
	int ret = 0;
	while (i > 0) {
		ret += (*tree)[i];
		i -= i &(-i);
	}
	return ret;
}

void add(std::vector<int> *tree, int i, int k) {
		while (i < (*tree).size()) {
			(*tree)[i] += k;
			i += i & (-i); 
		}
	return;
}

void make(std::vector<int> *tree, int N, std::vector<int> data) {
	(*tree).insert((*tree).begin(), data.begin(), data.end());
	(*tree).insert((*tree).begin(), 0);

	for (int i = 1; i < (*tree).size(); i++) {
		int p = i + (i & (-i));
		if ( p < (*tree).size()) {
			(*tree)[p] = (*tree)[p] + (*tree)[i]; 
		}
	}
	printf("debugpoint");
}


long long paletta_sort(int N, int V[]) {
	std::vector<int> even, odd, fenwickEven, fenwickOdd;

	for (int i = 0; i < N; i++) {
		if(V[i] % 2)
			odd.push_back(V[i]);
		else
			even.push_back(V[i]);
	}

	make(&fenwickEven, N, even);
	make(&fenwickOdd, N, odd);

	//         ________
    //     _jgN########Ngg_
    //   _N##N@@""  ""9NN##Np_
    //  d###P            N####p
    //  "^^"              T####
    //                    d###P
    //                 _g###@F
    //              _gN##@P
    //            gN###F"
    //           d###F
    //          0###F
    //          0###F
    //          0###F
    //          "NN@'

    //           ___
    //          q###r
    //           ""

	return 42;
	
}







#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int* V;
static long long int numero_ribaltamenti;

// Declaring functions
long long int paletta_sort(int N, int* V);

int main() {
		fr = fopen("input.txt", "r");
		fw = fopen("output.txt", "w");

	// Reading input
	fscanf(fr, "%d ", &N);
	V = (int*)malloc(N * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, "%d ", &V[i0]);
	}

	// Calling functions
	numero_ribaltamenti = paletta_sort(N, V);

	// Writing output
	fprintf(fw, "%lld\n", numero_ribaltamenti);
	
	fclose(fr);
	fclose(fw);
	return 0;
}