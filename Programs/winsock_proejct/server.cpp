#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int __cdecl  main(void) {

    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL, *ptr = NULL, hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

	ZeroMemory(&hints, sizeof (hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
   		printf("getaddrinfo failed: %d\n", iResult);
    	WSACleanup();
    	return 1;
	}

    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (ListenSocket == INVALID_SOCKET) {
    	printf("Error at socket(): %ld\n", WSAGetLastError());
    	freeaddrinfo(result);
    	WSACleanup();
    	return 1;
	}

    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);

    if (iResult == SOCKET_ERROR) {
      printf("Error at bind(): %ld\n", WSAGetLastError());
      freeaddrinfo(result);
      closesocket(ListenSocket);
      WSACleanup();
      return 1;
    }

    freeaddrinfo(result);

    if ( listen( ListenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
    	printf( "Listen failed with error: %ld\n", WSAGetLastError() );
    	closesocket(ListenSocket);
    	WSACleanup();
    	return 1;
}

    ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
    	printf("accept failed: %d\n", WSAGetLastError());
    	closesocket(ListenSocket);
    	WSACleanup();
    	return 1;
}

	closesocket(ListenSocket);

	do {
    	iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    	if (iResult > 0) {
        	printf("Bytes received: %d\n", iResult);
    		printf("Message recived: %s\n", recvbuf);

        	iSendResult = send(ClientSocket, recvbuf, iResult, 0);
        	if (iSendResult == SOCKET_ERROR) {
            	printf("send failed: %d\n", WSAGetLastError());
            	closesocket(ClientSocket);
            	WSACleanup();
            	return 1;
        	}
        	printf("Bytes sent: %d\n", iSendResult);
    	}

    	else if (iResult == 0)
        	printf("Connection closing...\n");

    	else {
        	printf("recv failed: %d\n", WSAGetLastError());
        	closesocket(ClientSocket);
        	WSACleanup();
        	return 1;
    		}

	} while (iResult > 0);

	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
    	printf("shutdown failed: %d\n", WSAGetLastError());
    	closesocket(ClientSocket);
    	WSACleanup();
    	return 1;
		}

    	closesocket(ClientSocket);
    	WSACleanup();
    	return 0;

}