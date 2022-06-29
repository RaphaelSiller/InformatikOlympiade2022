#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//fenwick tree( a.k.a Binary Index Tree)

// update function is to update the value at a particular index in BIT
void update(int index, int value, int * BIT, int n) {
   for(; index<=n; index += index &(-index)) {
      BIT[index] += value;
   }
} 

int query(int index,int *BIT) {
  int sum=0;
  for(; index > 0; index -= index &(-index)) {
    sum += BIT[index];
  }
  return sum;
}

int main() {
   int n;
   cin>>n;

   int *arr=new int[n+1]();
   
   int *BIT=new int[n+1]();

   for(int i=1;i<=n;i++)
   {
     cin>>arr[i];
     update(i,arr[i],BIT,n);
   }

   //Queries
   cout<<"sum of first 5 elements"<<" "<<query(5,BIT)<<endl;
   cout<<"sum from 2nd index to 6th index"<<" "<<query(6,BIT)-query(1,BIT)<<endl;
   



 return 0;
}

int make