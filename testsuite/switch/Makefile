export CC=arm-none-eabi-gcc
export CXX=arm-none-eabi-g++
export AR=arm-none-eabi-ar
export LIB = switch

all:
	cd lib && $(MAKE) $(MAKECMDGOALS)
	cd app && $(MAKE) $(MAKECMDGOALS)

clean:
	cd lib && $(MAKE) $(MAKECMDGOALS)
	cd app && $(MAKE) $(MAKECMDGOALS)

test:
	umeq-arm app/app
