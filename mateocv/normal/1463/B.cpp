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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll s=0;
		fore(i,0,n)s+=a[i];
		ll res[2]={0,0};
		fore(i,0,n){
			res[i&1]+=abs(a[i]-1);
		}
		assert(2ll*min(res[0],res[1])<=s);
		if(res[0]<res[1]){
			fore(i,0,n){
				if(i%2==0)cout<<"1 ";
				else cout<<a[i]<<" ";
			}
		}else{
			fore(i,0,n){
				if(i%2==1)cout<<"1 ";
				else cout<<a[i]<<" ";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}