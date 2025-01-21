#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include "Backend.h"

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
/*
#define DEFAULT_BUFLEN 512


WSADATA wsaData;
int iResult;

SOCKET ConnectSocket = INVALID_SOCKET;

int recvbuflen = DEFAULT_BUFLEN;
char sendbuf[DEFAULT_BUFLEN];
char recvbuf[DEFAULT_BUFLEN];
*/

Client client = Client("localhost", DEFAULT_PORT);



int main(int argc, char **argv) {

    client.ConnectToServer();
    client.SendAndRecive();
    client.SendAndRecive();
}