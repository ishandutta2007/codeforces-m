#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll b[n];
	fore(i,0,n)cin>>b[i];
	ll maxi=0;
	ll a[n];
	fore(i,0,n){
		a[i]=b[i]+maxi;
		maxi=max(maxi,a[i]);
	}
	fore(i,0,n)cout<<a[i]<<" ";
	return 0;
}