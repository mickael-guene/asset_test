export CC=arm-none-eabi-gcc
export AR=arm-none-eabi-ar
export LIB = fp

all:
	cd lib && $(MAKE) $(MAKECMDGOALS)
	cd app && $(MAKE) $(MAKECMDGOALS)

clean:
	cd lib && $(MAKE) $(MAKECMDGOALS)
	cd app && $(MAKE) $(MAKECMDGOALS)

test:
	umeq-arm app/app
