#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    scanf("%i",&n);

    if(n==1)return 2;

    return n/3+(n%3>0);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}