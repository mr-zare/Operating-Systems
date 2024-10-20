//az code haye site hay roberoo estefade shode: https://www.cs.usfca.edu/~mmalensek/cs326/schedule/code/week11/pi-pthread.c.html   va
// https://cboard.cprogramming.com/cplusplus-programming/180321-multi-threading-calculating-pi-user-input.html ast va az hal anha bara hal donbale dade shode bar asas
//khaste soal estefade shode.

#include <pthread.h>
#include <stdio.h>
#include <math.h>

pthread_mutex_t lock_ch;
double ans=0;
const int tedadthread=10;
int tedad=10000000;

void* compute(void* args){
	double sum=0;
    int begin=*((pthread_t*)args);
    for (int i = begin; tedad >= i; i=tedadthread+i)
    {
        double formula=1.0;
        if(i&1) formula=-1.0;
        formula=formula/(2.0*i+1.0);
        sum+=formula;
    }
    pthread_mutex_lock(&lock_ch);
    ans=ans+sum;
    pthread_mutex_unlock(&lock_ch);
}

int main(){
    pthread_mutex_init(&lock_ch,NULL);
    pthread_t thread_ids[tedadthread];
    int ids_t[tedadthread];
    int i=0;
    while(i<tedadthread)
    {
        ids_t[i]=i;
        pthread_create(thread_ids+i,NULL,*compute,ids_t+i);
        i++;
	}
	i=0;
	while(i<tedadthread)
	{
        pthread_join(thread_ids[i],NULL);
        i++;
	}
    printf("answer with tedad=%d: %lf\n",tedad,ans);
    printf("meqdar pi/4 :%lf\n",M_PI/4.0);
    return 0;
}