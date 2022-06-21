#include <iostream>
#include <vector>

using namespace std;

typedef struct node_s {
	int xl; //startIndex
	int xr; //endIndex
	long long value;
	long long minValue;
	int nChildren;
} node;



void init(vector<long long> a);
void init(std::vector<long long> a, int xl, int xr, int currentIndex);

//Denoted by op = 1
long long get_sum(int l, int r);

//Denoted by op = 2
void add(int l, int r, long long x);

//Denoted by op = 3
void set_range(int l, int r, long long x);

//Denoted by op = 4
long long get_min(int l, int r);

//Denoted by op = 5
int lower_bound(int l, int r, long long x);










#include <vector>

vector<node> segTree;
int nDataElements;
node emptyNode = {-1, -1, 0, __LONG_LONG_MAX__, 0};

void init(std::vector<long long> a) {
	nDataElements = a.size();
	int segTreeSize = 1;
	while (segTreeSize < nDataElements)
		segTreeSize *= 2;
	
	segTree.assign(segTreeSize*2, emptyNode);
	init(a, 0, nDataElements-1, 0);
	printf("debugpoint");
}

void init(std::vector<long long> a, int xl, int xr, int currentIndex)  {
	//If out of Range
	if (xl > xr)
		return;

	//if only 1 element
	if (xl == xr) {
		segTree[currentIndex] = {xl, xr, a[xl], a[xl], 0};
		return;
	}

	//if more than 1 element, recur for left and right subtrees and calculate sum of both values
	int middleIndex = (xl+xr)/2;
	init(a, xl, middleIndex, currentIndex*2+1);
	init(a, middleIndex+1, xr, currentIndex*2+2);

	int value = segTree[currentIndex*2+1].value + segTree[currentIndex*2+2].value;
	int minValue = segTree[currentIndex*2+1].minValue < segTree[currentIndex*2+2].minValue ? segTree[currentIndex*2+1].minValue : segTree[currentIndex*2+2].minValue;
	segTree[currentIndex] = {segTree[currentIndex*2+1].xl, segTree[currentIndex*2+2].xr, value, minValue, segTree[currentIndex*2+1].nChildren + segTree[currentIndex*2+2].nChildren + 2};
}

long long get_sum(int l, int r) {
	return 42;
}

void add(int l, int r, long long x) {
	
}

void set_range(int l, int r, long long x) {
	
}

long long get_min(int l, int r) {
	return 42;
}

int lower_bound(int l, int r, long long x) {
	return 42;
}






































int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init(a);
	
	for (int i = 0; i < q; i++) {
		int op, l, r;
		long long x;
		cin >> op;
		cin >> l >> r;
		if (op == 2 or op == 3 or op == 5)
			cin >> x;
		if (op == 1) cout << get_sum(l, r) << "\n";
		if (op == 2) add(l, r, x);
		if (op == 3) set_range(l, r, x);
		if (op == 4) cout << get_min(l, r) << "\n";
		if (op == 5) cout << lower_bound(l, r, x) << "\n";
	}
	
	return 0;
}