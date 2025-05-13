#include "../include/NetworkManager.h"
#include <iostream>
#include <cstring>

#ifdef _WIN32
#include <winsock2.h>
typedef int socklen_t;
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#define PORT 8080

NetworkManager::NetworkManager(NetworkRole _role) : role(_role), running(false)
{
#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}

NetworkManager::~NetworkManager()
{
    Stop();
#ifdef _WIN32
    WSACleanup();
#endif
}

void NetworkManager::Start()
{
    running = true;
    if (role == NetworkRole::SERVER)
        serverThread = std::thread(&NetworkManager::RunServer, this);

    else if (role == NetworkRole::CLIENT)
        serverThread = std::thread(&NetworkManager::RunClient, this);
}

void NetworkManager::Stop()
{
    running = false;
    if (serverThread.joinable())
        serverThread.join();
}

void NetworkManager::SetOwnPosition(const Coordinates &_position)
{
    ownPosition = _position;
}

Coordinates NetworkManager::GetOtherPosition() const
{
    return otherPosition;
}

void NetworkManager::RunServer()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[sizeof(Coordinates)] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 1);
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);

    while (running)
    {
        send(new_socket, (char *)&ownPosition, sizeof(Coordinates), 0);
        recv(new_socket, buffer, sizeof(Coordinates), 0);
        memcpy(&otherPosition, buffer, sizeof(Coordinates));
    }

#ifdef _WIN32
    closesocket(new_socket);
    closesocket(server_fd);
#else
    close(new_socket);
    close(server_fd);
#endif
}

void NetworkManager::RunClient()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[sizeof(Coordinates)] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (running)
    {
        send(sock, (char *)&ownPosition, sizeof(Coordinates), 0);
        recv(sock, buffer, sizeof(Coordinates), 0);
        memcpy(&otherPosition, buffer, sizeof(Coordinates));
    }

#ifdef _WIN32
    closesocket(sock);
#else
    close(sock);
#endif
}