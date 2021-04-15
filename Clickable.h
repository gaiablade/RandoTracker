#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <iostream>

#include <QLabel>
#include <QPixmap>

class Clickable : public QLabel
{
    Q_OBJECT
public:
    Clickable(QString name, QString image_path, QWidget* parent = nullptr);

signals:
    void clicked();

private:
    void mousePressEvent(QMouseEvent* event);
    void toggleCollected();

private:
    QImage image;
    QImage darkened;
    bool collected{false};
};

#endif // CLICKABLE_H