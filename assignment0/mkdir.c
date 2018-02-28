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
	if(argv[2] != NULL){
		if(strcmp(argv[1], "-v") == 0){
			int i =2;
			while(argv[i] != '\0'){
				struct stat st = {0};
				char cwd[1024];
				getcwd(cwd, sizeof(cwd));
				strcat(cwd, "/");
				strcat(cwd, argv[i]);
				printf("%s\n", cwd);
				if(stat(cwd, &st) == -1){
					mkdir(cwd, 0700);
					printf(GRN "%s\n" RESET, "Directory Created!");
				}
				else
				{
					printf(RED "%s\n" RESET, "Directory Already Exists!");
				}
				i = i + 1;

			}
		}
		else if(strcmp(argv[1], "-p") == 0){
			int i = 2;
			while(argv[i] != '\0'){
				char path[300];
				char *p = NULL;
				size_t length;
				snprintf(path, sizeof(path), "%s", argv[i]);
				length = strlen(path);
				if(path[length-1] == '/'){
					path[length-1] = 0;
				}
				for(p = path+1; *p; p++){
					if(*p == '/'){
						*p = 0;
						mkdir(path, S_IRWXU);
						*p = '/';
					}
				}
				mkdir(path, S_IRWXU);
				printf(GRN "%s\n", "All directories created successfully!" RESET);
				i = i + 1;
			}
			
		}
		else
		{
			int i = 1;
			while(argv[i] != '\0'){
				struct stat st = {0};
				char cwd[1024];
				getcwd(cwd, sizeof(cwd));
				strcat(cwd, "/");
				strcat(cwd, argv[i]);
				if(stat(cwd, &st) == -1){
					mkdir(cwd, 0700);
				}
				else
				{
					printf(RED "%s\n" RESET, "Directory Already Exists!");
				}
				i = i + 1;
			}	
		}
	}
	else{
		if(argv[1] == NULL){
			printf(RED "%s\n", "Missing Argument!" RESET);
		}
		else if(strcmp(argv[1], "--help") == 0){
	 		printf(GRN "Usage: mkdir [OPTION]... DIRECTORY...\nCreate the DIRECTORY(ies), if they do not already exist.\n\nMandatory arguments to long options are mandatory for short options too.\n  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask\n  -p, --parents     no error if existing, make parent directories as needed\n  -v, --verbose     print a message for each created directory\n  -Z                   set SELinux security context of each created directory\n                         to the default type\n      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux\n                         or SMACK security context to CTX\n      --help     display this help and exit\n      --version  output version information and exit\n\n\nGNU coreutils online help: <http://www.gnu.org/software/coreutils/>\nFull documentation at: <http://www.gnu.org/software/coreutils/mkdir>\nor available locally via: info '(coreutils) mkdir invocation'\n" RESET);

		}
		else{
			int i = 1;
			while(argv[i] != '\0'){
				struct stat st = {0};
				char cwd[1024];
				getcwd(cwd, sizeof(cwd));
				strcat(cwd, "/");
				strcat(cwd, argv[i]);
				if(stat(cwd, &st) == -1){
					mkdir(cwd, 0700);
				}
				else
				{
					printf(RED "%s\n" RESET, "Directory Already Exists!");
				}
				i = i + 1;
			}
		}
	}


	return 0;
}

