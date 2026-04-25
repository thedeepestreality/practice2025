#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>

#include "bmp_functions.h"
#include "bmp_headers.h"

void readBmp(const std::string& filename, std::vector<uint8_t>& rgb_data, int& width, int& height)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
        throw std::runtime_error("Failed to open input file");

    BMPHeader bmp_header;
    file.read(reinterpret_cast<char*>(&bmp_header), sizeof(BMPHeader));

    DIBHeader dib_header;
    file.read(reinterpret_cast<char*>(&dib_header), sizeof(DIBHeader));

    width = dib_header.width;
    height = std::abs(dib_header.height);

    // Calculate row padding (BMP rows are padded to multiple of 4 bytes)
    int row_byte_size = 3 * width;
    int row_byte_size_padded = (row_byte_size + 3) & ~3;
    int padding = row_byte_size_padded - row_byte_size_padded;

    // Move to pixel data
    file.seekg(bmp_header.data_offset);

    // Read pixel data
    rgb_data.resize(row_byte_size * height);
    char buf[4];
    char* data_ptr = reinterpret_cast<char*>(rgb_data.data());

    for (int y = 0; y < height; ++y) {
        file.read(data_ptr + y * row_byte_size, row_byte_size);
        file.read(buf, padding);
    }
}

void writeBmp(const std::string& filename, const std::vector<uint8_t>& rgb_data, int width, int height)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file)
        throw std::runtime_error("Failed to open output file");

    unsigned int data_offset = sizeof(DIBHeader) + sizeof(BMPHeader); // 54 bytes
    int row_byte_size = 3 * width;
    int row_byte_size_padded = (row_byte_size + 3) & ~3;
    int padding = row_byte_size_padded - row_byte_size_padded;

    BMPHeader bmp_header;
    bmp_header.signature = 0x4d42;
    bmp_header.file_size = height * row_byte_size_padded + data_offset;
    bmp_header.data_offset = data_offset;
    file.write(reinterpret_cast<char*>(&bmp_header), sizeof(BMPHeader));

    DIBHeader dib_header;
    dib_header.header_size = sizeof(DIBHeader);
    dib_header.width = width;
    dib_header.height = -height;
    dib_header.planes = 1;
    dib_header.bits_per_pixel = 24;
    dib_header.compression = 0;
    dib_header.image_size = 3 * width * height;
    dib_header.x_pixels_per_meter = 0;
    dib_header.y_pixels_per_meter = 0;
    dib_header.colors_used = 0;
    dib_header.important_colors = 0;
    file.write(reinterpret_cast<char*>(&dib_header), sizeof(DIBHeader));

    char buf[4] = {};

    const char* data_ptr = reinterpret_cast<const char*>(rgb_data.data());
    for (int y = 0; y < height; ++y) {
        file.write(data_ptr + y * row_byte_size, row_byte_size);
        file.write(buf, padding);
    }
}
