#include "bits/stdc++.h"
using namespace std;
int f[1000000];
void update(int idx,int value,int n)
{
    for(int i=idx;i<=n;i+=(i&(-i))) f[i]+=value; 
}
int query(int idx,int n)
{
    int sum=0;
    for(int i=idx;i>0;i-=(i&(-i))) sum+=f[i];
    return sum;
}
int main()
{
    int n;
    cin >> n; // array size
    for(int i=1;i<=n;i++) 
    {
        int num;
        cin >> num;
        update(i,num,n);
    }
    cout << query(n,n);  //query from array index 1 to n
}