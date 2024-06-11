# bash脚本
## 变量
在 Bash 脚本中，所有的变量默认都是字符串，无论你是否将它们视为整数、浮点数或其他数据类型。这意味着，当你赋值和访问变量时，Bash 会将它们视为文本。

然而，你可以在某些情况下将变量视为其他类型。例如：

- 整数：你可以使用 `declare -i` 或 `let` 命令来创建一个整数变量。例如，`declare -i var` 或 `let var=5`。

- 数组：你可以使用括号 `()` 来创建一个数组。例如，`arr=(1 2 3)`。

- 关联数组（或哈希表）：在 Bash 4.0 及以上版本，你可以使用 `declare -A` 命令来创建一个关联数组。例如，`declare -A arr`，然后你可以这样设置和访问元素：`arr[key]=value` 和 `${arr[key]}`。

- 环境变量：这些是在你的 shell 会话和任何从中启动的程序之间共享的变量。你可以使用 `export` 命令来创建环境变量。例如，`export VAR=value`。

请注意，Bash 不支持浮点数。如果你需要进行浮点数运算，你可以使用 `bc` 或 `awk` 等工具。


```bash
#!/bin/bash
echo $0
echo $1
echo $2
echo $#
echo $*
echo $?
echo $$
echo $PPID

```
这是一个 Bash 脚本，它打印出一些特殊的预定义变量的值。这些变量是：

- `$0`：这是脚本的名称。
- `$1`，`$2` 等：这些是传递给脚本的参数。`$1` 是第一个参数，`$2` 是第二个参数，以此类推。
- `$#`：这是传递给脚本的参数的数量。
- `$*`：这是所有的位置参数（即传递给脚本的参数）作为一个单一的字符串。如果参数包含空格，这可能会导致问题。
- `$?`：这是最后执行的命令的退出状态。如果命令成功执行，那么这个值通常是 0。否则，这个值是非零的。
- `$$`：这是当前 shell 的进程 ID。
- `$PPID`：这是父进程的进程 ID。

# 进程
`ps -f` 命令的英文全称是 "process status - full format listing"。

- `ps` 是 "process status" 的缩写，这是一个在 Unix 和 Unix-like 系统（如 Linux）中常用的命令行工具，用于查看当前系统的进程状态。

- `-f` 是 "full format" 的缩写，这是一个选项，表示以完整格式列出进程信息。完整格式通常包括 UID，PID，PPID，C，STIME，TTY，TIME 和 CMD 等字段。

## 关于ps常用的有哪些

`ps` 命令有许多常用的选项，以下是一些例子：

- `ps -e`：列出所有进程。
- `ps -f`：以完整格式列出进程。
- `ps -u`：以用户为主的格式列出进程。
- `ps -x`：列出没有控制终端的进程。
- `ps -l`：以长格式列出进程。
- `ps -j`：以作业格式列出进程。
- `ps -a`：列出除会话领导外的所有进程。
- `ps -r`：列出运行中的进程。
- `ps -T`：列出属于当前终端的所有进程。

你可以使用 `man ps` 命令查看 `ps` 命令的完整文档，了解更多选项和用法。

`ps --forest` 是一个在 Unix 和 Unix-like 系统（如 Linux）中常用的命令行工具 `ps` 的选项，用于以树状图的形式显示进程和它们的父子关系。

在这个树状图中，每个进程都会显示其 PID（进程 ID），并且子进程会缩进以显示它们是哪个进程的子进程。这对于理解进程的层次结构和它们之间的关系非常有用。

例如，你可能会看到类似这样的输出：

```bash
PID TTY          TIME CMD
  2 ?        00:00:00 kthreadd
  3 ?        00:00:00   ksoftirqd/0
  5 ?        00:00:00   kworker/0:0H
  7 ?        00:00:00   rcu_sched
```

在这个例子中，`ksoftirqd/0`、`kworker/0:0H` 和 `rcu_sched` 都是 `kthreadd` 的子进程，因为它们被缩进了。

# 命令
`ls -ail /usr/bin` 是一个在 Unix 和 Unix-like 系统（如 Linux）中常用的命令行命令，用于列出 `/usr/bin` 目录下的文件和目录的详细信息。

这个命令的各个部分的含义如下：

- `ls`：这是 "list" 的缩写，是一个命令行工具，用于列出目录的内容。
- `-a`：这是 "all" 的缩写，是一个选项，表示列出所有文件，包括隐藏文件（以点开头的文件）。
- `-i`：这是 "inode" 的缩写，是一个选项，表示显示每个文件的 inode 号。inode 是文件系统中的一个数据结构，用于存储文件的元数据。
- `-l`：这是 "long" 的缩写，是一个选项，表示以长格式列出文件信息，包括文件权限、所有者、大小、修改时间等。
- `/usr/bin`：这是要列出的目录的路径。

