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
#define PI (3.1415926535898)

int main(){
	long double n, r, ans;
	ans = 0;
	scanf("%Lf %Lf", &n,&r);
	n = sin(PI / n);
	ans = r*n / (1 - n);
	printf("%.10Lf\n",ans);


	return 0;
}