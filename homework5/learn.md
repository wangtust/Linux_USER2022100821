## git 
### 怎么查看当前文件夹是否属于git仓库
你可以在终端中使用 `git status` 命令来检查当前文件夹是否属于一个 Git 仓库。如果当前文件夹是一个 Git 仓库，这个命令会显示关于仓库状态的信息。如果当前文件夹不是一个 Git 仓库，这个命令会显示一个错误消息。

在终端中输入以下命令：

```bash
git status
```

如果你看到类似 "On branch master" 或 "No commits yet" 的消息，那么当前文件夹是一个 Git 仓库。如果你看到 "fatal: not a git repository (or any of the parent directories): .git" 的消息，那么当前文件夹不是一个 Git 仓库。
### 怎么提交修改
`git add .` 是一个 Git 命令，用于将当前目录下的所有更改添加到 Git 的暂存区。这包括新文件、已修改的文件和已删除的文件。这是准备提交更改的第一步。

在执行 `git add .` 命令后，你可以使用 `git commit` 命令来提交这些更改。例如：

```bash
git commit -m "Your commit message"
```

其中，"Your commit message" 是你的提交信息，应该简短地描述你所做的更改。
在你提交了更改之后，你可以使用 `git push` 命令将这些更改同步到你的 GitHub 仓库。这个命令会将你的本地仓库的更改推送到远程仓库。

如果你正在使用的分支是 `master`，你可以使用以下命令将更改推送到 GitHub：

```bash
git push origin master
```

这个命令的意思是将 `master` 分支的更改推送到 `origin`，其中 `origin` 通常是你的 GitHub 仓库的别名。

如果你正在使用的分支不是 `master`，你需要将 `master` 替换为你正在使用的分支的名称。例如，如果你正在使用的分支是 `dev`，你应该使用以下命令：

```bash
git push origin dev
```
### 什么是git分支
Git 分支是 Git 版本控制系统的一个重要特性，它允许你在同一份代码库中并行开发多个功能或修复多个问题。

在 Git 中，"分支" 是指向提交对象的可变引用。每次提交时，Git 都会创建一个新的提交对象并更新当前分支的引用，使其指向这个新的提交对象。这样，每个分支都代表了一个独立的开发历史。

你可以使用 `git branch` 命令来创建、列出、删除或重命名分支。你可以使用 `git checkout` 命令来切换到不同的分支。你可以使用 `git merge` 命令来合并两个分支的更改。

使用分支，你可以在不影响主开发线（通常是 `master` 分支）的情况下开发新功能或修复问题。当新功能开发完成或问题修复完成后，你可以将分支的更改合并回主开发线。
### git两台电脑同时用
如果你在两台电脑上都对同一个 GitHub 仓库进行了更改，并且想要保证这两台电脑上的更改都能同步到 GitHub 仓库，你可以按照以下步骤操作：

1. 在第一台电脑上，将你的更改提交到本地 Git 仓库，然后将这些更改推送到 GitHub。你可以使用以下命令：

```bash
git add .
git commit -m "Your commit message"
git push origin master
```

2. 在第二台电脑上，首先使用 `git pull` 命令将 GitHub 仓库的最新更改拉取到本地。这样，你就可以获取到第一台电脑上的更改。然后，将你在第二台电脑上的更改提交到本地 Git 仓库，并将这些更改推送到 GitHub。你可以使用以下命令：

```bash
git pull origin master
git add .
git commit -m "Your commit message"
git push origin master
```

这样，GitHub 仓库就会包含这两台电脑上的所有更改。

注意，如果两台电脑上的更改有冲突（即修改了同一个文件的同一部分），你需要在执行 `git pull` 命令后解决这些冲突，然后再提交和推送更改。