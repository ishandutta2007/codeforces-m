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

int main()
{
//	freopen("input.txt","r",stdin);
	string t;
	cin>>t;
	string c="";
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='1' || t[i]=='3' || t[i]=='5' || t[i]=='7' || t[i]=='9')
		{
			c+=t[i];
			continue;
		}
		if(isdigit(t[i])) continue;
		if(t[i]!='a' && t[i]!='e' && t[i]!='o' && t[i]!='i' && t[i]!='u')
		{
		}
		else
		{
			c+=t[i];
		}
	}
//	cout<<c<<endl;
	cout<<c.size()<<endl;
	return 0;
}