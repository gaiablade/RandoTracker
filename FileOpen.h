#pragma once

#include <fmt/core.h>

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>

namespace fs = std::filesystem;

using Json = nlohmann::json;

struct Item_Data {
    std::string name;
    std::string filename;
    int grid_x{-1}, grid_y{-1};
};

struct Row_Data {
    std::vector<Item_Data> items;
};

struct Tab_Data {
    std::string tab_name;
    std::string background_image{};
    std::vector<Row_Data> rows;
    int grid_width{-1}, grid_height{-1};
};

class FileOpen {
public:
    FileOpen() = default;
    static FileOpen open(const std::string&);
//private:
    std::string game_title;
    std::vector<Tab_Data> tabs;
};