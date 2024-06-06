//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/ntt>
//using namespace std;
//NTT<998244353,3,21> ntt;
//int c0[1500005];
//int c1[1500005];
//int c2[1500005];
//vector<int> v0,v1,v2;
//int n0,n1,n2;
//vector<int> num;
//
//inline void div(int T[],int len,int m,int b[],int &n)
//{
//	ll cur=0;
//	n=0;
//	for(int i=len-1;i>=0;i--)
//	{
//		cur=cur*100+T[i];
//		b[n++]=cur/m;
//		cur%=m;
//	}
//	reverse(b,b+n);
//	while(n && b[n-1]==0) n--;
//	if(cur==0) return;
//	b[0]++;
//	cur=0;
//	while(b[cur]==100)
//	{
//		b[cur]=0;
//		b[++cur]++;
//	}
//	chmax(n,cur+1);
//}
//
//inline void multiply(const vector<int> &a,const vector<int> &b,vector<int> &c)
//{
//	ntt.multiply(a,b,c);
//	int cur=0;
//	for(int i=0;i<=(int)c.size();i++)
//	{
//		if(i==(int)c.size())
//		{
//			if(!cur) break;
//			c.push_back(0);
//		}
//		c[i]+=cur;
//		cur=c[i]/100;
//		c[i]%=100;
//	}
//}
//
//inline void sqr(vector<int> &a)
//{
//	ntt.sqr(a);
//	int cur=0;
//	for(int i=0;i<=(int)a.size();i++)
//	{
//		if(i==(int)a.size())
//		{
//			if(!cur) break;
//			a.push_back(0);
//		}
//		a[i]+=cur;
//		cur=a[i]/100;
//		a[i]%=100;
//	}
//}
//
//inline void multiply(vector<int> &c,int value)
//{
//	int cur=0;
//	for(int i=0;i<=(int)c.size();i++)
//	{
//		if(i==c.size())
//		{
//			if(!cur) break;
//			c.push_back(0);
//		}
//		c[i]=cur+c[i]*3;
//		cur=c[i]/100;
//		c[i]%=100;
//	}
//}
//
//inline void fastpow(vector<int> &num,int x)
//{
//	num={1};
//	for(int i=22;i>=0;i--)
//	{
//		sqr(num);
//		if((1<<i) & x) multiply(num,3);
//	}
//}
//
//inline bool compare(const vector<int> &a,const vector<int> &b)
//{
//	if(a.size()!=b.size()) return a.size()<b.size();
//	for(int i=a.size()-1;i>=0;i--)
//	{
//		if(a[i]!=b[i]) return a[i]<b[i];
//	}
//	return false;
//}
//
//char c[1500005];
//int len;
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	scanf("%s",c);
//	len=strlen(c);
//	reverse(c,c+len);
//	for(int i=0;i<len;i++) c[i]-='0';
//	for(int i=0;i<(len-1)/2+1;i++)
//	{
//		c0[i]=c[i*2]+c[i*2+1]*10;
//	}
//	n0=(len-1)/2+1;
//	for(int i=0;i<n0;i++) v0.push_back(c0[i]);
//	div(c0,n0,2,c1,n1);
//	for(int i=0;i<n1;i++) v1.push_back(c1[i]);
//	div(c1,n1,2,c2,n2);
//	for(int i=0;i<n2;i++) v2.push_back(c2[i]);
//	int b=(int)((double)(n2-1)/(log10(3)/2.0-eps));
//	chmax(b,0);
//	fastpow(num,b);
//	int res=inf;
//	int s3=b;
//	while(compare(num,v2)) multiply(num,3),s3++;
//	chmin(res,s3*3+4);
//	while(compare(num,v1)) multiply(num,3),s3++;
//	chmin(res,s3*3+2);
//	while(compare(num,v0)) multiply(num,3),s3++;
//	chmin(res,s3*3);
//	chmax(res,1);
//	cout<<res<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp make_pair
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
#ifndef _SELF_NTT
#define _SELF_NTT 1
#ifndef SELF_MODINT
#define SELF_MODINT 1
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt(ll _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
	ModInt <mod> operator ++(int)
	{
		int t=x;
		x++;
		if(x==mod) x=0;
		return t;
	}
	ModInt <mod>& operator --()// prefix
	{
		--x;
		if(x==-1) x+=mod;
		return *this;
	}
	ModInt <mod> operator --(int)
	{
		int t=x;
		x--;
		if(x==-1) x+=mod;
		return t;
	}
	ModInt <mod> operator -()const
	{
		return ModInt <mod>((x==0?0:mod-x));
	}
};

