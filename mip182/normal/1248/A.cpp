#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define sz(x) (int)x.size()

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int t;
cin>>t;
rep(jj,t)
{
ll n;
cin>>n;
ll cnt1=0,cnt2=0;
for (int i=0;i<n;i++)
{
int x;
cin>>x;
if (x%2==0)
cnt1++;
}
ll m;
cin>>m;
for (int i=0;i<m;i++)
{
    int x;
    cin>>x;
    if (x%2==0)
    cnt2++;
}
cout<<cnt1*cnt2+(n-cnt1)*(m-cnt2)<<endl;
}}