#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

char *cmdHistory[20];
FILE *fp;	
int count = 0;

void func_cd(char *inp){
	char cwd[1024];
	char parent[200];
	getcwd(cwd, sizeof(cwd));
	int res = 0;
	if(inp == NULL)
	{
		char* homedir = getenv("HOME");
		res = chdir(homedir);
	}

	else if(strcmp(inp,"~") == 0)
	{
		char* homedir = getenv("HOME");
		res = chdir(homedir);
	}
	else if(strcmp(inp, "..") == 0)
	{
		res = chdir("../");
	}
	else
	{	
		res = chdir(inp);
		if(res == -1){
			printf(RED "%s is an invalid directory \n" RESET , inp);
		}
	}
	getcwd(cwd, sizeof(cwd));
}

void func_pwd(char *inp){

	if(inp != NULL){
		if(strcmp(inp, "--help") == 0){
			printf(GRN "Print the name of the current working directory.\n\n Options:\n-L\tprint the value of $PWD if it names the current working directory\n-P\tprint the physical directory, without any symbolic links\nBy default, `pwd' behaves as if `-L' were specified.\nExit Status:\nReturns 0 unless an invalid option is given or the current directorycannot be read.\n" RESET);
		}
		else if(strcmp(inp, "--version") == 0){
			printf(GRN "GNU bash, version 4.3.48(1)-release (x86_64-pc-linux-gnu)\nCopyright (C) 2013 Free Software Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n\nThis is free software; you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n" RESET);
		}
		else{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			printf(MAG "%s\n" RESET, cwd );
		}
	}
	else{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			printf(MAG "%s\n" RESET, cwd );
		}
}

void add_to_history(char *inp){

	fp = fopen("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/historyfile.txt", "a");
	fprintf(fp, "%s\n", strdup(inp));
	fclose(fp);
	cmdHistory[count] = strdup(inp);
	count++;

}

void func_historyy(char *inp1, char *inp2){
	if(strcmp(inp1, "history") == 0 && inp2 == NULL){

		FILE* file = fopen("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/historyfile.txt", "r");
		if(file != NULL){
			char l[500];
			int cnt = 1;
			while(fgets(l, sizeof(l), file) != NULL){
				printf("\t%d  ", cnt);
				fputs(l,stdout);
				cnt = cnt + 1;
			}
			fclose(file);
		}
	}else if(strcmp(inp1, "history") == 0 && inp2 != NULL){
		int x = atoi(inp2);
		if(x > 0){
			int i = 0;
			int k = count-1;
			int linecount = 0;
			FILE* file1 = fopen("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/historyfile.txt", "r");
			if(file1 != NULL){
				char l[500];
				
				while(fgets(l, sizeof(l), file1) != NULL){	
					linecount = linecount + 1;
				}
				fclose(file1);
			}

			FILE* file = fopen("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/historyfile.txt", "r");
			if(file != NULL){
				char l[500];
				int cnt = 1;
				while(fgets(l, sizeof(l), file) != NULL){
					if(cnt > linecount-x){
						printf("\t%d  ", cnt);
						fputs(l,stdout);
					}
					cnt = cnt + 1;
				}
				fclose(file);
			}
		}
		else{
			if(strcmp(inp2, "-c") == 0){
				FILE* file = fopen("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/historyfile.txt", "w");
			}
			else
			{
				FILE* file = fopen("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/historyfile.txt", "r");
				if(file != NULL){
					char l[500];
					int cnt = 1;
					while(fgets(l, sizeof(l), file) != NULL){
						printf("\t");
						fputs(l,stdout);
						cnt = cnt + 1;
					}
					fclose(file);
				}
			}
		}
	}
}

