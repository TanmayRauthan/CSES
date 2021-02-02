#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007 
using namespace std;
#define pll pair<ll,ll>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
vector<ll> p;
ll finds(ll a)
{
    if(p[a]<0)
        return a;
    return p[a]=finds(p[a]);
}
void unions(ll a,ll b)
{
    if(p[a]<p[b])
    {
        p[a]+=p[b];
        p[b]=a;
    }
    else
    {
        p[b]+=p[a];
        p[a]=b;
    }
}
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
        p.resize(n+1,-1);
        ll l,r,cnt=0;
        for(i=0;i<m;i++)
        {
            cin>>l>>r;
            ll a=finds(l);
            ll b=finds(r);
            if(a!=b)
                unions(a,b);
        }
        vector<ll> ar;
        for(i=1;i<=n;i++)
        {
            if(p[i]<0)
            {
                cnt++;//cout<<i<<p[i]<<" "<<" ";
                ar.push_back(i);
            }
        }
        cout<<cnt-1<<endl;
        ll st=ar[0];
        for(i=1;i<ar.size();i++)
            cout<<st<<" "<<ar[i]<<endl;
    }
}
