#include <bits/stdc++.h>
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
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int N, w[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d", &N);
	vector <int> arr;
	for (int i=1;i<=N;i++){
		bool sw = 0;
		for (int j=1;j<=N;j++){
			scanf("%d", w[i]+j);
			if (w[i][j] == 1 || w[i][j] == 3) sw = 1;
		}
		if (!sw) arr.pb(i);
	}
	printf("%d\n", sz(arr));
	for (int t: arr) printf("%d ", t); puts("");
}