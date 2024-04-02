# Atlas Simple Shell Project
![Atlas Simple Shell Project](https://i.ibb.co/wR6sN8V/SIMPLE-SHELL.png)

## Description
A shell implemented in C serves as a command-line interpreter for Unix-like operating systems, facilitating user interaction with the system by accepting commands via the command-line interface and executing them. Acting as an intermediary between the user and the operating system, the C-based shell reads input commands, parses them, and then orchestrates their execution, enabling users to interact with the system by typing commands and receiving corresponding responses.

## Installation and Testing in Interactive and Non-interactive mode
First, clone the repository to your local machine:

```
$ git clone https://github.com/dacods/atlas-simple_shell.git
```

Next, go to the atlas-simple_shell directory:

```
$ cd atlas-simple_shell
```

Then, use the command to compile:

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
execve: No such file or directory
#$ /bin/ls
AUTHORS  README.md  execute_command_with_args.c  hsh  main.h  man_1_simple_shell  shell.c  shell_input.c
#$ ^[[D^[[D^[[D
execve: No such file or directory
#$ ^[[C^[[C^[[C^[[C
execve: No such file or directory
#$ exit
/atlas-simple_shell#
#$ ^C
/atlas-simple_shell# 
```

Non-interactive mode:

```
/atlas-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS  README.md  execute_command_with_args.c  hsh  main.h  man_1_simple_shell  shell.c  shell_input.c
/atlas-simple_shell#
```
## Flowchart
![Simple_shell_flow drawio](https://github.com/dacods/atlas-simple_shell/assets/135403583/e0f0f995-3f27-4d37-8284-600c968dee65)


## Authors and Acknowledgments

- LJ Thao [<a href="mailto:yengfong.thao@atlasschool.com">Email</a>] | [<a href="https://github.com/LJThao">@LJThao</a>]
- Dacoda Takagi [<a href="mailto:dacods.21@gmail.com">Email</a>] | [<a href="https://github.com/dacods/">@dacods</a>]

<p align="center">
  <img src="https://media1.giphy.com/media/1oF1KAEYvmXBMo6uTS/giphy.gif?cid=6c09b952mab0863mf9e67wk3bsrsznh9wn4ccgmvitg1xq8i&ep=v1_internal_gif_by_id&rid=giphy.gif&ct=g"/>
</p>
