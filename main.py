import random
import pyperclip
n = random.randint(1, 1e5)
m = random.randint(1, 1e5)

k = []
for i in range(7):
    k.append(random.randint(1, 1e5))

use = 0
d = 0
while (d<n):
    for i in range(6, -1, -1):
        d += k[i]
        use += 1
        if (d>=n):
            break

s = ""

print(f"{n} {m}")
s += f"{n} {m}\n"
for i in k:
    s += f"{i} "
    print(i, end=" ")

s += "\t"

print("\n")

if (use>m*7):
    print(-1)
    s += "-1"
elif (use%7==0):
    print(m-(use//7)+1, 1)
    s += f"{m-(use//7)+1} {1}"
else:
    print(m-(use//7), 7-use%7+1)
    s += f"{m-(use//7)} {7-use%7+1}"
pyperclip.copy(s)