#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QFile>
#include <QComboBox>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class JsonHandler {
public:
    //fix necessario per poter salvare tutte le modifiche e aggiungere elementi
    template <class T>
    static void saveEnumToJson(const unordered_map<const T, const string>& map, const QString& filePath, const QString& key) {
        QFile file(filePath);
        
        if (file.open(QIODevice::WriteOnly)) {
            QJsonObject root;
            QJsonArray array;
           
            for (const auto&[type, name] : map) {
                QJsonObject obj;
                obj["nome"] = QString::fromStdString(name);
                obj["enum"] = static_cast<int>(type);
                array.append(obj);
            }
           
            root[key] = array;
            QJsonDocument doc(root);
            file.write(doc.toJson());
        }
    }

    static void loadEnumFromJson(QComboBox* combo, const QString& filePath, const QString& key) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            QJsonDocument document = QJsonDocument::fromJson(data);
            QJsonObject root = document.object();
            QJsonArray array = root[key].toArray();

            combo->clear();  // Pulisce la comboBox prima di popolarla

            for (const QJsonValue& value : array) {
                QJsonObject obj = value.toObject();
                QString displayName = obj["nome"].toString();
                int enumValue = obj["enum"].toInt();
                combo->addItem(displayName, enumValue);  // Aggiungi item con nome e enumValue
            }
        }
    }
};

#endif //JSONHANDLER_H
