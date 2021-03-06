#include "metamodel.h"

#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QtEndian>

#include "metamodel/level.h"

#include <iostream>

MetaModel::MetaModel(QObject * parent) :
    QObject(parent),
    sublevelCount(0),
    idsCount(0)
{
    cpuAndNetwork = new Level("CPU And Network");
    runtimeEnvironment = new Level("Runtime Environment");
    process = new Level("Process");
    applicationComponent = new Level("Application Component");
}

bool MetaModel::setModel(const QString file)
{

    QDomDocument doc("log_model");
    bool ret = doc.setContent(new QFile(file));

    if (ret == false) {
        return false;
    }

    QDomElement docElem = doc.documentElement();

    QDomNodeList n0 = docElem.elementsByTagName("cpu_and_network");
    if (n0.size() != 1) {
        return false;
    }

    QDomNodeList n1 = docElem.elementsByTagName("runtime_environment");
    if (n0.size() != 1) {
        return false;
    }

    QDomNodeList n2 = docElem.elementsByTagName("process");
    if (n0.size() != 1) {
        return false;
    }

    QDomNodeList n3 = docElem.elementsByTagName("application_component");
    if (n0.size() != 1) {
        return false;
    }

    QDomNode cpuAndNetworkNode = n0.at(0);
    QDomNode runtimeEnvironmentNode = n1.at(0);
    QDomNode processNode = n2.at(0);
    QDomNode applicationComponentNode = n3.at(0);

    QDomElement cpuAndNetworkElement = cpuAndNetworkNode.toElement();
    if (cpuAndNetworkElement.isNull() ) {
        return false;
    }

    QDomElement runtimeEnvironmentElement = runtimeEnvironmentNode.toElement();
    if (runtimeEnvironmentNode.isNull()) {
        return false;
    }

    QDomElement processElement = processNode.toElement();
    if (processElement.isNull()) {
        return false;
    }

    QDomElement applicationComponentElement = applicationComponentNode.toElement();
    if (applicationComponentElement.isNull()) {
        return false;
    }

    if (parseLevel(cpuAndNetwork, &cpuAndNetworkElement) == false) {
        return false;
    }

    if (parseLevel(runtimeEnvironment, &runtimeEnvironmentElement) == false) {
        return false;
    }

    if (parseLevel(process, &processElement) == false) {
        return false;
    }

    if (parseLevel(applicationComponent, &applicationComponentElement) == false) {
        return false;
    }

    return ret;
}

void MetaModel::printLevel(Level * level)
{
    qDebug() << "Level name=" << level->getName();

    for (int i = 0; i < level->getIds()->count(); i++) {
        qDebug() << " Id: name=" << (*level->getIds())[i]->getName() << " size=" << (*level->getIds())[i]->getSize();
    }

    for (int i = 0; i < level->getSubLevels()->count(); i++) {
        SubLevel * subLevel = (*level->getSubLevels())[i];
        qDebug() << " SubLevel name=" << subLevel->getName();
        for (int j = 0; j < subLevel->getLogTypes()->count(); ++j) {
            LogType * logType = (*(subLevel->getLogTypes()->begin() + j));
            qDebug() << "  LogType name=" << logType->getName()
                     << " value=" << logType->getValue()
                     << " indicator=" << logType->getIndicator()
                     << " priority=" << logType->getPriority()
                     << " log_struct=" << logType->getLogStruct();
            for (int k = 0; k < logType->getLogCodes()->count(); ++k) {
                qDebug() << "   LogCodes name=" << (*(logType->getLogCodes()->begin() + k)).getName()
                         << " value=" << (*(logType->getLogCodes()->begin() + k)).getValue();
            }
        }
    }

}

Tree *MetaModel::getTree()
{
    return &root;
}


QList<LogEvent *> * MetaModel::getEvents()
{
    return &events;
}

Level * MetaModel::getCpuAndNetwork()
{
    return cpuAndNetwork;
}

Level * MetaModel::getRuntimeEnvironment()
{
    return runtimeEnvironment;
}

Level * MetaModel::getProcess()
{
    return process;
}

Level * MetaModel::getApplicationComponent()
{
    return applicationComponent;
}

bool MetaModel::getIndicator(unsigned int type)
{
    return ((type & 0xffff) & 0x1000) != 0;
}

