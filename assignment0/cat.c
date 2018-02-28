#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
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
	if(strcmp(argv[1], "-n") == 0){
		int i = 2;
		int cnt = 1;
		while(argv[i] != '\0'){
			int flag;
			struct stat st = {0};
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			strcat(cwd, "/");
			strcat(cwd, argv[i]);
			if(stat(cwd, &st) == -1){
				printf(RED "%s\n", "No such directory exists!" RESET);
			}
			FILE *file = fopen(cwd, "r");
			if(file != NULL){
				char l[1000];
				while(fgets(l, sizeof(l), file) != NULL){
					printf("\t%d ", cnt);
					fputs(l, stdout);
					cnt = cnt+1;
				}
				fclose(file);
			}
			else
			{
				printf(RED "%s\n", "Error!" RESET);
			}
			i = i+1;
		}
	}
	else if(strcmp(argv[1], "-E") == 0){
		int i = 2;
		while(argv[i] != '\0'){
			int flag;
			struct stat st = {0};
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			strcat(cwd, "/");
			strcat(cwd, argv[i]);
			if(stat(cwd, &st) == -1){
				printf(RED "%s\n" RESET, "No such file exists!");
			}
			FILE* file = fopen(cwd, "r");
			if(file != NULL){
				char l[500];
				while(fgets(l, sizeof(l), file) != NULL){
					int len = strlen(l);
					int i = 0;
					l[len-1] = '$';
					fputs(l, stdout);
					printf("\n");
				}
				fclose(file);
			}
			else
			{
				printf(RED "%s\n" RESET, "Error");
			}
			i = i + 1;
		}

	}
	else
	{
		//printf("%s\n", "aa");
		int i = 1;
		while(argv[i] != '\0'){
			//printf("%s\n", "bb");
			struct stat st = {0};
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			strcat(cwd, "/");
			strcat(cwd, argv[i]);
			//printf("%s\n", cwd);
			if(stat(cwd, &st) == -1){
				printf(RED "%s\n" RESET, "No such file exists!");
			}
			FILE* file = fopen(cwd, "r");
			if(file != NULL){
				char l[500];
				while(fgets(l, sizeof(l), file) != NULL){
					fputs(l,stdout);
				}
				fclose(file);
			}
			else
			{
				printf(RED "%s\n" RESET, "Error");
			}
			i = i + 1;

		}
	}

	return 0;
}