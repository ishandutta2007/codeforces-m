/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int t,n,k;
int v[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>v[i];
		int ans=1;
		for(int i=1;i<=n-k;i++){
			int lmt=i-1;
			if(v[i]>i-1)ans=0;
			if(v[i]>0)continue;
			if(v[i]==0)ans=1ll*ans*(k+1)%mod;
			else ans=1ll*ans*(k+1+i-1)%mod;
		}
		for(int i=n-k+1;i<=n;i++)if(v[i]>0)ans=0;
		for(int i=1;i<=k;i++)ans=1ll*ans*i%mod;
		cout<<ans<<endl;
	}
	return 0;
}