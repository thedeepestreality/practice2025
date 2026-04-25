#include <vector>
#include <iostream>
#include <exception>

#include "bmp_headers.h"
#include "bmp_functions.h"

int main(int argc, char* argv[])
{
    std::vector<uint8_t> bmp_data;
    int width;
    int height;

    try
    {
        readBmp(argv[1], bmp_data, width, height);
        writeBmp(argv[2], bmp_data, width, height);
    }
    catch(std::exception ex)
    {
        std::cout << "Exception caught: " << ex.what() << '\n';
    }

    return 0;
}