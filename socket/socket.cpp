#include <iostream>
#include "server.h"

using namespace std;

int main(){
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

    //auto screen = GetDC(NULL);
	//while (true) {
	//	for (size_t i = 0; i < 100; i++) {
	//		for (size_t j = 0; j < 100; j++) {
	//			int p = 0xFF00FF00; //black-blue-green-red
	//			SetPixel(screen, i, j, p);
	//		}
	//	}
	//}
	server();
    cout << "Hello World!\n";
}
