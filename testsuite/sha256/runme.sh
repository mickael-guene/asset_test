set -e

make clean && env CFLAGS='-O0' make all && make test
make clean && env CFLAGS='-O1' make all && make test
make clean && env CFLAGS='-O2' make all && make test
make clean && env CFLAGS='-O3' make all && make test
make clean && env CFLAGS='-Os' make all && make test