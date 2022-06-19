#include <iostream>
#include <vector>

using namespace std;

typedef struct node_s {
	struct node_s *nodel;
	struct node_s *noder;
	int xl;
	int xr;
	long long value;
	long long minValue;
} node_t;

void init(vector<long long> a);

//Denoted by op = 1
long long get_sum(int l, int r);
long long get_sum(int l, int r, node_t *node);

//Denoted by op = 2
void add(int l, int r, long long x);
void add(int l, int r, long long x, node_t *node);

//Denoted by op = 3
void set_range(int l, int r, long long x);
void set_range(int l, int r, long long x, node_t *node);

//Denoted by op = 4
long long get_min(int l, int r);
long long get_min(int l, int r, node_t *node);

//Denoted by op = 5
int lower_bound(int l, int r, long long x);
int lower_bound(int l, int r, long long x, node_t *node);


#include <vector>


std::vector<std::vector<node_t>> tree;


void init(std::vector<long long> a) {
	int dataSize = a.size();
	//add first level
	std::vector<node_t> newLevel;
	for (int i = 0; i < dataSize; i++) { //Create leaf nodes
		node_t node_t = {nullptr, nullptr, i, i, a[i], a[i]};
		newLevel.push_back(node_t);
	}

	if (newLevel.size() % 2) { //if odd  number of nodes in this level, add empty node
		node_t node_t = {nullptr, nullptr, dataSize, dataSize, 0, INT32_MAX};
		newLevel.push_back(node_t);
	}
	
	tree.push_back(newLevel);

	//Construct the remaining levels
	while (tree[0].size() > 1) { //While root hasn't been reached
		newLevel.clear();
		for (int i = 0; i < tree[0].size(); i+=2) {
			int xr = tree[0][i+1].xr >= 0 ? tree[0][i+1].xr : tree[0][i].xr; // Ignore empty nodes
			int minValue = tree[0][i].minValue < tree[0][i+1].minValue ? tree[0][i].minValue : tree[0][i+1].minValue; //Find the minValue
			node_t node = {&tree[0][i], &tree[0][i+1], tree[0][i].xl, xr, tree[0][i].value + tree[0][i+1].value, minValue};
			newLevel.push_back(node);
		}
		
		if (newLevel.size() % 2 && tree[0].size() > 2) { //if odd  number of nodes in this level, add empty node
			node_t node = {nullptr, nullptr, -1, -1, 0, INT32_MAX};
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

long long get_sum(int l, int r, node_t *node) {
	if (l <= node->xl && r > node->xr) //If completely within, return node value
		return node->value;

	if (l > node->xr || r <= node->xl) //if completely outside, return 0
		return 0;

	return get_sum(l, r, node->nodel) + get_sum(l, r, node->noder); //Continue to go deeper
}

void add(int l, int r, long long x) {
	add(l, r, x, &tree[0][0]);
}

void add(int l, int r, long long x, node_t *node) {
	if (!(l > node->xr || r <= node->xl)) { // if there's something to change
		if(node->xl == node->xr) { // if on last Level
			node->value += x;
			node->minValue = node->value;
		} else { //else go deeper

			add(l, r, x, node->nodel);
			add(l, r, x, node->noder);

			node->minValue = node->nodel->minValue < node->noder->minValue ? node->nodel->minValue : node->noder->minValue;
			node->value = node->nodel->value + node->noder->value;
		}
	}
	
}

void set_range(int l, int r, long long x) {
	set_range(l, r, x, &tree[0][0]);
}

void set_range(int l, int r, long long x, node_t *node) {
	if (!(l > node->xr || r <= node->xl)) { // if there's something to change
		
		if (l <= node->xl && r > node->xr) { //If completely within, return node value
			if(node->xl == node-> xr) { // if on last Level
				node->value = x;
				node->minValue = x;
			} else { //else go deeper
				node->value = 2*x;
				node->minValue = x;
				set_range(l, r, x, node->nodel);
				set_range(l, r, x, node->noder);
			}

		} else { //else go deeper
			set_range(l, r, x, node->nodel);
			set_range(l, r, x, node->noder);
			node->minValue = node->nodel->minValue < node->noder->minValue ? node->nodel->minValue : node->noder->minValue;
			node->value = node->nodel->value + node->noder->value;
		}
	}
}

long long get_min(int l, int r) {
	return get_min(l, r, &tree[0][0]);
}

long long get_min(int l, int r, node_t *node) {
	if (l <= node->xl && r > node->xr) //If completely within, return node value
		return node->minValue;

	if (l > node->xr || r <= node->xl) //if completely outside, return 0
		return INT32_MAX;

	//Continue to go deeper
	int minValueL = get_min(l, r, node->nodel);
	int minValueR = get_min(l, r, node->noder);
	return minValueL < minValueR ? minValueL : minValueR;
}

int lower_bound(int l, int r, long long x) {
		return lower_bound(l, r, x, &tree[0][0]);
}

int lower_bound(int l, int r, long long x, node_t *node) {
	if (l > node->xr || r <= node->xl) //if completely outside, return -1
		return -1;
	
	if (node->xl == node->xr) //If leaf node return index
		return node->xl;
	
	int ret;
	if(node->nodel->minValue < x && (ret = lower_bound(l, r, x, node->nodel)) >= 0 ) //if left node is correct
		return ret;
	else
		return node->noder->minValue < x ? lower_bound(l, r, x, node->noder) : -1;
}