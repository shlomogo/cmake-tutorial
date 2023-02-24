#!/bin/bash

# parse arguments
for i in "$@"; do
  case $i in
    --help|-h)
      help=YES
      shift
      ;;
    --build|-b)
      build=YES
      shift
      ;;
    --local|-l)
      local=YES
      shift
      ;;
    *)
      echo "Unknown option $i"
      exit 1
      ;;
  esac
done

if [ ${help} ]; then
    echo "usage: run-in-docker.sh [-h|--help] [-b|--build] [-l|--local]"
    echo ""
    echo "Runs the cmake-tutorial docker image. By default"
    echo "it pulls the image from a remote server."
    echo ""
    echo "-h, --help        display this help message and exit"
    echo "-b, --build       build the docker image and exit"
    echo "-l, --local       run using the local docker image"
    exit 0
fi

local_image="cmake-tutorial"
remote_image="gotlibsh/cmake-tutorial:latest"

if [ ${build} ]; then
    docker build -t ${local_image} .
    exit 0
fi

if [ ${local} ]; then
    image=${local_image}

    # exit if image does not exist
    if ! docker inspect --type=image ${image} > /dev/null 2>&1; then
        echo "'${image}' docker image does not exist (hint: use -b to build it)"
        exit 1
    fi
else
    image=${remote_image}
fi

docker run -u $(id -u):$(id -g) -v $PWD:/workspace -w /workspace -it --rm ${image}
