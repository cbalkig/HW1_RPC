all: clean client server

common.h: common.x
	rpcgen common.x

common_svc.c common_clnt.c client.c: common.h

client: client.o common_clnt.o
	cc -o client client.o common_clnt.o

server: server.o common_svc.o
	cc -o server server.o common_svc.o

.PHONY: clean

clean:
	-rm *.o
	-rm client
	-rm server
	-rm common.h
	-rm common_clnt.c
	-rm common_svc.c