#include<bits/stdc++.h>
#define ll long long
const double pi = acos(-1); 
using namespace std;
int main()
{
	int n,r;cin>>n>>r;
	double p=sin(pi/(1.0*n)),ans=r*1.0*p/(1.0-p);
	printf("%.10lf",ans);
}