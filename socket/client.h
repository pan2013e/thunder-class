#ifndef _CLIENT_H
#define _CLIENT_H

#include <stdio.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string>

void client(void);

#endif /* _CLIENT_H */