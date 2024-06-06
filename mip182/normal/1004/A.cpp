#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,d;
    cin>>n>>d;
    vector <int> x(n);
    rep(i,n)
    cin>>x[i];
    sort(all(x));
    ll ans=0;
    for (int i=0;i<n-1;i++)
    {
        if (x[i+1]-x[i]>=2*d) {
            ans+=2;
            if ((x[i+1]-x[i])==2*d)
                ans--;
        }
    }
    cout<<ans+2;
}