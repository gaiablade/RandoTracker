#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("background-color: #262626; color: #DDDDDD;");
    ui->menubar->setStyleSheet("border: 1px solid #222222;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    if (!tabs.empty()) {
        for (auto& tab : tabs) {
            tab->close();
        }
        tabs.clear();
    }
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
                    tabs.emplace_back(std::make_unique<Tab>(tab));
                    tab_widget->addTab(tabs.back().get(), tab.tab_name.c_str());
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

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_openNewWindowButton_clicked()
{
    if (tab_widget) {
        //tab_widget->currentWidget()->setParent(nullptr);
        QWidget* c = tab_widget->currentWidget();
        if (c) {
            c->setParent(nullptr);
            c->show();
        }
    }
}
