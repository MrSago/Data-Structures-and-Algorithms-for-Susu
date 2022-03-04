
if test $# -ne 1
then
    echo "Syntax: ./build.sh [target]"
    exit
fi

mkdir -p build

cmake -DCMAKE_BUILD_TYPE:STRING=Release -H./ -B./build
cmake --build build/ --config Release --target $1 -j 4
