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
		ll n,c; cin>>n>>c;
		map<ll,ll> mp;
		fore(i,0,n){
			ll x; cin>>x;
			mp[x]++;
		}
		ll res=0;
		for(auto i:mp)res+=min(i.snd,c);
		cout<<res<<"\n";
	}
	
	return 0;
}