cmd=[]
p=[]
ans=[]
n=0
vis=[]

while 1:
    s=input()
    cmd.append(s)
    if (s=="end"):
        break

# 初始化
n=len(cmd)
ans=["" for _ in range(n)]
vis=[0 for _ in range(n)]

# 得到每行的空格
for x in cmd:
    a=0
    for i in range(len(x)):
        if (x[i]==' '):
            a+=1
        else:
            break
    p.append(a)

# 確認縮排是否正確
for i in range(0, n-1):
    if (p[i]-p[i-1]!=2 and p[i]-p[i-1]>0):
        print("ERR!")
        exit(0)
    elif ((p[i]-p[i-1])%2==1):
        print("ERR!")
        exit(0)

for i in range(n):
    # 處理 emptyline
    if (cmd[i]=="emptyline"):
        for j in range(i+1, n):
            if (cmd[j]=="emptyline"):
                if (j-i==1):
                    ans[i]="\n";
                    break
                else:
                    ans[i]=f"//Describe({i+2},{j-1})"

    elif (cmd[i]=="safe"):
        tmp=[]
        for j in range(i-1, 0, -1):
            if (p[i]!=p[j]):
                break
            elif (vis[j]==0):
                tmp.append(cmd[j][p[j]:])
                vis[j]=1

        tmp.sort()
        for x in tmp:
            print(f"tmp: {x}")
        exit(0)
        print("!!!Analyze({})")

print(p)

# 輸出
for i in range(n):
    print(f"{i}. {ans[i]}")