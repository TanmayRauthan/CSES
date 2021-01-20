#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007 
using namespace std;
#define pll pair<ll,ll>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
bool v[1001][1001];
int pre[1001][1001];
ll n,m;
class dist{
public:
    ll a,b,di;
    dist(ll p,ll q,ll d)
    {
        a=p,b=q,di=d;
    }
};
bool check(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||v[i][j]==1)
        return false;
    return true;
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
        dist source(0,0,0),end(0,0,0);
        for(i=0;i<n;i++)
        {
            cin>>s;
            for(j=0;j<m;j++)
            {
                if(s[j]=='#')
                    v[i][j]=1;
                else if(s[j]=='A')
                {
                    source.a=i;source.b=j;
                }
                else if(s[j]=='B')
                {
                    end.a=i;end.b=j;
                }
                else
                    v[i][j]=0;
            }
        }
        vector<int> dx(4),dy(4);
        dx={0,0,1,-1};
        dy={-1,1,0,0};
        queue<dist> q;
        q.push(source);
        v[source.a][source.b]=1;
        ll x,y,z;
        while(!q.empty())
        {
            x=q.front().a;
            y=q.front().b;
            z=q.front().di;
            if(x==end.a&&y==end.b)
            {
                cout<<"YES\n"<<z<<endl;
                break;
            }
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(check(x+dx[k],y+dy[k]))
                {
                    q.push(dist(x+dx[k],y+dy[k],z+1));
                    v[x+dx[k]][y+dy[k]]=1;
                    pre[x+dx[k]][y+dy[k]]=k;
                }
            }
        }
        if(q.empty())
        {
            cout<<"NO";
            break;
        }
        vector<char> ar(z);
        z--;
        while((end.a!=source.a||end.b!=source.b)&&z>=0)
        {
            if(pre[end.a][end.b]==0)
            {
                ar[z]='L';
                end.b=end.b+1;
            }
            else if(pre[end.a][end.b]==1)
            {
                ar[z]='R';
                end.b=end.b-1;
            }
            else if(pre[end.a][end.b]==2)
            {
                ar[z]='D';
                end.a=end.a-1;
            }
            else
            {
                ar[z]='U';
                end.a=end.a+1;
            }
            z--;
        }
        for(i=0;i<ar.size();i++)
            cout<<ar[i];
    }
}
