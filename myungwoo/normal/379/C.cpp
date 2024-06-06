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

#define MAXN 300005

int N,A[MAXN],idx[MAXN],B[MAXN];

bool cmp(const int &a,const int &b){ return A[a]<A[b]; }

int main()
{
    int i,x=0;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i), idx[i] = i;
    sort(idx+1,idx+N+1,cmp);
    for (i=1;i<=N;i++){
        if (x < A[idx[i]]) x = A[idx[i]];
        else x++;
        B[idx[i]] = x;
    }
    for (i=1;i<=N;i++) printf("%d ",B[i]); puts("");
}