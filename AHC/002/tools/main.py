total=0
cnt=0

while 1:
    try:
        s=input().split()
        total+=int(input())
        cnt+=1
    except:
        break

print(f"total: {total} average: {total/cnt}")