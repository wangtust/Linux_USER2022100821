# 进程间通信方式有哪些
进程间通信（Inter-Process Communication，IPC）是指在不同进程之间传递和共享信息的机制。以下是一些常见的进程间通信方式：

1. **管道（Pipe）和命名管道（Named Pipe）**：管道是一种半双工的通信方式，数据只能单向流动；而命名管道则是全双工的。

2. **消息队列（Message Queue）**：消息队列是由消息的链表，存放在内核中并由消息队列标识符标识。

3. **共享内存（Shared Memory）**：共享内存就是映射一段能被其他进程所访问的内存，这段共享内存由一个进程创建，但多个进程都可以访问。

4. **信号量（Semaphore）**：信号量是一个计数器，可以用来控制多个进程对共享资源的访问。

5. **套接字（Socket）**：套接字可以用于不同机器之间的进程通信。

6. **信号（Signal）**：信号是一种更复杂的通信方式，用于通知接收进程某个事件已经发生。

以上就是一些常见的进程间通信方式，每种方式都有其特点和适用场景，需要根据具体需求来选择。

在Linux系统中，我们可以使用管道（Pipe）来实现进程间的通信。以下是一个简单的C语言示例，展示了如何使用管道在父进程和子进程之间传递数据：

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    /* 创建管道 */
    if (pipe(fd) == -1) {
        fprintf(stderr,"Pipe failed");
        return 1;
    }

    /* 创建子进程 */
    pid = fork();

    if (pid < 0) { /* fork失败 */
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) { /* 父进程 */
        /* 关闭不需要的读端 */
        close(fd[READ_END]);

        /* 写入数据到管道 */
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1); 

        /* 关闭写端 */
        close(fd[WRITE_END]);
    } else { /* 子进程 */
        /* 关闭不需要的写端 */
        close(fd[WRITE_END]);

        /* 从管道读取数据 */
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s",read_msg);

        /* 关闭读端 */
        close(fd[READ_END]);
    }

    return 0;
}
```

在这个例子中，父进程创建了一个管道，然后创建了一个子进程。父进程将数据写入管道，子进程从管道读取数据。

管道（Pipe）是一种基于内核的进程间通信机制。在Linux系统中，管道是一种半双工的通信方式，数据只能单向流动，通常用于父子进程之间的通信。

在你给出的代码中，父进程和子进程通过一个管道进行通信。管道有两个端口：一个读端（READ_END）和一个写端（WRITE_END）。父进程写入数据到管道的写端，子进程从管道的读端读取数据。

以下是代码的详细步骤：

1. 创建管道：`pipe(fd)`函数创建一个新的管道，`fd`是一个包含两个文件描述符的数组，`fd[0]`是读端，`fd[1]`是写端。

2. 创建子进程：`fork()`函数创建一个新的子进程。

3. 在父进程中：
   - 关闭不需要的读端：`close(fd[READ_END])`。
   - 写入数据到管道：`write(fd[WRITE_END], write_msg, strlen(write_msg)+1)`，这里`write_msg`是要写入的数据。
   - 关闭写端：`close(fd[WRITE_END])`。

4. 在子进程中：
   - 关闭不需要的写端：`close(fd[WRITE_END])`。
   - 从管道读取数据：`read(fd[READ_END], read_msg, BUFFER_SIZE)`，这里`read_msg`是用来存储读取的数据的缓冲区。
   - 打印读取的数据：`printf("read %s",read_msg)`。
   - 关闭读端：`close(fd[READ_END])`。

这样，父进程和子进程就通过管道实现了通信。

管道（Pipe）是一种特殊的文件，它是一种单向的、先进先出的、无结构的、固定大小的字节流。这些特性具体解释如下：

1. 单向性：管道是单向的，这意味着数据只能在一个方向上流动。在创建管道时，会生成两个文件描述符，一个用于读取，一个用于写入。数据从写入端进入管道，从读取端出来。

2. 先进先出：管道遵循先进先出（FIFO）的原则，也就是说，最先进入管道的数据最先被读出。

3. 无结构：管道没有内部结构，它只是一个字节流。这意味着你不能像在文件中那样在管道中寻找特定位置的数据。

4. 固定大小：管道的大小是固定的，当管道满时，任何试图写入的进程都会被阻塞，直到有其他进程从管道中读取数据为止。同样，如果管道为空，任何试图从中读取数据的进程都会被阻塞，直到有其他进程向管道写入数据为止。

5. 文件性质：从本质上说，管道是一种特殊的文件，它存在于内存中，而不是硬盘上。但是，和普通文件一样，管道也有文件描述符，并且可以使用像read()和write()这样的系统调用来操作管道。

这些特性使得管道成为进程间通信的一种简单有效的方式。
## pipe函数
`pipe()`函数是在Unix和Linux系统中用于创建管道的系统调用。管道是一种进程间通信的方式，允许一个进程向另一个进程发送数据。

`pipe()`函数的原型如下：

```c
#include <unistd.h>
int pipe(int pipefd[2]);
```

这个函数接收一个包含两个整数的数组`pipefd`作为参数。当函数成功执行后，`pipefd[0]`将会是管道的读取端的文件描述符，`pipefd[1]`将会是管道的写入端的文件描述符。

如果`pipe()`函数成功执行，它将返回0。如果执行失败，它将返回-1，并设置全局变量`errno`以指示错误类型。

在你的代码中，`pipe(fd)`创建了一个新的管道，其中`fd`是一个包含两个文件描述符的数组，`fd[0]`是读取端，`fd[1]`是写入端。如果`pipe()`函数执行失败，程序将打印错误信息并返回1。

	管道的读写（实际上是Linux中文件的读写系统调用）：
#include <unistd.h>
原型：size_t write(int filedes,const void * buf,size_t nbytes);	//写
功能：把buf开始nbytes字节的内容插入到filedes所指出的文件的当前位置。
返回值：若成功则返回已写的字节数，若出错则返回-1。

原型：size_t read(int filedes,const void* buf,size_t nbytes);   //读
		功能：从filedes所指出的文件的当前位置，读取nbytes个字节数据，并存放在
buf所指出的缓冲区中。
		返回值：若成功则返回读到的字节数，若已到文件结尾则返回0,若出错则返回-1。

`write()`和`read()`是Linux系统中的两个系统调用，用于文件和管道的读写操作。以下是它们的详细解释：

1. `write()`函数：

```c
#include <unistd.h>
ssize_t write(int filedes, const void *buf, size_t nbytes);
```

`write()`函数将`buf`开始的`nbytes`字节的内容写入到`filedes`所指定的文件或管道。`filedes`是要写入的文件或管道的文件描述符，`buf`是要写入的数据的缓冲区，`nbytes`是要写入的字节数。

如果函数执行成功，它将返回实际写入的字节数。如果出错，它将返回-1，并设置全局变量`errno`以指示错误类型。

2. `read()`函数：

```c
#include <unistd.h>
ssize_t read(int filedes, void *buf, size_t nbytes);
```

`read()`函数从`filedes`所指定的文件或管道的当前位置读取`nbytes`个字节的数据，并将其存放在`buf`所指定的缓冲区中。`filedes`是要读取的文件或管道的文件描述符，`buf`是用来存储读取的数据的缓冲区，`nbytes`是要读取的字节数。

如果函数执行成功，它将返回实际读取的字节数。如果已到达文件或管道的结尾，它将返回0。如果出错，它将返回-1，并设置全局变量`errno`以指示错误类型。
