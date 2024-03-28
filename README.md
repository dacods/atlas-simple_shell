# Atlas Simple Shell Project
![Atlas Simple Shell Project](https://i.ibb.co/wR6sN8V/SIMPLE-SHELL.png)

## Description
A shell implemented in C serves as a command-line interpreter for Unix-like operating systems, facilitating user interaction with the system by accepting commands via the command-line interface and executing them. Acting as an intermediary between the user and the operating system, the C-based shell reads input commands, parses them, and then orchestrates their execution, enabling users to interact with the system by typing commands and receiving corresponding responses.

## Testing in interactive mode and non-interactive mode and on how to use it?
First, we clone our repository to our local machine by:

```
$ git clone https://github.com/dacods/atlas-simple_shell.git
```

Next, we go to our location and find the atlas-simple_shell folder by:

```
$ cd atlas-simple_shell
```

Then, we will use this command to compile:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Interactive mode by running:

```
$ ./hsh
```

Non-interactive mode by running:

```
$ echo "/bin/ls" | ./hsh
```

## Usage examples
Interactive mode:

```
/atlas-simple_shell# ./hsh
#$ ls
./hsh: No such file or directory
#$ /bin/ls
AUTHORS  README.md  execute_command_with_args.c  hsh  main.h  man_1_simple_shell  shell.c
#$ ^[[D^[[D^[[D
.hsh: No such file or directory
#$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#$ exit
./hsh: No such file or directory
#$ ^C
```

Non-interactive mode:

```
/atlas-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS  README.md  execute_command_with_args.c  hsh  main.h  man_1_simple_shell  shell.c
/atlas-simple_shell#
```

## Authors and Acknowledgments

```
LJ Thao | Dacoda Takagi
```

<p align="center">
  <img src="https://media1.giphy.com/media/1oF1KAEYvmXBMo6uTS/giphy.gif?cid=6c09b952mab0863mf9e67wk3bsrsznh9wn4ccgmvitg1xq8i&ep=v1_internal_gif_by_id&rid=giphy.gif&ct=g"/>
</p>
