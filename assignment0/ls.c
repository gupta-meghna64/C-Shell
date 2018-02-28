#include <dirent.h>
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


int main(int argc, char const *argv[]){

	if(argv[1] != NULL){
		
		DIR *curr_directory;
		struct dirent *dir;
		curr_directory = opendir(".");
		if(curr_directory){
			while((dir = readdir(curr_directory)) != NULL){
				
				if(strcmp(argv[1], "-U") == 0){
					char *nm;
					nm = dir->d_name;
					char c = nm[0];
					if(c != '.'){
						printf( CYN "%s\n" RESET, dir->d_name);		
					}
				}
			}
			closedir(curr_directory);
		}

		struct dirent **dirlist;
		int num;
		num = scandir(".", &dirlist, 0, alphasort);
		int i = 0;
		for(i=0; i < num; i++){
			if(strcmp(argv[1], "-a") == 0){
				printf( CYN "%s\n" RESET, dirlist[i]->d_name);
				free(dirlist[i]);
			}
		}
		free(dirlist);
	}

	else{
		struct dirent **dirlist;
		int num;
		num = scandir(".", &dirlist, 0, alphasort);
		int i = 0;
		for(i=0; i < num; i++){
			char *nm;
			nm = dirlist[i]->d_name;
			char c = nm[0];
			if(c != '.'){
				printf( CYN "%s\n" RESET, dirlist[i]->d_name);
				free(dirlist[i]);
			}
		}
		free(dirlist);
	}
	return(0);
}