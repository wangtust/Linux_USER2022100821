要将本地的更改同步到GitHub仓库，可以按照以下步骤进行操作：

1. **添加远程仓库地址**：首先，将GitHub仓库的地址添加为本地仓库的远程地址。在本地仓库目录下执行以下命令：

    ```bash
    git remote add origin https://github.com/wangtust/Data_structure.git
    ```

    这将远程仓库命名为`origin`，你也可以使用其他名称。

2. **将本地更改提交到本地仓库**：确保你已经将所有要提交的更改添加到暂存区。可以使用以下命令将更改提交到本地仓库：

    ```bash
    git add .  # 将所有更改添加到暂存区
    git commit -m "提交说明"  # 提交更改并附上说明
    ```

3. **推送更改到GitHub仓库**：使用以下命令将更改推送到GitHub仓库：

    ```bash
    git push -u origin main
    ```

    这会将本地的`main`分支推送到名为`origin`的远程仓库。

如果你之前已经将GitHub仓库的地址添加为远程仓库，并且已经将更改推送到GitHub，可以跳过第一步，直接执行第二步和第三步。

>shuaiwang@ShuaideMacBook-Air 数据结构 % git push -u origin main

To github.com:wangtust/Data_structure.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'github.com:wangtust/Data_structure.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
*******
这个提示表明远程仓库包含你本地没有的提交。在这种情况下，你需要先将远程仓库的更改拉取到本地，解决任何可能的冲突，然后再尝试推送你的更改。

你可以按照提示中的建议执行以下命令：

```bash
git pull origin main
```

然后解决任何可能的冲突，并提交合并的更改。完成后，再次尝试推送你的更改：

```bash
git push origin main
```

这应该解决推送被拒绝的问题。
>shuaiwang@ShuaideMacBook-Air 数据结构 % git pull origin main

remote: Enumerating objects: 6, done.
remote: Counting objects: 100% (6/6), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (6/6), 1.81 KiB | 168.00 KiB/s, done.
From github.com:wangtust/Data_structure
 * branch            main       -> FETCH_HEAD
 * [new branch]      main       -> origin/main
hint: You have divergent branches and need to specify how to reconcile them.
hint: You can do so by running one of the following commands sometime before
hint: your next pull:
hint: 
hint:   git config pull.rebase false  # merge
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint: 
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
fatal: Need to specify how to reconcile divergent branches.
*******
这个提示表明你的本地分支和远程分支存在差异，需要指定如何调解它们之间的分歧。你可以通过以下方式之一解决：

1. 使用合并（merge）：合并将创建一个新的提交，包含两个分支的更改。这是默认操作。
    ```bash
    git config pull.rebase false
    ```

2. 使用变基（rebase）：变基将将你的提交放在远程分支提交的后面，而不是创建一个新的合并提交。
    ```bash
    git config pull.rebase true
    ```

3. 仅允许快速前进（fast-forward only）：如果远程分支是你本地分支的直接祖先，则允许快速前进，否则将失败。
    ```bash
    git config pull.ff only
    ```

你可以选择其中一种方式，并再次运行`git pull`来解决分歧。例如，如果你想使用合并方式：

```bash
git pull origin main
```

完成解决冲突后，你应该能够顺利地推送你的更改到远程仓库。

>shuaiwang@ShuaideMacBook-Air 数据结构 % git pull origin main

From github.com:wangtust/Data_structure
 * branch            main       -> FETCH_HEAD
fatal: refusing to merge unrelated histories
这个错误通常是因为本地分支和远程分支的历史不相关，可能是因为你的本地仓库是新的，而远程仓库已经存在一些提交记录。这种情况下，Git 默认会拒绝合并，因为合并会创建一个新的提交，但它不知道如何将两者的历史整合在一起。

要解决这个问题，你可以使用`--allow-unrelated-histories`选项来允许合并不相关的历史。在执行`git pull`时添加这个选项即可：

```bash
git pull origin main --allow-unrelated-histories
```

这样应该能够允许合并不相关的历史，然后你可以解决任何合并冲突并提交合并后的更改。完成后，你就可以顺利地将你的更改推送到远程仓库了。
******
要退出并保存提交消息，你可以按照编辑器的退出方法，通常是按下 `Esc` 键然后输入 `:wq`（表示保存并退出），然后按 `Enter` 键。
****
>接下来，你可以运行 `git push origin main` 命令将合并后的更改推送到 GitHub 上的主分支。
