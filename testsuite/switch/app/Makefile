CPPFLAGS=-I../lib
CFLAGS+=

VPATH = src
OBJS = obj/main.o

all: app

obj/%.o: %.c
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) $(XCFLAGS) -c -o $@

app: $(OBJS)
	$(CC) $(XLDFLAGS) $^ -L../lib -l$(LIB) -o $@ --specs=rdimon.specs -Wl,--script=umeq.ld

clean:
	rm -f obj/* app

