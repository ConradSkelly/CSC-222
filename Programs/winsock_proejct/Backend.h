#ifndef BACKEND_H
#define BACKEND_H

#include <string>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512

struct Client {
    WSADATA wsaData;
    int iResult;

    SOCKET ConnectSocket = INVALID_SOCKET;

    int recvbuflen = DEFAULT_BUFLEN;
    char sendbuf[DEFAULT_BUFLEN];
    char recvbuf[DEFAULT_BUFLEN];

    int ConnectToServer();
    Client(std::string host, std::string port);
};

struct Server {

    WSADATA wsaData;
    int iResult;
    int iSendResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    int recvbuflen = DEFAULT_BUFLEN;
    char sendbuf[DEFAULT_BUFLEN];
    char recvbuf[DEFAULT_BUFLEN];


    int ConnectToClient();
    std::string ReceiveAndSend();
    int Shutdown();
    Server(std::string host, std::string port);
};


#endif
