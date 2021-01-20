#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007 
using namespace std;
#define pll pair<ll,ll>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
bool v[1001][1001];
ll n,m;
bool check(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||v[i][j]==1)
        return false;
    return true;
}
void dfs(vector<int> dx,vector<int> dy,int i,int j)
{
    v[i][j]=1;
    for(int k=0;k<4;k++)
    {
        if(check(i+dx[k],j+dy[k]))
        {
            //cout<<i+dx[k]<<" "<<j+dy[k]<<endl;
            dfs(dx,dy,i+dx[k],j+dy[k]);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    fast;
    ll i,j,t=1,k,d;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m;string s;
        for(i=0;i<n;i++)
        {
            cin>>s;
            for(j=0;j<m;j++)
            {
                if(s[j]=='.')
                    v[i][j]=0;
                else
                    v[i][j]=1;
            }
        }
        vector<int> dx(4),dy(4);int cnt=0;
        dx={0,0,1,-1};
        dy={-1,1,0,0};
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {   
                if(v[i][j]!=1&&check(i,j))
                {
                    //cout<<"s "<<i<<" "<<j<<endl;
                    cnt++;
                    dfs(dx,dy,i,j);
                }
            }
        }
        cout<<cnt;
    }
}
