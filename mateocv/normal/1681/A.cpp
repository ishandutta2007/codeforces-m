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
		ll n,m; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		cin>>m;
		vector<ll> b(m);
		fore(i,0,m)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b));
		ll maxi=max(a.back(),b.back());
		cout<<((a.back()==maxi)?"Alice\n":"Bob\n");
		cout<<((b.back()==maxi)?"Bob\n":"Alice\n");
	}
	
	return 0;
}