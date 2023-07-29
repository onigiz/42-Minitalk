#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


// Sinyal işleyici işlevi
void customSignalHandler(int signum) {
    printf("Sinyal %d alındı. Program kapanıyor...\n", signum);
    sleep(2);
    printf("Program kapandı!\n\n");
    exit(signum);
}

int main() {
    // SIGINT sinyali için customSignalHandler işlevini atayalım.
    signal(SIGINT, customSignalHandler);

    while (1) {
        printf("Program çalışıyor. Çıkmak için Ctrl+C tuş kombinasyonunu kullanın.\n");
        sleep(1);
    }

    return 0;
}
