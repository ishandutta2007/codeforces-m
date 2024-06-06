//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//const double eps=1e-9;
//int n,m,x;
//char c[35][35];
//char s[500005];
//map <char,int> dis;
//
//inline void init()
//{
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			if(c[i][j]!='S') dis[c[i][j]]=0;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			if(c[i][j]=='S') continue;
//			double minDis=inf;
//			for(int ni=0;ni<n;ni++)
//			{
//				for(int nj=0;nj<m;nj++)
//				{
//					if(c[ni][nj]!='S') continue;
//					chmin(minDis,sqrt((double)(ni-i)*(ni-i)+(nj-j)*(nj-j)));
//				}
//			}
//			if(minDis<=x+eps) dis[c[i][j]+'A'-'a']=0;
//			else if(minDis>=inf-eps);
//			else
//			{
//				if(dis.find(c[i][j]+'A'-'a')!=dis.end());
//				else dis[c[i][j]+'A'-'a']=1;
//			}
//		}
//	}
//}
//
//int type(char c)
//{
//	if(dis.find(c)==dis.end()) return -1;
//	return dis[c];
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>m>>x;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s",c[i]);
//	}
//	int q;
//	cin>>q;
//	scanf("%s",s);
//	int res=0;
//	init();
//	for(int i=0;i<q;i++)
//	{
//		int f=type(s[i]);
//		if(f==-1) over("-1");
//		res+=f;
//	}
//	cout<<res<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=200003;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,set <T> s)
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
	for(int i=0;i<vec.size();i++)
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
const double eps=1e-9;
int n,m,x;
char c[35][35];
char s[500005];
map <char,int> dis;

inline void init()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i][j]!='S') dis[c[i][j]]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i][j]=='S') continue;
			double minDis=inf;
			for(int ni=0;ni<n;ni++)
			{
				for(int nj=0;nj<m;nj++)
				{
					if(c[ni][nj]!='S') continue;
					chmin(minDis,sqrt((double)(ni-i)*(ni-i)+(nj-j)*(nj-j)));
				}
			}
			if(minDis<=x+eps) dis[c[i][j]+'A'-'a']=0;
			else if(minDis>=inf-eps);
			else
			{
				if(dis.find(c[i][j]+'A'-'a')!=dis.end());
				else dis[c[i][j]+'A'-'a']=1;
			}
		}
	}
}

int type(char c)
{
	if(dis.find(c)==dis.end()) return -1;
	return dis[c];
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>x;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	int q;
	cin>>q;
	scanf("%s",s);
	int res=0;
	init();
	for(int i=0;i<q;i++)
	{
		int f=type(s[i]);
		if(f==-1) over("-1");
		res+=f;
	}
	cout<<res<<endl;
	return 0;
}