void func_echoo(char *arr[]){
	int i=2;
	if(arr[1] == NULL){
		printf("\n");
	}else{
		if(strcmp(arr[1], "-e") == 0){
			while(arr[i] != '\0'){
				char *s = arr[i];
				int len;
				len = strlen(s);
				int j;
				for(j=0; j < len; j++){
					char c = s[j];
					if(c == '\\'){
						char next = s[j+1];
						if(next == 'n'){
							printf("\n");
							j = j + 1;
						}
						else if(next == 't'){
							printf("    ");
							j = j + 1;
						}
						else if(next == 'c'){
							break;
						}
					}else{
						if(c != '"' && c != '\''){
							printf("%c", c);
						}
					}
				}
				printf(" ");
				i = i + 1;
			}
			printf("\n");
		}
		else if(strcmp(arr[1], "-n") == 0){
			printf("%s\n", "echo-n");
			while(arr[i] != '\0'){
				char *s = arr[i];
				int len;
				len = strlen(s);
				int j;
				for(j=0; j < len; j++){
					char c = s[j];
					if(c != '\\' && c != '"' && c != '\''){
						printf("%c", c);
					}
				}
				printf(" ");
				i = i + 1;
			}
		}

		
		else{
			int i = 1;
			while(arr[i] != '\0'){
				char *s = arr[i];
				int len;
				len = strlen(s);
				int j;
				for(j=0; j < len; j++){
					char c = s[j];
					if(c != '\\' && c != '"' && c != '\''){
						printf("%c", c);
					}
				}
				printf(" ");
				i = i + 1;
			}
		printf("\n");
		}
		
	}
}

void func_help(){
	printf(CYN"\n \t \t \t    WELCOME TO C SHELL \t \t \t \nThis is an implementation of the Linux/Unix Shell in C Language. Similiar to the Linux Shell, it allows the users to enter various commands, and then it works accordingly. It supports a list of internal and external commands which are described briefly below. The implementation doesn't use the inbuilt external command implementations, instead it uses exec and fork to call the programs written for the external commands. This has been made as a part of the Operating Systems - CSE231 Course at IIIT Delhi.\n\n" RESET);
	printf( YEL "\t \t\t    Features \t \t \t \n" RESET);
	printf(YEL "The commands supported are: \n1) cd \nThis is used to change the current directory of the program. The flags supported are:\n\ta) cd .. : takes you to the parent directory\n\tb) cd ~ : takes you to the root directory\n\tc) cd [dirname] : takes you to the directory name specified\n" RESET);
	printf(YEL "\n2) echo\nThis displays a line of text. The flags supported are:\n\ta) echo -n : do not output the trailing newline\n\tb) echo -e : enable interpretation of backslash escapes\n" RESET);
	printf(YEL "\n3) history\nMany programs read input from the user a line at a time. The GNU His‐tory library is able to keep track of those lines, associate arbitrary data with each line. The flags supported are:\n\ta) history -c : This clears the history\n\tb) history [n] : Will output the last n commands entered by the user\n" RESET);
	printf(YEL "\n4) pwd\nThis prints the name of current/working directory. The flags supported are:\n\ta) pwd --help : display this help and exit\n\tb) pwd --version : output version information and exit\n" RESET);
	printf(YEL "\n5) exit\nThis causes normal process termination.\n" RESET);
	printf(YEL "\n6) mkdir\nThis make directories. The flags supported are:\n\ta) mkdir -v : print a message for each created directory\n\tb) mkdir -p : creates the parent directories as well\n\tc) mkdir --help : display this help and exit\n" RESET);
	printf(YEL "\n7) rm\nThis remove files or directories. The flags suuported are:\n\ta) rm -d : remove empty directories\n\tb) rm -f : ignore nonexistent files and arguments, never prompt\n\tc) rm -v : explain what is being done\n" RESET);
	printf(YEL "\n8) ls\nThis list directory contents. The flags supported are:\n\ta) ls -U : do not sort; list entries in directory order\n\tb) ls -a : do not ignore entries starting with .\n" RESET);
	printf(YEL "\n9) cat\nThis concatenates files and print on the standard output. The flags supported are:\n\ta) cat -E : display $ at end of each line\n\tb) cat -n : number all output lines\n" RESET);
	printf(YEL "\n10) date\nThis prints or set the system date and time. The flags supported are:\n\ta) date -u : print or set Coordinated Universal Time (UTC)\n\tb) date -r : display the last modification time of FILE\n" RESET);
}



void func_exit(){
	printf(RED "%s\n", "Exit" RESET);
	printf(YEL "%s\n", "These are stopped jobs." YEL);
	exit(0);
}

