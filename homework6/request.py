import requests

# 发送请求到本地服务器
r = requests.get("http://172.28.81.115:8888")
print(r.status_code)
print(r.text)

# 发送请求到外部网站
r = requests.get("http://jnu.edu.cn")
print(r.status_code)
print(r.text)

# 将响应体写入文件
with open('./data.txt', 'w', encoding='utf-8') as t_file:
    t_file.write(r.text)
