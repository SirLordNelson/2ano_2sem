#include "mysystem.h"

int mysystem(const char* command){
	int res = -1;
	int status;
	int i = 0;
    char *args[64];
    char *token = strtok((char *)command, " ");

    while(token != NULL){
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

	if(fork() == 0){
		execvp(args[0], args);
		_exit(EXIT_FAILURE);
	}
	if(WEXITSTATUS(status)) return WEXITSTATUS(status);
	else return res;
}