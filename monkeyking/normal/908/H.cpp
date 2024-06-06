//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/dsu>
//using namespace std;
//int n;
//char c[55][55];
//DSUAE dsu;
//vector<int> scc[55];
//vector<vector<int> > a;
//int b[55][55];
//int p[55];
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	double t=clock();
//	scanf("%d",&n);
//	dsu.init(n);
//	for(int i=0;i<n;i++) scanf("%s",c[i]);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if(c[i][j]=='A') dsu.merge(i,j);
//		}
//	}
//	for(int i=0;i<n;i++) scc[dsu.find(i)].push_back(i);
//	int now=0;
//	for(int i=0;i<n;i++)
//	{
//		if(scc[i].empty()) continue;
//		for(auto x:scc[i])
//		{
//			for(auto y:scc[i])
//			{
//				if(c[x][y]=='X') over("-1");
//			}
//		}
//		if(scc[i].size()>1) now+=scc[i].size();else now+=1;
//		if(scc[i].size()>1) a.push_back(scc[i]);
//	}
//	n=a.size();
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if(i==j) continue;
//			bool noXor=true;
//			for(auto x:a[i])
//			{
//				for(auto y:a[j])
//				{
//					noXor&=(c[x][y]!='X');
//				}
//			}
//			if(!noXor) b[i][j]=1;else b[i][j]=0;
//		}
//	}
//	for(int i=0;i<n;i++) p[i]=i;
//	int res=inf;
//	while((clock()-t)/CLOCKS_PER_SEC<=0.001)
//	{
//		random_shuffle(p,p+n);
//		vector<vector<int> > v;
//		for(int i=0;i<n;i++)
//		{
//			int x=p[i];
//			int found=false;
//			for(auto &vv:v)
//			{
//				int ok=true;
//				for(auto &u:vv)
//				{
//					ok&=(b[u][x]==0);
//				}
//				if(ok)
//				{
//					found=true;
//					vv.push_back(x);
//					break;
//				}
//			}
//			if(!found)
//			{
//				v.push_back(vector<int>{x});
//			}
//		}
//		chmin(res,v.size());
//	}
//	cout<<res+now-1<<endl;
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
using namespace std;
#endif
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
struct DSUAE
{
	int *f;
	inline void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			f[i]=i;
		}
	}
	inline void init(int n)
	{
		f=new int[n+5];
		clear(n);
	}
	inline int find(int x)
	{
		return (f[x]==x?x:f[x]=find(f[x]));
	}
	inline void merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(x&1) f[x]=y;else f[y]=x;
	}
};

struct DSU
{
	int *f;
	int *depth;
	int *sz;
	inline void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			f[i]=i;
			depth[i]=1;
			sz[i]=1;
		}
	}
	inline void init(int n)
	{
		f=new int[n+5];
		depth=new int [n+5];
		sz=new int [n+5];
		clear(n);
	}
	inline int find(int x)
	{
		return (f[x]==x?x:f[x]=find(f[x]));
	}
	inline int getSize(int x)
	{
		return sz[find(x)];
	}
	inline int merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return false;
		if(depth[x]>depth[y])
		{
			f[y]=x;
			sz[x]+=sz[y];
		}
		else if(depth[y]>depth[x])
		{
			f[x]=y;
			sz[y]+=sz[x];
		}
		else
		{
			sz[y]+=sz[x];
			f[x]=y;
			depth[y]++;
		}
		return true;
	}
	inline int same(int x,int y)
	{
		return (find(x)==find(y));
	}
	~DSU()
	{
		delete f;
		delete depth;
		delete sz;
	}
};

struct PersistentDSU:public DSU
{
	int find(int x)
	{
		return (x==f[x]?x:find(f[x]));
	}
	inline int merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return false;
		if(depth[x]>depth[y])
		{
			f[y]=x;
			sz[x]+=sz[y];
		}
		else if(depth[y]>depth[x])
		{
			f[x]=y;
			sz[y]+=sz[x];
		}
		else
		{
			sz[y]+=sz[x];
			f[x]=y;
			depth[y]++;
		}
		return true;
	}
};
using namespace std;
int n;
char c[55][55];
DSUAE dsu;
vector<int> scc[55];
vector<vector<int> > a;
int b[55][55];
int p[55];

int main()
{
//	// freopen("input.txt","r",stdin);
	double t=clock();
	scanf("%d",&n);
	dsu.init(n);
	for(int i=0;i<n;i++) scanf("%s",c[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(c[i][j]=='A') dsu.merge(i,j);
		}
	}
	for(int i=0;i<n;i++) scc[dsu.find(i)].push_back(i);
	int now=0;
	for(int i=0;i<n;i++)
	{
		if(scc[i].empty()) continue;
		for(auto x:scc[i])
		{
			for(auto y:scc[i])
			{
				if(c[x][y]=='X') over("-1");
			}
		}
		if(scc[i].size()>1) now+=scc[i].size();else now+=1;
		if(scc[i].size()>1) a.push_back(scc[i]);
	}
	n=a.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			bool noXor=true;
			for(auto x:a[i])
			{
				for(auto y:a[j])
				{
					noXor&=(c[x][y]!='X');
				}
			}
			if(!noXor) b[i][j]=1;else b[i][j]=0;
		}
	}
	for(int i=0;i<n;i++) p[i]=i;
	int res=inf;
	while((clock()-t)/CLOCKS_PER_SEC<=0.001)
	{
		random_shuffle(p,p+n);
		vector<vector<int> > v;
		for(int i=0;i<n;i++)
		{
			int x=p[i];
			int found=false;
			for(auto &vv:v)
			{
				int ok=true;
				for(auto &u:vv)
				{
					ok&=(b[u][x]==0);
				}
				if(ok)
				{
					found=true;
					vv.push_back(x);
					break;
				}
			}
			if(!found)
			{
				v.push_back(vector<int>{x});
			}
		}
		chmin(res,v.size());
	}
	cout<<res+now-1<<endl;
	return 0;
}