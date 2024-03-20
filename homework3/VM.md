# 关于vm虚拟机运行Ubuntu，并通过ssh远程连接
ifconfig  # 查看虚拟机IP地址
user2022100821@ubuntu2204:~/Linux_USER2022100821$ ifconfig
ens160: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
********
 inet 172.16.150.129  
 *******
    
        netmask 255.255.255.0  broadcast 172.16.150.255
        inet6 fe80::20c:29ff:fed0:8e83  prefixlen 64  scopeid 0x20<link>
        ether 00:0c:29:d0:8e:83  txqueuelen 1000  (Ethernet)
        RX packets 184536  bytes 108977026 (108.9 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 123408  bytes 127163550 (127.1 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 46  memory 0x3fe00000-3fe20000  

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 75322  bytes 79150076 (79.1 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 75322  bytes 79150076 (79.1 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

安装sshd

>sudo apt-get install openssh-server

启动sshd

>sudo net start sshd

检查防火墙设置

>sudo ufw disable

检验：

>ssh localhost
若成功，则表示安装成功并且连接