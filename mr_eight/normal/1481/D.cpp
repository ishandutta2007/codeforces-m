//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0) {
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
int n,m,a[1002],b[1002];
char mp[1002][1002];
int main() {
	F(qwqqwq,1,read()) {
		cin>>n>>m;
		F(i,1,n)a[i]=b[i]=0;
		F(i,1,n) {
			scanf("%s",mp[i]+1);
		}
		F(i,1,n) {
			F(j,i+1,n) {
				if(mp[i][j]==mp[j][i]||(m%2==1)) {
					puts("YES");
					F(qq,1,m+1) {

						if(qq&1)write(i,' ');
						else write(j,' ');

					}
					putchar('\n');
					goto orz;
				}
			}
		}
		F(i,1,n) {
			F(j,1,n) {
				if(mp[i][j]=='a')a[i]=j;
				else if(mp[i][j]=='b')b[i]=j;
			}
		}
		F(i,1,n) {
			F(j,1,n) {
				if(i!=j) {
					if(mp[i][j]=='a') {
						if(a[j]) {
							puts("YES");
							if(m%4==0) {
								write(j,' ');
								F(qq,1,m>>1) {
									if(qq&1)write(i,' ');
									else write(j,' ');
								}
							} else {
								write(i,' ');
								F(qq,1,m>>1) {
									if(qq&1)write(j,' ');
									else write(i,' ');
								}
							}
							i=a[j];
							if(m%4==0) {
								F(qq,1,m>>1) {
									if(qq&1)write(i,' ');
									else write(j,' ');
								}
							} else {
								F(qq,1,m>>1) {
									if(qq&1)write(i,' ');
									else write(j,' ');
								}
							}
							puts("");
							goto orz;
						}
					} else {
						if(b[j]) {
#define a b
							puts("YES");
							if(m%4==0) {
								write(j,' ');
								F(qq,1,m>>1) {
									if(qq&1)write(i,' ');
									else write(j,' ');
								}
							} else {
								write(i,' ');
								F(qq,1,m>>1) {
									if(qq&1)write(j,' ');
									else write(i,' ');
								}
							}
							i=a[j];
							if(m%4==0) {
								F(qq,1,m>>1) {
									if(qq&1)write(i,' ');
									else write(j,' ');
								}
							} else {
								F(qq,1,m>>1) {
									if(qq&1)write(i,' ');
									else write(j,' ');
								}
							}
							puts("");
#undef a
							goto orz;
						}
					}
				}
			}
		}
		puts("NO");
orz:
		;
	}
	return 0;
}
/*
4 2
*aaa
b*ba
ba*b
bba*
*/