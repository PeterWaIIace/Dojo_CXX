#pragma once

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <array>

constexpr int CONNECTIONS = 500;

int32_t check(uint32_t err_code);
class Receiver
{
    public:
    Receiver(int fd);

    std::string rpayload();

    private:
    int sockfd;
};

class Server{
    public:
    Server(int port);

    Receiver slisten();

    std::array<int,1024> recv(int fd);
    private:
    int run;
    int opt;
    int port;
    int sockfd;
    struct sockaddr_in servaddr;
    struct sockaddr_in destaddr;

    std::array<int,1024> recv_buffer;
};
