
#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <stdio.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string>
#include <chrono>
#include <thread>

#ifdef __APPLE__
#include <CoreGraphics/CoreGraphics.h>
#endif /* CoreGraphics Library */

void client(void);

uint8_t *screen(int &w,int &h);

#endif /* _CLIENT_H_ */

