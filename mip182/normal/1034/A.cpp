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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

const ll INFLL = 1e18;
const int MAXN = 15000000+1;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
int p[MAXN];

void solve()
{
    p[1]=1;
    for (int i=2;i<MAXN;i++)
    {
        if (p[i])
            continue;
        p[i]=i;
        for (ll j=1ll*i*i;j<MAXN;j+=i)
            p[j]=(p[j]==0?i:min(p[j],i));
    }
    int n;
    cin>>n;
    vector <int> a(n);
    in(a);
    {
        int y = 0;
        for (auto to:a)
            y = __gcd(to, y);
        for (auto &to:a)
            to /= y;
    }
    map<int,int> m;
    rep(i,n){
        int x=a[i];
        while (x>1)
        {
            int y=p[x];
            m[y]++;
            while (x%y==0)
                x/=y;
        }
    }
    int x=0;
    for (auto to:m) {
        x = max(x, to.se);
    }
    cout<<(n-x==n?-1:n-x)<<'\n';
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}