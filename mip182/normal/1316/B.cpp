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
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
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
        string s;
        cin>>s;
        set <pair <string,int> > ss;
        for (int i=1;i<n;i++)
        {

                string p="";
                if ((n-i)%2==0)
                {
                    for (int j=i-1;j<n;j++)
                        p+=s[j];
                    for (int j=i-2;j>=0;j--)
                        p+=s[j];
                }
                else
                {
                    for (int j=i-1;j<n;j++)
                        p+=s[j];
                    for (int j=0;j<i-1;j++)
                        p+=s[j];
                }
                ss.insert({p,i});
        }
        reverse(all(s));
        ss.insert({s,n});
        cout<<(*ss.begin()).fi<<'\n'<<(*ss.begin()).se<<'\n';

    }




}