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
typedef long long lld;
typedef pair<int,int> pii;

#define MAXN 300005

int N,K,A[MAXN];

int main()
{
    int i,g;
    scanf("%d%d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    sort(A+1,A+N+1);
    for (g=A[1];;){
        bool sw=0;
        for (i=1;i<=N;i++){
            while (A[i]%g > K) g--, sw = 1;
        }
        if (!sw) break;
    }
    printf("%d\n",g);
}