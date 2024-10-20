#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <math.h>

#define M 8


struct Prime{

    int value;

    int counter;

    int PU;

};


struct Prime calculate(struct Prime X){
	
    X.value = X.PU + X.value;
    X.counter--;
    X.PU = (X.PU + 1) % M;
    return X;
}



struct Prime* generate(){

    struct Prime *Prime_Numbers = (struct Prime*)malloc(100 * sizeof(struct Prime));
    int numbers = 0;
    int isPrime = 1;
    int i = 2;

    while(numbers < 100){

        int x = i % 8;

        for(int j = 2; j <= sqrt(i); j++){

            if(i % j == 0){

                isPrime = 0;

                break;

            }

        }

        if(isPrime){

            struct Prime temp;

            temp.value = temp.counter = i;

            temp.PU = i % M;

            Prime_Numbers[numbers] = temp;

            numbers++;

        }

        isPrime = 1;

        i++;

    }

    return Prime_Numbers;

}


int main(void){

    struct Prime *Prime_Numbers = generate();
    int fd[2];
    pipe(fd);
    int betweenChilds[2 * M];

    for(int i = 0; i < M; i++){

        pipe(&betweenChilds[2 * i]);

    }
    for(int i = 0; i < 8; i++){

        int child = fork();
        if(child == 0){

            struct Prime childrenPassing;



            while(read(betweenChilds[i * 2], &childrenPassing, sizeof(struct Prime)) > 0){


                if(childrenPassing.value == -1) break;

                childrenPassing = calculate(childrenPassing);
                if(childrenPassing.counter == 0){

                    write(fd[1], &childrenPassing, sizeof(struct Prime));

                }
                else{

                    write(betweenChilds[2 * childrenPassing.PU + 1], &childrenPassing, sizeof(struct Prime));

                }

            }

            exit(0);

        }

    }



    for(int i = 0; i < 100; i++){

        write(betweenChilds[2 * Prime_Numbers[i].PU + 1], &Prime_Numbers[i], sizeof(struct Prime));

    }



    for(int i = 0; i < 100; i++){
    	
        struct Prime Temp;

        if(read(fd[0], &Temp, sizeof(struct Prime)) > 0){

            printf("Here is the value of %d th number after all the processes: %d\n", i + 1, Temp.value);

        }

    }



    for(int i = 0; i < M; i++){

        struct Prime Temp = {-1, 0, 0};
        write(betweenChilds[i * 2 + 1], &Temp, sizeof(struct Prime));
    }
    return 0;

}