unsigned int MetaModel::getPriority(unsigned int type)
{
    return 0;
}

unsigned int MetaModel::getLogStruct(unsigned int type)
{
    return 0;
}

unsigned int MetaModel::getLogLevel(unsigned int type)
{
    return 0;
}

unsigned int MetaModel::getLogType(unsigned int type)
{
    return 0;
}

Id * MetaModel::getId(unsigned int idNum)
{
    Id * id = 0;
    unsigned int size;

    size = cpuAndNetwork->getIds()->size();
    if (size > idNum) {
        id = cpuAndNetwork->getIds()->at(idNum);
        return id;
    }
    if (idNum >= size) {
        idNum = idNum - size;
    }

    size = runtimeEnvironment->getIds()->size();
    if (size > idNum) {
        id = runtimeEnvironment->getIds()->at(idNum);
        return id;
    }
    if (idNum >= size) {
        idNum = idNum - size;
    }

    size = process->getIds()->size();
    if (size > idNum) {
        id = process->getIds()->at(idNum);
        return id;
    }
    if (idNum >= size) {
        idNum = idNum - size;
    }

    size = applicationComponent->getIds()->size();
    if (size > idNum) {
        id = applicationComponent->getIds()->at(idNum);
        return id;
    }
    if (idNum >= size) {
        idNum = idNum - size;
    }

    return id;
}

bool MetaModel::parseLevel(Level * level, QDomElement * levelElement)
{
    QDomNodeList levelIds = levelElement->elementsByTagName("id");
    for (int i = 0; i < levelIds.count(); i++) {
        QDomElement element = levelIds.at(i).toElement();
        if (element.isNull()) {
            return false;
        }
        bool ok;
        int size = element.attribute("size").toInt(&ok);
        if (size > 0) {
            if (ok == false) {
                return false;
            }
            QString name = element.text();
            Id * id = new Id(size, name, idsCount);
            idsCount++;
            level->insert(id);
        }
    }

    QDomNodeList levelSubLevels = levelElement->elementsByTagName("level");
    for (int i = 0; i < levelSubLevels.count(); i++) {
        QDomElement element = levelSubLevels.at(i).toElement();
        if (element.isNull()) {
            return false;
        }
        QDomNodeList levelNameNodes = element.elementsByTagName("name");
        if (levelNameNodes.count() != 1) {
            return false;
        }
        QDomElement nameElement = levelNameNodes.at(0).toElement();
        if (nameElement.isNull()) {
            return false;
        }
        QString levelName = nameElement.text();
        SubLevel * subLevel = new SubLevel(levelName, sublevelCount);
        sublevelCount++;
        QDomNodeList logTypes = element.elementsByTagName("log_type");
        for (int j = 0; j < logTypes.count(); j++) {
            QDomElement logTypeElement = logTypes.at(j).toElement();
            if (logTypeElement.isNull()) {
                return false;
            }
            QString name(logTypeElement.attribute("name").toAscii());
            bool ok;
            unsigned int value = logTypeElement.attribute("value").toUInt(&ok, 16);
            if (ok == false) {
                return false;
            }
            bool indicator = (logTypeElement.attribute("indicator").toUInt(&ok) != 0);
            if (ok == false) {
                return false;
            }
            unsigned int priority = logTypeElement.attribute("priority").toUInt(&ok);
            if (ok == false) {
                return false;
            }
            unsigned int logStruct = logTypeElement.attribute("log_struct").toUInt(&ok);
            if (ok == false) {
                return false;
            }

            LogType * logType = new LogType(value, name);

            if (indicator != logType->getIndicator()) {
                return false;
            }
            if (priority != logType->getPriority()) {
                return false;
            }
            if (logStruct != logType->getLogStruct()) {
                return false;
            }

            QDomNodeList logCodes = logTypeElement.elementsByTagName("log_code");

            for (int k = 0; k < logCodes.count(); k++) {
                QDomElement logCodeElement = logCodes.at(k).toElement();
                if (logCodeElement.isNull()) {
                    return false;
                }
                unsigned int logCodeValue = logCodeElement.attribute("value").toUInt(&ok, 16);
                if (ok == false) {
                    return false;
                }
                LogCode logCode(logCodeValue, logCodeElement.text());
                logType->insert(logCode);
            }

            subLevel->insert(logType);
        }
        level->insert(subLevel);
    }

    return true;
}

