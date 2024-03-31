# wav文件

```bash
root@Y7000P:/home/USER2022100821/work/Linux_homework/homework4# xxd -l 44 523hz8k8bit.wav
00000000: 5249 4646 641f 0000 5741 5645 666d 7420  RIFFd...WAVEfmt 
00000010: 1000 0000 0100 0100 401f 0000 401f 0000  ........@...@...
00000020: 0100 0800 6461 7461 401f 0000            ....data@...
```
你提供的是一个 WAV 文件头的十六进制表示。这个头信息包含了 WAV 文件的一些基本属性。以下是每个部分的解释：

- `5249 4646`：这是 "RIFF" 的 ASCII 码的十六进制表示，表示这是一个 RIFF 文件格式。
- `641f 0000`：这是文件大小，以字节为单位，不包括前 8 个字节。这个值是小端格式，所以实际的大小是 `0x00001f64`，即 8036 字节。
- `5741 5645`：这是 "WAVE" 的 ASCII 码的十六进制表示，表示这是一个 WAV 文件。
- `666d 7420`：这是 "fmt " 的 ASCII 码的十六进制表示，表示接下来是格式块。
- `1000 0000`：这是格式块的大小，以字节为单位。这个值是小端格式，所以实际的大小是 `0x00000010`，即 16 字节。
- `0100`：这是音频格式，`0x0001` 表示 PCM。
- `0100`：这是声道数，`0x0001` 表示单声道。
- `401f 0000`：这是采样率，以 Hz 为单位。这个值是小端格式，所以实际的采样率是 `0x00001f40`，即 8000 Hz。
- `401f 0000`：这是字节率，以字节/秒为单位。这个值是小端格式，所以实际的字节率是 `0x00001f40`，即 8000 字节/秒。
- `0100`：这是每个样本的字节数，`0x0001` 表示每个样本 1 字节。
- `0800`：这是每个样本的位数，`0x0008` 表示每个样本 8 位。
- `6461 7461`：这是 "data" 的 ASCII 码的十六进制表示，表示接下来是数据块。
- `401f 0000`：这是数据块的大小，以字节为单位。这个值是小端格式，所以实际的大小是 `0x00001f40`，即 8000 字节。

所以，这是一个单声道、采样率 8000 Hz、每个样本 8 位的 PCM WAV 文件，数据块的大小是 8000 字节。

## 为什么参数是44
WAV 文件的头部信息，也被称为 "WAV 文件头" 或 "WAV 文件元数据"，通常是 44 字节长。这 44 字节包含了关于音频数据的重要信息，如采样率、位深度、声道数等。

以下是 WAV 文件头的一般结构：

- RIFF header (12 字节)
- fmt subchunk (24 字节)
- data subchunk header (8 字节)

这些部分加起来总共是 44 字节。这就是为什么我们通常只查看前 44 字节来查看 WAV 文件头的信息。

然而，有些 WAV 文件可能有额外的元数据，这些元数据会在 data subchunk header 之后。如果你想查看这些额外的元数据，你可能需要查看超过 44 字节的数据。

WAV 文件的头部信息是由以下几个部分组成的：

- RIFF header：这是文件的开始，长度为 12 字节。它包含了 "RIFF" 标记（4 字节），整个文件的大小（4 字节），以及 "WAVE" 标记（4 字节）。

- fmt subchunk：这个部分描述了音频数据的格式，长度为 24 字节。它包含了 "fmt " 标记（4 字节），fmt subchunk 的大小（4 字节，通常为 16），音频格式（2 字节，通常为 1 表示 PCM），声道数（2 字节），采样率（4 字节），字节率（4 字节），块对齐（2 字节），以及每个样本的位数（2 字节）。

- data subchunk header：这个部分标记了音频数据的开始，长度为 8 字节。它包含了 "data" 标记（4 字节）和音频数据的大小（4 字节）。

这些部分加起来就是 WAV 文件头的 44 字节。然而，有些 WAV 文件可能有额外的元数据，这些元数据会在 data subchunk header 之后。

"RIFF" 是 "Resource Interchange File Format" 的缩写，这是一种用于存储音频、视频和文本数据的文件格式。在 WAV 文件中，"RIFF" 标记标识了文件是一个 RIFF 文件。

"RIFF" 标记是文件头的前 4 个字节，通常是 ASCII 字符 "R", "I", "F", "F"。这个标记后面跟着的 4 个字节表示整个文件的大小，然后是 "WAVE" 标记，表示这是一个 WAV 文件。

在处理 WAV 文件时，通常首先检查 "RIFF" 标记，以确认文件是一个有效的 RIFF 文件。

"wave" 标记在 WAV 文件的 RIFF 头部中，用来标识这个文件是一个 WAV 格式的音频文件。它紧跟在 "RIFF" 标记和文件大小之后。

"wave" 标记是由 ASCII 字符 "W", "A", "V", "E" 组成的 4 个字节。在读取 WAV 文件时，通常会检查这个标记，以确认文件是一个有效的 WAV 文件。

如果在预期的位置没有找到 "wave" 标记，那么文件可能不是一个有效的 WAV 文件，或者可能被损坏。

"fmt " subchunk 是 WAV 文件头部的一部分，它描述了音频数据的格式。这个部分的长度通常是 24 字节，包含以下信息：

- "fmt " 标记：这是 4 个字节，通常是 ASCII 字符 "f", "m", "t", " "。
- fmt subchunk 的大小：这是 4 个字节，通常是 16，表示 fmt subchunk 的剩余部分的大小。
- 音频格式：这是 2 个字节，通常是 1，表示 PCM（脉冲编码调制）。
- 声道数：这是 2 个字节，表示音频的声道数，例如 1 表示单声道，2 表示立体声。
- 采样率：这是 4 个字节，表示每秒的样本数，例如 44100。
- 字节率：这是 4 个字节，表示每秒的字节数，它等于采样率 * 块对齐。
- 块对齐：这是 2 个字节，表示每个样本的字节数，它等于声道数 * 每个样本的位数 / 8。
- 每个样本的位数：这是 2 个字节，表示每个样本的位数，例如 16。

这些信息对于解码和播放 WAV 文件的音频数据是必要的。
## 终端打开问题
>每次打开终端自动到root用户下

你的问题可能是由于你的 shell 的默认用户设置为了 root。你可以通过修改你的 shell 的配置文件来改变默认用户。

如果你使用的是 bash，那么你可以在你的 home 目录下找到一个名为 `.bashrc` 或 `.bash_profile` 的文件，打开这个文件并在文件的末尾添加以下行：

```bash
su - USER2022100821
```

然后保存并关闭文件。下次你打开一个新的终端时，你应该会自动切换到 USER2022100821 用户。

如果你使用的是其他的 shell，那么你需要找到对应的配置文件并进行类似的修改。例如，如果你使用的是 zsh，那么你需要修改 `.zshrc` 文件。

请注意，这种方法需要你的 USER2022100821 用户有权限切换到其他用户。如果没有，你可能需要在 root 用户下运行 `visudo` 命令，并在打开的文件中添加一行，允许 USER2022100821 用户无需密码就可以切换到其他用户：

```bash
USER2022100821 ALL=(ALL:ALL) NOPASSWD: ALL
```

然后保存并关闭文件。这样，USER2022100821 用户就可以无需密码就可以切换到其他用户了。

>怎么查看当前用户是不是root权限
在 Linux 中，你可以通过运行 `sudo -l` 命令来查看当前用户是否有 root 权限。这个命令会列出当前用户可以以 sudo 方式运行的所有命令。如果输出中包含 `(ALL : ALL) ALL`，那么当前用户就有 root 权限。

以下是运行 `sudo -l` 命令的示例：

```bash
$ sudo -l
Matching Defaults entries for username on this host:
    env_reset, mail_badpass,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin

User username may run the following commands on this host:
    (ALL : ALL) ALL
```

在这个示例中，username 用户可以以 sudo 方式运行所有命令，所以他有 root 权限。

请注意，运行 `sudo -l` 命令可能需要你输入当前用户的密码。
# 一些命令
## ps  -aux  | grep 8659 
```bash
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 16:20:17 11] $ echo $$
8659
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 16:20:58 12] $ pstree -p | grep 8659
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 16:21:04 13] $ ps  -aux  | grep 8659
USER202+  8659  0.0  0.0  10036  5084 pts/7    S    16:16   0:00 -bash
USER202+  9688  0.0  0.0   8168   656 pts/7    S+   16:21   0:00 grep --color=auto 8659
```
你运行的 `ps -aux | grep 8659` 命令是在所有当前运行的进程中查找 PID 为 8659 的进程。

从你的输出中可以看到，有两个进程的信息被列出：

1. PID 为 8659 的进程，这是一个 bash shell 进程，它在 pts/7 终端上运行，由 USER202+ 用户启动。

2. PID 为 9688 的进程，这是你刚刚运行的 `grep` 命令，它在查找包含 "8659" 的行。

所以，PID 为 8659 的进程是一个 bash shell 进程，由 USER202+ 用户在 pts/7 终端上启动的。

你提到的 `ps -aux | grep 8659` 命令实际上是两个命令的组合。

1. `ps -aux`：这个命令的全称是 "process status"。它用于显示系统中的进程状态。`-aux` 是这个命令的选项，其中：
   - `a` 表示显示所有用户的进程；
   - `u` 表示以用户为中心的格式显示进程信息；
   - `x` 表示显示没有控制终端的进程。

2. `grep 8659`：这个命令的全称是 "global regular expression print"。它用于在输入中搜索匹配特定模式的行。在这个命令中，`8659` 是要搜索的模式，所以 `grep 8659` 会输出包含 "8659" 的行。

