#pragma once

#include <memory>
#include <vector>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

#include "Clickable.h"
#include "FileOpen.h"

#include <filesystem>

namespace fs = std::filesystem;

class Tab : public QWidget
{
    Q_OBJECT
public:
    Tab(Tab_Data& tab_data, QWidget* parent = nullptr);
    void changeColor(const std::string& color_string);
private:
    std::unique_ptr<QGridLayout> layout;
    std::vector<std::unique_ptr<Clickable>> icons;
};