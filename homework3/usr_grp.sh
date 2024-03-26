#!/bin/bash

# 遍历 /etc/passwd 文件中的所有用户
for user in $(cut -d: -f1 /etc/passwd); do
  # 显示用户名
  echo -n "$user : "
  # 显示用户所属的所有组
  groups $user
done
