CPPFLAGS=-I. -Isrc
CFLAGS+=-masset

VPATH = src:src/runtime
OBJS = obj/ff.o obj/diskio_ram.o obj/runtime.o

all: lib$(LIB).a

lib$(LIB).a: obj/$(LIB)_veneer.o obj/$(LIB)AsObj.o
	$(AR) -rc $@ $^

obj/$(LIB)_veneer.o: src/veneer.S
	$(CC) -DIMPL=impl_$(LIB) $^ -c -o $@

obj/$(LIB)AsObj.o: obj/$(LIB)Enc.elf
	wine Tools/bin/iexe2obj.exe --prefix impl_$(LIB) $^ $@; true

obj/$(LIB)Enc.elf: obj/$(LIB).elf
	cp $^ $@

obj/$(LIB).elf: $(OBJS)
	$(LD) $^ -o $@ -e 0x8000 --script=link.ld

obj/%.o: %.c
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) -c -o $@

obj/runtime.o: runtime.c
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) -fno-builtin -c -o $@

clean:
	rm -f obj/* lib$(LIB).a
