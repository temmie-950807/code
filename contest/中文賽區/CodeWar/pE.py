s = input().split()
v = []

for x in s:

    if (len(x)>=2 and x[0]=='-' and x[1]=='-'):
        continue
    if (len(x)>=2 and x[0]=='+' and x[1]=='-'):
        continue
    if (len(x)>=2 and x[0]=='-' and x[1]=='+'):
        continue
    if (len(x)>=2 and x[0]=='+' and x[1]=='+'):
        continue

    flag=1
    for i in range(1, len(x)):
        if (x[i]=='e' or x[i]=='E'):
            break
        if (x[i]=='-' or x[i]=='+'):
            flag=0
            break

    if (flag==0):
        continue


    try:
        v.append([int(x), x])
    except:
        try:
            v.append([eval(x), x])
        except:
            pass
        pass

v.sort(reverse=True)
for x in v:
    print(x[1], end=" ")