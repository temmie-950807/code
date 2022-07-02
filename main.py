num = str(input())

new = num[::-1]

if int(new) == 0:
    new = ""
else:
    while new[0] == "0":
        if new[0] == "0":
            new = new.replace("0", "", 1)

print(new)