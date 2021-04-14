#pragma once

#include <fmt/core.h>

#include <iostream>
#include <fstream>
#include <vector>

#include "vendor/nlohmann/json.hpp"

using Json = nlohmann::json;

struct Item {
    std::string name;
    std::string filename;
    int grid_x{-1}, grid_y{-1};
};

struct Row {
    std::vector<Item> items;
};

struct Tab {
    std::string tab_name;
    std::vector<Row> rows;
    int grid_width{-1}, grid_height{-1};
};

class FileOpen {
public:
    FileOpen() = default;
    static FileOpen open(const std::string&);
//private:
    std::string game_title;
    std::vector<Tab> tabs;
};