template <int mod>
inline int mabs(const ModInt <mod> &a)
{
	return a.x;
}

template <int mod>
bool operator == (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
bool operator != (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return (a.x!=b.x);
}

template <int mod>
bool operator != (ModInt <mod> a,int x)
{
	return (a.x!=x);
}

template <int mod>
inline ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
inline ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
inline ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
inline ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
inline void operator -= (ModInt <mod> &a,ModInt <mod> b)
{
	a.x-=b.x;
	a.x+=(a.x>>31&mod);
}

template <int mod,typename T>
inline void operator -= (ModInt <mod> &a,const T &b)
{
	a.x-=b;
	a.x+=(a.x>>31&mod);
}

template <int mod>
inline ModInt <mod> operator * (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
inline ModInt <mod> operator * (const ModInt <mod> &a,const int &b)
{
	return 1LL*a.x*b%mod;
}

template <int mod>
inline void operator *= (ModInt <mod> &a,const ModInt <mod> &b)
{
	a.x=1LL*a.x*b.x%mod;
}

template <int mod,typename T>
inline void operator *= (ModInt <mod> &a,const T &b)
{
	a=a*b;
}

template <int mod>
inline void operator += (ModInt <mod> &a,const ModInt <mod> &b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod,typename T>
void operator +=(ModInt <mod> &a,const T &b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
inline ModInt <mod> mod_inv(ModInt <mod> x)
{
	int m=mod-2;
	ModInt <mod> basic=x;
	x=1;
	while(m)
	{
		if(m&1) x*=basic;
		m>>=1;
		basic*=basic;
	}
	return x;
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,ModInt <mod> b)
{
	return a*mod_inv(b);
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,int b)
{
	return a*mod_inv((ModInt <mod>)b);
}

template <int mod>
void operator /= (ModInt <mod> &a,int b)
{
	a*=mod_inv(ModInt <mod> (b));
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
inline ModInt <mod> operator ^ (ModInt <mod> basic,int x)
{
	ModInt <mod> res=1;
	while(x)
	{
		if(x&1)	res*=basic;
		basic*=basic;
		x>>=1;
	}
	return res;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	x.x%=mod;
	if(x.x<0) x.x+=mod;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
#endif
template <int mod,int g,int LogN>
struct NTT
{
	using Int=ModInt <mod>;
	static const int MaxN=(1<<LogN);
	int w[MaxN+5];
	int fastpow(int basic,int x)
	{
		int res=1;
		while(x)
		{
			if(x&1) res=1LL*res*basic%mod;
			basic=1LL*basic*basic%mod;
			x>>=1;
		}
		return res;
	}
	int inv[MaxN+5];
	int buf[MaxN+5];
	int ww[MaxN+5];
	inline void ntt(vector<int> &v,int rev,int lg)
	{
		int n=(1<<lg);
		memset(buf,0,sizeof(int)*n);
		v.resize(n,0);
		for(int i=0;i<n;i++)
		{
			inv[i]=(inv[i>>1]>>1) | ((i&1)<<(lg-1));
		}
		for(int i=0;i<n;i++)
		{
			buf[i]=v[inv[i]];
		}
		int lvl=LogN;
		int *ba,*bb,*wa,*wb;
		int tmp;
		for(int b=1;b<n;b*=2)
		{
			lvl--;
			for(int i=0;i<b*2;i++) ww[i]=(rev?w[MaxN-(i<<lvl)]:w[i<<lvl]);
			for(int i=0;i<n;i+=b*2)
			{
				ba=buf+i;
				bb=buf+i+b;
				wa=ww;
				wb=ww+b;
				for(int j=0;j<b;j++)
				{
					tmp=1LL**wa**bb%mod;
					*bb=*ba-tmp;
					*ba+=tmp;
					*ba-=mod;
					*ba+=((*ba)>>31 & mod);
					*bb+=((*bb)>>31 & mod);
					ba++;
					bb++;
					wa++;
					wb++;
				}
			}
		}
		int t=fastpow(n,mod-2);
		if(rev)
		{
			for(int i=0;i<(1<<lg);i++)
			{
				buf[i]=1LL*buf[i]*t%mod;
			}
		}
		for(int i=0;i<(1<<lg);i++) v[i]=buf[i];
	}
	void multiply(vector<int> a,vector<int> b,vector<int> &c)
	{
		int n=(int)a.size()+b.size()-1;
		if(min(a.size(),b.size())<=60)
		{
			c.clear();
			c.resize(max(0,n),0);
			for(int i=0;i<(int)a.size();i++)
			{
				for(int j=0;j<(int)b.size();j++)
				{
					c[i+j]=(1LL*a[i]*b[j]+c[i+j])%mod;
				}
			}
			while(c.size() && c.back()==0) c.pop_back();
		}
		int nn=1,lg=0;
		while(nn<n)
		{
			nn<<=1;
			lg++;
		}
		c.resize(nn);
		a.resize(nn,0);
		b.resize(nn,0);
		ntt(a,0,lg);
		ntt(b,0,lg);
		for(int i=0;i<nn;i++)
		{
			c[i]=1LL*a[i]*b[i]%mod;
		}
		ntt(c,1,lg);
		while(c.size() && c.back()==0) c.pop_back();
	}
	void sqr(vector<int> &a)
	{
		int n=(int)a.size()+a.size()-1;
		int nn=1,lg=0;
		while(nn<n)
		{
			nn<<=1;
			lg++;
		}
		a.resize(nn,0);
		ntt(a,0,lg);
		for(int i=0;i<nn;i++)
		{
			a[i]=1LL*a[i]*a[i]%mod;
		}
		ntt(a,1,lg);
		while(a.size() && a.back()==0) a.pop_back();
	}
	vector<Int> multiply(const vector<Int> &a,const vector<Int> &b)
	{
		vector<int> ta(a.size()),tb(b.size());
		for(int i=0;i<(int)a.size();i++) ta[i]=a[i].x;
		for(int i=0;i<(int)b.size();i++) tb[i]=b[i].x;
		vector<int> tc;
		multiply(ta,tb,tc);
		vector<Int> c(tc.size());
		for(int i=0;i<(int)c.size();i++) c[i].x=tc[i];
		return c;
	}
	NTT()
	{
		w[0]=1;
		int ur=fastpow(g,(mod-1)>>LogN);
		for(int i=1;i<=MaxN;i++)
		{
			w[i]=1LL*w[i-1]*ur%mod;
		}
	}
};

template <int mod,int g,int LogN>
struct Polynomial:vector<int>
{
	static NTT<mod,g,LogN> ntt;
	Polynomial(){}
	Polynomial(int x)
	{
		if(x==1) push_back(1);else assert(x==0);
	}
	Polynomial(const vector<int> &v)
	{
		for(int i=0;i<v.size();i++) push_back(v[i]);
	}
	Polynomial& operator += (const Polynomial &oth)
	{
		if(size()<oth.size()) resize(oth.size(),0);
		int *x=&(*this)[0];
		const int *y=&oth[0];
		int n=min(size(),oth.size());
		for(int i=0;i<n;i++)
		{
			*x+=*y-mod;
			*x+=((*x)>>31 & mod);
			x++;
			y++;
		}
		return (*this);
	}
	Polynomial operator * (const Polynomial &oth)const
	{
		Polynomial t;
		ntt.multiply((*this),oth,t);
		return t;
	}
};
#endif
using namespace std;
NTT<998244353,3,21> ntt;
int c0[1500005];
int c1[1500005];
int c2[1500005];
vector<int> v0,v1,v2;
int n0,n1,n2;
vector<int> num;

inline void div(int T[],int len,int m,int b[],int &n)
{
	ll cur=0;
	n=0;
	for(int i=len-1;i>=0;i--)
	{
		cur=cur*100+T[i];
		b[n++]=cur/m;
		cur%=m;
	}
	reverse(b,b+n);
	while(n && b[n-1]==0) n--;
	if(cur==0) return;
	b[0]++;
	cur=0;
	while(b[cur]==100)
	{
		b[cur]=0;
		b[++cur]++;
	}
	chmax(n,cur+1);
}

inline void multiply(const vector<int> &a,const vector<int> &b,vector<int> &c)
{
	ntt.multiply(a,b,c);
	int cur=0;
	for(int i=0;i<=(int)c.size();i++)
	{
		if(i==(int)c.size())
		{
			if(!cur) break;
			c.push_back(0);
		}
		c[i]+=cur;
		cur=c[i]/100;
		c[i]%=100;
	}
}

inline void sqr(vector<int> &a)
{
	ntt.sqr(a);
	int cur=0;
	for(int i=0;i<=(int)a.size();i++)
	{
		if(i==(int)a.size())
		{
			if(!cur) break;
			a.push_back(0);
		}
		a[i]+=cur;
		cur=a[i]/100;
		a[i]%=100;
	}
}

inline void multiply(vector<int> &c,int value)
{
	int cur=0;
	for(int i=0;i<=(int)c.size();i++)
	{
		if(i==c.size())
		{
			if(!cur) break;
			c.push_back(0);
		}
		c[i]=cur+c[i]*3;
		cur=c[i]/100;
		c[i]%=100;
	}
}

inline void fastpow(vector<int> &num,int x)
{
	num={1};
	for(int i=22;i>=0;i--)
	{
		sqr(num);
		if((1<<i) & x) multiply(num,3);
	}
}

inline bool compare(const vector<int> &a,const vector<int> &b)
{
	if(a.size()!=b.size()) return a.size()<b.size();
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]!=b[i]) return a[i]<b[i];
	}
	return false;
}

char c[1500005];
int len;
int main()
{
//	// freopen("input.txt","r",stdin);
	scanf("%s",c);
	len=strlen(c);
	reverse(c,c+len);
	for(int i=0;i<len;i++) c[i]-='0';
	for(int i=0;i<(len-1)/2+1;i++)
	{
		c0[i]=c[i*2]+c[i*2+1]*10;
	}
	n0=(len-1)/2+1;
	for(int i=0;i<n0;i++) v0.push_back(c0[i]);
	div(c0,n0,2,c1,n1);
	for(int i=0;i<n1;i++) v1.push_back(c1[i]);
	div(c1,n1,2,c2,n2);
	for(int i=0;i<n2;i++) v2.push_back(c2[i]);
	int b=(int)((double)(n2-1)/(log10(3)/2.0-eps));
	chmax(b,0);
	fastpow(num,b);
	int res=inf;
	int s3=b;
	while(compare(num,v2)) multiply(num,3),s3++;
	chmin(res,s3*3+4);
	while(compare(num,v1)) multiply(num,3),s3++;
	chmin(res,s3*3+2);
	while(compare(num,v0)) multiply(num,3),s3++;
	chmin(res,s3*3);
	chmax(res,1);
	cout<<res<<endl;
	return 0;
}