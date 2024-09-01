#pragma once

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <array>
#include <string>
#include <algorithm> // for std::copy and std::fill
#include <optional>

class Sender
{
    public:
    Sender(int fd);

    void spayload(std::string payload);
    
    private:
    int client_fd;
};


class Client
{
    public:
    Client(int port);

    std::optional<Sender> cconnect(std::string addr);

    private:

    int status, valread, client_fd;
    int connected = 0;
    struct sockaddr_in serv_addr;

};