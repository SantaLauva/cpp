#include <iostream>
#include <ws2tcpip.h>
#include <tchar.h>  // _T identifier
using namespace std;

int main()
{
    // Set up DLL

    SOCKET serverSocket, acceptSocket;
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

    // Set up Server Socket

    serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (serverSocket == INVALID_SOCKET)
    {
        cout << "Error at socket(): " << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "socket() is OK!" << endl;
    }

    // Bind Socket to the servers IP address and a valid port

    sockaddr_in service;
    service.sin_family = AF_INET;
    InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
    service.sin_port = htons(port);

    if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        cout << "bind() failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "bind() is OK!" << endl;
    }

    // Initiate Listen

    if (listen(serverSocket, 1) == SOCKET_ERROR)
    {
        cout << "listen(): Error listening on socket: " << WSAGetLastError() << endl;
    }
    else
    {
        cout << "listen() is OK" << endl;
    }

    // Accept Connection from Client

    acceptSocket = accept(serverSocket, NULL, NULL);

    if (acceptSocket == INVALID_SOCKET)
    {
        cout << "accept failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }

    cout << "Accepted connection" << endl;
    system("pause");
    WSACleanup();

    return 0;
}