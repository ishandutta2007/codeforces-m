//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int t;
int main(){
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		if(k%3==0){
			n%=(k+1);
			if(n==k){
				puts("Alice");
				continue;
			}
			if(n%3==0){
				puts("Bob");
			}else{
				puts("Alice");
			}
			continue;
		}
		if((n-1)%3==0||(n-2)%3==0||(n>=k&&(n-k)%3==0)){
			puts("Alice");
		}else{
			puts("Bob");
		}
	}
	return 0;
}