n = int(input())
flag=1
kinf=False
ok = False
j=0
x1, y1 = 1, 1
x2, y2 = 2, 2
k, b = 1, 1
for i in range(n):
    x, y = map(int, input().split())
    if (j==0):
        x1, y1 = x, y
    elif(j==1):
        if ((x!=x1 and y!=y1) or (y==y1 and x!=x1)):
            x2, y2 = x, y
            k = (y1 - y2) / (x1 - x2)
            b=y1-k*x1
            ok = True
        elif(x==x1 and y==y1):
            j=0
        elif(y!=y1 and x==x1):
            kinf=True
    elif(ok):
        if (k * x + b != y):
            flag=0
    elif(kinf):
        if (x!=x1):
            flag=0
    j=j+1
if (flag):
    print("yes")
else:
    print("no")
