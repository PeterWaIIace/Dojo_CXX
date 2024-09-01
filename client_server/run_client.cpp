#include "client.hpp"
#include <iostream>

int main()
{
    Client client(8080);

    while(1)
    {
        std::cout << "waiting" << std::endl;
        auto result = client.cconnect("127.0.0.1");
        if(result)
        {
            std::cout << "sending: " << "hello world" << std::endl;
            result->spayload(std::string("hello world"));
        }
    }
}