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
}ll t,n,a[3005],ans;int pre[3005][3005],las[3005][3005];
int main(){
    cin>>t;
    while(t--){
    	cin>>n;
    	F(i,1,n)cin>>a[i];
    	F(i,0,n+1){
    		F(j,0,n+1){
    			pre[i][j]=las[i][j]=0;
			}
		}ans=0;
    	F(i,1,n){
    		F(j,1,n){
    			if(a[i]==j){
    				pre[i][a[i]]=pre[i-1][a[i]]+1;
				}else{
					pre[i][j]=pre[i-1][j];
				}
			}
		}UF(i,n,1){
    		F(j,1,n){
    			if(a[i]==j){
    				las[i][a[i]]=las[i+1][a[i]]+1;
				}else{
					las[i][j]=las[i+1][j];
				}
			}
		}F(i,1,n){
			F(j,i+1,n){
				ans+=((ll)pre[i-1][a[j]])*las[j+1][a[i]];
			}
		}cout<<ans<<endl;
	}
    return 0;
}