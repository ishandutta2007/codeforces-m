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
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int a[5005];

bool check(int x)
{
	int ta=x;
	int tb=a[x];
	int tc=a[tb];
	if(ta==a[tc]) return true;else return false;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	rep(n)
	{
		cin>>a[i];
		--a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(check(i)) over("YES")
	}
	cout<<"NO\n";
	return 0;
}