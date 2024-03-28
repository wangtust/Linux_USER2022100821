# fork
`fork()` 是一个在 Unix 和 Linux 系统中常用的系统调用，用于创建新的进程。当一个进程调用 `fork()` 时，它会创建一个新的进程。新的进程（称为子进程）是原始进程（称为父进程）的一个副本。子进程从父进程继承了代码、数据和堆栈等资源，但是它有自己的进程 ID。

`fork()` 的返回值在父进程和子进程中是不同的。在父进程中，`fork()` 返回新创建的子进程的进程 ID。在子进程中，`fork()` 返回 0。如果 `fork()` 调用失败，它会返回一个负值。

以下是一个使用 `fork()` 的简单示例：

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process\n");
    } else {
        printf("This is the parent process, child pid is %d\n", pid);
    }

    return 0;
}
```

在这个例子中，我们首先调用 `fork()` 创建一个新的进程。然后我们检查 `fork()` 的返回值来确定我们是在父进程中还是在子进程中，然后打印相应的消息。

`fork()` 是一个在 Unix 和 Linux 系统中常用的系统调用，它用于创建一个新的进程。这个新的进程被称为子进程，它是调用 `fork()` 的原始进程（被称为父进程）的副本。

子进程从父进程那里继承了大部分的属性，例如文件描述符、环境变量和程序计数器等，但是它有自己的进程 ID，父进程 ID，它也有自己的内存空间。

`fork()` 的返回值在父进程和子进程中是不同的。在父进程中，`fork()` 返回新创建的子进程的进程 ID。在子进程中，`fork()` 返回 0。如果 `fork()` 调用失败，它会返回一个负值。

在 `fork()` 之后，父进程和子进程将会从 `fork()` 调用之后的地方开始执行。这意味着父进程和子进程将会执行相同的代码，但是由于 `fork()` 的返回值不同，它们可以执行不同的操作。

这是一个使用 `fork()` 的简单示例：

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process\n");
    } else {
        printf("This is the parent process, child pid is %d\n", pid);
    }

    return 0;
}
```

在这个例子中，我们首先调用 `fork()` 创建一个新的进程。然后我们检查 `fork()` 的返回值来确定我们是在父进程中还是在子进程中，然后打印相应的消息。

# wait
`wait()` 是一个在 Unix 和 Linux 系统中常用的系统调用，它使父进程暂停执行，直到它的一个子进程结束为止。当一个子进程结束时，它的进程描述符并不会立即消失，而是等待父进程读取它的退出状态。在这个时间里，子进程被称为 "僵尸进程"。`wait()` 函数允许父进程读取子进程的退出状态，并清理这些僵尸进程。

`wait()` 的返回值是已经结束的子进程的进程 ID，如果调用失败，它会返回 -1。

以下是一个使用 `wait()` 的简单示例：

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid, child_pid;
    int status;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process\n");
    } else {
        child_pid = wait(&status);
        printf("This is the parent process, child %d exited with status %d\n", child_pid, WEXITSTATUS(status));
    }

    return 0;
}
```

在这个例子中，我们首先调用 `fork()` 创建一个新的进程。然后我们检查 `fork()` 的返回值来确定我们是在父进程中还是在子进程中。在父进程中，我们调用 `wait()` 来等待子进程结束，并打印子进程的退出状态。
## &status
&status表示把wait函数的返回值赋值给status吗

不完全是。在 C 语言中，`&` 符号用于获取一个变量的地址，所以 `&status` 是变量 `status` 的地址。当你将 `&status` 传递给 `wait()` 函数时，你实际上是在告诉 `wait()` 函数将子进程的退出状态存储在 `status` 变量所在的内存位置。

这是因为 `wait()` 函数需要一个方式来将子进程的退出状态返回给调用者，但是它已经使用了它的返回值来返回已经结束的子进程的进程 ID。所以，它使用了一个指针参数（在这个例子中是 `&status`）来返回额外的信息。

所以，当 `wait()` 函数返回后，`status` 变量将包含子进程的退出状态。你可以使用 `WEXITSTATUS(status)` 宏来获取这个退出状态。
## pid_t
`pid_t` 是一个用于存储进程 ID 的数据类型。在 Unix 和 Linux 系统中，每个进程都有一个唯一的进程 ID，这个 ID 是一个整数。`pid_t` 就是用来存储这个整数的数据类型。

`pid_t` 的具体类型取决于系统，但通常它是一个有符号整数类型，如 `int` 或 `long`。在大多数系统中，进程 ID 是一个正整数，但是 `pid_t` 是有符号的，因为一些函数（如 `fork()`）可能需要返回一个负值来表示错误。

在 C 语言中，你可以像使用其他整数类型一样使用 `pid_t`。例如，你可以将 `fork()` 的返回值赋值给一个 `pid_t` 变量，然后检查这个变量的值来确定你是在父进程中还是在子进程中。

## WEXITSTATUS(status)
`WEXITSTATUS(status)` 是一个宏，用于从 `wait()` 或 `waitpid()` 函数返回的状态值中提取子进程的退出状态。

当你在父进程中调用 `wait()` 或 `waitpid()` 函数来等待子进程结束时，这些函数会返回一个状态值。这个状态值包含了一些关于子进程结束的信息，例如子进程是正常结束还是被信号终止。

`WEXITSTATUS(status)` 宏接受这个状态值作为参数，并返回子进程的退出状态。这个退出状态是子进程调用 `exit()` 函数时传递的值，或者是 `main()` 函数的返回值。

例如，如果子进程调用 `exit(3)` 或者 `main()` 函数返回 3，那么在父进程中 `WEXITSTATUS(status)` 将返回 3。

在 C 语言中，宏是预处理器（preprocessor）的一部分，它在编译代码之前运行。宏可以看作是一种简单的文本替换工具。

你可以使用 `#define` 指令来定义一个宏。例如：

```c
#define PI 3.14159
```

然后在你的代码中，每次出现 `PI`，预处理器都会将其替换为 `3.14159`。

宏也可以带有参数，这使得宏可以像函数一样工作。例如：

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

在这个例子中，`MAX(a, b)` 是一个宏，它接受两个参数 `a` 和 `b`，并返回两者中的较大值。然后在你的代码中，每次出现 `MAX(x, y)`，预处理器都会将其替换为 `((x) > (y) ? (x) : (y))`。

`WEXITSTATUS(status)` 就是一个带有参数的宏，它从 `wait()` 或 `waitpid()` 函数返回的状态值中提取子进程的退出状态。

## 