#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

	if(argv[2] != NULL){
		if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "-dv") == 0){
			int i = 2;
			while(argv[i] != "\0"){
				int flag;
				struct stat st = {0};
				char cwd[1024];
				getcwd(cwd, sizeof(cwd));
				strcat(cwd, "/");
				strcat(cwd, argv[i]);
				if(stat(cwd, &st) == -1){
					printf(RED "%s\n" RESET, "No such directory exists!" RESET);
				}else{
					flag = rmdir(cwd);
					if(!flag){
						printf(GRN "%s\n" RESET, "Directory deleted successfully!" RESET);
					}else{
						printf(RED "%s\n" RESET, "Can only remove empty directory!" RESET);
				
					}
				}
				i = i + 1;
			}
		}
		else if(strcmp(argv[1], "-f") == 0){
			int i = 2;
			while(argv[i] != '\0'){
				int flag;
				struct stat st = {0};
				char cwd[1024];
				getcwd(cwd, sizeof(cwd));
				strcat(cwd, "/");
				strcat(cwd, argv[i]);
				if(remove(cwd) == 0){
				}
				else{
				}
				i = i + 1;
			}
		}
		else{
			int i = 1;
			while(argv[i] != '\0'){
				int flag;
				struct stat st = {0};
				char cwd[1024];
				getcwd(cwd, sizeof(cwd));
				strcat(cwd, "/");
				strcat(cwd, argv[i]);
				if(remove(cwd) == 0){
				}else{
				}
				i = i + 1;
			}
		}
	}

	// if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-v") == 0){
	// 	int flag;
	// 	struct stat st = {0};
	// 	char cwd[1024];
	// 	getcwd(cwd, sizeof(cwd));
	// 	strcat(cwd, "/");
	// 	strcat(cwd, argv[2]);
	// 	if(stat(cwd, &st) == -1){
	// 		printf(RED "%s\n" RESET, "No such directory exists!");
	// 	}else{
	// 		flag = rmdir(cwd);
	// 		if(!flag){
	// 			printf(GRN "%s\n" RESET, "Directory deleted successfully!");
	// 		}else{
	// 			printf(RED "%s\n" RESET, "Can only remove empty directory!");
		
	// 		}
	// 	}
	// }
	// else if(strcmp(argv[1], "-f") == 0){
	// 	int flag;
	// 	struct stat st = {0};
	// 	char cwd[1024];
	// 	getcwd(cwd, sizeof(cwd));
	// 	strcat(cwd, "/");
	// 	strcat(cwd, argv[2]);
	// 	if(remove(cwd) == 0){
	// 	}else{
	// 	}
	// }
	// else{
	// 	int flag;
	// 	struct stat st = {0};
	// 	char cwd[1024];
	// 	getcwd(cwd, sizeof(cwd));
	// 	strcat(cwd, "/");
	// 	strcat(cwd, argv[1]);
	// 	if(remove(cwd) == 0){
	// 	}else{
	// 	}
	// }
	
	return 0;
}