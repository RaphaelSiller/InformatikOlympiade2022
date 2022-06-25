#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#define MAX 1000

using namespace std;


typedef struct node_s
{
    long long value;
    long long minValue = __LONG_LONG_MAX__;
} node_t;


node_t segTree[MAX] = {0};  // To store segment tree
node_t lazy[MAX] = {0};  // To store pending updates
int segTreeSize;


void init(std::vector<long long> arr);
void init(std::vector<long long> arr, int ss, int se, int si);

//Denoted by op = 1
long long get_sum(int l, int r);
long long getSumUtil(int ss, int se, int qs, int qe, int si);

//Denoted by op = 2
void add(int l, int r, long long x);
void add_util(int si, int ss, int se, int us, int ue, int diff);

//Denoted by op = 3
void set_range(int l, int r, long long x);

//Denoted by op = 4
long long get_min(int l, int r);
long long getMinUtil(int ss, int se, int qs, int qe, int si);

//Denoted by op = 5
int lower_bound(int l, int r, long long x);




void init(std::vector<long long> arr, int ss, int se, int si) {
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se) {
        segTree[si].value = arr[ss];
        segTree[si].minValue = arr[ss];
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    int mid = (ss + se)/2;
    init(arr, ss, mid, si*2+1);
    init(arr, mid+1, se, si*2+2);
    
    segTree[si].value = segTree[si*2 + 1].value + segTree[si*2 + 2].value;
    long long minValueL = segTree[si*2 + 1].minValue, minValueR = segTree[si*2 + 2].minValue;
    segTree[si].minValue = minValueL < minValueR ? minValueL : minValueR;

}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void init(std::vector<long long> arr) {
	segTreeSize = arr.size();
	// Fill the allocated memory st
    init(arr, 0, segTreeSize-1, 0);
}







long long get_sum(int l, int r) {
	return getSumUtil(0, segTreeSize-1, l, r-1, 0);
}

long long getSumUtil(int ss, int se, int qs, int qe, int si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si].value != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        segTree[si].value += (se-ss+1)*lazy[si].value;
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2+1].value += lazy[si].value;
            lazy[si*2+2].value += lazy[si].value;
        }
 
        // unset the lazy value for current node as it has
        // been updated
        lazy[si].value = 0;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)
 
    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return segTree[si].value;
 
    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}






void add(int l, int r, long long x) {
	add_util(0, 0, segTreeSize-1, l, r-1, x);
}

/*  si -> index of current node in segment tree
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void add_util(int si, int ss, int se, int us, int ue, int diff)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy[si].value != 0)
    {
        // Make pending updates using value stored in lazy
        // nodes
        segTree[si].value += (se-ss+1)*lazy[si].value;
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1].value   += lazy[si].value;
            lazy[si*2 + 2].value   += lazy[si].value;
        }
 
        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si].value = 0;
    }
 
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
 
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        segTree[si].value += (se-ss+1)*diff;
 
        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itself
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 + 1].value   += diff;
            lazy[si*2 + 2].value   += diff;
        }
        return;
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
    int mid = (ss+se)/2;
    add_util(si*2+1, ss, mid, us, ue, diff);
    add_util(si*2+2, mid+1, se, us, ue, diff);
 
    // And use the result of children calls to update this
    // node
    segTree[si].value = segTree[si*2+1].value + segTree[si*2+2].value;
}






void set_range(int l, int r, long long x) {
	
}

long long get_min(int l, int r) {
	return getMinUtil(0, segTreeSize - 1, l, r-1, 0);
}

// A recursive function to get the max of values in given
// a range of the array. The following are the parameters
// for this function
// si --> Index of the current node in the segment tree
// Initially, 0 is passed as root is always at index 0
// ss & se --> Starting and ending indexes of the
// segment represented by current node
// i.e., tree[si]
// qs & qe --> Starting and ending indexes of query
// range
long long getMinUtil(int ss, int se, int qs, int qe, int si)
{
 
    // If lazy flag is set for current node of segment tree
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si].value != 0) {
 
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        segTree[si].value += lazy[si].value;
 
        // Checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se) {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si * 2 + 1].value += lazy[si].value;
            lazy[si * 2 + 2].value += lazy[si].value;
        }
 
        // Unset the lazy value for current node as it has
        // been updated
        lazy[si].value = 0;
    }
 
    // Out of range
    if (ss > se || ss > qe || se < qs)
        return __LONG_LONG_MAX__;
 
    // At this point, we are sure that pending lazy updates
    // are done for current node. So we can return value
    // (same as it was for a query in our previous post)
 
    // If this segment lies in range
    if (ss >= qs && se <= qe)
        return segTree[si].minValue;
 
    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se) / 2;
    return min(getMinUtil(ss, mid, qs, qe, 2 * si + 1), getMinUtil(mid + 1, se, qs, qe, 2 * si + 2));
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