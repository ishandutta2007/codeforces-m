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
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;

void solve()
{
    int n,q;
    cin>>n>>q;
    vector <int> a(n);
    in(a);
    ll now_sum=0;
    ll now_max=0;
    vector <pair <ll,int> > b;
    for (int i=0;i<n;i++)
    {
        now_sum+=a[i];
        if (now_max<now_sum)
            b.pb({now_sum,i}),now_max=now_sum;
    }
    ll total=now_sum;
    while (q--)
    {
        ll val;
        cin>>val;
        if (now_sum<=0)
        {
            if (val>now_max)
            {
                cout<<-1<<' ';
            }
            else
            {
                auto to=lower_bound(all(b),mp(val,-1));
                cout<<(*to).se<<' ';
            }
        }
        else
        {
            if (val<=now_max)
            {
                auto to=lower_bound(all(b),mp(val,-1));
                cout<<(*to).se<<' ';
            }
            else
            {
                ll g=(val-now_max+now_sum-1)/now_sum;
                ll ans=g*n;
                val-=g*now_sum;
                auto to=lower_bound(all(b),mp(val,-1));
                cout<<ans+(*to).se<<' ';
            }
        }
    }
    cout<<'\n';
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
    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}