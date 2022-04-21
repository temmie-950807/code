def get_next(s):
    global next
    next[0] = -1

    j=0
    k=-1

    while j<len(s):
        print(f"j: {j:2} k:{k:2} s: {s[0:j]}")
        if k==-1 or s[j]==s[k]: # 比對+1後的字串
            j+=1
            k+=1
            next[j]=k
        else:
            k=next[k]
    print(f"j: {j:2} k:{k:2} s: {s[0:j]}")

ip = input("pls input string: ")
next = [0 for _ in range(len(ip)+1)]
get_next(ip)
print(" ".join(map(str, next)))