`|` 是一个管道符，它将前一个命令的输出作为后一个命令的输入。所以，`ps -aux | grep 8659` 命令的作用是在所有进程的信息中搜索 PID 为 8659 的进程。
## 使用pstree -p | grep 8659和pstree -p | grep $$没反应
如果你在运行 `pstree -p | grep $$` 命令时没有任何输出，那可能是因为你的 shell 进程在 pstree 的输出中没有被列出。这可能是因为 pstree 默认只显示那些有子进程的进程，而你的 shell 进程可能没有任何子进程。

你可以尝试使用 `ps -p $$` 命令来查看你的 shell 进程的状态。这个命令会显示 PID 为 $$ 的进程的详细信息。

如果你想在 pstree 的输出中看到你的 shell 进程，你可以尝试在你的 shell 进程中启动一个子进程，然后再运行 `pstree -p | grep $$` 命令。例如，你可以运行 `sleep 60 &` 命令来启动一个在后台运行 60 秒的子进程，然后再运行 `pstree -p | grep $$` 命令。

按照这个操作执行后还是没反应

这个问题可能是由于 `pstree` 命令的输出没有包含所有的进程，或者 `grep` 命令没有正确地匹配到你的 shell 进程。

你可以尝试直接运行 `pstree -p` 命令，然后手动在输出中查找你的 shell 进程。你的 shell 进程的 PID 是 $$，所以你应该在输出中查找这个数字。

另外，你也可以尝试使用 `pgrep` 命令来查找你的 shell 进程。`pgrep` 命令可以在运行的进程中查找匹配特定模式的进程。你可以运行 `pgrep -fl $$` 命令，这个命令会在运行的进程中查找 PID 为 $$ 的进程，并显示这个进程的详细信息。

你运行的 `pgrep -fl $$` 命令是用来查找 PID 为 $$ 的进程的。在这个命令中，`$$` 是一个特殊的 shell 变量，它代表当前 shell 的 PID。

然而，从你的输出中可以看到，这个命令并没有找到任何匹配的进程。这可能是因为你的 shell 进程在运行 `pgrep -fl $$` 命令时已经结束，或者 `pgrep` 命令没有正确地匹配到你的 shell 进程。

你可以尝试再次运行你的程序，然后立即运行 `pgrep -fl $$` 命令，看看是否能找到你的进程。如果你的程序是一个长时间运行的进程，那么你应该能在运行的进程中看到它。

另外，你的输出中的 `[1]+ Done sleep 60` 表示你之前在后台启动的 `sleep 60` 命令已经完成。这个信息是由你的 shell 自动输出的，它表示你的后台进程的状态已经改变。

# 为什么我在vscode创建的文件默认权限都是root，我想把默认权限改为USER2022100821
在 Linux 系统中，新创建的文件的所有者默认是创建该文件的用户。如果你在 VS Code 中创建的文件的所有者是 root，那可能是因为你以 root 用户身份运行了 VS Code。

你可以通过以下步骤更改文件的所有者：

1. 打开一个终端。
2. 使用 `chown` 命令更改文件的所有者。例如，如果你想将文件的所有者更改为 USER2022100821，你可以运行以下命令：

```bash
sudo chown USER2022100821 filename
```

在这个命令中，你需要将 `filename` 替换为你想更改的文件的路径。

为了避免以后创建的文件仍然属于 root，你应该以你自己的用户身份运行 VS Code，而不是以 root 用户身份运行。你可以通过在终端中输入 `code` 命令来以你自己的用户身份启动 VS Code。

>我怎么看当前终端是属于哪个用户
在 Linux 系统中，你可以使用 `whoami` 命令来查看当前终端的用户。这个命令会打印出当前用户的用户名。

在你的终端中输入以下命令，然后按回车键：

```bash
whoami
```

这个命令会返回当前用户的用户名。如果你以 root 用户身份运行了终端，那么这个命令会返回 "root"。如果你以其他用户身份运行了终端，那么这个命令会返回那个用户的用户名。
```bash
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 17:21:02 74] $ ls -l
total 172
-rw-r--r-- 1 root root  8044 Mar 29 15:08 523hz8k8bit.wav
-rw-r--r-- 1 root root  8233 Mar 29 16:43 learn.md
-rwxr-xr-x 1 root root 16880 Mar 29 17:18 testid
-rw-r--r-- 1 root root   152 Mar 29 17:16 testid.c
-rwxr-xr-x 1 root root 16968 Mar 29 15:51 wav
-rw-r--r-- 1 root root   754 Mar 29 15:51 wav.c
-rwxr-xr-x 1 root root 17144 Mar 29 16:01 wav2
-rw-r--r-- 1 root root  1164 Mar 29 16:01 wav2.c
-rw-r--r-- 1 root root 79977 Mar 29 15:13 命令.md
```
怎么把当下文件夹的所有文件权限全改为USER2022100821

在 Linux 系统中，你可以使用 `chown` 命令来更改文件或目录的所有者。如果你想将当前目录下的所有文件和子目录的所有者更改为 USER2022100821，你可以使用 `-R` 参数（表示递归）并使用通配符 `*`（表示所有文件和目录）。

在你的终端中输入以下命令，然后按回车键：

```bash
sudo chown -R USER2022100821 *
```

这个命令会将当前目录下的所有文件和子目录的所有者更改为 USER2022100821。请注意，由于这个操作可能需要管理员权限，所以你可能需要在命令前面加上 `sudo`。

如果你只想更改文件的所有者，而不更改目录的所有者，你可以使用 `find` 命令：

```bash
sudo find . -type f -exec chown USER2022100821 {} \;
```

这个命令会找到当前目录及其子目录下的所有文件，并将它们的所有者更改为 USER2022100821。

```bash
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 17:24:07 79] $ sudo chown -R USER2022100821:USER2022100821 *
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 17:24:10 80] $ ls -l
total 172
-rw-r--r-- 1 USER2022100821 USER2022100821  8044 Mar 29 15:08 523hz8k8bit.wav
-rw-r--r-- 1 USER2022100821 USER2022100821  8233 Mar 29 16:43 learn.md
-rwxr-xr-x 1 USER2022100821 USER2022100821 16880 Mar 29 17:18 testid
-rw-r--r-- 1 USER2022100821 USER2022100821   152 Mar 29 17:16 testid.c
-rwxr-xr-x 1 USER2022100821 USER2022100821 16968 Mar 29 15:51 wav
-rw-r--r-- 1 USER2022100821 USER2022100821   754 Mar 29 15:51 wav.c
-rwxr-xr-x 1 USER2022100821 USER2022100821 17144 Mar 29 16:01 wav2
-rw-r--r-- 1 USER2022100821 USER2022100821  1164 Mar 29 16:01 wav2.c
-rw-r--r-- 1 USER2022100821 USER2022100821 79977 Mar 29 15:13 命令.md
```


在你的输出中，"USER2022100821" 是文件的所有者，而 "root" 是文件的组。这意味着这些文件的所有者已经被成功更改为 "USER2022100821"，但是这些文件仍然属于 "root" 组。

如果你想将这些文件的组也更改为 "USER2022100821"，你可以使用 `chown` 命令的 `user:group` 语法。在你的终端中输入以下命令，然后按回车键：

```bash
sudo chown -R USER2022100821:USER2022100821 *
```

这个命令会将当前目录下的所有文件和子目录的所有者和组都更改为 "USER2022100821"。

```bash
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 17:24:07 79] $ sudo chown -R USER2022100821:USER2022100821 *
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 17:24:10 80] $ ls -l
total 172
-rw-r--r-- 1 USER2022100821 USER2022100821  8044 Mar 29 15:08 523hz8k8bit.wav
-rw-r--r-- 1 USER2022100821 USER2022100821  8233 Mar 29 16:43 learn.md
-rwxr-xr-x 1 USER2022100821 USER2022100821 16880 Mar 29 17:18 testid
-rw-r--r-- 1 USER2022100821 USER2022100821   152 Mar 29 17:16 testid.c
-rwxr-xr-x 1 USER2022100821 USER2022100821 16968 Mar 29 15:51 wav
-rw-r--r-- 1 USER2022100821 USER2022100821   754 Mar 29 15:51 wav.c
-rwxr-xr-x 1 USER2022100821 USER2022100821 17144 Mar 29 16:01 wav2
-rw-r--r-- 1 USER2022100821 USER2022100821  1164 Mar 29 16:01 wav2.c
-rw-r--r-- 1 USER2022100821 USER2022100821 79977 Mar 29 15:13 命令.md
```

## 为什么我在vscode侧边栏新建了文本文件，权限仍然是root的，我刚才已经把终端改成USER2022100821了

VS Code 会以启动它的用户身份来创建新的文件。如果你以 root 用户身份启动了 VS Code，那么 VS Code 创建的新文件的所有者将会是 root，即使你已经在终端中切换到了其他用户。

为了解决这个问题，你需要以你自己的用户身份启动 VS Code。你可以通过在终端中输入 `code` 命令来以你自己的用户身份启动 VS Code。如果你已经以 root 用户身份启动了 VS Code，你可能需要先关闭它，然后再以你自己的用户身份重新启动它。

如果你已经以你自己的用户身份启动了 VS Code，但是新创建的文件的所有者仍然是 root，那可能是因为你的系统设置了某些特殊的权限规则。在这种情况下，你可能需要查看你的系统文档，或者联系你的系统管理员以获取帮助。

在 Visual Studio Code 中，新建文件的默认权限通常由你的操作系统和文件系统决定，VS Code 本身并没有提供直接设置新建文件默认权限的选项。

在 Linux 或 MacOS 中，新建文件的默认权限通由 `umask` 命令决定。你可以在终端中输入 `umask` 命令查看当前的设置，或者输入 `umask 022`（或你想要的其他值）来更改设置。这将影响所有新建文件的默认权限。

