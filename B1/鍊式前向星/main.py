N = int(input("N: "))
head = [-1 for _ in range(0, N+1)]
node = []

while 1:
    try:
        # input
        node_1, node_2, weight = map(int, input().split())
        
        # first path
        edge = [node_2, weight, head[node_1]]
        head[node_1] = len(node)
        node.append(edge)

        # second path
        edge = [node_1, weight, head[node_2]]
        head[node_2] = len(node)
        node.append(edge)

        for i in head:
            print(f"{i:2d} | ", end="")
            k = i
            while i!=-1:
                print(f"{node[k]} ", end="")
                
                if node[k][2]==-1:
                    break

                k = node[k][2]
            print()
    except:
        break