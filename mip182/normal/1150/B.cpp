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
int n;
cin>>n;
vector <string> s(n);
for (int i=0;i<n;i++)
cin>>s[i];
bool ok=true;
for (int i=0;i<n-2;i++)
{
for (int j=1;j<n-1;j++)
{
if (s[i][j]=='.')
{
if (s[i][j]=='.'&&s[i+1][j]=='.'&&s[i+2][j]=='.'&&s[i+1][j-1]=='.'&&s[i+1][j+1]=='.')
{
    s[i][j]='#'; s[i+1][j]='#'; s[i+2][j]='#';s[i+1][j-1]='#';s[i+1][j+1]='#';
}
else
ok=false;
}
}
}
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    {
        if (s[i][j]=='.')
        ok=false;
    }
}
if (ok)
cout<<"YES";
else
cout<<"NO";
}