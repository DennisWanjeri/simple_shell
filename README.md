## Simple Shell
> In this project, we coded from scratch a simple Unix shell.
> This shell is an interactive commandline interpreter.
> This shell that we created utilizes the command line interface (CLI).
> It allows users to type in a defined set of commands
> (e.g. "env" to print out the environment, "rm" to remove files,
> "ls" to list file in the current directory, etc) and have the operating
> system run the appropriate function. Our shell is a simple version
> that handles memory leaks very well and has basic functionality.
> It allows the user to manipulate folders however they want,
> from writing, reading, etc, print things to the terminal,
> change directories, print where you are in the system, among others.

### Synopsis
> On this Simple Shell repository it holds all the code necessary for
> our custom simple shell to run. Our shell currently handles the executions
> of executables found in the environmental variable PATH.
> Some of the commands that our shell supports include /bin/ls, pwd, env, etc.

#### Some of the allowed functions and system calls
```access```, ```chdir```, ```close```, ```closedir```, ```execve```,```exit```
```_exit```, ```signal```, ```malloc```, ```free```, ```getcwd```, ```wait```, ```write```.

### File Descriptions




### Shell Usage
* Install
```
(your_terminal)$ git clone https://github.com/DennisWanjeri/simple_shell.git
(your_terminal)$ cd simple_shell
```
* Compile
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
* Usage: non-interactive mode
```
echo "/bin/ls" | ./hsh
```
* Usage: interactive mode
```
(your_terminal)$ ./hsh
```

#### Illustration
```
#cisfun$ ls -l
total 4
-rw-rw-r-- 1
-rw-rw-r-- 1
-rw-rw-r-- 1
-rw-rw-r-- 1
#cisfun$ echo "simple shell easy!"
simple shell easy!
#cisfun$ exit 98
(your_terminal)$
```
#### Authors
1. [Dennis Wanjeri](https://github.com/DennisWanjeri)
2. [Jane Ng'ethe](https://github.com/Janengethe)