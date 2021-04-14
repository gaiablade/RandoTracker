#include "FileOpen.h"

FileOpen FileOpen::open(const std::string& filename) {
    FileOpen fo;

    std::ifstream in(filename);
    Json json = Json::parse(in);

    if (json.find("game_title") == json.end()) {
        throw "Error! Attribute game_title is not defined!";
    }

    if (!json["game_title"].is_string()) {
        throw "Error! Attribute game_title must be a string!";
    }

    if (json.find("tabs") == json.end()) {
        throw "Error! Array element \"tabs\" is not defined!";
    }

    if (!json["tabs"].is_array()) {
        throw "Error! Array element \"tabs\" is not an array!";
    }

    fo.game_title = json["game_title"];
    fo.tabs.reserve(json["tabs"].size());

    auto& tabs = json["tabs"];

    auto parseTab = [&](Json& tab) {
        if (tab.find("tab_name") == tab.end()) {
            throw "Error! Attribute \"tab_name\" not defined!";
        }
        if (!tab["tab_name"].is_string()) {
            throw "Error! Attribute \"tab_name\" must be a string!";
        }
        if (tab.find("rows") == tab.end()) {
            throw "Error! Array attribute \"rows\" not defined!";
        }
        if (!tab["rows"].is_array()) {
            throw "Error! Attribute \"rows\" must be an array!";
        }

        Tab t;
        t.tab_name = tab["tab_name"];

        if (tab.find("grid_width") != tab.end()) {
            if (!tab["grid_width"].is_number()) {
                throw "Error! Attribute \"grid_width\" must be a number!";
            } else {
                t.grid_width = tab["grid_width"];
            }
        }
        if (tab.find("grid_height") != tab.end()) {
            if (!tab["grid_height"].is_number()) {
                throw "Error! Attribute \"grid_height\" must be a number!";
            } else {
                t.grid_height = tab["grid_height"];
            }
        }

        for (auto row = tab["rows"].begin(); row != tab["rows"].end(); row++) {
            t.rows.emplace_back();
            for (auto item = row->begin(); item != row->end(); item++) {
                if (!item->is_object()) {
                    throw "Error! Item must be an object!";
                }
                if (item->find("name") == item->end()) {
                    throw "Error! Item attribute \"name\" not defined!";
                }
                if (!item->operator[]("name").is_string()) {
                    throw "Error! Item attribute \"name\" must be a string!";
                }
                if (item->find("img") == item->end()) {
                    throw "Error! Item attribute \"filename\" not defined!";
                }
                if (!item->operator[]("img").is_string()) {
                    throw "Error! Item attribute \"filename\" must be a string!";
                }
                Item i;
                i.name = item->operator[]("name");
                i.filename = item->operator[]("img");

                if (item->find("grid_x") != item->end()) {
                    if (!item->operator[]("grid_x").is_number()) {
                        throw "Error! Attribute \"grid_x\" must be a number!";
                    } else {
                        i.grid_x = item->operator[]("grid_x");
                    }
                }
                if (item->find("grid_y") != item->end()) {
                    if (!item->operator[]("grid_y").is_number()) {
                        throw "Error! Attribute \"grid_y\" must be a number!";
                    } else {
                        i.grid_y = item->operator[]("grid_y");
                    }
                }

                t.rows.back().items.push_back(i);
            }
        }

        return t;
    };

    for (auto it = tabs.begin(); it != tabs.end(); it++) {
        fo.tabs.emplace_back(parseTab(*it));
    }

    return fo;
}
