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
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,m;
int a[305][305];

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}

void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int s=0;
			for(int k=0;k<4;k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(out(nx,ny)) continue;
				s++;
			}
			if(s<a[i][j])
			{
				cout<<"NO\n";
				return;
			}
			a[i][j]=s;
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	quickcin;
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}