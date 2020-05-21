#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <chrono>
#include <thread>

#ifdef __APPLE__
#include <CoreGraphics/CoreGraphics.h>
#endif /* CoreGraphics Library */

void server(void);

#endif /* _SERVER_H_ */