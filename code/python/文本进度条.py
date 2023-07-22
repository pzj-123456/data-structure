import time
import  math
scale = 50
print("执行开始".center(scale//2,"-"))
start = time.perf_counter()
for i in range(scale + 1):
    a = '*' * i
    b='*'*(scale-i)
    c=(i/scale)*100
    d=c+(1-math.sin(c*6.28+3.14/2))/-8
    dur = time.perf_counter() - start
    print("\r{:^3.0f}%[{}->{}]{:.2f}s".format(d,a,b,dur),end="")
    # :^3.0f  ^表示居中
    time.sleep(0.1)
print("\n"+"执行结束".center(scale//2,'-'))
