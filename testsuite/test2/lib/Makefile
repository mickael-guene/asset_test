CPPFLAGS=-I.
CFLAGS+=-masset
ifdef GARBAGE_COLLECTION
	CFLAGS+=-ffunction-sections -Wl,--gc-sections
endif

VPATH = src:src/runtime
OBJS = obj/test1.o obj/test2.o obj/runtime.o

all: lib$(LIB).a

lib$(LIB).a: obj/$(LIB)AsObj.o
	$(AR) -rc $@ $^

obj/$(LIB)AsObj.o: obj/$(LIB)Enc.elf
	exe2obj --stub --prefix impl_$(LIB) $^ $@; true

obj/$(LIB)Enc.elf: obj/$(LIB).elf
	cp $^ $@

obj/$(LIB).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: %.c
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) -c -o $@

obj/runtime.o: runtime.c
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) -fno-builtin -c -o $@

clean:
	rm -f obj/* lib$(LIB).a
