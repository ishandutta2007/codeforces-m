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
		ll n,a,b; cin>>n>>a>>b;
		ll c[a],d[b];
		fore(i,0,a)cin>>c[i];
		fore(i,0,b)cin>>d[i];
		ll br=0;
		fore(i,0,a){
			if(c[i]==n){
				cout<<"YES\n"; br++; break;
			}
		}
		if(br)continue;
		cout<<"NO\n";
	}
	
	return 0;
}