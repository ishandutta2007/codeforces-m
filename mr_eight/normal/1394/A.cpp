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
}
ll n,m,d,a[100002],f[100002],cnt,ans,qwq;
inline ll q(ll num){
	return (num-1)*d;
}
int main(){
    cin>>n>>d>>m;
    F(i,1,n)a[i]=read();
    sort(a+1,a+n+1);
    F(i,1,n)f[i]=f[i-1]+a[i];
    F(i,1,n)if(a[i]<=m)cnt++;
    if(cnt==n){
    	cout<<f[n];
    	return 0;
	}
    F(i,1,n-cnt){
    	if(q(i)>n-i)break;  	
    	qwq=n-cnt-i;
		if(q(i)-qwq+d<0)continue;
    	ans=max(ans,max(f[cnt]-f[max(q(i)-qwq,0ll)],0ll)+f[n]-f[n-i]);
	}cout<<ans;
    return 0;
}