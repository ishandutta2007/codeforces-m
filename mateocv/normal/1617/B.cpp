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
		ll n; cin>>n;
		if(n%4==1)cout<<n/2-1<<" "<<n/2+1<<" 1\n";
		else if(n%4==3)cout<<n/2-2<<" "<<n/2+2<<" 1\n";
		else cout<<(n-1)/2<<" "<<n/2<<" 1\n";
	}
	
	return 0;
}