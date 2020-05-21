#include "client.h"

using namespace std;

void client(){
    //create socket
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    //set up server's ip and port
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = 0x00000000; //listen on localhost
    serverAddress.sin_port = 0xBEAF;

    connect(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    string data = "Hello";
    send(socketFD,data.c_str(),data.length(),0);

}

int main(int argc, char *argv[]){
    client();
    return 0;
}