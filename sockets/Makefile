CC=clang
CFLAGS= -g
COMMON_OBJS = common.o

all: $(COMMON_OBJS) tcpc tcps

tcpc: tcpclient.c $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o tcpc tcpclient.c $(COMMON_OBJS)

tcps: tcpserver.c $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o tcps tcpserver.c $(COMMON_OBJS)

clean:
	rm -rf *.o *.dSYM tcpc tcps