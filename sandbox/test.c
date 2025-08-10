#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return 1;
	}

	SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == INVALID_SOCKET)
	{
		printf("Socket creation failed\n");
		WSACleanup();
		return 1;
	}

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
	{
		printf("Bind failed\n");
		closesocket(server_fd);
		WSACleanup();
		return 1;
	}

	listen(server_fd, 10);
	printf("Server listening on port 8080...\n");

	while (1)
	{
		int addrlen = sizeof(address);
		SOCKET client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen);
		if (client_fd == INVALID_SOCKET)
		{
			printf("Accept failed\n");
			continue;
		}

		char buffer[1024] = {0};
		recv(client_fd, buffer, sizeof(buffer), 0);
		printf("Request:\n%s\n", buffer);

		const char *response = "HTTP/1.1 200 OK\r\n"
		                       "Content-Type: text/plain\r\n"
		                       "Content-Length: 50\r\n"
		                       "\r\n"
		                       "<div>Hello_world</div>";

		send(client_fd, response, strlen(response), 0);
		closesocket(client_fd);
	}

	closesocket(server_fd);
	WSACleanup();
	return 0;
}
