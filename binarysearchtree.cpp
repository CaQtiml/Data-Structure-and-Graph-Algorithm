#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
typedef struct node
{
    int data;
    struct node *l,*r;
}node;
node* new_node(int x){
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=x;
    tmp->l=NULL;
    tmp->r=NULL;
    return tmp;
}
void insert(node* root,int data){
    node *walk = root;
    while(1){
        if(data<walk->data){
            printf("L");
            if(walk->l==NULL){walk->l=new_node(data);break;}
            else walk=walk->l;
        }
        else{
            printf("R");
            if(walk->r==NULL){walk->r=new_node(data);break;}
            else walk=walk->r;
        }
    }

}
int main(){
    node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(root==NULL){
            root = new_node(x);
            printf("*\n");
        }
        else insert(root,x),printf("*\n");
    }
}