bool MetaModel::parse(const QString fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);

    events.clear();

    unsigned int fileSize = file.size();
    unsigned int fileRead = 0;
    while ((fileRead + 10) < fileSize) {

        unsigned short int typeTmp;
        file.read((char *) &typeTmp, 2);
        typeTmp = qFromBigEndian(typeTmp);
        unsigned int type = typeTmp;

        unsigned char lenTmp;
        file.read((char *) &lenTmp, 1);
        lenTmp = qFromBigEndian(lenTmp);
        unsigned int len = (unsigned int) lenTmp;

        unsigned int timestamp_s;
        file.read((char *) &timestamp_s, 4);
        timestamp_s = qFromBigEndian(timestamp_s);

        unsigned short int timestamp_m;
        file.read((char *) &timestamp_m, 2);
        timestamp_m = qFromBigEndian(timestamp_m);

        unsigned long long int timestamp = timestamp_s * 1000 + timestamp_m;

        unsigned int code;
        file.read((char *) &code, 4);
        code = qFromBigEndian(code);

        fileRead += 10;

        LogType * logType = 0;

        if (logType == 0) {
            logType = cpuAndNetwork->getLogType(type);
        }
        if (logType == 0) {
            logType = runtimeEnvironment->getLogType(type);
        }
        if (logType == 0) {
            logType = process->getLogType(type);
        }
        if (logType == 0) {
            logType = applicationComponent->getLogType(type);
        }

        if (logType != 0) {
//            logType = new LogType(type, "Undefined");
//        }

        QList<Id *> idsTmp;
        unsigned int lenRead = 0;
        float indicator = 0;
        for (unsigned int i = 0; i < logType->getLogStruct(); i++) {

            Id * id  = getId(i);

                if (id != 0) {

                char * buffer = new char[id->getSize() / 8];
                qint64 ret = file.read(buffer, id->getSize() / 8);
                fileRead += id->getSize() / 8;
                id->parse(buffer);
                delete buffer;

                lenRead += id->getSize() / 8;

                idsTmp.insert(idsTmp.end(), id);

                if (lenRead > (len - 10)) {
                    return false;
                }

            }

        }

        if (logType->getIndicator() == true) {
            if ((len - 10 - lenRead) != 4) {
                return false;
            }
            file.read((char *) &indicator, sizeof(float));
            fileRead += sizeof(float);

            lenRead += sizeof(float);
        }


        LogEvent * ev= new LogEvent(logType, len, timestamp, code, indicator, getSubLevel(logType));
        for (int i = 0; i < idsTmp.size(); i++) {
            ev->insertId(idsTmp[i]);
        }
        events.insert(events.end(), ev);

        } else {

            if (len > 10) {
                char * buffer = new char[len - 10];
                file.read(buffer, len - 10);
                fileRead += len - 10;
                delete buffer;
            }
        }
    }

    file.close();

    arrangeEvents();

    return true;
}

SubLevel * MetaModel::getSubLevel(LogType * logType) {
    foreach (SubLevel * sub, *(cpuAndNetwork->getSubLevels())) {
        foreach (LogType * type, *(sub->getLogTypes())) {
            if ((type->getValue() == logType->getValue()) && (type->getName() == logType->getName())) {
                return sub;
            }
        }
    }

    foreach (SubLevel * sub, *(runtimeEnvironment->getSubLevels())) {
        foreach (LogType * type, *(sub->getLogTypes())) {
            if ((type->getValue() == logType->getValue()) && (type->getName() == logType->getName())) {
                return sub;
            }
        }
    }

    foreach (SubLevel * sub, *(process->getSubLevels())) {
        foreach (LogType * type, *(sub->getLogTypes())) {
            if ((type->getValue() == logType->getValue()) && (type->getName() == logType->getName())) {
                return sub;
            }
        }
    }

    foreach (SubLevel * sub, *(applicationComponent->getSubLevels())) {
        foreach (LogType * type, *(sub->getLogTypes())) {
            if ((type->getValue() == logType->getValue()) && (type->getName() == logType->getName())) {
                return sub;
            }
        }
    }

    return 0;

}

void MetaModel::arrangeEvents()
{
    foreach (LogEvent * event, events) {
        root.insert(event);
    }

}













































