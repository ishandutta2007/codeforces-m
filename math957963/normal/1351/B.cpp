#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	int t, x, y, xx, yy;
	bool v;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		v = true;
		if (x > y)swap(x, y);
		if (xx > yy)swap(xx, yy);
		if (y != yy)v = false;
		if ((x + xx) != y)v = false;
		if (v)printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}