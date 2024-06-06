//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//tuple <int,int,int> data[100005];
//vector <int> lsh;
//int L[100005];
//int R[100005];
//int f[100005];
//int nn;
//int oL[100005];
//int oR[100005];
//
//inline int find(int x)
//{
//	return (f[x]==x?x:f[x]=find(f[x]));
//}
//
//inline void merge(int x,int y)
//{
//	x=find(x);
//	y=find(y);
//	if(x==y) return;
//	chmin(L[x],L[y]);
//	chmax(R[x],R[y]);
//	f[y]=x;
//}
//
//inline void merge(int x,vector <int> &v)
//{
//	for(auto y:v)
//	{
//		merge(x,y);
//	}
//	v.clear();
//}
//
//struct SegmentTree
//{
//	vector <int> ids[1600005];
//	inline void findMerge(int x,int l,int r,int pos,int id)
//	{
//		if(pos>=r || pos<l) return;
//		merge(id,ids[x]);
//		if(x>=nn) return;
//		findMerge(x*2,l,l+r>>1,pos,id);
//		findMerge(x*2+1,l+r>>1,r,pos,id);
//	}
//	inline void addLine(int x,int l,int r,int ql,int qr,int id)
//	{
//		if(ql>=r || qr<=l) return;
//		if(l>=ql && r<=qr)
//		{
//			ids[x].push_back(id);
//			return;
//		}
//		addLine(x*2,l,l+r>>1,ql,qr,id);
//		addLine(x*2+1,l+r>>1,r,ql,qr,id);
//	}
//}sgt;
//
//inline void addLine(int l,int r,int id)
//{
//	oL[id]=L[id]=l;
//	oR[id]=R[id]=r;
//	sgt.findMerge(1,0,nn,l,id);
//	sgt.findMerge(1,0,nn,r,id);
//	sgt.addLine(1,0,nn,L[id]+1,R[id],id);
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n;
//	vector <int> lshid;
//	for(int i=0;i<n;i++)
//	{
//		f[i]=i;
//	}
//	for(int i=0;i<n;i++)
//	{
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		if(x==1)
//		{
//			lsh.push_back(y);
//			lsh.push_back(z);
//			lsh.push_back(y+1);
//			lsh.push_back(z-1);
//		}
//		data[i]=make_tuple(x,y,z);
//	} 
//	sort(all(lsh));
//	lsh.erase(unique(all(lsh)),lsh.end());
//	nn=1;
//	while(nn<(int)lsh.size())
//	{
//		nn<<=1;
//	}
//	for(int i=0;i<n;i++)
//	{
//		int type,x,y;
//		tie(type,x,y)=data[i];
//		if(type==1)
//		{
//			x=lower_bound(all(lsh),x)-lsh.begin();
//			y=lower_bound(all(lsh),y)-lsh.begin();
//			addLine(x,y,i);
//			lshid.push_back(i);
//		}
//		else
//		{
//			x--;
//			y--;
//			x=lshid[x];
//			y=lshid[y];
//			y=find(y);
//			if(((oL[x]<=L[y] && oR[x]>=R[y]) || (oL[x]>=R[y]) || (oR[x]<=L[y])) && (x!=y))
//			{
//				puts("NO");
//			}
//			else
//			{
//				puts("YES");
//			}
//		}
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
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_CONTROL_OF_MOD
int mod;
#else
const int mod=1e9+7;
#endif
const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
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
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T> 
void operator *= (vector <T> &vec,int k)
{
	for(auto &x:vec) x*=k;
}

template <typename T>
void operator -= (vector <T> &a,const vector <T> &b)
{
	assert(a.size()==b.size());
	for(size_t it=0;it<a.size();it++)
	{
		a[it]-=b[it];
	}
}

template <typename T>
vector <T> operator * (const vector <T> &vec,int k)
{
	vector <T> res(vec);
	res*=k;
	return res;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

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
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
using namespace std;
int n;
tuple <int,int,int> data[100005];
vector <int> lsh;
int L[100005];
int R[100005];
int f[100005];
int nn;
int oL[100005];
int oR[100005];

inline int find(int x)
{
	return (f[x]==x?x:f[x]=find(f[x]));
}

inline void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	chmin(L[x],L[y]);
	chmax(R[x],R[y]);
	f[y]=x;
}

inline void merge(int x,vector <int> &v)
{
	for(auto y:v)
	{
		merge(x,y);
	}
	v.clear();
}

struct SegmentTree
{
	vector <int> ids[1600005];
	inline void findMerge(int x,int l,int r,int pos,int id)
	{
		if(pos>=r || pos<l) return;
		merge(id,ids[x]);
		if(x>=nn) return;
		findMerge(x*2,l,l+r>>1,pos,id);
		findMerge(x*2+1,l+r>>1,r,pos,id);
	}
	inline void addLine(int x,int l,int r,int ql,int qr,int id)
	{
		if(ql>=r || qr<=l) return;
		if(l>=ql && r<=qr)
		{
			ids[x].push_back(id);
			return;
		}
		addLine(x*2,l,l+r>>1,ql,qr,id);
		addLine(x*2+1,l+r>>1,r,ql,qr,id);
	}
}sgt;

inline void addLine(int l,int r,int id)
{
	oL[id]=L[id]=l;
	oR[id]=R[id]=r;
	sgt.findMerge(1,0,nn,l,id);
	sgt.findMerge(1,0,nn,r,id);
	sgt.addLine(1,0,nn,L[id]+1,R[id],id);
}

int main()
{
	// freopen("input.txt","r",stdin);
	cin>>n;
	vector <int> lshid;
	for(int i=0;i<n;i++)
	{
		f[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
		{
			lsh.push_back(y);
			lsh.push_back(z);
			lsh.push_back(y+1);
			lsh.push_back(z-1);
		}
		data[i]=make_tuple(x,y,z);
	} 
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	nn=1;
	while(nn<(int)lsh.size())
	{
		nn<<=1;
	}
	for(int i=0;i<n;i++)
	{
		int type,x,y;
		tie(type,x,y)=data[i];
		if(type==1)
		{
			x=lower_bound(all(lsh),x)-lsh.begin();
			y=lower_bound(all(lsh),y)-lsh.begin();
			addLine(x,y,i);
			lshid.push_back(i);
		}
		else
		{
			x--;
			y--;
			x=lshid[x];
			y=lshid[y];
			y=find(y);
			if(((oL[x]<=L[y] && oR[x]>=R[y]) || (oL[x]>=R[y]) || (oR[x]<=L[y])) && (x!=y))
			{
				puts("NO");
			}
			else
			{
				puts("YES");
			}
		}
	}
	return 0;
}