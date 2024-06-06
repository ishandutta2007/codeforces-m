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
inline int Rand(){return rand()*32768+rand();}
int T;
string s,t;
int nxt[100005][26];
int main(){
	cin>>T;
	while(T--){
		cin>>s>>t;
		for(int i=s.size()-1;i>=0;i--){
			for(int j=0;j<26;j++)nxt[i][j]=(i+1==s.size()?s.size():nxt[i+1][j]);
			nxt[i][s[i]-'a']=i;
		}
		int cnt=0,pos=0,ans=1;
		for(char c:t){
			int tmp=nxt[pos][c-'a'];
			if(tmp==s.size()){
				cnt++;pos=0;
			}
			tmp=nxt[pos][c-'a'];
			if(tmp==s.size()){
				ans=0;break;
			}
			pos=tmp+1;
			if(pos==s.size()){
				cnt++;pos=0;
			}
		}
		if(!ans)puts("-1");
		else cout<<cnt+(pos!=0)<<endl;
	}
	return 0;
}