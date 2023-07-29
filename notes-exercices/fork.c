#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/*
                 parent   child
                 ------   -----
pid:              25110   25111
fork returns:     25111       0
getpid returns:   25110   25111
getppid returns:  ?????   25110


*/

int main() {
    
    int pid = fork();

    if (pid < 0)
        return 1;

    if (pid == 0)
    {
        while (1)
        {
            printf("Child returns. PID: %d", getpid());
            //usleep(500000);
        }
    }
    else
    {
        printf("Waiting...\n");
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
    }
    
}
