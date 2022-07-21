import random
a = 0
b = 0
ans = [1, 2, 3, 4]
output = []

for i in range(1000000):
    score = 0
    for j in range(50):
        k = random.choice(ans)
        if k==1:
            score += 2
    
    output.append(score)
    if (score == 60):
        a += 1
    b += 1

print(a, b)
print(sum(output)/len(output))