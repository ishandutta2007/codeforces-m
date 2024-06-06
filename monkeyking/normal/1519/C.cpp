//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//vector<int> a[200005];
//vector<ll> sum[200005];
//int n;
//pii d[200005];
//ll s[200005];
//
//int cnt;
//void add(int i,int size,int x)
//{
//	i++;
//	for(int l=1,r;l<=size;l=r+1)
//	{
//		cnt++;
//		int dt=size/l;
//		r=size/dt;
//		int ls=size-dt*l,rs=size-dt*r;
//		if(ls<i) continue;
//		if(rs>=i)
//		{
//			s[l]+=x;
//			s[r+1]-=x;
//			continue;
//		}
//		int d=(ls-i)/dt;
//		s[l]+=x;
//		s[l+d+1]-=x;
//	}
//	s[size+1]+=x;
//}
//
//void solve()
//{
//	ll tot=0;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++) a[i].clear();
//	for(int i=0;i<n;i++) scanf("%d",&d[i].first);
//	for(int i=0;i<n;i++) scanf("%d",&d[i].second);
//	for(int i=0;i<n;i++) a[d[i].first-1].push_back(d[i].second);
//	for(int i=0;i<n;i++) sort(all(a[i]));
//	for(int i=0;i<n;i++)
//	{
//		sum[i].clear();sum[i].resize(a[i].size());
//		for(int j=0;j<sum[i].size();j++) sum[i][j]=a[i][j]+(j?sum[i][j-1]:0);
//	}
//	for(int i=0;i<=n;i++) s[i]=0;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=1;j<=(int)a[i].size();j++)
//		{
//			tot+=a[i][j-1];
//			int t=a[i].size()%j;
//			ll x=(t?sum[i][t-1]:0);
//			s[j]+=x;
//			s[j+1]-=x;
//		}
//		if(sum[i].size()) s[a[i].size()+1]+=sum[i].back();
//	}
//	for(int i=1;i<=n;i++)
//	{
//		s[i]+=s[i-1];
//		printf("%lld ",tot-s[i]);
//	}
//	puts("");
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	// freopen("output.txt","w",stdout);
//	int T;
//	cin>>T;
//	while(T--)
//	{
//		solve();
//	}
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
#ifdef __TAKE_CONST_EPS
const double eps=__TAKE_CONST_EPS;
#else
const double eps=1e-9;
#endif
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
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
using namespace std;

vector<int> a[200005];
vector<ll> sum[200005];
int n;
pii d[200005];
ll s[200005];

int cnt;
void add(int i,int size,int x)
{
	i++;
	for(int l=1,r;l<=size;l=r+1)
	{
		cnt++;
		int dt=size/l;
		r=size/dt;
		int ls=size-dt*l,rs=size-dt*r;
		if(ls<i) continue;
		if(rs>=i)
		{
			s[l]+=x;
			s[r+1]-=x;
			continue;
		}
		int d=(ls-i)/dt;
		s[l]+=x;
		s[l+d+1]-=x;
	}
	s[size+1]+=x;
}

void solve()
{
	ll tot=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) a[i].clear();
	for(int i=0;i<n;i++) scanf("%d",&d[i].first);
	for(int i=0;i<n;i++) scanf("%d",&d[i].second);
	for(int i=0;i<n;i++) a[d[i].first-1].push_back(d[i].second);
	for(int i=0;i<n;i++) sort(all(a[i]));
	for(int i=0;i<n;i++)
	{
		sum[i].clear();sum[i].resize(a[i].size());
		for(int j=0;j<sum[i].size();j++) sum[i][j]=a[i][j]+(j?sum[i][j-1]:0);
	}
	for(int i=0;i<=n;i++) s[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=(int)a[i].size();j++)
		{
			tot+=a[i][j-1];
			int t=a[i].size()%j;
			ll x=(t?sum[i][t-1]:0);
			s[j]+=x;
			s[j+1]-=x;
		}
		if(sum[i].size()) s[a[i].size()+1]+=sum[i].back();
	}
	for(int i=1;i<=n;i++)
	{
		s[i]+=s[i-1];
		printf("%lld ",tot-s[i]);
	}
	puts("");
}

int main()
{
//	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}