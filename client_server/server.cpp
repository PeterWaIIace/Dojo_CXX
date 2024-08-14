#pragma once

#include "server.hpp"
#include <iostream> 

int32_t check(uint32_t err_code)
{
    if(err_code < 0){
        printf("Failure");
        exit(EXIT_FAILURE);
    };
    return err_code;
}

Receiver::Receiver(int fd): sockfd(fd) {};


std::string Receiver::rpayload()
{
    std::array<char, 1024> arr;
    ssize_t length = read(sockfd,arr.data(),arr.size());
    std::string str(arr.data(), length);
    return str;
};

Server::Server(int port) : sockfd(socket(AF_INET,SOCK_STREAM,0)), port(port){
    opt = 1;
    run = 1;
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    check(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR ,&opt, sizeof(opt)));
    check(bind(sockfd,reinterpret_cast<const sockaddr*>(&servaddr),sizeof(servaddr)));
    check(listen(sockfd,CONNECTIONS));
};

Receiver Server::slisten()
{
    socklen_t cli_addr_size = sizeof(servaddr);
    int conn_sock;
    std::cout << "waiting for connnection" << std::endl;
    conn_sock = accept(sockfd,reinterpret_cast<struct sockaddr*>(&destaddr),&cli_addr_size);
    return Receiver(conn_sock);
}
