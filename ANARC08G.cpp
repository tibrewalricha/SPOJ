#include<cstdio>
using namespace std;

int main()
{
    int n,i,j,m,c,arr[1010],res1,res2;

    c=0;
    while(scanf("%d",&n)!=EOF)
    {
        c++;
        if(n==0)
            break;

        for(i=0;i<n;i++)
            arr[i] = 0;

        res1=res2=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&m);
                arr[i]-=m;
                arr[j]+=m;
                res1+=m;
            }
        }

        for(i=0;i<n;i++)
        {
            if(arr[i]>=0)
                res2+=arr[i];
        }
        printf("%d. %d %d\n",c,res1,res2);
    }
    return 0;
}
