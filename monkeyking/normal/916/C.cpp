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
typedef unsigned long long ull;
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	cout<<100511<<' '<<100511<<endl; 
	for(int i=1;i<=n-2;i++)
	{
		cout<<i<<' '<<i+1<<' '<<1<<endl;
	}
	cout<<n-1<<' '<<n<<' '<<100511-n+2<<endl;
	m-=n-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(m<=0) break;
			if(i>=j) continue;
			if(i==j-1) continue;
			cout<<i<<' '<<j<<' '<<810543257<<endl;
			m--;
		}
		if(m<=0) break;
	}
	return 0;
}