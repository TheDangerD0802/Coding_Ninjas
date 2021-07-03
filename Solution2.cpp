#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp ;
void print(int dest)
{
    if(mp[dest]==INT_MAX)
	    cout<<"-1"<<endl;
	else
	    cout<<mp[dest]<<endl;
}
void solve(int src, int dest ,vector<pair<int,int>>adj[])
{
    set<pair<int,int>>s;
	mp[src]=0;
	s.insert({0,src});
	while(!s.empty()){
	    pair<int,int>tmp=*(s.begin());
	    s.erase(s.begin());
	    int u=tmp.second;
	    for(auto i=adj[u].begin();i!=adj[u].end();++i){
	        int v=(*i).first;
	        int weight=(*i).second;
	        int temp = mp[u]+weight;
	        if(mp[v]>temp){
	            if(mp[v]!=INT_MAX)
	                s.erase(s.find({mp[v],v}));
	            mp[v]=temp;
	            s.insert({mp[v],v});
	        }
	    }
	}
	print(dest);
	
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		mp[x]=INT_MAX;
	}
	int e;
	cin>>e;
	vector<pair<int,int>>adj[1000001];
	while(e--){
		int x,y,d;
		cin>>x>>y>>d;
		adj[x].push_back({y,d});
}
	int src,dest;
	cin>>src>>dest;
	solve(src,dest,adj);
	return 0;
}