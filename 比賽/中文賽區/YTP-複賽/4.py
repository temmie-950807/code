N, M = map(int, input().split())
A = [list(map(int, input().split()))for i in range(N)]
for i in range(M):
    x, y, r = map(int, input().split())
    k = 0
    for j in A:
        if j[0]<=x<=j[2]:
            c = x
        elif x<j[0]:
            c = j[0]
        else:
            c = j[2]
        if j[1]<=y<=j[3]:
            d = y
        elif y<j[1]:
            d = j[1]
        else:
            d = j[3]
        if ((c-x)**2+(d-y)**2)**0.5<=r:
            k+=1
    print(k)

