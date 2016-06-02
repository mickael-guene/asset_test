export CC=arm-none-eabi-gcc
export LD=arm-none-eabi-ld
export AR=arm-none-eabi-ar
export LIB = aes

all:
	cd lib && $(MAKE) $(MAKECMDGOALS)
	cd app && $(MAKE) $(MAKECMDGOALS)

clean:
	cd lib && $(MAKE) $(MAKECMDGOALS)
	cd app && $(MAKE) $(MAKECMDGOALS)

test:
	umeq-arm app/app
