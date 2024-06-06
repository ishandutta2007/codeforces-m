#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int par[MAXN],sz[MAXN];
void make_set(int s)
{
    par[s]=s;
    sz[s]=1;
}
int find_set(int s)
{
    if (par[s]==s)
        return s;
    return par[s]=find_set(par[s]);
}
void union_sets(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if (u!=v)
    {
       if (sz[u]<sz[v])
           swap(u,v);
       par[v]=u;
       sz[u]+=sz[v];
    }
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for (auto to:s)
    {
        if (to=='R')
            cnt++;
    }
    if (cnt==n||cnt==0)
    {
        int ans=1;
        cout<<1+(n-1)/3<<'\n';
        return;
    }
    int ans=0;
    for (int i=0;i<n;i++)
        make_set(i);
    for (int i=0;i<n;i++)
    {
        if (s[(i-1+n)%n]==s[i])
            union_sets((i-1+n)%n,i);
        if (s[(i+1)%n]==s[i])
            union_sets((i+1)%n,i);
    }
    for (int i=0;i<n;i++)
    {
        if (find_set(i)==i) {
            if (sz[i]<3)
                continue;
            ans+=sz[i]/3;
        }
    }

    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    cin>>_t;
//    _t=1;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}