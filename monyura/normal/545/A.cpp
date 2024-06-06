#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
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
#include <bitset>
#include <sstream>
#include <cassert>
#include <utility>
#include <iterator>

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
typedef pair<double, int> pdi;



void run()
{
	int n;
	cin>>n;
	int A[102][102];
	rep(i,0,n)
	rep(j,0,n)
	scanf("%d",&A[i][j]);
	vector<int> res;
	rep(i,0,n)
	{
		bool ok = true;
		rep(j,0,n)
			if (A[i][j] == 1 || A[i][j] == 3)
				ok = false;
		if (ok)
			res.push_back(i);
	}
	cout<<res.size()<<endl;
	rep(i,0,res.size())
	cout<<res[i]+1<<' ';
	cout<<endl;
}

//#define prob "i"

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
	run();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}