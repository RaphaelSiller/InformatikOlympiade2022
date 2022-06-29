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












bool isOrdinato(int N, int V[]);
long long paletta_sort(int N, int V[]);

bool isOrdinato(int N, int V[])
{
    bool isO = true;
 
 
        for(int i = 0; i < N-1; i++)
        {
            if(V[i] > V[i+1])
                return false;
        }
 
    return isO;
}
 
long long paletta_sort(int N, int V[]) {
 
	//Check if it's possible to sort
	for (int i = 0; i < N; i+=2)
	{
		if(V[i]%2==1)
			return -1;

		if(V[i+1]%2==0)
			return -1;
	}
	

 
    long long contatore = 0;
    int temp;
    int t1 = 0;
 
    bool t = true;
 
        for(int i = 0; i < N-2; i++)
        {
            t1++;
 
 
            if(V[i] > V[i+2])
            {
                contatore++;
 
                temp = V[i];
                V[i] = V[i+2];
                V[i+2] = temp;
 
                i-=3;
 
                if(i <-1)
                    i=-1;
            }
 
 
        }
 
     t = isOrdinato(N,V);
 
        if(!t)
            return -1;
 
        if(t && contatore == 0)
            return 0;
 
    return contatore;
}
