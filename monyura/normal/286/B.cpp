//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);


void run()
{
	int n;
	int p[2001000];
	cin>>n;
	rep(i,0,n)
		p[i]=i+1;
	rep(st,2,n+1)
		rep(i,0,(n + st - 1) / st)
			swap(p[st - 2 + min((i+1)*st,n)], p[st-2]);
	rep(i,0,n)
		printf("%d ",p[n-1+i]);
	puts("");
}





int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/