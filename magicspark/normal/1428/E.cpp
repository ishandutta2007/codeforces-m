/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,k,a[100005],cur[100005];
int calc(int sum,int cnt){
	if(cnt>sum)return -1e18;
	int val=sum/cnt;
	int big=sum-val*cnt,small=cnt-big;
	return big*(val+1)*(val+1)+small*val*val;
}
set<pair<int,int> >s;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)s.insert(make_pair(calc(a[i],1)-calc(a[i],2),i));
		cur[i]=1;
	}
	int tms=k-n;
	while(tms--){
		int x=s.rbegin()->second;
		cur[x]++;
		s.erase(s.find(*s.rbegin()));
		if(cur[x]<a[x])s.insert(make_pair(calc(a[x],cur[x])-calc(a[x],cur[x]+1),x)); 
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//		cerr<<i<<" "<<cur[i]<<" "<<a[i]<<endl;
		ans+=calc(a[i],cur[i]);
	}
	cout<<ans<<endl;
	return 0;
}