#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define module 1000000007
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);                        
#define bs binary_search
#define mp make_pair
#define endl '\n'
#define Endl '\n'

#define vi vector<int>
#define vll vector<long long>
#define ss string

#define mi map<int,int>
#define mll map<long long,long long>
#define mb map<int,bool>
#define ms map<string,int>
#define map1 unordered_map<ll,ll>
#define cmap unordered_map<char,int>

#define dev(x) cout<<x<<endl
#define dev2(x,y) cout<<x<<" "<<y<<endl
#define dev3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define read(x) cin>>x;
#define read2(x,y) cin>>x>>y;

struct node{
	int u,v;
};

int findParent(int v,int* parent)
{
	if(v==parent[v])
		return v;
	
	// compression
	parent[v] = findParent(parent[v],parent);	
	return parent[v];
}

bool findcycle(node* edges,int n,int e)
{
	// find cycle Using : Union find Algorithm
	int i,p1,p2;
	
	int* parent=new int[n+3];
	int* rank=new int[n+3]();
	
	for(i=0;i<n;i++)
		parent[i]=i;
		
	for(i=0;i<e;i++)
	{
		p1=findParent(edges[i].u, parent);
		p2=findParent(edges[i].v, parent);
		
		if(p1==p2)
			return true;
		
		// rank
		if(rank[p1]==rank[p2])
		{
			rank[p1]++;
			parent[p2]=p1;
		}
		else if( rank[p1] > rank[p2])
		{
			parent[p2]=p1;
		}
		else
		{
			parent[p2]=p1;
		}
	}
	return false;
}

int main()
{
	ll i,j,n,q,y,t,x,p,e;
	cin>>n>>e;
	
	node* edges=new node[e+2];
	for(i=0;i<e;i++)
		cin>>edges[i].u>>edges[i].v;
	
	bool isCycle = findcycle(edges,n,e);
	if(isCycle)
		cout<<"Yes, Cycle is Present";
	else
		cout<<"No, Cycle is not Present";
			
	cout<<endl;
}
