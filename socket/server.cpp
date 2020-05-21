#include "server.h"

void server(){
    //create socket
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    //set up ip and port
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = 0x00000000; //listen on localhost
    serverAddress.sin_port = 0xBEAF;

    //apply for port
    bind(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    listen(socketFD, 6);

    //create connection to the client
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(clientAddress);
    int connection = accept(socketFD, (struct sockaddr *)&clientAddress, &len); //wait for connection

    //receive data from client
    const int size = 100;
    char data[size];
    recv(connection, data, size, 0);
    printf("recv: %s\n", data);
}

int main(int argc, const char *argv[]){
    server();
    return 0;
}