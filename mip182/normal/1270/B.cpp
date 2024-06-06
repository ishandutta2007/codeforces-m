#include <bits/stdc++.h>
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
    int n;
    cin>>n;
    vector <ll> a(n);
    rep(i,n)
    cin>>a[i];
    pair <int,int> ans={-1,-1};
    for (int i=0;i<n-1;i++)
    {
        if (abs(a[i]-a[i+1])>=2) {
            ans = {i, i+1};
            break;
        }
    }

    if (ans.first==-1)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        cout<<ans.first+1<<" "<<ans.second+1<<'\n';
    }


    }







}