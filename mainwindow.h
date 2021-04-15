#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QGridLayout>
#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QPushButton>
#include <QTabWidget>

#include <fstream>
#include <iostream>
#include <memory>

#include <fmt/color.h>
#include <nlohmann/json.hpp>

#include "Clickable.h"
#include "FileOpen.h"
#include "Tab.h"

// filesystem goes at the end to prevent moc bug (why does this exist)
#include <filesystem>

using Json = nlohmann::json;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<QGridLayout> grid_layout;
    std::unique_ptr<QTabWidget> tab_widget;
    std::vector<std::unique_ptr<Tab>> tabs;
};

#endif // MAINWINDOW_H
