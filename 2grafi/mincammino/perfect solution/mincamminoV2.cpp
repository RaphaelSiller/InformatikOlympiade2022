#include <queue>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct arco {
    long long to;
    long long weight;
    arco(long long t, long long w) {
        to = t;
        weight = w;
    }
};

struct str {
    long long nodo;
    long long peso;
    str(long long n, long long p) {
        nodo = n;
        peso = p;
    }
    
    bool operator<(const str &a) const {
        return peso > a.peso;
    }
};

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M;
    cin >> N >> M;

    long long start, end;
    cin >> start >> end;
    start--; end--;

    vector<long long> distances(N, LLONG_MAX);
    distances[start] = 0;

    vector<vector<arco>> grafo(N);
    for (int i = 0; i < M; i++) {
        long long a, b, p;
        cin >> a >> b >> p;
        a--; b--;
        grafo[a].push_back(arco(b, p));
    }

    priority_queue<str> pq;
    pq.push(str(start, 0));

    while (!pq.empty()) {
        str nodo = pq.top();
        pq.pop();
        for (arco x : grafo[nodo.nodo]) {
            long long somma = nodo.peso + x.weight;
            if (somma < distances[x.to]) {
                pq.push(str(x.to, somma));
                distances[x.to] = somma;
            }
        }
    }

    cout << distances[end] << endl;
}