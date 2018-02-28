all: newshell.exe rm mkdir ls date cat

newshell.exe: newshell.o
	gcc -o newshell.exe newshell.o

newshell.o:newshell.c
	gcc -c newshell.c

rm:rm.c
	gcc rm.c -o rm
mkdir:mkdir.c
	gcc mkdir.c -o mkdir
ls:ls.c
	gcc ls.c -o ls 
date:date.c
	gcc date.c -o date
cat: cat.c
	gcc cat.c -o cat
clean:
	rm newshell.o newshell.exe mkdir ls rm date cat
