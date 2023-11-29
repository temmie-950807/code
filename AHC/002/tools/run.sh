#!/bin/bash
g++-13 main.cpp -o main
: > temp.txt

l=0
r=10

for ((i=l ; i<r ; i++)) do
    # echo -n case$i:" "
    echo done: $i
    if (($i<10)); then
        ./main < in/000$i.txt > out/000$i.txt 2>> temp.txt
    else
        ./main < in/00$i.txt  > out/00$i.txt 2>> temp.txt
    fi
done

python3 main.py < temp.txt