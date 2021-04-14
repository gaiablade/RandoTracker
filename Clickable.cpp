#include "Clickable.h"

Clickable::Clickable(QString name, QString image_path, QWidget* parent)
    : QLabel(parent)
    , image(image_path)
{
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    this->setToolTip(name);

    QImage darkened = image.scaledToWidth(image.width() * 2);
    for (int i = 0; i < darkened.height(); i++) {
        for (int j = 0; j < darkened.width(); j++) {
            if (darkened.pixelColor(j, i).alpha() > 0.99) {
                QColor color = QColor(darkened.pixelColor(j, i));
                color.setRgb(color.red() * 0.5, color.green() * 0.5, color.blue() * 0.5);
                darkened.setPixelColor(j, i, color);
            }
        }
    }
    setPixmap(QPixmap::fromImage(darkened));

    connect(this, &Clickable::clicked, &Clickable::toggleCollected);
}

void Clickable::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

void Clickable::toggleCollected() {
    collected = !collected;

    if (collected) {
        setPixmap(QPixmap::fromImage(image.scaledToWidth(image.width() * 2)));
    } else {
        QImage darkened = image.scaledToWidth(image.width() * 2);
        for (int i = 0; i < darkened.height(); i++) {
            for (int j = 0; j < darkened.width(); j++) {
                if (darkened.pixelColor(j, i).alpha() > 0.99) {
                    QColor color = QColor(darkened.pixelColor(j, i));
                    color.setRgb(color.red() * 0.5, color.green() * 0.5, color.blue() * 0.5);
                    darkened.setPixelColor(j, i, color);
                }
            }
        }
        setPixmap(QPixmap::fromImage(darkened));
    }
}