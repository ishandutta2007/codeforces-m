#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int t, n;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n==1)puts("-1");
        else{
            printf("2");
            for(int i=1; i<n; i++)printf("3");
            puts("");
        }
    }
}