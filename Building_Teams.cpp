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
        vector<int> p(n+1);bool f=0;
        queue<int> q;
        for(i=1;i<=n;i++)
        {
        f=0;
        if(visi[i]==false)
        {//cout<<endl;cout<<i<<"- ";
            q.push(i);
            p[i]=1;
            visi[i]=true;
        while(!q.empty())
        {
            int u=q.front();//cout<<u<<" ";
            list<int>::iterator it;
            q.pop();
            for(it=v[u].begin();it!=v[u].end();it++)
            {
                if(visi[*it]==true&&p[*it]==p[u])
                {
                    f=1;
                    break;
                }
                else if(visi[*it]==false)
                {
                    q.push(*it);
                    visi[*it]=true;
                    if(p[u]==1)
                        p[*it]=2;
                    else
                        p[*it]=1;
                }
            }
            if(f)
                break;
        }
        if(f)
            break;
    }
}
        if(f)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            for(i=1;i<=n;i++)
                cout<<p[i]<<" ";
        }
    }
}
