#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


void run()
{
	int A[51],B[51],n,m;
	cin>>n;
	rep(i,0,n) scanf("%d",A+i);
	cin>>m;
	rep(i,0,m) scanf("%d",B+i);
	vector<int> vec;
	rep(i,0,n)
		rep(j,0,m)
			if (B[j]%A[i]==0)
				vec.push_back(B[j]/A[i]);
	int bst=*max_element(all(vec));
	int res=0;
	rep(i,0,vec.size())
		if (vec[i]==bst) ++res;
	cout<<res<<endl;
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*
3 2
lasdbqwrisdiasdfnasdfgcfsjdagee
lasdbqwrisdiasdfnasdfgcfsjdagee
zaazzzzzzzzaaaazzzzzzzzzzddzzzz


*/