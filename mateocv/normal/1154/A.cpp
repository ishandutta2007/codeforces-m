#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll a,b,c,d; cin>>a>>b>>c>>d;
	ll m=max(max(a,b),max(c,d));
	if(m-a>0)cout<<m-a<<" ";
	if(m-b>0)cout<<m-b<<" ";
	if(m-c>0)cout<<m-c<<" ";
	if(m-d>0)cout<<m-d<<" ";
	return 0;
}