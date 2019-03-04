#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
    }
    int fs(int i) //findset
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j) //issameset
    {
        return (fs(i)==fs(j));
    }
    void us(int i,int j) //unionset
    {
        
        p[fs(i)]=fs(j);
    }
};
vector<pair<int,ii> > v;
int main()
{
    int n,m;
    cin >> n >> m;
    // n= number of Node
    // m= number of edge
    UnionFind uf(n+5);
    while(m--)
    {
        int x,y,w;
        cin >> x >> y >> w;
        v.pb(mkp(w,mkp(x,y)));
    }
    sort(all(v));
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        int x,y;
        int w;
        w=v[i].F;
        x=v[i].S.F;
        y=v[i].S.S;
        if(!uf.iss(x,y))
        {
            uf.us(x,y);
            //printf("==%d\n",w);
            ans+=w;
        }
    }
    printf("%d\n",ans);

}
/*
    kruskal algo
    5 7
      0 1 4
      0 2 4
      0 3 6
      0 4 6
      1 2 2
      2 3 8
      3 4 9
*/
