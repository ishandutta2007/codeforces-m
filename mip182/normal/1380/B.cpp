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
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    cin>>_t;
    while (_t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        int R=0,P=0,S=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='R')
                P++;
            else if (s[i]=='P')
                S++;
            else
                R++;
        }
        if (R>=P&&R>=S)
        {
            for (int i=0;i<n;i++)
                cout<<'R';
            cout<<'\n';
        }
        else
        {
            if (P>=R&&P>=S)
            {
                for (int i=0;i<n;i++)
                    cout<<'P';
                cout<<'\n';
            }
            else
            {
                for (int i=0;i<n;i++)
                    cout<<'S';
                cout<<'\n';
            }
        }

    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}