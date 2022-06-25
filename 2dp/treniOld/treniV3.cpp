// typedef struct result_s result;
// struct result_s
// {
// 	int distance;
// 	bool isHypertrainPossible;
// };

#define MAXN 1000000
#include <vector>

int nDays;
std::vector<int> superTrain;
std::vector<int> hyperTrain;

std::vector<int> longestDistanceToThisDay;

int trainChooser(int currentDay) {
	if(currentDay < 0)
		return 0;

	if(longestDistanceToThisDay[currentDay] != -1) //if best Result is already known
		return longestDistanceToThisDay[currentDay];
	
	//calculate length for superTrain
	longestDistanceToThisDay[currentDay] = trainChooser(currentDay-1) + superTrain[currentDay];

	//calculate lenght for hyperTrain
	int hyperLength = trainChooser(currentDay-2) + hyperTrain[currentDay];

	//Choose better option
	if(longestDistanceToThisDay[currentDay] < hyperLength)
		longestDistanceToThisDay[currentDay] = hyperLength;
	
	return longestDistanceToThisDay[currentDay];
}

int tempo_massimo(int N, int A[], int B[]){
	nDays = N;
	superTrain.assign(A, A + N);
	hyperTrain.assign(B, B + N);
	longestDistanceToThisDay.assign(4, -1);

	int ret = trainChooser(N-1);
	
	return ret;
}












#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int tempo_massimo(int, int[], int[]);

int main()
{
    int n;
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d", &n) == 1);

    int *a = (int*)calloc(n, sizeof(int));
    int *b = (int*)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
      assert(fscanf(in, "%d", a + i) == 1);
      assert(fscanf(in, "%d", b + i) == 1);
    }

    int answ = tempo_massimo(n, a, b);
    fprintf(out, "%d\n", answ);

    free(a);
    free(b);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}