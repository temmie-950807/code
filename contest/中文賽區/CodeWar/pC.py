t = int(input())

for i in range(t):
    s=input()
    p=""

    for x in s:
        if (x.isupper()):
            p+=x.lower()
        elif (x.islower()):
            p+=x

    if p==reversed(p):
        print("Y", end="")
    
    for i in range(len(s)):
        k=s[:i-1]+s[i+1:]
        print(k)

        if p==reversed(p):
            print("Y", end="")

    print("N", end="")
    