# pipex

## Project Description

The `pipex` project is part of the School 42 curriculum, aimed at enhancing your understanding of process creation, inter-process communication, and file I/O in Unix-like operating systems. The goal of this project is to implement a simplified version of the shell pipeline functionality using C.

## What It Does

The `pipex` program emulates the behavior of the Unix shell pipeline. It takes two commands and connects the output of the first command to the input of the second command, passing through a pipe.

## Implementation Details

- **Language**: The project is implemented in C.
- **Main Program**:
  - `pipex infile cmd1 cmd2 outfile`: Executes `cmd1`, redirects its output to `cmd2` using a pipe, and writes the final output to `outfile`.
- **Headers**:
  - `#include <unistd.h>`: For pipe, fork, dup2, and execve functions.
  - `#include <stdlib.h>`: For memory allocation.
  - `#include <fcntl.h>`: For file operations.
  - `#include <sys/wait.h>`: For wait function.
- **Key Concepts**:
  - **Pipes**: Used for creating a unidirectional data channel between two processes.
  - **Fork**: Used for creating child processes.
  - **Dup2**: Used for redirecting file descriptors.
  - **Execve**: Used for executing commands.
  - **File Descriptors**: Managed to handle input and output redirection.

### How It Works

1. **Opening Files**: The program opens the `infile` for reading and the `outfile` for writing.
2. **Creating Pipes**: A pipe is created to connect the output of the first command to the input of the second command.
3. **Forking Processes**:
   - The first child process executes `cmd1`, redirecting its output to the write end of the pipe.
   - The second child process executes `cmd2`, redirecting its input from the read end of the pipe.
4. **Redirecting File Descriptors**:
   - `dup2` is used to redirect the standard input and output to the appropriate file descriptors.
5. **Executing Commands**:
   - `execve` is used to execute the commands in the respective child processes.
6. **Waiting for Processes**: The parent process waits for both child processes to complete.

---

This project provides a practical exercise in using Unix system calls for process management and inter-process communication, essential skills for systems programming.
