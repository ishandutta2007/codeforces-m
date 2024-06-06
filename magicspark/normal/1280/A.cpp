/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
//500 pts
int T,x,ans;
char buf[200000];
string read(){
	scanf("%s",buf);return buf;
}
void modify(string &s,int &len,int pos,int t){
//	cerr<<t<<" "<<len-pos+1<<endl;
	int l=pos,r=len;
	while(t--){
		if(s.size()<=x){
			for(int i=l;i<=r;i++){
				s.push_back(s[i]);
			}
		}
		len+=r-l+1;len%=mod;len=(len+mod)%mod;
	}
}
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d",&x);
		string s=" "+read();
		ans=s.size()-1;
		for(int i=1;i<=x;i++){
			modify(s,ans,i+1,s[i]-'0'-1);
//			cerr<<i<<" "<<ans<<endl;
		}
//		cerr<<s<<endl;
		cout<<ans%mod<<endl;
	}
	return 0;
}