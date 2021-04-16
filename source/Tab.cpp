#include "Tab.h"

Tab::Tab(Tab_Data& tab_data, QWidget* parent)
    : QWidget(parent)
    , layout(std::make_unique<QGridLayout>())
{
    //setStyleSheet("background-color: #262626; color: #DDDDDD;");
    setWindowTitle(tab_data.tab_name.c_str());

    int row_no = 0;
    for (auto& row: tab_data.rows) {
        int column_no = 0;
        for (auto& item: row.items) {
            // Determine grid position:
            int grid_x = item.grid_x > -1 ? item.grid_x : column_no;
            int grid_y = item.grid_y > -1 ? item.grid_y : row_no;

            // Create image
            fs::path image_path = fs::path(item.filename);
            if (fs::exists(image_path)) {
                icons.emplace_back(std::make_unique<Clickable>(item.name.c_str(), image_path.c_str(), this));
                layout->addWidget(icons.back().get(), grid_y, grid_x);
            } else {
                icons.emplace_back(std::make_unique<Clickable>(item.name.c_str(), "question_mark.png", this));
                layout->addWidget(icons.back().get(), grid_y, grid_x);
            }
            column_no++;
        }
        row_no++;
    }

    for (int i = 0; i < layout->columnCount(); i++) {
        layout->setColumnStretch(i, 1);
    }

    this->setLayout(layout.get());
    this->show();
}

void Tab::changeColor(const std::string& color_string) {
    setStyleSheet(fmt::format("background-color:{}", color_string).c_str());
}