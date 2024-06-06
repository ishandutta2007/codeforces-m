/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
inline int Rand(){return rand()*32768+rand();}
int n,x,tmp[1005],S,full;
char s[1005];
unordered_map<int,int>dp[1005];
bool good(int xx){
	if(~xx&(1<<x))return 1;
	if(xx&full)return 1;
	return 0;
}
int dfs(int x,int mask){
	if(x==n)return 0;
	mask&=S;
	int lmt=mask&full;
	lmt&=-lmt;
	mask&=(lmt-1);
	if(dp[x].find(mask)!=dp[x].end()){
		return dp[x][mask];
	}
	int ret=dfs(x+1,mask)+1;
	int msk=mask;
	mask=(mask<<tmp[x+1])|1;
	if(good(mask))ret=min(ret,dfs(x+1,mask));
//	cerr<<x<<" "<<msk<<" "<<ret<<endl;
	return dp[x][msk]=ret;
}
int main(){
	scanf("%s%d",s,&x);
	for(int i=1;i<x;i++)if(x%i==0)full|=(1<<i);
	for(int i=0;i<=x;i++)S|=(1<<i);
	n=strlen(s);
	for(int i=1;i<=n;i++){
		tmp[i]=s[i-1]-'0';
	}
	cout<<dfs(0,1)<<endl;
	return 0;
}