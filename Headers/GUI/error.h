#ifndef ERRORS_H
#define ERRORS_H

#include "qtmetamacros.h"
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>

#include <string>

using std::string;

class ErrorStructure : public QDialog {
    Q_OBJECT
protected:
    QLabel* text;
    QVBoxLayout* errorLayout;
public:
    ErrorStructure(QWidget* parent = nullptr);
};

class ErrorChanging : public ErrorStructure {
    Q_OBJECT
private:
    QButtonGroup* action;
public:
    ErrorChanging(QWidget* parent = nullptr);
public slots:
    void changeWidget(int id);
signals:
    void azione(const QString& choice);
};

class ErrorClosing : public ErrorStructure {
    Q_OBJECT
private:
    QButtonGroup* action;
public:
    ErrorClosing(QWidget* parent = nullptr);
public slots:
    void changeWidget(int id);
signals:
    void azione(const QString& choice);
};

class ErrorDuplicate : public ErrorStructure {
    Q_OBJECT
private:
    QPushButton* confirm;
public:
    ErrorDuplicate(QWidget* parent = nullptr, const string& mode = string(),
            const string& title = string());
public slots:
    void chiudiErrore();
};

class ErrorMissing : public ErrorStructure {
    Q_OBJECT
private:
    QPushButton* confirm;
public:
    ErrorMissing(QWidget* parent = nullptr, const string& mode = string(),
            const string& title = string());
public slots:
    void chiudiErrore();
};

class ErrorNoResult : public ErrorStructure {
    Q_OBJECT
private:
    QPushButton* confirm;
public:
    ErrorNoResult(QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

class ErrorNoTitle : public ErrorStructure {
    Q_OBJECT
private:
    QPushButton* confirm;
public:
    ErrorNoTitle(const string& title = string(), QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

class MessageSuccess : public ErrorStructure {
    Q_OBJECT
private:
    QPushButton* confirm;
public:
    MessageSuccess(QWidget* parent = nullptr, const string& mode = string(), const string& title = string());
public slots:
    void chiudiErrore();
};

class ErrorNoFile : public ErrorStructure {
    Q_OBJECT
private:
    QPushButton* confirm;
public:
    ErrorNoFile(QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

#endif //ERRORS_H