请注意，`umask` 命令的设置只对当前的 shell 会话有效。如果你想要永久更改 `umask` 的设置，你需要在你的 shell 配置文件（如 `~/.bashrc` 或 `~/.bash_profile`）中添加 `umask 022` 命令。

如果你在 VS Code 中使用的是 WSL (Windows Subsystem for Linux)，你也可以在 WSL 的 shell 配置文件中设置 `umask`。

如果你在 Windows 中使用 VS Code，文件的默认权限由 Windows 的 ACL (Access Control Lists) 决定，你可能需要在 Windows 的文件属性对话框中更改设置。

### umask
你的 `umask` 设置为 `0002`，这意味着新建文件的默认权限将是 `664`（`777` 减去 `umask` 的值），对应的权限是 `-rw-rw-r--`。这意味着文件所有者和所在组的用户可以读写文件，其他用户只能读取文件。

如果你在 VS Code 中创建的新文件仍然属于 root，那么可能是因为 VS Code 是以 root 用户身份运行的，或者是因为某些特定的设置或插件改变了文件的所有者。

你可以尝试以下步骤来解决问题：

1. 确保你是以非 root 用户身份运行 VS Code。你可以在终端中输入 `ps -ef | grep code` 来查看 VS Code 的运行用户。

2. 检查你的 VS Code 设置和插件。在 VS Code 中，打开设置（File > Preferences > Settings）和扩展视图（View > Extensions），查看是否有设置或插件可能影响到文件的所有者。

3. 如果以上步骤都不能解决问题，你可能需要联系 VS Code 的支持团队以获取更多帮助。你可以在 VS Code 的官方网站上找到他们的联系方式。

希望这些信息对你有所帮助。如果你有任何其他问题，欢迎随时向我提问。

## 找到原因为什么一直建文件都是root权限
因为开始是root，然后使用su命令转到USER2022100821下的，用ps -ef | grep code
查看所有有关code的命令，发现最下面的进程
```bash
root       44947   44946  0 22:40 pts/0    00:00:00 /bin/bash /root/.vscode-server/bin/863d2581ecda6849923a2118d93a088b0745d9d6/out/vs/base/node/cpuUsage.sh 44420 44428 44429
USER202+   44954   44429  0 22:40 pts/5    00:00:00 grep --color=auto code
[USER2022100821@Y7000P ~ 03.29 22:40:38 2] $ echo $$
44429
```
里面有root的进程，su命令是子进程，USER2022100821运行的进程是在root进程的下面，用pstree -p 44429就可以看到进程树
```bash
[USER2022100821@Y7000P ~ 03.29 22:41:28 4] $ pstree -p 44420
bash(44420)───su(44428)───bash(44429)───pstree(45367)
```
你的发现是正确的。你是从 root 用户通过 `su` 命令切换到 `USER2022100821` 用户，但是这个会话仍然是在 root 用户的上下文中。因此，从这个会话启动的所有进程，包括 VS Code，都会以 root 用户身份运行。

如果你想以 `USER2022100821` 用户身份运行 VS Code，你需要从 `USER2022100821` 用户的会话中启动 VS Code。你可以通过以下步骤来实现：

1. 完全注销当前的会话，或者关闭当前的终端窗口。

2. 以 `USER2022100821` 用户身份登录。

3. 启动 VS Code。

这样，你在 VS Code 中创建的新文件应该会属于 `USER2022100821` 用户，而不是 root 用户。

在 Linux 系统中，你可以通过以下步骤来注销当前的会话：

1. 如果你是在图形界面中，你可以通过点击系统菜单中的 "注销" 或 "退出" 选项来注销当前会话。

2. 如果你是在终端中，你可以通过输入 `exit` 命令来结束当前的会话。如果你是通过 `su` 命令切换到其他用户，你可能需要多次输入 `exit` 命令来回到原始用户。

请注意，注销会话会关闭所有由该会话启动的程序，包括 VS Code。在注销会话之前，请确保你已经保存了所有未保存的工作。

## 这个是wsl的问题，默认登陆vscode是root用户，在命令行下用wsl -l列举已安装的ubuntu系统
wsl --unregister Ubuntu-20.04，删除了多余的ubuntu系统
再运行wsl也能从Windows命令行进入ubuntu2，可以看到文件夹

# pid，ppid，uid，gid
这段 C 语言代码的功能是打印出当前进程的 PID（进程 ID）、PPID（父进程 ID）、UID（用户 ID）和 GID（组 ID）。

代码解析如下：

- `getpid()` 函数返回当前进程的 PID。
- `getppid()` 函数返回父进程的 PID。
- `getuid()` 函数返回当前用户的 UID。
- `getgid()` 函数返回当前用户的 GID。

这些信息对于理解进程的运行环境和权限非常有用。例如，UID 和 GID 可以用来确定进程有哪些系统资源的访问权限。

这些 ID 都是在 Unix 和类 Unix 系统（如 Linux）中用于标识进程和用户的唯一标识符。

- PID（Process ID）：这是进程的唯一标识符。每个进程在系统中都有一个唯一的 PID。
- PPID（Parent Process ID）：这是创建当前进程的进程的 PID。也就是说，它是当前进程的父进程的 PID。
- UID（User ID）：这是用户的唯一标识符。在 Unix 系统中，每个用户都有一个唯一的 UID。系统通过 UID 来识别用户，并控制用户的访问权限。例如，UID 为 0 的用户通常是 root 用户，拥有最高的权限。
- GID（Group ID）：这是用户组的唯一标识符。在 Unix 系统中，每个用户都属于至少一个用户组，每个用户组都有一个唯一的 GID。系统通过 GID 来识别用户组，并控制用户组的访问权限。

UID 和 GID 是 Unix 权限管理的基础。每个文件都有一个所有者（UID）和一个所属的用户组（GID）。文件的权限设置决定了哪些用户（UID）和用户组（GID）可以访问（读、写、执行）这个文件。

```bash
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.29 17:26:18 84] $ ./testid
pid:19667, ppid:8659, uid:1000, gid:1000
```
在 Linux 系统中，每个用户都有一个唯一的用户 ID（UID），每个用户组都有一个唯一的组 ID（GID）。这些 ID 用于识别用户和用户组，并控制他们的访问权限。

当你在 Linux 系统中创建一个新用户时，系统会自动分配一个 UID 和 GID。在许多 Linux 发行版中，第一个创建的非 root 用户的 UID 和 GID 通常会被设置为 1000。所以，如果你的 UID 和 GID 都是 1000，那可能是因为你是在系统中创建的第一个非 root 用户。

请注意，不同的系统可能会有不同的 UID 和 GID 分配规则。在一些系统中，第一个创建的非 root 用户的 UID 和 GID 可能不是 1000。

# 文件权限
在 Linux 系统中，文件的执行权限是由文件的权限设置决定的。你可以使用 `chmod` 命令来改变文件的权限。

如果你想给文件添加执行权限，你可以使用以下命令：

```bash
chmod +x 文件名
```

例如，如果你想给 `test.txt` 文件添加执行权限，你可以使用以下命令：

```bash
chmod +x test.txt
```

请注意，你需要有足够的权限才能改变文件的权限。通常，这意味着你需要以文件的所有者或 root 用户身份运行 `chmod` 命令。你可以使用 `sudo` 命令来以 root 用户身份运行 `chmod` 命令，例如：

```bash
sudo chmod +x test.txt
```

在运行 `sudo` 命令时，你可能需要输入你的密码。

在 `chmod +x 文件名` 命令中，`x` 代表 "执行" 权限，而 `文件名` 应该被替换为你想要修改权限的文件的名称。

例如，如果你有一个名为 `script.sh` 的脚本文件，并且你想要给它添加执行权限，你应该运行以下命令：

```bash
chmod +x script.sh
```

在这个命令中，`+x` 表示你想要添加执行权限，而 `script.sh` 是你想要修改权限的文件的名称。

# power shell和cmd
PowerShell 和 CMD 是 Windows 系统中的两种命令行接口，它们有以下主要的区别：

1. **命令和语法**：CMD 使用传统的 DOS 命令，而 PowerShell 使用基于 .NET 的 cmdlet 命令。PowerShell 的命令更加强大和灵活，可以进行复杂的脚本编程。

2. **管道操作**：在 CMD 中，管道操作只能传递文本，而在 PowerShell 中，管道可以传递对象，这使得 PowerShell 的管道操作更加强大。

3. **远程管理**：PowerShell 支持远程管理，可以在一台计算机上管理其他的计算机。而 CMD 不支持这个功能。

4. **系统集成**：PowerShell 更深度地集成到了 Windows 系统中，可以访问和管理许多系统组件，例如注册表、事件日志等。

5. **安全性**：PowerShell 提供了更强的安全性，包括执行策略、签名的脚本等。

总的来说，PowerShell 是一个比 CMD 更强大、更灵活、更安全的命令行接口。

"CMD" 和 "PowerShell" 这两个名字都反映了它们的主要功能和设计目标。

1. **CMD**：这个名字是 "Command Prompt" 的缩写，意为 "命令提示符"。这个名字反映了它的主要功能，即提供一个环境，用户可以在其中输入和执行命令。CMD 是 Windows 系统中的传统命令行接口，它继承了 MS-DOS 的许多命令和特性。

2. **PowerShell**：这个名字由 "Power" 和 "Shell" 两部分组成。"Power" 表示强大的能力，"Shell" 在计算机科学中通常指的是用户与操作系统交互的接口。这个名字反映了 PowerShell 的设计目标，即提供一个强大的、灵活的、可以访问和管理操作系统深层功能的环境。PowerShell 不仅是一个命令行接口，还是一个脚本语言和自动化框架。

PowerShell 有许多常用的命令，以下是一些例子：

