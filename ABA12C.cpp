#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#include<climits>
#define MAXLEN 110
using namespace std;

void knapsack_bottom_up(int val[],int w)
{
    int ans[w+1],i,j;

    for(i=1;i<=w;i++)
    {
        ans[i] = val[i];
    }


    for(i=2;i<=w;i++)
    {
        for(j=1;j<i;j++)
        {
            if(val[i-j]==-1 || ans[j]==-1)
                continue;

            if(ans[i]==-1)
                ans[i] = ans[j] + val[i-j];
            else
                ans[i] = min(ans[i],ans[j]+val[i-j]);
        }
    }
    printf("%d\n",ans[w]);
}

int main()
{
    int n,k,arr[MAXLEN],i,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=k;i++)
            scanf("%d",&arr[i]);

        knapsack_bottom_up(arr,k);
    }
}
