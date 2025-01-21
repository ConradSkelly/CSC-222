#include "Backend.h"

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main() {
	Server server = Server("localhost", DEFAULT_PORT);
	server.ConnectToClient();
	server.ReceiveAndSend();
	server.Shutdown();
}