1. `Get-Command`：列出所有可用的 cmdlet 和函数。

2. `Get-Help`：获取 cmdlet 或函数的帮助信息。

3. `Get-Process`：获取当前运行的进程信息。

4. `Get-Service`：获取系统服务的状态。

5. `Start-Service` 和 `Stop-Service`：启动或停止系统服务。

6. `Set-ExecutionPolicy`：设置脚本执行策略。

7. `Import-Module`：导入 PowerShell 模块。

8. `New-Item`：创建新的文件或文件夹。

9. `Remove-Item`：删除文件或文件夹。

10. `Set-Content` 和 `Get-Content`：写入或读取文件内容。

11. `ConvertTo-Json` 和 `ConvertFrom-Json`：将对象转换为 JSON 格式，或从 JSON 格式转换为对象。

这只是 PowerShell 命令的一小部分，PowerShell 提供了大量的 cmdlet 和函数，可以进行复杂的脚本编程和系统管理任务。

在 PowerShell 中，cmdlet（读作 "command-let"）是执行特定操作的轻量级命令。每个 cmdlet 都是一个小的 .NET 类，它实现了特定的功能。PowerShell 通过 cmdlet 提供了大量的功能，包括文件系统管理、进程管理、服务管理等。

cmdlet 的命名通常遵循 "动词-名词" 的格式，例如 `Get-Command`、`Get-Help` 等。动词部分表示 cmdlet 执行的操作，名词部分表示操作的对象。

你可以使用 `Get-Command` cmdlet 来列出所有可用的 cmdlet，或者使用 `Get-Help` cmdlet 来获取特定 cmdlet 的帮助信息。


在 PowerShell 中，你可以使用 `function` 关键字来创建函数。以下是如何创建上述 `Say-Hello` 函数的步骤：

1. 打开 PowerShell。

2. 输入以下代码：

```powershell
function Say-Hello {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Name
    )

    Write-Output "Hello, $Name!"
}
```

3. 按 Enter 键执行代码。这将定义 `Say-Hello` 函数。

4. 现在你可以调用这个函数了。例如，输入 `Say-Hello -Name "World"`，然后按 Enter 键，你将看到输出 "Hello, World!"。

请注意，这个函数只在当前 PowerShell 会话中有效。如果你关闭 PowerShell，这个函数就会消失。如果你想在每次打开 PowerShell 时都能使用这个函数，你可以将函数的定义添加到你的 PowerShell 配置文件中。

# 信号测试
## signal函数
`signal` 是 C 语言中的一个函数，用于处理操作系统发送给程序的信号。信号是一种软件中断，可以由操作系统或其他程序发送。

`signal` 函数的原型如下：

```c
void (*signal(int sig, void (*func)(int)))(int);
```

这个函数接受两个参数：

1. `sig`：这是要处理的信号的编号。例如，`SIGINT` 是中断信号的编号，通常由用户按 Ctrl+C 来发送。

2. `func`：这是一个函数指针，指向一个接受一个整数参数并返回 `void` 的函数。当程序接收到 `sig` 信号时，就会调用这个函数。

`signal` 函数的返回值是一个函数指针，指向之前处理 `sig` 信号的函数。如果之前没有为 `sig` 信号设置过处理函数，那么返回的函数指针将是 `SIG_DFL`（表示默认的处理函数）或 `SIG_IGN`（表示忽略信号的函数）。

例如，下面的代码将 SIGINT 信号的处理函数设置为 `mysignal` 函数：

```c
signal(SIGINT, mysignal);
```

这意味着，当程序接收到 SIGINT 信号时，它会调用 `mysignal` 函数，而不是默认的行为（即终止程序）。



`signal` 函数在 C 语言中用于设置信号的处理函数。它的原型如下：

```c
void (*signal(int sig, void (*func)(int)))(int);
```

这个函数接受两个参数：

1. `sig`：这是要处理的信号的编号。例如，`SIGINT` 是中断信号的编号，通常由用户按 Ctrl+C 来发送。

2. `func`：这是一个函数指针，指向一个接受一个整数参数并返回 `void` 的函数。当程序接收到 `sig` 信号时，就会调用这个函数。

下面是一个使用 `signal` 函数的例子：

```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// 信号处理函数
void handler(int sig)
{
    printf("Received signal %d\n", sig);
    exit(1);
}

int main()
{
    // 设置 SIGINT 信号的处理函数为 handler
    signal(SIGINT, handler);

    // 进入无限循环
    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
```

在这个例子中，我们定义了一个名为 `handler` 的函数，这个函数接受一个整数参数（信号编号），打印出一个消息，然后调用 `exit` 函数终止程序。

然后在 `main` 函数中，我们使用 `signal` 函数将 SIGINT 信号的处理函数设置为 `handler`。这意味着，当我们按 Ctrl+C（发送 SIGINT 信号）时，程序会调用 `handler` 函数，打印出 "Received signal 2"（因为 SIGINT 的信号编号是 2），然后终止。

如果我们没有使用 `signal` 函数设置 SIGINT 信号的处理函数，那么当我们按 Ctrl+C 时，程序会立即终止，而不会打印出任何消息。

不完全是。`signal` 函数本身并不会等待或接收信号，它的作用是设置信号的处理函数。当你调用 `signal` 函数时，你告诉操作系统，当接收到特定的信号时，应该调用你指定的函数。

信号可以在任何时候发送给进程，不仅仅是在你调用 `signal` 函数之后。信号可以由用户（通过终端或 `kill` 命令）、操作系统（例如，当进程使用了非法指令或尝试访问非法内存时）或其他进程发送。

当进程接收到信号时，如果你已经使用 `signal` 函数为这个信号设置了处理函数，那么这个函数就会被调用。如果你没有设置处理函数，那么信号的默认行为就会执行。

所以，你可以说，当你调用 `signal` 函数后，你的进程开始等待（或者说，准备处理）你指定的信号。但是，`signal` 函数本身并不会等待或接收信号。


是的，你的理解是正确的。`signal` 函数的第一个参数是信号的编号，第二个参数是一个函数指针，指向你想要在接收到该信号时执行的函数。

例如，下面的代码将 SIGINT 信号的处理函数设置为 `handler` 函数：

```c
signal(SIGINT, handler);
```

在这个例子中，`SIGINT` 是信号的编号（在大多数系统中，它的值是 2），`handler` 是一个函数指针，指向你定义的处理函数。

当你的程序接收到 SIGINT 信号时（例如，当用户在终端中按 Ctrl+C），它就会调用 `handler` 函数。如果你没有使用 `signal` 函数设置 SIGINT 信号的处理函数，那么当你的程序接收到 SIGINT 信号时，它会执行信号的默认行为（在大多数系统中，SIGINT 的默认行为是终止程序）。

在 `mysignal` 函数中调用 `signal` 函数是为了改变 SIGINT 信号的处理函数。

在 Unix-like 系统中，当一个信号处理函数被调用时，该信号的处理函数会被自动设置为默认的处理函数。这意味着，如果你的程序再次接收到同一个信号，它会执行默认的处理函数，而不是你设置的处理函数。

在你的代码中，当 `mysignal` 函数被调用时，SIGINT 信号的处理函数会被自动设置为默认的处理函数。然后，`mysignal` 函数中的 `signal(SIGINT, SIG_DFL);` 这行代码再次将 SIGINT 信号的处理函数设置为默认的处理函数。这是为了确保，当你的程序再次接收到 SIGINT 信号时，它会执行默认的处理函数，而不是 `mysignal` 函数。

如果你想要在每次接收到 SIGINT 信号时都执行 `mysignal` 函数，你可以在 `mysignal` 函数中将 SIGINT 信号的处理函数设置为 `mysignal`，如下所示：

```c
void mysignal(int sig)
{
    printf("\n I got signal %d \n", sig );
    signal(SIGINT, mysignal);
}
```

这样，每次 `mysignal` 函数被调用时，它都会将 SIGINT 信号的处理函数设置为 `mysignal`，所以你的程序在每次接收到 SIGINT 信号时都会执行 `mysignal` 函数。


## kill
`kill` 命令在 Linux 和其他 Unix-like 系统中用于发送信号给进程。以下是一些常见的 `kill` 命令的用法：

1. 发送 SIGTERM 信号（这是默认的信号）：

```bash
kill <PID>
```

在这个命令中，`<PID>` 是你想要发送信号的进程的 PID。

2. 发送其他的信号。你可以使用 `-s` 选项，后面跟信号的名字，或者直接使用信号的编号：

```bash
kill -s <signal> <PID>
kill -<signal> <PID>
```

例如，发送 SIGINT 信号（通常由用户按 Ctrl+C 发送）：

```bash
kill -s SIGINT <PID>
kill -2 <PID>
```

发送 SIGUSR1 信号（一个用户定义的信号）：

```bash
kill -s SIGUSR1 <PID>
kill -10 <PID>
```

3. 发送信号给多个进程。你可以在命令行中列出多个 PID：

```bash
kill <PID1> <PID2> <PID3> ...
```

4. 发送信号给一个进程组。你可以使用 `-` 符号，后面跟进程组的 ID：

```bash
kill -- -<PGID>
```

在这个命令中，`<PGID>` 是你想要发送信号的进程组的 ID。

注意：在使用 `kill` 命令时，你需要有足够的权限。如果你试图发送信号给一个你没有权限的进程，你会收到一个错误消息。


`SIG_DFL` 是一个特殊的信号处理函数，它表示信号的默认处理函数。在 Unix-like 系统（包括 Linux）中，每个信号都有一个默认的处理函数。例如，SIGINT 信号的默认处理函数是终止进程，SIGUSR1 和 SIGUSR2 信号的默认处理函数也是终止进程。

