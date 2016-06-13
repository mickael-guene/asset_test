set -e

make clean && env CFLAGS='-O0' make all && make test
make clean && env CFLAGS='-O1' make all && make test
make clean && env CFLAGS='-O2' make all && make test
make clean && env CFLAGS='-O3' make all && make test
make clean && env CFLAGS='-Os' make all && make test
make clean && env CFLAGS='-O0' GARBAGE_COLLECTION=1 make all && make test
make clean && env CFLAGS='-O1' GARBAGE_COLLECTION=1 make all && make test
make clean && env CFLAGS='-O2' GARBAGE_COLLECTION=1 make all && make test
make clean && env CFLAGS='-O3' GARBAGE_COLLECTION=1 make all && make test
make clean && env CFLAGS='-Os' GARBAGE_COLLECTION=1 make all && make test