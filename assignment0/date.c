#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int main(int argc, char const *argv[])
{
	char arr[150];
	time_t currtime;
	struct tm *local_time;
	
	if(argv[1] != NULL && argv[2] != NULL){
		if(strcmp(argv[1], "-r") == 0){
			struct tm *filetime;
			struct stat st = {0};
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			strcat(cwd, "/");
			strcat(cwd, argv[2]);
			stat(cwd, &st);
			if(stat(cwd, &st) == -1){
				printf(RED "%s\n", "No such file exists!" RESET);
			}
			else{
				filetime = gmtime(&(st.st_mtime));
				printf(YEL "%s" RESET, asctime(filetime));
			}
		}	
	}

	else if(argv[1] != NULL){
		if(strcmp(argv[1], "-u") == 0){
			currtime = time(NULL);
			local_time = gmtime(&currtime);
			printf(YEL "%s" RESET, asctime(local_time));
		}
		else{
			printf(RED "%s\n", "Invalid Argument!" RESET);
		}

	}

	else{

		if(argv[1] != NULL){
			printf(RED "%s\n", "Invalid Argument!" RESET);
		}
		else{
			time_t tm;
			time(&tm);
			printf(YEL "%s" RESET, ctime(&tm));
		}

	}
	return 0;
}