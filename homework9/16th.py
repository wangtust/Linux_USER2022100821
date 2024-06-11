num1 = input("请输入第一个16进制数: ")
num2 = input("请输入第二个16进制数: ")

# 将输入的16进制数转换为整数
num1_int = int(num1, 16)
num2_int = int(num2, 16)

# 计算乘积
product = num1_int * num2_int

# 将乘积转换为16进制数并输出
print("乘积为: " + hex(product).upper()[2:])