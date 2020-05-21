/* 
 * client cli-app for macOS
 * link CoreGraphics library and CoreFoundation library when compiling
 */
#include "client.h"
#include <iostream>

#define SERVER_IP 0xED7BA8C0

using namespace std;

uint8_t *screen(int &w,int &h){
    CGImageRef img = CGWindowListCreateImage(CGRectMake(10, 70, 10, 10),
                        kCGWindowListOptionOnScreenOnly, kCGNullWindowID, kCGWindowImageDefault);

    w = (int)CGImageGetWidth(img);
    h = (int)CGImageGetHeight(img);

    // get raw data of the image pixels
    CGDataProviderRef provider = CGImageGetDataProvider(img);
    CFDataRef imageData = CGDataProviderCopyData(provider);
    uint8_t *bytes = (uint8_t *) CFDataGetBytePtr(imageData); //point to the data of the original pixels
    
    return bytes;
}

void client(){
    //create socket
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    //set up server's ip and port
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = SERVER_IP; //listen on localhost
    serverAddress.sin_port = 0xBEAF;

    connect(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        //capture screenshot and send
        int w,h;
        uint8_t *pixels = screen(w, h);
        cout << "sleep and send ("<< pixels <<")" <<endl;
        send(socketFD,pixels,w*h*4,0);
    }
    
}

int main(int argc, char *argv[]){
    client();
    return 0;
}