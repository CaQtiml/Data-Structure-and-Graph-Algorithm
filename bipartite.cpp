#include "bits/stdc++.h"
#define vi vector<int> 
#define INF -10
using namespace std;
int main()
{
	vector<vi> adj ;
	int n,m;
	cin >> n >> m;
	adj.assign(n+100,vi());
	vi color(n+100,INF);
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	queue<int>q;
	q.push(1);
	color[1]=0;
	bool bpt=true;
	while(!q.empty()&&bpt)
	{
		int u=q.front();
		q.pop();
		for(auto i : adj[u])
		{
			if(color[i]==INF)
			{
				color[i]=1-color[u];
				q.push(i);
			}
			else if(color[i]==color[u])
			{
				bpt=false;
				break;
			}
		}
	}
	(bpt==true) ? cout << "yes" : cout << "no";
	
}

//doesn't test with strong testcase
