#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n;
int a[32];
pair<int,int> w[32];
int b[32];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",a+i);
		w[i]=mp(a[i],i);
	}
	sort(w,w+n);
	fore(i,0,n-1)b[w[i].snd]=w[i+1].fst;
	b[w[n-1].snd]=w[0].fst;
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",b[i]);
	}
	puts("");
	return 0;
}