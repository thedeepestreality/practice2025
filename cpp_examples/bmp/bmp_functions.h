#include <vector>
#include <string>
#include <cstdint>

void readBmp(const std::string& filename, std::vector<uint8_t>& rgb_data, int& width, int& height);

void writeBmp(const std::string& filename, const std::vector<uint8_t>& rgb_data, int width, int height);
