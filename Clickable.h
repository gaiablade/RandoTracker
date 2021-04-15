#pragma once

#include <iostream>

#include <QLabel>
#include <QMouseEvent>
#include <QPixmap>
#include <QStyle>

class Clickable : public QLabel
{
    Q_OBJECT
public:
    Clickable(QString name, QString image_path, QWidget* parent = nullptr);

signals:
    void clicked();

private:
    virtual void mousePressEvent(QMouseEvent* event) override;
    void toggleCollected();

private:
    QImage image;
    QImage darkened;
    bool collected{false};
};