所以，`ls -ail /usr/bin` 命令会列出 `/usr/bin` 目录下的所有文件和目录的详细信息，包括它们的 inode 号。

# 外部命令&内部命令
在 Linux 中，命令可以分为内部命令和外部命令。

内部命令是 shell 程序的一部分，当你在命令行输入这些命令时，shell 会直接执行，而不需要调用其他程序。这些命令通常是一些基本的、常用的命令，例如 `cd`、`echo`、`exit` 等。

外部命令则是独立的程序，它们通常存储在 `/bin`、`/usr/bin`、`/sbin`、`/usr/sbin` 等目录中。当你在命令行输入这些命令时，shell 会在这些目录中查找对应的程序并执行。这些命令通常是一些复杂的、功能强大的命令，例如 `ls`、`grep`、`awk` 等。

你可以使用 `type` 命令来查看一个命令是内部命令还是外部命令。例如，`type cd` 会显示 `cd is a shell builtin`，表示 `cd` 是一个内部命令；`type ls` 会显示 `ls is /bin/ls`，表示 `ls` 是一个外部命令。

这是 `type` 命令的输出结果，用于查看 `ps` 命令的类型。

输出结果 `ps is hashed (/usr/bin/ps)` 表示 `ps` 是一个外部命令，它的路径是 `/usr/bin/ps`。

"hashed" 的意思是这个命令的路径已经被 shell 缓存起来了，下次执行这个命令时，shell 可以直接从缓存中获取路径，而不需要再去搜索整个 PATH。这可以提高命令的执行速度。


在 Bash shell 中，命令的路径缓存是通过哈希表（hash table）实现的。当你首次运行一个命令时，shell 会在 PATH 环境变量所列出的目录中搜索这个命令，找到后就会把命令的名称和路径存储在哈希表中。下次再运行这个命令时，shell 就可以直接从哈希表中获取命令的路径，而不需要再去搜索整个 PATH，从而提高了命令的执行速度。

这个哈希表是存储在内存中的，它是 shell 进程的一部分。当 shell 进程结束时，哈希表也会被清空。

你可以使用 `hash` 命令来查看或操作哈希表。例如，`hash` 命令无参数时会列出哈希表中的所有条目，`hash -r` 命令会清空哈希表，`hash command` 命令会把 `command` 命令添加到哈希表中（如果它还不在哈希表中）。
```bash
[USER2022100821@Y7000P~] [05.24 22:10]$ hash
hits    command
   4    /usr/bin/which
   2    /usr/bin/ps
   1    /usr/bin/ls
   1    /usr/bin/cat
```
这是 `hash` 命令的输出结果，列出了当前 shell 进程的哈希表中的所有条目。

每一行都代表一个条目，包含以下信息：

- 命令被执行的次数（hits）
- 命令的路径（command）

例如，第一行：

```
4    /usr/bin/which
```

表示 `/usr/bin/which` 命令被执行了 4 次。

这个哈希表是用来加速命令查找的。当你执行一个命令时，shell 会首先在哈希表中查找这个命令，如果找到了就直接执行，如果没找到就会在 PATH 环境变量所列出的目录中搜索这个命令，找到后就会把命令的名称和路径添加到哈希表中。

`type -a` 命令用于显示所有可能的解释或位置的命令。在这个例子中，`echo` 有三种可能的解释：

1. `echo is a shell builtin`：这表示 `echo` 是一个 shell 内置命令。当你在命令行输入 `echo` 时，shell 会直接执行这个命令，而不需要调用其他程序。

2. `echo is /usr/bin/echo` 和 `echo is /bin/echo`：这表示 `echo` 也是一个外部命令，它的程序文件位于 `/usr/bin/echo` 和 `/bin/echo`。当你在命令行输入 `echo` 时，如果 shell 没有找到内置命令，就会在这些路径中查找并执行对应的程序。

这种情况下，当你执行 `echo` 命令时，shell 会优先执行内置命令，因为内置命令的执行速度更快。如果你想强制执行外部命令，可以指定完整的路径，例如 `/bin/echo`。

# POSIX是什么
POSIX（Portable Operating System Interface）是一种操作系统接口标准，由 IEEE（Institute of Electrical and Electronics Engineers）制定。它定义了操作系统应该提供的接口，以便软件可以在不同的操作系统上移植。

POSIX 标准涵盖了许多方面，包括文件系统、shell、线程、进程控制、定时器、消息传递、共享内存等。许多现代操作系统，包括 Linux、macOS 和 BSD，都遵循 POSIX 标准。Windows 也提供了一些 POSIX 兼容性，尽管并不完全。

