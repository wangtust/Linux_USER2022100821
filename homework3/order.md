# linux命令
#删除目录不加-r会报错
$ rm data
rm: cannot remove ‘data’: Is a directory
#正确删除文件夹
$ rm -r data
#强制删除文件夹
$ rm -rf data
******
实例
将文件 aaa 改名为 bbb :

mv aaa bbb
将 info 目录放入 logs 目录中。注意，如果 logs 目录不存在，则该命令将 info 改名为 logs。

mv info/ logs 
再如将 /usr/runoob 下的所有文件和目录移到当前目录下，命令行为：

$ mv /usr/runoob/*  . 