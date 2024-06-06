#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define pii pair <int, int>
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int n,k;
cin>>n>>k;
vector < vector <int> > g(2e5);
for (int i=0;i<n;i++){
int x;
cin>>x;
int h=0;
while (x>0)
{
g[x].pb(h);
h++;
x/=2;
}
g[0].pb(h);
}
ll ans=INF;
for (int i=0;i<=2*(1e5);i++)
{
if (g[i].size()>=k)
{
sort(g[i].begin(),g[i].end());
ll sum=0;
for (int j=0;j<k;j++)
sum+=g[i][j];
ans=min(sum,ans);

}
}
cout<<ans;}