当你使用 `signal` 或 `sigaction` 函数设置信号的处理函数时，你可以使用 `SIG_DFL` 来指定你想要使用信号的默认处理函数。例如，下面的代码将 SIGINT 信号的处理函数设置为默认的处理函数：

```c
signal(SIGINT, SIG_DFL);
```

这意味着，当你的程序接收到 SIGINT 信号时，它会执行默认的处理函数，也就是终止进程。

请注意，`SIG_DFL` 是一个宏，它在 `<signal.h>` 头文件中被定义为一个空的函数指针。你不能直接调用 `SIG_DFL`，因为它不是一个真正的函数。你只能将它作为参数传递给 `signal` 或 `sigaction` 函数。

## pause
`pause` 是一个在 Unix-like 系统（包括 Linux）中的系统调用，它会使当前进程==暂停执行==，直到接收到一个信号。如果接收到的信号的处理函数被调用并返回后，`pause` 函数也会返回，并返回一个 -1 的错误值。

`pause` 函数的原型如下：

```c
#include <unistd.h>

int pause(void);
```

`pause` 函数没有参数。如果接收到的信号的处理函数被调用并返回后，`pause` 函数会返回 -1，并设置 `errno` 为 EINTR。

下面是一个使用 `pause` 函数的例子：

```c
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signum) {
    printf("Received signal %d\n", signum);
}

int main() {
    signal(SIGINT, handler);
    printf("Pausing... Press Ctrl+C to exit\n");
    pause();
    printf("Pause returned\n");
    return 0;
}
```

在这个例子中，我们首先使用 `signal` 函数设置 SIGINT 信号的处理函数为 `handler`。然后，我们调用 `pause` 函数，使进程暂停执行，直到接收到一个信号。如果你在终端中按 Ctrl+C，那么 SIGINT 信号会被发送，`handler` 函数会被调用，然后 `pause` 函数返回。

`mysignal` 函数的参数 `sig` 是由操作系统提供的，当操作系统向你的程序发送一个信号时，它会把信号的编号作为参数传递给你的信号处理函数。

在你的代码中，当你调用 `signal(SIGUSR1, mysignal);` 时，你告诉操作系统，当接收到 SIGUSR1 信号时，应该调用 `mysignal` 函数。然后，当 SIGUSR1 信号被发送到你的程序（例如，通过 `kill` 命令或其他方式），操作系统会调用 `mysignal` 函数，并把 SIGUSR1 的编号（在大多数系统中，它的值是 10）作为参数传递给 `mysignal` 函数。

所以，`mysignal` 函数的参数 `sig` 的值是由发送到你的程序的信号的编号决定的。

在 Unix-like 系统（包括 Linux）中，每个信号都有一个唯一的编号。这个编号是由操作系统定义的，不同的信号有不同的编号。

SIGUSR1 信号的编号在大多数系统中是 10。这个编号是由操作系统定义的，不是由你的程序定义的。你的程序只是使用这个编号来识别和处理信号。

你可以在 `<signal.h>` 头文件中找到所有信号的编号。在大多数系统中，SIGUSR1 的定义如下：

```c
#define SIGUSR1 10
```

所以，当你的程序接收到 SIGUSR1 信号时，操作系统会调用你的信号处理函数，并把 10 作为参数传递给你的函数。

在 Linux 系统中，你可以在 `/usr/include` 目录下找到 `<signal.h>` 头文件。你可以使用 `cat` 命令或者任何文本编辑器来查看它的内容。

例如，你可以在终端中使用以下命令来查看 `<signal.h>` 头文件的内容：

```bash
cat /usr/include/signal.h
```

这将会在终端中显示 `<signal.h>` 头文件的内容。

如果你想要在 Visual Studio Code 中查看这个文件，你可以在 Visual Studio Code 中打开 `/usr/include/signal.h` 这个文件。

请注意，`<signal.h>` 头文件的具体位置可能会因系统而异。在某些系统中，你可能需要使用 `find` 命令来查找 `<signal.h>` 头文件的位置。例如：

```bash
find /usr/include -name signal.h
```

这个命令会在 `/usr/include` 目录及其子目录中查找名为 `signal.h` 的文件，并显示它们的路径。


信号的名称是由操作系统定义的，你不能随意编写信号的名称。在 Unix-like 系统（包括 Linux）中，所有的信号名称都是以 "SIG" 开头的。

例如，SIGINT、SIGTERM、SIGUSR1 和 SIGUSR2 都是有效的信号名称。你不能使用像 "MY_SIGNAL" 这样的名称，因为操作系统不会识别它。

你可以在 `<signal.h>` 头文件中找到所有有效的信号名称。你应该总是使用这些预定义的信号名称来编写你的程序。

如果你想要在你的程序中使用自定义的信号，你可以使用 SIGUSR1 和 SIGUSR2 这两个用户定义的信号。这两个信号的默认行为是终止进程，但是你可以使用 `signal` 函数改变它们的行为，使它们执行你自己的函数。


在 Linux 系统中，你可以使用 `kill -l` 命令来查看所有的信号名称和它们的编号。在终端中输入以下命令：

```bash
kill -l
```

这个命令会列出所有的信号名称，以及它们对应的编号。

另外，你也可以在 `<signal.h>` 头文件中找到所有的信号名称和它们的编号。这个文件通常位于 `/usr/include/signal.h`，你可以使用 `cat` 命令或者任何文本编辑器来查看它的内容。

## testgignal2.c
```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
 
void mysignal(int sig)
{
	printf("\n I got signal %d \n", sig );   //  显示捕获的信号

(void) signal(SIGINT, SIG_DFL);     //  注解1
}
 
int main()
{
	
	signal(SIGINT, mysignal);  // i注解 2 
	while(1)
	{
		printf("Hello World!\n");
		sleep(10);   // 睡眠10秒 
	}
	return 0;
}
```
你的理解基本正确，但是有一点需要澄清：`signal` 函数本身并不会“接收”或“处理”信号。它的作用是设置信号的处理函数。当操作系统向你的程序发送信号时，操作系统会调用你为该信号设置的处理函数。

下面是你的程序的执行过程：

1. 当你的程序启动时，`main` 函数中的 `signal(SIGINT, mysignal);` 这行代码将 SIGINT 信号的处理函数设置为 `mysignal`。

2. 然后，你的程序进入一个无限循环，在每次循环中，它打印 "Hello World!"，然后暂停执行 10 秒。

3. 当你在终端中运行 `kill -SIGINT` 命令时，操作系统会向你的程序发送 SIGINT 信号。因为你已经将 SIGINT 信号的处理函数设置为 `mysignal`，所以操作系统会调用 `mysignal` 函数。

4. 在 `mysignal` 函数中，`printf("\n I got signal %d \n", sig);` 这行代码会打印 "I got signal "，后面跟着信号的编号（在大多数系统中，SIGINT 的编号是 2）。

5. 然后，`signal(SIGINT, SIG_DFL);` 这行代码将 SIGINT 信号的处理函数设置为默认的处理函数。这意味着，如果你的程序再次接收到 SIGINT 信号，它会执行默认的处理函数，而不是 `mysignal` 函数。

6. `mysignal` 函数结束后，你的程序会回到无限循环，继续打印 "Hello World!"，然后暂停执行 10 秒。

请注意，`signal` 函数只是设置信号的处理函数，它并不会等待信号的到来。当你的程序接收到信号时，操作系统会立即调用相应的处理函数，无论你的程序当前正在做什么。


## ps 和pstree
`ps` 命令是 "process status" 的缩写，它用于显示当前进程的状态。你可以使用各种选项来改变 `ps` 命令的输出。例如，`ps -A` 会显示所有的进程，`ps -u username` 会显示指定用户的进程。

`pstree` 命令用于显示进程的树状图。它可以帮助你理解进程之间的父子关系。`pstree` 命令没有官方的全称，但是你可以把它理解为 "process tree"。

这两个命令的主要区别在于它们的输出格式：`ps` 命令以列表的形式显示进程，而 `pstree` 命令以树状图的形式显示进程。此外，`pstree` 命令只显示进程的父子关系，而 `ps` 命令可以显示更多的信息，如进程的状态、CPU 使用率、内存使用量等。

这是两个命令的基本用法：

```bash
ps -A  # 显示所有进程
pstree  # 显示进程的树状图
```

你可以使用 `man ps` 和 `man pstree` 命令来查看这两个命令的详细用法。


在 `ps` 和 `pstree` 命令中，`-p` 参数的含义是不同的。

在 `ps` 命令中，`-p` 参数用于指定要显示的进程的 PID（进程 ID）。例如，`ps -p 1234` 会显示 PID 为 1234 的进程的信息。

在 `pstree` 命令中，`-p` 参数用于在进程名后面显示进程的 PID。例如，`pstree -p` 会显示进程的树状图，并在每个进程名后面显示其 PID。

这是两个命令的使用示例：

```bash
ps -p 1234  # 显示 PID 为 1234 的进程的信息
pstree -p  # 显示进程的树状图，并在每个进程名后面显示其 PID
```

你可以使用 `man ps` 和 `man pstree` 命令来查看这两个命令的详细用法。

# 命令行参数和环境变量
```c
#include <stdio.h>
#include <unistd.h>
#include<signal.h>
extern char** environ;

void handler(int n)   //自定义函数，用于收到信号, 继续运行程序
{
    printf("get signal  USR1， test prg continue \n");
}

int main(int argc,char *argv[])
{
int i;
    signal(SIGUSR1,handler); // 设置信号SIGUSR1 处理程序
       for (i=0; argv[i]!=NULL; ++i)
        printf("argv[%d]=%s\n", i,argv[i]);
       for (i=0; environ[i]!=NULL; ++i)
        printf("environ[%d]=%s\n",i, environ[i]);
	printf("test prg, %s,  pid:%d, ppid:%d, euid:%d\n", argv[0],getpid(), getppid(), geteuid());
//    sleep(15);   //进程睡眠15秒
   pause();   //  让自己睡眠 （通过 信号 可以唤醒）
	printf("test prg end. \n");
    return(0);  //  返回，即结束当前进程
}
```
这段代码的主要功能是设置一个信号处理函数，然后打印出命令行参数、环境变量和一些进程信息，最后暂停执行，直到接收到一个信号。

