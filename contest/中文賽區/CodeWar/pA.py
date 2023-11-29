def main():
    N = 10**3
    val = [0 for _ in range(N)]
    s=eval(input().replace("null", "None"))
    ma=0

    if (s==[] or s==[None]):
        print(0)
        exit(0)

    assert len(s)<N

    now=0
    nxt=1
    for x in s:
        if x==None:
            now+=1
        else:
            val[nxt]=x+val[now]
            ma=max(ma, val[nxt])
            nxt+=1

    print(ma)

main()