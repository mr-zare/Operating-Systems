#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

/*
int main(int argc, char *argv[]) {
	char inps[200];
	gets(inps);
	int i=0,t=1;
	while(inps[i]!='\0')
	{
 		i=i+1;
		t=t+1;
	}
	int sum;
	char sefr = '0';

	for(i=0;i<t;i++)
	{
		if(inps[i]==' ')
		{
            continue;
		}
		if(inps[i]=='}')
		{
            sum=0;
			int j=i;
			while(inps[j]!='{')
			{
				j=j-1;
				if(isdigit(inps[j]))
				{
					if(isdigit(inps[j-1]) && isdigit(inps[j-2]))
					{
						sum=sum+(inps[j-2]-sefr)*100+(inps[j-1]-sefr)*10 +(inps[j]-sefr);
						j=j-1;
					}
					else if(isdigit(inps[j-1]) && isdigit(inps[j-2])!=true)
					{
						sum=sum+(inps[j-1]-sefr)*10+(inps[j]-sefr);
					}
					else{
						sum=sum+(inps[j]-sefr);
					}
				}
	    	}
            inps[j]=' ';
            inps[i]=' ';
            printf("%d\n",sum);

		}
	}
	return 0;
}
*/

int main(int argc, char *argv[]) {
	char inps[200];
	gets(inps);
	int i=0,t=1;
	while(inps[i]!='\0')
	{
 		i=i+1;
		t=t+1;
	}
	int sum;
	char sefr = '0';

	for(i=0;i<t;i++)
	{
		if(inps[i]==' ')
		{
            continue;
		}
		if(inps[i]=='}')
		{
            sum=0;
			int j=i;
			while(inps[j]!='{')
			{
				j=j-1;
				if(isdigit(inps[j]))
				{
					int m=0,z=1;
					while(isdigit(inps[j]))
					{
						if(inps[j]==' ')
						{
							j=j-1;
							continue;
						}
						m=m+(inps[j]-sefr)*z;
						z=z*10;
						j=j-1;
					}
				
					sum=sum+m;
				/*
					if(isdigit(inps[j-1]) && isdigit(inps[j-2]))
					{
						sum=sum+(inps[j-2]-sefr)*100+(inps[j-1]-sefr)*10 +(inps[j]-sefr);
						j=j-1;
					}
					else if(isdigit(inps[j-1]) && isdigit(inps[j-2])!=true)
					{
						sum=sum+(inps[j-1]-sefr)*10+(inps[j]-sefr);
					}
					else{
						sum=sum+(inps[j]-sefr);
					}
				*/
				}
	    	}
            inps[j]=' ';
            inps[i]=' ';
            printf("%d\n",sum);

		}
	}
	return 0;
}