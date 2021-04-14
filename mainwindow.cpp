#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    const QString filename = QFileDialog::getOpenFileName(this, tr("Select a file"), "./tracker_files", tr("JSON Files (*.json)"));
    if (!filename.isEmpty()) {
        auto file = std::filesystem::path(filename.toStdString());
        auto extension = file.extension().string();

        if (extension != ".json") {
            QMessageBox message;
            std::string msg = "Selected file is no a JSON file! Given filetype: " + extension;
            message.setText(QString::fromStdString(msg));
            message.exec();
            return;
        } else {
            try {
                auto fo = FileOpen::open(file.string());

                ui->label->setText(QString(fo.game_title.c_str()));

                grid_layout = std::make_unique<QGridLayout>();
                tab_widget  = std::make_unique<QTabWidget>(ui->tracker);
                grid_layout->addWidget(tab_widget.get());

                for (auto& tab: fo.tabs) {
                    // TODO: Fix memory leaks lol this whole sections is v bad
                    QWidget* w = new QWidget();
                    QGridLayout* l = new QGridLayout();

                    int row_no = 0;
                    for (auto& row: tab.rows) {
                        int item_no = 0;
                        for (auto& item: row.items) {
                            // Determine grid position:
                            int grid_x = item.grid_x > -1 ? item.grid_x : item_no;
                            int grid_y = item.grid_y > -1 ? item.grid_y : row_no;
                            // Create image
                            std::filesystem::path image_path = file.parent_path() / item.filename;
                            if (std::filesystem::exists(image_path)) {
                                Clickable* clickable = new Clickable(item.name.c_str(), image_path.c_str());
                                l->addWidget(clickable, grid_y, grid_x);
                                item_no++;
                            } else {
                                Clickable* clickable = new Clickable(item.name.c_str(), "question_mark.png");
                                l->addWidget(clickable, grid_y, grid_x);
                                item_no++;
                            }
                        }
                        row_no++;
                    }

                    for (int i = 0; i < l->columnCount(); i++) {
                        l->setColumnStretch(i, 1);
                    }

                    w->setLayout(l);

                    tab_widget->addTab(w, QString::fromStdString(tab.tab_name));
                }

                ui->tracker->setLayout(grid_layout.get());
            }  catch (const char* e) {
                QMessageBox message;
                message.setText(QString(e));
                message.exec();
                return;
            }
        }
    }
}
