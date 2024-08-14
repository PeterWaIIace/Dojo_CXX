#include "server.hpp"
#include <iostream>

int main()
{
    Server server(8080);

    while(1)
    {
        auto array = server.slisten().rpayload();
        std::cout << array.data() << std::endl;
    }
}