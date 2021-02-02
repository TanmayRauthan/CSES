#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007 
using namespace std;
#define pll pair<ll,ll>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    fast;
    ll n,m,i,j,t=1,k,d;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m;
        list<int> v[n+1];
        int l,r;
        for(i=0;i<m;i++)
        {
            cin>>l>>r;
            v[l].push_back(r);
            v[r].push_back(l);
        }
        vector<bool> visi(n+1,false);
        vector<int> p(n+1);
        queue<int> q;
        q.push(1);
        visi[1]=true;
        while(!q.empty())
        {
            int u=q.front();
            list<int>::iterator it;
            q.pop();
            if(u==n)
                break;
            for(it=v[u].begin();it!=v[u].end();it++)
            {
                if(visi[*it]==false)
                {
                    q.push(*it);
                    p[*it]=u;
                    visi[*it]=true;
                }
            }
        }
        if(visi[n]==false)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            int u=n;
            vector<int> ar;
            int cnt=1;
            ar.push_back(u);
            while(u!=1)
            {
                cnt++;
                u=p[u];
                ar.push_back(u);
            }
            cout<<cnt<<endl;
            while(cnt>=1)
            {
                cout<<ar[cnt-1]<<" ";
                cnt--;
            }
        }
    }
}