void run_shell()
{
	
	int statusID;
	while(1)
	{
		char user_input[1000];
		char **arguments;
		printf("Welcome to your shell >> ");
		scanf ("%[^\n]%*c", user_input);
		add_to_history(user_input);


		char *tokenPtr[10];
		int i=0;
		tokenPtr[i] = strtok(user_input, " ");
		while(tokenPtr[i] != NULL)
		{
			tokenPtr[++i] = strtok(NULL, " ");
		}

		int flag = 0;
		// initialize the string tokenizer and receive pointer to first token
		if(strcmp(tokenPtr[0], "exit") == 0){
			flag = 1;
			func_exit();
		}
		else if(strcmp(tokenPtr[0], "cd") == 0){
			flag = 1;
			func_cd(tokenPtr[1]);
		}
		else if(strcmp(tokenPtr[0], "pwd") == 0){
			flag = 1;
			func_pwd(tokenPtr[1]);
		}
		else if(strcmp(tokenPtr[0], "history") == 0){
			flag = 1;
			func_historyy(tokenPtr[0], tokenPtr[1]);
		}
		else if(strcmp(tokenPtr[0], "echo") == 0){
			flag = 1;
			func_echoo(tokenPtr);
		}
		else if(strcmp(tokenPtr[0], "help") == 0){
			flag = 1;
			func_help();
		}

		pid_t PID;
		int stat;
		PID = fork();
		if(PID < 0)
		{
			printf("%s\n", "Error in forking the current process!");
		}
		else if(PID == 0)
		{
			//child process
			if(strcmp(tokenPtr[0], "date") == 0 && tokenPtr[1] != NULL && tokenPtr[2] != NULL){
				flag = 1;
				execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/date", "date", tokenPtr[1], tokenPtr[2], NULL);
			}
			else if(strcmp(tokenPtr[0], "date") == 0 && tokenPtr[1] != NULL){
				flag = 1;
				execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/date", "date", tokenPtr[1], NULL);	
			}
			else if(strcmp(tokenPtr[0], "date") == 0){
				flag = 1;
				execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/date", "date", NULL);
			}
			else if(strcmp(tokenPtr[0], "ls") == 0 && tokenPtr[1] != NULL){
				flag = 1;
				execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/ls", "ls", tokenPtr[1], NULL);
			}
			else if(strcmp(tokenPtr[0], "ls") == 0){
				flag = 1;
				execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/ls", "ls", NULL);	
			}

			else if(strcmp(tokenPtr[0], "mkdir") == 0 && tokenPtr[1] == NULL){
				flag = 1;
				printf(RED "%s\n", "Missing Arguments!" RESET);
			}
			else if(strcmp(tokenPtr[0], "mkdir") == 0 && tokenPtr[1] != NULL)
			{
				flag =1;
				execv("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/mkdir", tokenPtr);
			}
			else if(strcmp(tokenPtr[0], "rm") == 0 && tokenPtr[1] == NULL){
				flag = 1;
				printf(RED "%s\n", "Missing Argument!" RESET);
			}
			else if(strcmp(tokenPtr[0], "rm") == 0 && tokenPtr[1] != NULL){
				execv("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/rm", tokenPtr);
			}
			// else if(strcmp(tokenPtr[0], "rm") == 0 && tokenPtr[1] != NULL && tokenPtr[2] == NULL){
			// 	flag = 1;
			// 	execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/rm", "rm", tokenPtr[1], NULL);
			// }
			// else if(strcmp(tokenPtr[0], "rm") == 0 && tokenPtr[1] != NULL){
			// 	flag = 1;
			// 	execl("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/rm", "rm", tokenPtr[1], tokenPtr[2], NULL);	
			// }
			else if(strcmp(tokenPtr[0], "cat") == 0){
				flag = 1;
				execv("/home/meghna/Desktop/winter2018/OS/assignments/assignment0/cat", tokenPtr);
			}
			if(flag == 0){
				printf(RED "%s\n", "Command not recognized!" RESET);
			}

			_exit(0);
			
		}
		else
		{
			//parent process
			waitpid(NULL);

		}
	}
}

int main(int argc, char const *argv[])
{
	run_shell();
	return 0;
}