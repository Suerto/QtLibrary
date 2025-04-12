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
    
        QJsonObject root;
    
        // Se il file esiste e contiene dati, leggili
        if (file.exists() && file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            file.close();
    
            QJsonDocument existingDoc = QJsonDocument::fromJson(data);
            if (existingDoc.isObject())
                root = existingDoc.object();
        }
    
        // Costruisci l'array per il nuovo enum
        QJsonArray array;
        for (const auto& [type, name] : map) {
            QJsonObject obj;
            obj["nome"] = QString::fromStdString(name);
            obj["enum"] = static_cast<int>(type);
            array.append(obj);
        }
    
        // Sovrascrivi (o aggiungi) la chiave specifica
        root[key] = array;
    
        // Salva tutto nel file
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            QJsonDocument doc(root);
            file.write(doc.toJson(QJsonDocument::Indented));
            file.close();
        }
    }

    static void loadEnumFromJson(const QString& filePath, const QString& key, QComboBox* comboBox) {
        if (!comboBox)
            return;

        QFile file(filePath);
        if (!file.exists() || !file.open(QIODevice::ReadOnly))
            return;

        QByteArray data = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isObject())
            return;

        QJsonObject root = doc.object();
        if (!root.contains(key) || !root[key].isArray())
            return;

        QJsonArray array = root[key].toArray();

        comboBox->clear(); // Pulisce prima eventuali elementi precedenti

        for (const auto& value : array) {
            if (value.isObject()) {
                QJsonObject obj = value.toObject();
                int enumValue = obj["enum"].toInt();
                QString nome = obj["nome"].toString();
                comboBox->addItem(nome, static_cast<int>(enumValue));
            }
        }
    }
};

#endif //JSONHANDLER_H
