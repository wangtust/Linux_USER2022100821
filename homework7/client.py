import socket
# 创建一个socket对象
s1 = socket.socket()
s1.connect(('127.0.0.1', 3031))
# 不断发送和接收数据
while 1:
    send_data = input("客户端要发送的信息：")
    # socket传递的都是bytes类型的数据,需要转换一下
    s1.send(send_data.encode("utf-8"))
    # 接收数据，最大字节数1024,对返回的二进制数据进行解码
    text = s1.recv(1024).decode("utf-8")
    print("服务端发送的数据：{}".format(text))
    print("------------------------------")
