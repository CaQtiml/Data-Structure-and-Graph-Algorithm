#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9+29;
int adj[2000][2000];
int tc[2000][2000];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<2000;i++)
	{
		for(int j=0;j<2000;j++)
		{
			adj[i][j]=INF;
		}
		adj[i][i]=0;
	}
	for(int i=0;i<n;i++)
	{
		tc[i][i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		//directed graph
		int u,v,w;
		cin >> u >> v >> w;
		adj[u][v]=w;
		tc[u][v]=1;
	}

	
	
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				tc[i][j] = tc[i][j] || (tc[i][k]&&tc[k][j]) ;
			} 
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("APSP(%d,%d)=%d\n",i,j,adj[i][j]);
		}
		cout << "\n";
	}
	cout << "\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout <<  tc[i][j] << " ";
		}
		cout << "\n";
	}
}