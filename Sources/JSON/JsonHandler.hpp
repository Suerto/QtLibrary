#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QFile>
#include <QComboBox>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "../../Headers/LogicModel/contenuto.h"

#include <unordered_map>
#include <vector>
#include <string>

using std::unordered_map;
using std::string;
using std::vector;

class JsonHandler {
public:
    template <class T>
    static void saveEnumToJson(const unordered_map<const T, const string>& map, const QString& filePath, const QString& key) {
        QFile file(filePath);
    
        QJsonObject root;
    
        if (file.exists() && file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            file.close();
    
            QJsonDocument existingDoc = QJsonDocument::fromJson(data);
            if (existingDoc.isObject())
                root = existingDoc.object();
        }
    
        QJsonArray array;
        for (const auto& [type, name] : map) {
            QJsonObject obj;
            obj["nome"] = QString::fromStdString(name);
            obj["enum"] = static_cast<int>(type);
            array.append(obj);
        }
    
        root[key] = array;
    
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

        comboBox->clear();

        for (const auto& value : array) {
            if (value.isObject()) {
                QJsonObject obj = value.toObject();
                int enumValue = obj["enum"].toInt();
                QString nome = obj["nome"].toString();
                comboBox->addItem(nome, static_cast<int>(enumValue));
            }
        }
    }
    
    static vector<unordered_map<string, string>> estraiArrayDiMappe(const QString& percorsoFile) {
        QFile file(percorsoFile);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw std::runtime_error("Impossibile aprire il file JSON.");
        }

        QByteArray dati = file.readAll();
        file.close();

        QJsonParseError errore;
        QJsonDocument doc = QJsonDocument::fromJson(dati, &errore);
        if (errore.error != QJsonParseError::NoError) {
            throw std::runtime_error(("Errore parsing JSON: " + errore.errorString()).toStdString());
        }

        if (!doc.isArray()) {
            throw std::runtime_error("Il file JSON deve contenere un array.");
        }

        QJsonArray array = doc.array();
        std::vector<std::unordered_map<std::string, std::string>> risultato;

        for (const QJsonValue& valore : array) {
            if (!valore.isObject())
                continue;

            QJsonObject oggetto = valore.toObject();
            std::unordered_map<std::string, std::string> mappa;

            for (auto it = oggetto.begin(); it != oggetto.end(); ++it) {
                mappa[it.key().toStdString()] = it.value().toString().toStdString();
            }

            risultato.push_back(std::move(mappa));
        }

        return risultato;
    }
    
    static void salvaArrayDiMappe(const QString& percorsoFile, const vector<Contenuto*>& contenuti) {
        QJsonArray array;
        
        qDebug() << "Percorso file : " << percorsoFile;
        qDebug() << "Contenuti da memorizzare : " << contenuti.size();
        for (const auto& ptr : contenuti) {
            qDebug() << "Puntatore : " << static_cast<void*>(ptr);
            qDebug() << "Raccolti attributi di un contenuto";
            std::unordered_map<std::string, std::string> mappa = ptr->fromObjectToMap();
            QJsonObject oggetto;

            for (const auto& obj : mappa) {
                oggetto[QString::fromStdString(obj.first)] = QString::fromStdString(obj.second);
            }

            array.append(oggetto);
            qDebug() << "Contenuto memorizzato nel Json";
        }

        QJsonDocument doc(array);
        QFile file(percorsoFile);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            throw std::runtime_error("Impossibile aprire il file per la scrittura.");
        }

        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
};

#endif //JSONHANDLER_H
