#include<stdio.h>
#include<string.h>

struct person
{
    char name[100];
    long pricekharj;
    long pricegerfte; 
};


int main(int argc, char const *argv[])
{
  struct person fard[15]={0,0,0};
  
  int num_person;
  int money;
  int numf;
  scanf("%d",&num_person);
  int i=0;
  for (i=0; i < num_person; i++)
  {
   scanf("%s",fard[i].name);
   }
   int j=0;
   char namegiftde[100];
   char namegiftgir[100];
   for (; j < num_person; j++)
   {
       scanf ("%s",namegiftde);
       scanf("%ld",&money);
       i=0;
       for (; i < num_person; i++)
       {
           if(strcmp(fard[i].name,namegiftde)!=0)
           {

           }
           else if(strcmp(fard[i].name,namegiftde)==0)
           {
               break;
           }
       }

       fard[i].pricekharj+=money;
        scanf("%d",&numf);

       if(numf==0)
       {
           fard[i].pricegerfte+=money;
           continue;
       }

       fard[i].pricegerfte+=money%numf;
       int z=0;
       int divide=numf;
       
   for (z=0; z < numf; z++)
   {
       scanf("%s",namegiftgir);
       i=0;
        for (; i < num_person; i++)
       {
           if(strcmp(fard[i].name,namegiftgir)!=0)
           {
               
           }
          else if(strcmp(fard[i].name,namegiftgir)==0)
           {
               break;
           }
       }
       fard[i].pricegerfte+=money/numf;
   }

   }
   i=0;
   for(; i < num_person; i++)
   {
       printf("%s %ld\n",fard[i].name,fard[i].pricegerfte-fard[i].pricekharj);
   }
   return 0;
}