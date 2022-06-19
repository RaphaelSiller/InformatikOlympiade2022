#include <iostream>
#include <vector>

using namespace std;

typedef struct segment_s {
	struct segment_s *segl;
	struct segment_s *segr;
	int xl;
	int xr;
	long long value;
	long long maxValue; //TODO implement maxValue
} segment;

void init(vector<long long> a);
long long get_sum(int l, int r);
long long get_sum(int l, int r, segment *seg);
void add(int l, int r, long long x);
void set_range(int l, int r, long long x);
long long get_min(int l, int r);
int lower_bound(int l, int r, long long x);











#include <vector>



std::vector<std::vector<segment>> tree;


void init(std::vector<long long> a) {
	int dataSize = a.size();
	//add first level
	std::vector<segment> newLevel;
	for (int i = 0; i < dataSize; i++) {
		segment node = {nullptr, nullptr, i, i, a[i], a[i]};
		newLevel.push_back(node);
	}

	if (newLevel.size() % 2) { //if odd  number of nodes in this level, add empty node
		segment node = {nullptr, nullptr, dataSize, dataSize, 0, INT32_MIN};
		newLevel.push_back(node);
	}
	
	tree.push_back(newLevel);

	//Construct the remaining levels
	while (tree[0].size() > 1) { //While root hasn't been reached
		int aofijhof = tree[0].size();
		newLevel.clear();
		for (int i = 0; i < tree[0].size(); i+=2) {
			int xr = tree[0][i+1].xr >= 0 ? tree[0][i+1].xr : tree[0][i].xr;
			int maxValue = tree[0][i].maxValue > tree[0][i+1].maxValue ? tree[0][i].maxValue : tree[0][i+1].maxValue;
			segment node = {&tree[0][i], &tree[0][i+1], tree[0][i].xl, xr, tree[0][i].value + tree[0][i+1].value, maxValue};
			newLevel.push_back(node);
		}
		
		if (newLevel.size() % 2 && tree[0].size() > 2) { //if odd  number of nodes in this level, add empty node
			segment node = {nullptr, nullptr, -1, -1, 0, INT32_MIN};
			newLevel.push_back(node);
		}
		// printf("Debugpoint");
		tree.insert(tree.begin(), newLevel);
	}
	// printf("Debugpoint");
}

long long get_sum(int l, int r) {
	
	return get_sum(l, r, &tree[0][0]);
}

long long get_sum(int l, int r, segment *seg) {
	if (l <= seg->xl && r > seg->xr) //If completely within, return node value
		return seg->value;

	if (l > seg->xr || r <= seg->xl) //if completely outside, return 0
		return 0;

	return get_sum(l, r, seg->segl) + get_sum(l, r, seg->segr); //Continue to go deeper
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