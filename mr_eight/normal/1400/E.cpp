//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}ll n,a[5002];int dp[5002][5002],m;
int getv[5002],vv[5002];
int main(){
    cin>>n;
    F(i,1,n)cin>>a[i];
    F(i,1,n)getv[i]=a[i];
    sort(getv+1,getv+n+1);
    m=unique(getv+1,getv+n+1)-getv-1;
    F(i,1,n){
    	F(j,0,m){
    		if(getv[j]==a[i]){
    			vv[i]=j;
    			break;
			}
		}
	}memset(dp,0x1f,sizeof(dp));
dp[0][0]=0;
    F(i,1,n){
    	UF(j,m,0){
    		if(getv[j]>a[i])continue;
    		dp[i][j]=dp[i][j+1];
    		dp[i][j]=min(dp[i][j],dp[i-1][j]+(getv[j]!=a[i]));
    		if(a[i-1]<j){
    			dp[i][j]=min((ll)dp[i][j],dp[i-1][vv[i-1]]+getv[j]-a[i-1]+(getv[j]!=a[i]));
			}if(j==0){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			}
		}
	}cout<<dp[n][0];
    return 0;
}