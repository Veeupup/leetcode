#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pc, pr = 0;
    pc = fork();
    if (pc < 0) {
        printf("Error fork\n");
    }    
    else if (pc == 0) {
        printf("I am child\n");
        sleep(3);
        exit(0);
    }    
    else {
        do {
            pr = waitpid(pc, NULL, WNOHANG);
            sleep(1);
            if (pr == 0) {
                printf("wait child...\n");
            }
        } while (pr == 0);
        
        printf("I am father, child exit code %d\n", pr);
    }
    
}
