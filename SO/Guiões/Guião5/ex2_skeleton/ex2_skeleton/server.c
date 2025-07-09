#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
#include "vector.h"

//Cliente pode receber um sigpipe (concorrência!)
int main (int argc, char * argv[]){
	init_vector();
	print_vector();

	if(mkfifo(SERVER, 0666) == -1) perror("mkfifo");

	while(1){
		int fds;
		Msg m;
		if((fds = open(SERVER, O_RDONLY)) == -1){
			perror("open server fifo");
			return -1;
		}else printf("[DEBUG] opened %s for reading\n", SERVER);

		int bytes_read;
		while((bytes_read = read(fds, &m, sizeof(m))) > 0){
			if(bytes_read == sizeof(m)){
				//falta completar
				m.occurrences = count_needle(m.needle);
				printf("found needle %d - %d times\n", m.needle, m.occurrences);
				char fifoc_name[20];
			}else perror("error reading");
		}
		close(fds);
	}
	return 0;
}