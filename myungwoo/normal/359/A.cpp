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

int N,M,A[51][51],ans=4;
bool R[51],C[51];

int main()
{
    int i,j;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%d",A[i]+j);
    for (i=1;i<=N;i++) R[i] = A[i][1] || A[i][M];
    for (i=1;i<=M;i++) C[i] = A[1][i] || A[N][i];
    for (i=1;i<=N;i++) if (R[i]) ans = 2;
    for (i=1;i<=M;i++) if (C[i]) ans = 2;
    for (i=1;i<N;i++) if (R[i] && R[i+1]) ans = 2;
    for (i=1;i<M;i++) if (C[i] && C[i+1]) ans = 2;
    printf("%d\n",ans);
}