#ifndef JSON_SELECTOR_H
#define JSON_SELECTOR_H

#include <QWidget>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <QDir>
#include <QFileDialog>
#include <QCoreApplication>

#include <array>
#include <string>

using std::array;
using std::string;

class JsonSelector : public QWidget {
    Q_OBJECT
private:
    array<string, 4> json{};
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
public:
    array<string, 4> getFiles() const;
    JsonSelector(QWidget* parent = nullptr);
signals:
    void caricaContenuti();
};

#endif //JSON_SELECTOR_H
