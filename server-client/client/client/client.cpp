#include <iostream>
#include <ws2tcpip.h>
#include <tchar.h>  // _T identifier
using namespace std;

int main()
{
    // Set up DLL

    SOCKET clientSocket;
    int port = 55555;
    WSADATA wsaData;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);

    if (wsaerr != 0)
    {
        cout << "The Winsock dll not found!" << endl;
        return 0;
    }
    else
    {
        cout << "The Winsock dll found!" << endl;
        cout << "The status: " << wsaData.szSystemStatus << endl;
    }

    // Set up Client Socket

    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Error at socket(): " << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "socket() is OK!" << endl;
    }

    // Connect with Server

    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
    clientService.sin_port = htons(port);

    if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        cout << "Client: failed to connect" << endl;
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "Client: connect() is OK" << endl;
    }

    // Communicate with the Server



    // Close Socket

    system("pause");
    WSACleanup();

    return 0;
}