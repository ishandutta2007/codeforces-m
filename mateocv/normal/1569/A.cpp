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
		string s; cin>>s;
		ll br=0;
		fore(i,0,n-1){
			if(s[i]!=s[i+1]){
				cout<<i+1<<" "<<i+2<<"\n";
				br++; break;
			}
		}
		if(!br)cout<<"-1 -1\n";
	}
	
	return 0;
}