首先，`handler` 函数是一个信号处理函数，它接收一个参数（信号编号），并打印出一个消息，表示已经接收到 SIGUSR1 信号。

在 `main` 函数中，`signal(SIGUSR1,handler);` 这行代码将 SIGUSR1 信号的处理函数设置为 `handler`。这意味着，当程序接收到 SIGUSR1 信号时，它会调用 `handler` 函数。

然后，程序打印出命令行参数和环境变量。`argv` 是一个数组，包含了命令行参数，`environ` 是一个数组，包含了环境变量。

接着，程序打印出一些进程信息，包括程序的路径、进程 ID、父进程 ID 和有效用户 ID。

最后，`pause();` 这行代码会使程序暂停执行，直到接收到一个信号。当程序接收到一个信号时，它会调用相应的信号处理函数，然后 `pause` 函数返回，并且程序继续执行。

如果你想要测试这段代码，你可以在运行程序的终端中使用 `kill -SIGUSR1 pid` 命令发送 SIGUSR1 信号，其中 `pid` 是你的程序的进程 ID。当你发送 SIGUSR1 信号后，你应该能在程序的输出中看到 "get signal  USR1， test prg continue"。

## environ 是一个数组，包含了环境变量。这是系统自己储存的吗
是的，`environ` 是一个由操作系统自动提供的全局变量，它是一个指针数组，包含了当前进程的所有环境变量。每个环境变量都是一个字符串，格式为 `name=value`。

你不需要定义 `environ`，它在程序开始执行时就已经存在了。你可以通过 `extern char** environ;` 这行代码来声明 `environ`，然后就可以在你的程序中使用它了。

这是一个使用 `environ` 的例子：

```c
#include <stdio.h>

extern char** environ;

int main() {
    for (char** env = environ; *env

 !=

 NULL; env++) {
        printf("%s\n", *env);
    }
    return 0;
}
```

这段代码会打印出当前进程的所有环境变量。

## int argc,char *argv[]
`argc` 和 `argv` 是在 C 和 C++ 程序的 `main` 函数中常见的参数。它们用于处理命令行参数。

`argc` 是 "argument count" 的缩写，它表示命令行参数的数量。`argc` 的值至少为 1，因为第一个参数总是程序的名称。

`argv` 是 "argument vector" 的缩写，它是一个指向字符串的指针数组，包含了所有的命令行参数。`argv[0]` 是程序的名称，`argv[1]` 是第一个参数，以此类推。`argv[argc]` 是一个空指针。

例如，如果你的程序名为 `myprog`，并且你在命令行中这样运行它：`./myprog arg1 arg2`，那么 `argc` 的值为 3，`argv[0]` 的值为 `./myprog`，`argv[1]` 的值为 `arg1`，`argv[2]` 的值为 `arg2`，`argv[3]` 的值为 NULL。
## environ[]数组
```bash
environ[0]=SHELL=/bin/bash
environ[1]=COLORTERM=truecolor
environ[2]=WSL2_GUI_APPS_ENABLED=1
environ[3]=TERM_PROGRAM_VERSION=1.87.2
environ[4]=WSL_DISTRO_NAME=Ubuntu2
environ[5]=NAME=Y7000P
environ[6]=PWD=/home/USER2022100821/work/Linux_homework/homework4
environ[7]=LOGNAME=USER2022100821
environ[8]=VSCODE_GIT_ASKPASS_NODE=/home/USER2022100821/.vscode-server/bin/863d2581ecda6849923a2118d93a088b0745d9d6/node
environ[9]=HOME=/home/USER2022100821
environ[10]=LANG=C.UTF-8
environ[11]=WSL_INTEROP=/run/WSL/15_interop
environ[12]=LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
environ[13]=WAYLAND_DISPLAY=wayland-0
environ[14]=GIT_ASKPASS=/home/USER2022100821/.vscode-server/bin/863d2581ecda6849923a2118d93a088b0745d9d6/extensions/git/dist/askpass.sh
environ[15]=VSCODE_GIT_ASKPASS_EXTRA_ARGS=
environ[16]=LESSCLOSE=/usr/bin/lesspipe %s %s
environ[17]=TERM=xterm-256color
environ[18]=LESSOPEN=| /usr/bin/lesspipe %s
environ[19]=USER=USER2022100821
environ[20]=VSCODE_GIT_IPC_HANDLE=/mnt/wslg/runtime-dir/vscode-git-81b51ee858.sock
environ[21]=DISPLAY=:0
environ[22]=SHLVL=0
environ[23]=XDG_RUNTIME_DIR=/mnt/wslg/runtime-dir
environ[24]=PS1=\[\][\u@\h \w \D{%m.%d} \t \#] $ \[\]
environ[25]=WSLENV=VSCODE_WSL_EXT_LOCATION/up
environ[26]=VSCODE_GIT_ASKPASS_MAIN=/home/USER2022100821/.vscode-server/bin/863d2581ecda6849923a2118d93a088b0745d9d6/extensions/git/dist/askpass-main.js
environ[27]=XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
environ[28]=PATH=/home/USER2022100821/.vscode-server/bin/863d2581ecda6849923a2118d93a088b0745d9d6/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files (x86)/VMware/VMware Workstation/bin/:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Program Files/NVIDIA Corporation/NVIDIA NvDLISR:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files/Cloudflare/Cloudflare WARP/:/mnt/c/Program Files/Git/cmd:/mnt/c/Users/32729/AppData/Local/Programs/Python/Launcher/:/mnt/c/Users/32729/AppData/Local/Microsoft/WindowsApps:/mnt/d/Microsoft VS Code/bin:/mnt/d/pycharm/PyCharm Community Edition 2023.3.4/bin:/mnt/c/Users/32729/AppData/Local/gitkraken/bin:/snap/bin
environ[29]=HOSTTYPE=x86_64
environ[30]=PULSE_SERVER=unix:/mnt/wslg/PulseServer
environ[31]=OLDPWD=/home/USER2022100821
environ[32]=TERM_PROGRAM=vscode
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.30 16:10:07 47] $ environ[33]=VSCODE_IPC_HOOK_CLI=/mnt/wslg/runtime-dir/vscode-ipc-98bfbf49-3cc4-41e9-b54c-77b0674ceca9.sock
environ[34]=_=./testp
```
`environ` 数组中的每一项都是一个环境变量，它们是由操作系统或者 shell 设置的，也可以由用户自定义。环境变量通常用于存储系统设置或者程序配置。

- `SHELL=/bin/bash`：这是用户的默认 shell，这里是 bash。
- `COLORTERM=truecolor`：这个变量通常用于告诉应用程序终端支持哪种颜色模式，这里是 truecolor。
- `WSL2_GUI_APPS_ENABLED=1`：这个变量可能是用于在 Windows Subsystem for Linux (WSL) 中启用 GUI 应用程序。
- `TERM_PROGRAM_VERSION=1.87.2`：这个变量可能是用于存储终端程序的版本号。
- `WSL_DISTRO_NAME=Ubuntu2`：这个变量可能是用于存储在 WSL 中使用的 Linux 发行版的名称。
- `NAME=Y7000P`：这个变量可能是用于存储计算机的名称。
- `PWD=/home/USER2022100821/work/Linux_homework/homework4`：这个变量存储了当前工作目录的路径。
- `LOGNAME=USER2022100821`：这个变量存储了当前用户的登录名。
- `VSCODE_GIT_ASKPASS_NODE=/home/USER2022100821/.vscode-server/bin/863d2581ecda6849923a2118d93a088b0745d9d6/node`：这个变量可能是 Visual Studio Code 用于处理 Git 认证的。
- `HOME=/home/USER2022100821`：这个变量存储了用户的主目录的路径。
- `LANG=C.UTF-8`：这个变量用于设置程序的语言环境和字符编码，这里是 C 语言环境和 UTF-8 编码。
- `LS_COLORS`：这个变量用于设置 `ls` 命令的颜色输出。
- `WAYLAND_DISPLAY`：Wayland 服务器的显示设备。
- `GIT_ASKPASS`：Git 使用的程序来处理密码提示。
- `VSCODE_GIT_ASKPASS_EXTRA_ARGS`：传递给 `GIT_ASKPASS` 程序的额外参数。
- `LESSCLOSE`：定义了 `less` 命令在退出时使用的 shell 命令。
- `TERM`：定义了你的终端类型，这里是 `xterm-256color`。
- `LESSOPEN`：定义了 `less` 命令在打开文件时使用的 shell 命令。
- `USER`：当前的用户名。
- `VSCODE_GIT_IPC_HANDLE`：VS Code 的 Git 插件使用的 IPC 通道。
- `DISPLAY`：定义了 X 服务器的显示设备。
- `SHLVL`：定义了 shell 的深度，每启动一个新的 shell，这个数字就会增加。
- `XDG_RUNTIME_DIR`：定义了非持久性用户特定文件的存储位置。
- `PS1`：定义了 shell 提示符的外观。
- `WSLENV`：定义了在 WSL 和 Windows 之间传递的环境变量。
- `VSCODE_GIT_ASKPASS_MAIN`：VS Code 的 Git 插件使用的主要 askpass 脚本。
- `XDG_DATA_DIRS`：定义了用户特定数据文件的搜索路径。
- `PATH`：定义了 shell 查找命令的路径。这里包含了许多目录，包括 VS Code、VMware、Windows 系统目录、NVIDIA、dotnet、Cloudflare WARP、Git、Python、WindowsApps、VS Code、PyCharm、gitkraken 和 snap。
- `HOSTTYPE`：你的主机类型，这里是 `x86_64`。
- `PULSE_SERVER`：PulseAudio 服务器的位置，这里是在 WSLg 的目录下。
- `OLDPWD`：你之前的工作目录。
- `TERM_PROGRAM`：你的终端程序，这里是 `vscode`。
- `VSCODE_IPC_HOOK_CLI`：VS Code 的 IPC 通道。
- `_`：最后一个执行的命令，这里是 `./testp`。

