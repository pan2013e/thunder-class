#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <chrono>
#include <thread>

#pragma comment(lib,"Ws2_32.lib")


void server(void);

#endif /* _SERVER_H_ */