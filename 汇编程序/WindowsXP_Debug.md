`debug.exe` 是一个在 MS-DOS 和早期版本的 Windows 中用于调试和测试程序的工具。以下是一些基本的 `debug.exe` 命令：

- `A`：Assemble。进入汇编模式，可以直接输入汇编指令。按 Enter 键两次退出汇编模式。

- `D`：Dump。显示内存中的内容。

- `E`：Enter。修改内存中的内容。

- `G`：Go。运行程序。

- `I`：Input。从端口读取数据。

- `L`：Load。从磁盘加载文件到内存。

- `N`：Name。指定要操作的文件名。

- `O`：Output。向端口写入数据。

- `R`：Register。显示或修改寄存器的值。

- `T`：Trace。单步执行程序。

- `U`：Unassemble。反汇编代码。

- `W`：Write。将内存中的内容写入到磁盘文件。

- `Q`：Quit。退出 `debug.exe`。

例如，你可以使用以下命令来创建一个简单的程序：

```dos
A
MOV AH, 9
MOV DX, 110
INT 21
INT 20
```

然后使用 `G` 命令来运行这个程序。

请注意，`debug.exe` 是一个非常基础的调试器，它的功能相比现代的调试器来说非常有限。如果你需要进行复杂的调试工作，你可能需要使用更强大的工具，例如 GDB 或 Visual Studio 的调试器。

对不起，我之前的回答中出现了一个错误。在 x86 架构的计算机中，文本模式的视频内存通常从 `B800:0` 开始，而不是 `B810:0`。

然而，你提到的 `B810:0` 地址仍然在文本模式的视频内存范围内。在文本模式下，`B800:0` 到 `B8FF:F` 的内存被用来存储屏幕上显示的字符和它们的属性。

如果你想在 `B810:0` 地址写入数据，你需要确保你的程序在实模式下运行，并且有足够的权限来访问这块内存。在 `debug.exe` 或其他运行在实模式下的程序中，你应该可以直接写入这块内存。