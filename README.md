# C-Shell

This is an implementation of the Linux/Unix Shell in C Language. Similiar to the Linux Shell, it allows the users to enter various commands, and then it works accordingly. It supports a list of internal and external commands which are described briefly below. The implementation doesn't use the inbuilt external command implementations, instead it uses exec and fork to call the programs written for the external commands. This has been made as a part of the Operating Systems - CSE231 Course at IIIT Delhi.

## Features

The various commands supported by the C-Shell is:
  #### 1) cd
  This is used to change the current directory of the program. The flags supported are:   
    a) cd ..  : takes you to the parent directory  
    b) cd ~   : takes you to the root directory  
    c) cd [dirname]   : takes you to the directory name specified
  #### 2) echo
  This displays a line of text. The flags supported are:  
    a) echo -n  : do not output the trailing newline  
    b) echo -e  : enable interpretation of backslash escapes  
  #### 3) history
  Many programs read input from the user a line at a time.  The GNU  His‐tory  library is able to keep track of those lines,   associate arbitrary data with each line. The flags supported are:  
    a) history -c  : This clears the history  
    b) history [n]  : Will output the last n commands entered by the user  
  #### 4) pwd
  This prints the name of current/working directory. The flags supported are:  
    a) pwd --help  : display this help and exit  
    b) pwd --version  : output version information and exit  
  #### 5) exit
  This causes normal process termination.  
  #### 6) mkdir
  This make directories. The flags supported are:  
    a) mkdir -v  : print a message for each created directory  
    b) mkdir --help  : display this help and exit  
  #### 7) rm
  This remove files or directories. The flags suuported are:  
    a) rm -d  : remove empty directories  
    b) rm -f  : ignore nonexistent files and arguments, never prompt  
    c) rm -v  : explain what is being done   
  #### 8) ls
  This list directory contents. The flags supported are:  
    a) ls -U  : do not sort; list entries in directory order  
    b) ls -a  : do not ignore entries starting with .    
  #### 9) cat
  This concatenates files and print on the standard output. The flags supported are:  
    a) cat -E  : display $ at end of each line  
    b) cat -n  : number all output lines  
  #### 10) date
  This prints or set the system date and time. The flags supported are:
    a) date -u  : print or set Coordinated Universal Time (UTC)
    b) date -r  : display the last modification time of FILE
        
## Setting it up

Clone the Repository and set it up on your Desktop. Open Terminal(Ctrl+Alt+T) and then type:  
    ``make``  
    ``.\newshell``  


## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc
