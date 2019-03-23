#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include<unistd.h>  
int main(int argc, char **argv)
{
	char s[100];
	char *line = NULL;
	size_t linesize = 0;
	size_t linelen;
	printf("yeet> ");
	while ((linelen = getline(&line, &linesize, stdin)) != -1) {

			if (strncmp("exit", line, 4) == 0) {
				// user wants to exit
				exit(0);
			} else if(strncmp("cd", strcat(line, line + 1), 2) == 0) {
				
				char *str;
				for(int i = 3; i < linelen; i++) {
						if(i == 3 && line [i] != '/') {
								str[i - 3] = '/';
						}
						str[i - 2] += line[i];
						
				}
				fwrite(str, 1, linelen - 2, stdout);
				
				chdir(str);
				
				//printf("hello\n");
			} else {
				char error_message[30] = "An error has occurred\n";
    			write(STDERR_FILENO, error_message, strlen(error_message)); 
			}
			//fwrite(line, linelen, 1, stdout);
			printf("yeet> ");
	// fork
	// if child, exec
	// if parent, wait
	}
	free(line);
	if (ferror(stdin))
			err(1, "getline");
}