```bash
[USER2022100821@Y7000P ~/work/Linux_homework/homework4 03.30 16:41:37 55] $ kill -USR1 32546
get signal  USR1， test prg continue 
test prg end. 
[1]+  Done                    ./testp one two2
```
这个消息是 shell 发出的，表示在后台运行的进程已经完成。

在这个例子中，`[1]+ Done ./testp one two2` 表示：

- `[1]` 是 shell 为后台进程分配的作业编号。
- `+` 表示这是最近的后台进程。
- `Done` 表示这个进程已经完成。
- `./testp one two2` 是你运行的命令。

所以，这个消息的意思是，你在后台运行的 `./testp one two2` 命令已经完成。


`pause` 函数是一个使进程暂停并等待信号的函数。当调用 `pause` 函数时，进程会停止执行，直到收到一个信号。

当进程收到信号后，会发生以下情况：

1. 如果该信号的处理方式被设置为默认或忽略，那么 `pause` 函数会返回，并且进程会继续执行 `pause` 函数后面的代码。

2. 如果该信号的处理方式被设置为一个函数，那么这个函数会被调用。在函数执行完毕后，`pause` 函数会返回，并且进程会继续执行 `pause` 函数后面的代码。

在你的代码中，你设置了 SIGUSR1 的处理函数为 `handler`。所以当你的进程接收到 SIGUSR1 信号时，`handler` 函数会被调用。在 `handler` 函数执行完毕后，`pause` 函数会返回，然后程序会继续执行。因为 `pause` 函数后面的代码是打印 "test prg end."，然后返回 0 结束程序。所以，当你的程序接收到 SIGUSR1 信号后，它会执行 `handler` 函数，然后继续执行，打印 "test prg end."，然后结束。

这就是为什么你在发送 SIGUSR1 信号后看到程序结束的原因。SIGUSR1 信号被 `handler` 函数处理了，但是 `pause` 函数返回后，程序继续执行并结束了。

# 总结signal函数和pause函数(testpause.c)
也就是说signal函数是把一个信号的执行机制改成一个我定义的函数，而pause函数是使程序暂停，等待我发送信号然后再继续执行对吧，也就是说signal函数在我没发送指令的时候就已经执行了，在这个进程里它把SIGUSR1的信号机制给改变了

是的，你的理解是完全正确的。

`signal` 函数用于设置一个信号的处理函数。在你的代码中，`signal(SIGUSR1, mysignal);` 这行代码将 SIGUSR1 信号的处理函数设置为 `mysignal` 函数。这意味着，当你的程序接收到 SIGUSR1 信号时，它会调用 `mysignal` 函数。

`pause` 函数会使程序暂停并等待接收信号。在你的代码中，`pause();` 这行代码会使程序暂停并等待信号。当程序接收到一个信号时，`pause` 函数返回，然后程序继续执行。

所以，`signal` 函数在你的程序开始运行时就已经执行了，它改变了 SIGUSR1 信号的处理方式。然后，`pause` 函数使程序暂停并等待你发送信号。当你发送 SIGUSR1 信号时，程序会调用 `mysignal` 函数，然后 `pause` 函数返回，程序继续执行。


# http协议
HTTP（HyperText Transfer Protocol，超文本传输协议）是一种用于分布式、协作式和超媒体信息系统的应用层协议。它是互联网上应用最广泛的一种网络协议。

HTTP 是一个基于请求-响应模型的协议。在 HTTP 中，浏览器（或其他客户端）发送一个请求到服务器，然后服务器返回一个响应。请求和响应都是 HTTP 消息，包含了一些信息，如 HTTP 方法（GET、POST 等）、URL、头部字段和消息体。

HTTP 是无状态的，意味着每个请求都是独立的，服务器不会保存之前的请求信息。但是，为了实现像用户登录这样的功能，我们通常会使用 cookies 或 session 来在多个请求之间保存状态。

HTTP 协议目前有两个主要版本：HTTP/1.1 和 HTTP/2。HTTP/2 在性能上有很大的提升，支持多路复用、服务器推送等特性。

## HTTP协议支持哪些常见的请求方法？
HTTP协议支持以下几种常见的请求方法：

1. `GET`：请求指定的页面信息，并返回实体主体。
2. `HEAD`：类似于 `get` 请求，但没有返回体。用于获取报头。
3. `POST`：向指定资源提交数据进行处理请求（例如提交表单或者上传文件）。数据被包含在请求体中。`POST` 请求可能会导致新的资源的建立和/或已有资源的修改。
4. `PUT`：从客户端向服务器传送的数据取代指定的文档的内容。
5. `DELETE`：请求服务器删除指定的页面。
6. `CONNECT`：HTTP/1.1 协议中预留给能够将连接改为管道方式的代理服务器。
7. `OPTIONS`：允许客户端查看服务器的性能。
8. `TRACE`：回显服务器收到的请求，主要用于测试或诊断。
9. `PATCH`：是对 `PUT` 方法的补充，用来对已知资源进行局部更新。

这些方法有时也被称为 HTTP 动词，因为它们描述了对资源的操作。
## URL
一个完整的URL（统一资源定位符）通常包含以下几个部分：

1. `协议`：也称为方案，如 `http`、`https`、`ftp` 等，它指定了如何访问资源。
2. `主机名`：也称为域名，如 `www.example.com`，它指定了资源所在的服务器的位置。
3. `端口`：如 `:80` 或 `:443`，它是可选的，如果没有指定，那么会使用协议的默认端口（例如，HTTP 的默认端口是 80，HTTPS 的默认端口是 443）。端口指定了服务器上的特定进程。
4. `路径`：如 `/path/to/myfile.html`，它指定了服务器上资源的具体位置。
5. `查询字符串`：以 `?` 开始，如 `?key1=value1&key2=value2`，它用于传递额外的参数。
6. `片段`：以 `#` 开始，如 `#section1`，它指向资源内的一个锚点。

例如，在 URL `https://www.example.com:443/path/to/myfile.html?key1=value1&key2=value2#section1` 中：

- `https` 是协议
- `www.example.com` 是主机名
- `443` 是端口
- `/path/to/myfile.html` 是路径
- `key1=value1&key2=value2` 是查询字符串
- `section1` 是片段

在计算机网络中，端口是一个特定的数字，用于标识网络服务或应用程序的特定进程。端口号是在 IP 地址之后的一个数字，通常在 URL 或网络请求中以冒号（:）后的形式出现。

端口号的范围是从 0 到 65535。其中，0 到 1023 的端口号被定义为“知名端口”，这些端口通常被系统级的服务或重要的网络协议使用。例如，HTTP 协议默认使用 80 端口，HTTPS 协议默认使用 443 端口。

当你的计算机发送或接收网络请求时，请求会被发送到特定的端口。例如，当你在浏览器中访问一个网站时，你的请求会被发送到服务器的 80 端口（如果是 HTTP）或 443 端口（如果是 HTTPS）。服务器上运行的软件会监听这些端口，当请求到达时，它会处理这些请求并发送响应。

## 服务器
域名的服务器可以位于世界的任何地方。它们通常位于数据中心，这些数据中心可能分布在全球各地。数据中心是专门用于存放服务器和相关硬件的设施，它们提供了必要的电力、冷却和网络连接。

一些大型的互联网公司，如 Google、Amazon 和 Microsoft，拥有自己的数据中心。他们在全球各地都有数据中心，以便提供更快、更可靠的服务。

另一些公司可能会选择使用托管服务，将他们的服务器放在第三方的数据中心。这些第三方公司提供硬件、电力、冷却和网络连接，而客户公司则负责管理和维护他们的服务器。

还有一些公司可能会选择使用云服务，如 Amazon Web Services、Google Cloud 或 Microsoft Azure。在这种情况下，服务器实际上是虚拟的，它们运行在云服务提供商的硬件上。这些云服务提供商在全球各地都有数据中心。

所以，一个域名的服务器可能位于世界的任何地方，具体取决于公司的需求和策略。

是的，服务器就是提供各种服务的计算机，例如网页托管、电子邮件、数据库管理等。服务器和普通的个人计算机在硬件和软件上都有一些区别：

1. `硬件`：服务器通常有更强大的处理器、更多的内存和更大的存储空间。它们也可能有冗余硬件（如电源和硬盘）以提高可靠性。此外，服务器硬件通常设计为24小时全天候运行。

2. `软件`：服务器通常运行专门的操作系统，如 Linux 的各种服务器版本或 Windows Server。这些操作系统为网络连接、安全性和稳定性等服务器任务提供了优化。

3. `用途`：普通计算机通常用于运行用户级的应用程序，如文字处理、电子表格和游戏。而服务器则用于运行为其他计算机提供服务的应用程序，如网页服务器、数据库服务器和邮件服务器。

4. `网络`：服务器通常有更快的网络连接，并且它们的 IP 地址通常是静态的，这样其他计算机就可以可靠地找到它们。

5. `维护`：服务器通常需要专门的 IT 人员进行管理和维护，包括安全更新、数据备份和性能监控等任务。

