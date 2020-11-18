#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void func1(){
    printf("****Alarm triggered**** \n");
}

void main(){
    //printf("before alarm \n");
    alarm(5); //emits signal
    signal(SIGALRM, func1); 
    pause(); //cause program to suspend and waits for the signal
}