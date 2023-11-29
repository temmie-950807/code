g++-13 main.cpp -o main

for ((i=0 ; i<50 ; i++)) do
    echo done: $i

    if (($i<10)); then
        cp tools/in/000$i.txt a.in
    else
        cp tools/in/00$i.txt a.in
    fi

    ./main < a.in > a.out
    cd tools
    cargo run --release --bin vis ../a.in ../a.out
    cd ../
    clear
    sleep 0.2
done