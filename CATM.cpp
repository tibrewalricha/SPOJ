#include<cstdio>
using namespace std;

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

bool check(int r1,int c1,int r2,int c2,int r3,int c3)
{
    int d1,d2,d3,d4;
    d1 = abs(r1-r2);
    d2 = abs(c1-c2);
    d3 = abs(r1-r3);
    d4 = abs(c1-c3);

    if(d1==d2 && d3==d4)
    {
        if((d1+d3 == abs(r2-r3))&& (d2+d4 ==abs(c2-c3)))
            return false;
    }
    return true;
}

int main()
{
    int m,n,r1,r2,r3,c1,c2,c3;

    scanf("%d%d",&m,&n);
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3);
        bool ans;

        ans = check(r1,c1,r2,c2,r3,c3);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
