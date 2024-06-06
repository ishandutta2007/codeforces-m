//#define _GLIBCXX_DEBUG
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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


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
        string s;
        cin>>s;
        map <pair <pii,pii> ,bool> m;
        int x=0,y=0;
        int n=s.size();
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='N')
            {
                if (m.find({{x,y},{x,y+1}})!=m.end())
                    cnt++;
                else
                    m[{{x,y},{x,y+1}}]=true,m[{{x,y+1},{x,y}}]=true,cnt+=5;
                y++;
            }
            if (s[i]=='S')
            {
                if (m.find({{x,y},{x,y-1}})!=m.end())
                    cnt++;
                else
                    m[{{x,y},{x,y-1}}]=true,m[{{x,y-1},{x,y}}]=true,cnt+=5;
                y--;
            }
            if (s[i]=='E')
            {
                if (m.find({{x,y},{x+1,y}})!=m.end())
                    cnt++;
                else
                    m[{{x,y},{x+1,y}}]=true,m[{{x+1,y},{x,y}}]=true,cnt+=5;
                x++;
            }
            if (s[i]=='W')
            {
                if (m.find({{x,y},{x-1,y}})!=m.end())
                    cnt++;
                else
                    m[{{x,y},{x-1,y}}]=true,m[{{x-1,y},{x,y}}]=true,cnt+=5;
                x--;
            }
        }
        cout<<cnt<<'\n';
    }


}