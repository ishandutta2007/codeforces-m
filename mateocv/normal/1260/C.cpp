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
		ll a,b,k; cin>>a>>b>>k;
		if(b<a)swap(a,b);
		ll g=__gcd(a,b);
		a/=g; b/=g;
		if((b-1+a-1)/a>=k){
			cout<<"REBEL\n";
		}else{
			cout<<"OBEY\n";
		}
	}
	
	return 0;
}