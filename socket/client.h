#ifndef _CLIENT_H
#define _CLIENT_H

#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <string>

#pragma comment(lib,"Ws2_32.lib")

void client(void);

#endif /* _CLIENT_H */