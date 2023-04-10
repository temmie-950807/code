t = int(input())
l = ["1"]

# pre-process
for i in range(2, 100000):
    l.append(l[-1]+str(i))

# print(l)

for i in range(1, 200005):

    flag=0

    for j in range(2, 1000):
        for k in range(1, j):

            # if (l[k]=="12345" and l[j]=="123456789"):
                # print(l[k], l[j])
                # print(int(l[j])-int(l[k]))
                # print(int(l[j])-int(l[k])%i)
                # print(int(l[j])-int(l[k])%i==0)
            if ((int(l[j])-int(l[k]))%i==0):
                print(f"\"{l[k]} {l[j]}\", ", end="")
                flag=1

            if flag:
                break

        if flag:
            break
    
    if flag==0:
        print(i, -1)
