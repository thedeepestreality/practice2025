#include <fstream>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "bmp_headers.h"

int main(int argc, char* argv[]) {

    std::ifstream file(argv[1], std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    BMPHeader bmpHeader;
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHeader));

    DIBHeader dibHeader;
    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(DIBHeader));

    unsigned int width;
    unsigned int height;

    width = dibHeader.width;
    height = -dibHeader.height;

    // Calculate row padding (BMP rows are padded to multiple of 4 bytes)
    int rowSize = (width * 3 + 3) & ~3;

    // Move to pixel data
    file.seekg(bmpHeader.data_offset);

    // Read pixel data
    std::vector<sf::Color> pixels(width * height);
    std::vector<char> row(rowSize);

    for (int y = 0; y < height; ++y) {
        file.read(row.data(), rowSize);

        for (int x = 0; x < width; x++) {
            // BMP stores as BGR
            char blue = row[x * 3];
            char green = row[x * 3 + 1];
            char red = row[x * 3 + 2];

            pixels[y * width + x] = sf::Color(red, green, blue);
        }
    }

    sf::Vector2u win_size(width, height);
    sf::RenderWindow window(sf::VideoMode(win_size), "BMP Image Viewer");
    sf::Image image(win_size, sf::Color::Black);

    // Set each pixel individually
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            image.setPixel({x, y}, pixels[y * width + x]);

    sf::Texture texture(image);
    sf::Sprite sprite(texture);

    window.clear();
    window.draw(sprite);
    window.display();

    while (window.isOpen())
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>())
                window.close();

    return 0;
}