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
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
int a[100005],b[100005];

bool compare(int a,int b)
{
	return a>b;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	sort(a,a+n,compare);
	sort(b,b+m,compare);
	if(n>m)
	{
		cout<<"YES\n";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]<a[i])
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}