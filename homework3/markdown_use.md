# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
一共就六级标题

# Markdown 基本语法
Markdown是一种轻量级标记语言，排版语法简洁，让人们更多地关注内容本身而非排版。它使用易读易写的纯文本格式编写文档，可与HTML混编，可导出 HTML、PDF 以及本身的 .md 格式的文件。因简洁、高效、易读、易写，Markdown被大量使用，如Github、Wikipedia、简书等。


就是这十个不到的标记符号，却能让人优雅地沉浸式记录，专注内容而不是纠结排版，达到「心中无尘，码字入神」的境界。

让我们从 Markdown 标题语法开始学习吧。

# Markdown 标题语法
要创建标题，请在单词或短语前面添加井号 (#) 。# 的数量代表了标题的级别。例如，添加三个 # 表示创建一个三级标题  (例如：### My Header)。

还可以在文本下方添加任意数量的 == 号来标
=====
识一级标题，或者 -- 号来标识二级标题
-----

Markdown 换行语法
在一行的末尾添加两个或多个空格，然后按回车键,即可创建一个换行(<br>)。

This is the first line.  
And this is the second line.  
可以看到末尾加了两行以上的空格   
要加粗文本，请在单词或短语的前后各添加两个星号（asterisks）或 __下划线__（underscores）。如需加粗一个单词或短语的中间部分用以表示强调的话，请在要加粗部分的两侧各添加两个**星号**（asterisks）。

注意要是斜体，就用一个*星号*          _一个下划线_
***同时要粗体和斜体就用三个***

要创建块引用，请在段落前添加一个 > 符号。  
# 多个段落的块引用
块引用可以包含多个段落。为段落之间的空白行添加一个 > 符号。
> Dorothy followed her through many of the beautiful rooms in her castle.
>
> The Witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.
### 原来引用就是给他贴的不一样

# 嵌套块引用
块引用可以嵌套。在要嵌套的段落前添加一个 >> 符号。
> Dorothy followed her through many of the beautiful rooms in her castle.
>
>> The Witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.
### 加了两个">" 即>>就是嵌套引用

# 带有其它元素的块引用
块引用可以包含其他 Markdown 格式的元素。并非所有元素都可以使用，你需要进行实验以查看哪些元素有效
> #### The quarterly results look great!
>
> - Revenue was off the chart.
> - Profits were higher than ever.
>
>  *Everything* is going according to **plan**.
# 有序列表
要创建有序列表，请在每个列表项前添加数字并紧跟一个英文句点。数字不必按数学顺序排列，但是列表应当以数字 1 起始。
1. First item
2. Second item
3. Third item
4. Fourth item
   
# 无序列表
要创建无序列表，请在每个列表项前面添加破折号 (-)、星号 (*) 或加号 (+) 。缩进一个或多个列表项可创建嵌套列表。
- First item
- Second item
- Third item
- Fourth item
* First item
* Second item
* Third item
* Fourth item
+ First item
+ Second item
+ Third item
+ Fourth item
- First item
- Second item
- Third item
    - Indented item
    - Indented item
- Fourth item
### 可以看到用这几个符号结果都是一样的

# 在列表中嵌套其他元素
要在保留列表连续性的同时在列表中添加另一种元素，请将该元素缩进四个空格或一个制表符，如下例所示：

# 段落
*   This is the first list item.
*   Here's the second list item.

    I need to add another paragraph below the second list item.

*   And here's the third list item.
  
# 引用块
*   This is the first list item.
*   Here's the second list item.

    > A blockquote would look great below the second list item.

*   And here's the third list item.

# 代码块
代码块通常采用四个空格或一个制表符缩进。当它们被放在列表中时，请将它们缩进八个空格或两个制表符。

1.  Open the file.
2.  Find the following code block on line 21:

        <html>
          <head>
            <title>Test</title>
          </head>

3.  Update the title to match the name of your website.
4.  这个就是c语言代码块，开头打两个tab制表符

        #include<stdio.h>
        int main(){
            printf("hello\n");
            return 0;
        }

# 图片
1.  Open the file containing the Linux mascot.
2.  Marvel at its beauty.  
  ![Tux, the Linux mascot](/assets/images/tux.png)
1.  Close the file.

# Markdown 代码语法
要将单词或短语表示为代码，请将其包裹在反引号 (`) 中。   

At the command prompt, type `nano`.	  
可以看到加个 `直接在英文模式下按esc下面那个按键就可以打出`  




