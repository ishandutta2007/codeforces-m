#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

#define MAXN 3003

int N,A[MAXN],B[MAXN],C[MAXN],D[MAXN],E[MAXN];

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i);
	for (i=1;i<=N;i++) scanf("%d",B+i);
	for (i=1;i<=N;i++) scanf("%d",C+i);
	D[1] = A[1]; E[1] = B[1];
	for (i=2;i<=N;i++){
		D[i] = max(A[i]+E[i-1],B[i]+D[i-1]);
		E[i] = max(B[i]+E[i-1],C[i]+D[i-1]);
	}
	printf("%d\n",D[N]);
}