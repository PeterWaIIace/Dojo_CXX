

#include "client.hpp"
#include <iostream>

Sender::Sender(int fd): client_fd(fd){};

void Sender::spayload(std::string payload)
{
    std::array<char, 1024> arr;
    // Step 1: Copy the string into the array
    std::copy(payload.begin(), payload.end(), arr.begin());

    // Fill the remaining part of the array with zeros
    std::fill(arr.begin() + payload.size(), arr.end(), 0);
    send(client_fd, arr.data(), arr.size(), 0);
}

Client::Client(int port)
{
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serv_addr, sizeof(serv_addr)); // Initialize serv_addr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
};

std::optional<Sender> Client::cconnect(const std::string addr)
{
    if (inet_pton(AF_INET, addr.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported" << std::endl;
        return std::nullopt;
    }
    if(not connected)
    {
        status = connect(client_fd, reinterpret_cast<struct sockaddr*>(&serv_addr) ,sizeof(serv_addr));
        connected = status >= 0 ? 1 : 0;
    }
    std::cout << "connected: " << status << std::endl;
    if(status >= 0 and connected)
    {
        return Sender(client_fd);
    }
    return std::nullopt;
};