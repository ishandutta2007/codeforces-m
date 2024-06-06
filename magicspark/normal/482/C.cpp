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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
double dp[1<<20];
int n,m;
ll ban[1<<20];
string s[55];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	m=s[1].size();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int mask=0;
			for(int k=0;k<m;k++){
				if(s[i][k]==s[j][k]){
					mask|=(1ll<<k);
				}
			}
			ban[mask]|=(1ll<<i)|(1ll<<j);
		}
	}
	for(int mask=(1<<m)-1;mask>=0;mask--){
		for(int j=0;j<m;j++)ban[mask]|=ban[mask|(1<<j)];
		double sum=0.0;int cnt=0;
		for(int j=0;j<m;j++){
			if(!(mask&(1<<j))){
				sum+=dp[mask|(1<<j)];
				cnt++;
			}
		}
		if(cnt>0)dp[mask]=sum/cnt;
		else dp[mask]=0;
		dp[mask]+=(double)__builtin_popcountll(ban[mask])/n;
	}
	cout<<setprecision(15);
	cout<<dp[0]<<endl;
	return 0;
}