总的来说，虽然服务器和普通计算机在技术上都是计算机，但是它们的硬件、软件和用途都被优化以满足不同的需求。

## 端口
在计算机网络中，端口是用来标识特定的网络服务或应用程序的。每个网络服务或应用程序都会监听一个或多个特定的端口，当网络请求到达这些端口时，对应的服务或应用程序就会处理这些请求。

端口的主要作用有以下几点：

1. `区分不同的服务`：在同一台计算机上，可能会运行多个网络服务，例如 HTTP 服务器、FTP 服务器和数据库服务器等。这些服务通常会监听不同的端口，以便可以同时处理多种类型的网络请求。

2. `并发处理请求`：通过使用不同的端口，一台服务器可以同时处理多个网络请求。例如，一个 web 服务器可以同时处理来自多个客户端的 HTTP 请求。

3. `安全`：通过限制哪些端口可以接收网络请求，可以增加系统的安全性。例如，防火墙可以配置为只允许特定的端口接收网络请求。

总的来说，端口是网络通信的一个重要组成部分，它使得一台计算机可以同时提供多种网络服务，并且可以并发处理多个网络请求。

当你在浏览器中输入一个网址（例如 `http://www.example.com`）并按下回车键时，你的计算机会向 `www.example.com` 的服务器发送一个 HTTP 请求。这个请求是通过网络发送的，而网络上的每一台计算机都有一个唯一的 IP 地址。

然而，一台服务器上可能会运行多个服务，例如 HTTP 服务器、FTP 服务器和邮件服务器等。每个服务都需要监听网络上的请求，但是它们不能全部监听同一个 IP 地址，否则它们就无法区分哪个请求是发给哪个服务的。这就是端口的作用。

在这个例子中，HTTP 服务器通常会监听 80 端口（或者对于 HTTPS，监听 443 端口）。所以当你的请求到达服务器时，它会被发送到 80 端口。HTTP 服务器会监听这个端口，当它看到有请求到达时，就会处理这个请求，并发送回应。

所以，端口的作用就是帮助服务器区分不同的服务，并且使得一台服务器可以同时处理多个网络请求。

是的，你的理解是正确的。在一台服务器上，可能会运行多种不同的服务，例如 HTTP 服务（网页服务器）、FTP 服务（文件传输）、SMTP 服务（邮件发送）等。每种服务都会监听一个特定的端口。

端口的作用就像是一个服务器上的“门牌号”。当一个网络请求到达服务器时，它会根据请求的端口号，将请求转发给监听在该端口上的服务。这样，服务器就可以根据端口号来区分和处理不同类型的网络请求。

例如，当你在浏览器中访问 `http://www.example.com` 时，你的请求会被发送到 `www.example.com` 服务器的 80 端口（HTTP 服务默认的端口）。服务器收到请求后，就知道这是一个 HTTP 请求，然后将请求转发给监听在 80 端口的 HTTP 服务进行处理。

所以，端口的主要作用就是帮助服务器区分和处理不同类型的网络请求。

是的，你的理解完全正确。端口就像是主机上的不同接口，每个接口都对应一个特定的服务。当你使用 HTTP 协议访问一个网站时，浏览器会默认地将请求发送到 80 端口，这个端口通常被 HTTP 服务监听。服务器收到请求后，就会将其交给监听在 80 端口的 HTTP 服务进行处理。这样，通过端口，服务器就能够区分和处理不同类型的网络请求。

## 浏览器访问的过程
当你在浏览器中输入一个 URL（例如 `http://www.example.com:8080`）并按下回车键时，浏览器会进行以下步骤来将请求发送到服务器：

1. `DNS 查询`：首先，浏览器会使用 DNS（域名系统）来将主机名（例如 `www.example.com`）转换为 IP 地址。这个过程称为 DNS 解析。

2. `创建 TCP 连接`：一旦浏览器得到了服务器的 IP 地址，它就会尝试到该地址的特定端口（在这个例子中是 8080）上建立一个 TCP 连接。TCP 是一种网络协议，它提供了一种可靠的、面向连接的通信方式。

3. `发送 HTTP 请求`：一旦 TCP 连接建立成功，浏览器就会通过这个连接发送一个 HTTP 请求到服务器。这个请求包含了你想要访问的资源的路径，以及其他的一些信息，如你的浏览器类型、支持的语言等。

4. `等待响应`：服务器收到请求后，会处理这个请求，然后发送一个 HTTP 响应回浏览器。这个响应包含了请求的资源，例如一个 HTML 页面。

5. `关闭连接`：一旦浏览器收到了响应，它就会关闭 TCP 连接。然后，它会解析和显示响应中的资源。

以上就是浏览器根据主机名和端口将请求发送到服务器的基本过程。

## 建立TCP连接

当你的计算机（客户端）尝试与服务器建立 TCP 连接时，实际上是进行了一个称为 "三次握手"（Three-way Handshake）的过程。以下是这个过程的详细步骤：

1. `SYN`：首先，客户端会发送一个 SYN（Synchronize）包到服务器，请求建立连接。这个包中包含了客户端的初始序列号。

2. `SYN-ACK`：服务器收到 SYN 包后，会回复一个 SYN-ACK（Synchronize-Acknowledge）包。这个包中包含了服务器的初始序列号，以及对客户端 SYN 包中序列号的确认。

3. `ACK`：最后，客户端收到 SYN-ACK 包后，会发送一个 ACK（Acknowledge）包给服务器，确认收到了服务器的 SYN-ACK 包。

以上三步完成后，TCP 连接就建立成功了，客户端和服务器就可以开始互相发送数据了。

需要注意的是，这个过程是双向的，也就是说，客户端和服务器都会维护一个序列号和确认号。这样，两边都可以独立地发送和接收数据，这就是所谓的全双工通信。

另外，服务器并不是根据客户端的 IP 地址来建立 TCP 连接的。实际上，当服务器收到客户端的 SYN 包后，它会创建一个新的套接字（Socket）来处理这个连接。这个套接字包含了客户端的 IP 地址和端口号，以及服务器自己的 IP 地址和端口号。这样，服务器就可以同时处理来自多个客户端的连接请求了。

## http的请求与响应
HTTP 请求和响应是 HTTP 协议中的两个核心概念，它们是客户端和服务器之间通信的基础。

1. `HTTP 请求`：当你在浏览器中输入一个 URL 并按下回车键时，浏览器会创建一个 HTTP 请求并发送到服务器。这个请求包含以下几个部分：
   - 请求行：包含了 HTTP 方法（如 GET、POST）、请求的资源的路径，以及 HTTP 版本。
   - 请求头：包含了一些元数据，如浏览器类型、支持的语言、内容类型等。
   - 请求体：对于一些方法（如 POST、PUT），请求体中会包含要发送给服务器的数据。

2. `HTTP 响应`：服务器收到 HTTP 请求后，会处理这个请求，然后创建一个 HTTP 响应并发送回浏览器。这个响应包含以下几个部分：
   - 状态行：包含了 HTTP 版本、状态码（如 200 表示成功，404 表示未找到）和状态文本。
   - 响应头：包含了一些元数据，如内容类型、内容长度、服务器信息等。
   - 响应体：包含了请求的资源，例如一个 HTML 页面。

以上就是 HTTP 请求和响应的基本概念。在 HTTP 协议中，客户端和服务器之间的通信就是通过这样的请求和响应来进行的。

## 访问查看www.jnu.edu.cn` 的 HTTP 请求和响应内容
你可以按照以下步骤使用 Chrome 的开发者工具来查看 `www.jnu.edu.cn` 的 HTTP 请求和响应内容：

1. 打开 Chrome 浏览器，输入 `www.jnu.edu.cn`，然后按下回车键。

2. 按下 `F12` 键或者右键点击页面，选择 "检查" 来打开开发者工具。

3. 在开发者工具的顶部菜单中，点击 "Network" 标签。

4. 刷新页面（按下 `F5` 键或者点击浏览器的刷新按钮）。你会看到 Network 面板中列出了所有的 HTTP 请求。

5. 在这些请求中，找到第一个请求（通常是对 `www.jnu.edu.cn` 的 GET 请求），点击它。

6. 在右侧的详细信息面板中，你可以看到这个 HTTP 请求的详细信息，包括请求行、请求头和请求体。

7. 同样，在详细信息面板的 "Response" 标签下，你可以看到服务器返回的 HTTP 响应的详细信息，包括状态行、响应头和响应体。

以上就是使用 Chrome 开发者工具查看 HTTP 请求和响应的基本步骤。请注意，由于网络环境和服务器的实际情况可能会有所不同，你看到的具体信息可能会有所不同。
### 请求行、请求头和请求体
HTTP 请求的详细信息主要包括请求行、请求头和请求体三个部分：

1. `请求行`：请求行是 HTTP 请求的第一行，它包含了三个部分：HTTP 方法、请求的资源的路径，以及 HTTP 版本。例如，`GET /index.html HTTP/1.1` 就是一个请求行，表示这是一个使用 HTTP/1.1 版本的 GET 请求，请求的资源是 `/index.html`。

2. `请求头`：请求头包含了一些元数据，这些元数据用于描述请求的一些详细信息。例如，`User-Agent` 头表示发起请求的浏览器类型，`Accept-Language` 头表示浏览器支持的语言，`Content-Type` 头表示请求体的数据类型等。

3. `请求体`：请求体包含了要发送给服务器的数据。对于一些方法（如 POST、PUT），请求体中会包含这些数据。例如，当你在一个表单中填写信息并点击提交按钮时，浏览器会创建一个 POST 请求，这个请求的请求体中就包含了你填写的信息。

以上就是 HTTP 请求的详细信息。请注意，不是所有的 HTTP 请求都有请求体，例如，GET 和 HEAD 请求就没有请求体。

