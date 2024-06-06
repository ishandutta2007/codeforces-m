//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
struct S{
	int a[26];
}x[23],sta[24];
inline S merge(const S &a,const S &b){
	S rt;
	F(i,0,25)rt.a[i]=min(a.a[i],b.a[i]);
	return rt;
}
int n;
ll a[1<<23],ans;
char s[23][20002];
#define mod 998244353
inline void dfs(int pos,int now){
	if(pos==n){
		a[now]=1;
		F(i,0,25)a[now]=a[now]*(sta[n].a[i]+1)%mod;
		if(!(__builtin_popcount(now)&1))a[now]=mod-a[now];
		return;
	}
	sta[pos+1]=sta[pos];
	dfs(pos+1,now);
	sta[pos+1]=merge(sta[pos],x[pos]);
	dfs(pos+1,now|(1<<pos));
}
int main() {
	cin>>n;
	F(i,0,n-1){
		scanf("%s",s[i]);
		for(int j=0;s[i][j]!='\0';++j)++x[i].a[s[i][j]-'a'];
	}
	F(i,0,25)sta[0].a[i]=1000000000;
	dfs(0,0);a[0]=0;
	F(i,0,n-1)F(j,0,(1<<n)-1)if(j>>i&1)a[j]+=a[j^(1<<i)];
	F(i,0,(1<<n)-1){
		ll mul=0;
		F(j,0,n-1)if(i>>j&1)mul+=j+1;
		ans^=a[i]%mod*mul*__builtin_popcount(i);
	}
	cout<<ans;
	return 0;
}