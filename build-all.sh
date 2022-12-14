for d in [0-9]*/; do
    cd $d
    mkdir -p build
    cd build

    if ! cmake ..; then
        echo "failed to build '$(basename $(dirname $PWD))'"
        exit 1
    fi
    if ! cmake --build .; then
        echo "failed to build '$(basename $(dirname $PWD))'"
        exit 1
    fi

    cd ../..
done

echo "Done."