POSIX 标准的目标是提高软件的可移植性。如果一个软件遵循 POSIX 标准，那么它就可以在任何遵循 POSIX 标准的操作系统上运行，而不需要做大量的修改。

# bash脚本
## 变量
 my_bash_var="this is my bash var"
在 Bash shell 中，变量名前面的 `$` 符号用于获取变量的值。这被称为变量替换或变量扩展。

例如，如果你有一个名为 `my_bash_var` 的变量，你可以使用 `$my_bash_var` 来获取它的值。如果你不加 `$` 符号，就只是一个普通的字符串，而不是变量。

这是一个例子：

```bash
my_bash_var="Hello, world!"
echo $my_bash_var  # 输出 "Hello, world!"
echo my_bash_var   # 输出 "my_bash_var"
```

在这个例子中，`echo $my_bash_var` 会输出 "Hello, world!"，因为 `$my_bash_var` 被替换为变量 `my_bash_var` 的值。而 `echo my_bash_var` 会输出 "my_bash_var"，因为没有 `$` 符号，所以 `my_bash_var` 就是一个普通的字符串，而不是变量。

echo ${my_bash_var}

# echo $PPID
在 Bash shell 中，`$PPID` 是一个特殊的环境变量，它表示当前 shell 的父进程的进程 ID。注意，这个变量的名字是大写的。

如果你尝试获取 `$ppid`（小写），你会得到一个空值，因为 Bash shell 是区分大小写的，`$ppid` 和 `$PPID` 是两个不同的变量。

你应该使用 `$PPID` 来获取当前 shell 的父进程的进程 ID，如下所示：

```bash
echo $PPID
```

如果 `$PPID` 也返回空值，那可能是因为你的 shell 不支持 `$PPID` 变量，或者你的 shell 没有父进程（例如，它是一个 init 进程）。

# shell脚本
## $?代表什么
在Shell脚本中，`$?`代表上一个命令的退出状态。如果上一个命令成功执行，那么`$?`的值就是0。如果上一个命令执行失败，那么`$?`的值就是非0。这个非0的值通常可以用来判断上一个命令的错误类型。

例如：

```bash
ls /nonexistentdirectory
echo $?
```

在这个例子中，`ls /nonexistentdirectory`命令会失败，因为`/nonexistentdirectory`目录不存在。然后，`echo $?`命令会输出上一个命令的退出状态，这个值应该是非0。

## 在脚本函数里$?干什么用

check_directory() {
    ls $1 > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "Directory exists."
    else
        echo "Directory does not exist."
    fi
}

## “./filename”、“sh filename”与“source filename”区别
`./filename`，`sh filename`和`source filename`这三种方式都可以用来执行Shell脚本，但它们之间存在一些重要的区别：

1. `./filename`：这种方式会在一个新的子Shell环境中执行脚本。这意味着脚本中定义的所有变量和函数都只在这个子Shell环境中可用，而在父Shell环境中不可用。此外，这种方式需要脚本具有执行权限。

2. `sh filename`：这种方式也会在一个新的子Shell环境中执行脚本，与`./filename`类似。但是，这种方式不需要脚本具有执行权限。此外，这种方式会使用`sh`来解释脚本，而不是脚本的shebang指定的解释器。这可能会导致一些与解释器相关的问题。

3. `source filename`：这种方式会在当前Shell环境中执行脚本。这意味着脚本中定义的所有变量和函数都将在当前Shell环境中可用，而不是在新的子Shell环境中。这种方式通常用于配置文件，例如`.bashrc`和`.bash_profile`。

总的来说，你应该根据你的具体需求来选择使用哪种方式来执行Shell脚本。

## bc
`bc`是一个在Unix系统中常用的命令行计算器。你可以使用它来进行任意精度的数学运算。以下是一些基本的使用方法：

1. 直接在命令行中进行计算：

```bash
echo "5 + 3" | bc
```

这个命令会输出8，因为5 + 3的结果是8。

2. 使用`bc`进行浮点数运算：

```bash
echo "scale=2; 3 / 2" | bc
```

这个命令会输出1.50，因为3除以2的结果是1.5，`scale=2`设置了小数点后的位数。

3. 使用`bc`进行更复杂的数学运算：

```bash
echo "scale=2; sqrt(4)" | bc -l
```

这个命令会输出2.00，因为4的平方根是2，`-l`选项加载了`bc`的数学库，这个库包含了一些常用的数学函数，例如`sqrt`。

4. 你也可以将你的计算表达式写入一个文件，然后使用`bc`命令来执行这个文件：

```bash
bc -l myfile
```

在这个命令中，`myfile`是包含你的计算表达式的文件。