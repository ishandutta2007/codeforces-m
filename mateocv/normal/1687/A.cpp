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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll cant=min(n,k);
		ll maxi=0,va=0;
		fore(i,0,cant)va+=a[i];
		maxi=va;
		fore(i,cant,n){
			va+=a[i]-a[i-cant];
			maxi=max(maxi,va);
		}
		fore(i,0,cant)maxi+=k-1-i;
		cout<<maxi<<"\n";
	}
	
	return 0;
}