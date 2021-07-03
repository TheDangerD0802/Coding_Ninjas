#include<bits/stdc++.h>
using namespace std;
vector<int> mp[1000001];
unordered_map<int,int>visit;
void solve(int a, int b)
{
    vector<int>ans;
    queue<int>q;
    visit[a]=1;
    q.push(a);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        for(int i:mp[y])
        {
            if(visit[i]==0)
            {
                if(i==b)
                ans.push_back(y);
                else 
                {
                    visit[i]=1;
                    q.push(i);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i:ans)
    cout<<i<<" ";
}
int main()
{
  
    int n,m,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        mp[a]={};
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        mp[a].push_back(b);
    }
    cin>>a>>b;
    solve(a,b);
}