#include "bits/stdc++.h"
#define vi vector<int>
using namespace std;
stack<int> ts;
vector<vi> e;
bool visit[100000];

void dfs(int u)
{
	visit[u]=true;
	for(auto c : e[u])
	{
		if(visit[c]==false) dfs(c);
	}
	ts.emplace(u);
}

int main(){
	for(int i=0;i<100000;i++)
	{
		visit[i]=false;
	}
	e.assign(100000,vi());
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].emplace_back(b);
		//e[b].emplace_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			dfs(i);
		}
	}
	while(!ts.empty())
	{
		printf("%d",ts.top());
		ts.pop();
	}
}

/*
SAMPLE TESTCASE1
6 7
0 1
0 2
1 2
1 3
2 3
3 4
2 5
OUTPUT : 012534
*/

//This code is not tested by strong testcase