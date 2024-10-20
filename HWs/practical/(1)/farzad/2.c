#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int n,i=0,max;
    scanf("%d",&n);
    int *inps;
    int t=0;        
    inps = malloc(n * sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&inps[i]);
    }
    max=0;
    for(i=1;i<=n;i++)
    {
        int t=0;
        int j=i;
        while(j+t<=n)
        {
            int sum=0,k=0;
            for(k=t;k<j+t;k++)
            {
                sum=sum+inps[k];
            }
            if(sum>max){
                max=sum;
            }
            t=t+1;
        }
    }
    if(max<0)
    {
        printf("%d",0);
    }
    else{
        printf("%d",max);
    }
    return 0;
}
