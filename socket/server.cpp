#include "server.h"
#define SERVER_IP 0x00000000

void drawPixels(char* pixels) {
    int w = 10, h = 10;
    auto screen = GetDC(NULL);
    for (size_t i = 0; i < w; i++) {
    	for (size_t j = 0; j < h; j++) {
            int index = h * j * 4 + i * 4;
            int p = 0;
            p += pixels[index + 2] << 24;
            p += pixels[index + 0] << 16;
            p += pixels[index + 1] << 8;
            p += pixels[index + 3] << 0;

    		SetPixel(screen, i, j, p);
    	}
    }
}

void server() {
    //create socket
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    //set up ip and port
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = SERVER_IP; 
    serverAddress.sin_port = 0xBEAF;

    //apply for port
    bind(socketFD, (struct sockaddr*) & serverAddress, sizeof(serverAddress));

    listen(socketFD, 6);

    //create connection to the client
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(clientAddress);
    int connection = accept(socketFD, (struct sockaddr*) & clientAddress, &len); //wait for connection

    //receive data from client
    while (true) {
        const int size = 400;
        char data[size];
        size_t n = recv(connection, data, size, 0);
        printf("recv: (%d)\n", n);
        drawPixels(data);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
