FROM rikorose/gcc-cmake:gcc-10
RUN apt-get update -y && apt-get -y install graphviz ninja-build
CMD ["bash"]