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
    cpuAndNetwork("CPU And Network"),
    runtimeEnvironment("Runtime Environment"),
    process("Process"),
    applicationComponent("Application Component")
{

}

bool MetaModel::setModel(const QString file)
{
    QDomDocument doc("Model");
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

    if (parseLevel(&cpuAndNetwork, &cpuAndNetworkElement) == false) {
        return false;
    }

    if (parseLevel(&runtimeEnvironment, &runtimeEnvironmentElement) == false) {
        return false;
    }

    if (parseLevel(&process, &processElement) == false) {
        return false;
    }

    if (parseLevel(&applicationComponent, &applicationComponentElement) == false) {
        return false;
    }

    return ret;
}

void MetaModel::printLevel(Level * level)
{
    qDebug() << "Level name=" << level->getName();

    for (int i = 0; i < level->getIds().count(); i++) {
        qDebug() << " Id: name=" << level->getIds()[i].getName() << " size=" << level->getIds()[i].getSize();
    }

    for (int i = 0; i < level->getSubLevels().count(); i++) {
        SubLevel subLevel = level->getSubLevels()[i];
        qDebug() << " SubLevel name=" << subLevel.getName();
        for (int j = 0; j < subLevel.getLogTypes().count(); ++j) {
            LogType logType = (*(subLevel.getLogTypes().begin() + j));
            qDebug() << "  LogType name=" << logType.getName()
                     << " value=" << logType.getValue()
                     << " indicator=" << logType.getIndicator()
                     << " priority=" << logType.getPriority()
                     << " log_struct=" << logType.getLogStruct();
            for (int k = 0; k < logType.getLogCodes().count(); ++k) {
                qDebug() << "   LogCodes name=" << (*(logType.getLogCodes().begin() + k)).getName()
                         << " value=" << (*(logType.getLogCodes().begin() + k)).getValue();
            }
        }
    }

}

QMap<unsigned int, Event> MetaModel::getEvents()
{
    return events;
}

Level MetaModel::getCpuAndNetwork()
{
    return cpuAndNetwork;
}

Level MetaModel::getRuntimeEnvironment()
{
    return runtimeEnvironment;
}

Level MetaModel::getProcess()
{
    return process;
}

Level MetaModel::getApplicationComponent()
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
            level->insert(Id(size, name));
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
        SubLevel subLevel(levelName);
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
            unsigned int indicator = logTypeElement.attribute("indicator").toUInt(&ok);
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
            LogType logType(value, name, indicator, priority, logStruct);
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
                logType.insert(logCode);
            }

            subLevel.insert(logType);
        }
        level->insert(subLevel);
    }

    return true;
}

bool MetaModel::parse(const QString fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);

    unsigned short int type;
    file.read((char *) &type, 2);
    type = qFromBigEndian(type);

    unsigned char len, lenTmp;
    file.read((char *) &len, 1);
    len = qFromBigEndian(len);
    lenTmp = len;

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

    lenTmp -= 10;

    cpuAndNetwork.getLogType(type);

    std::cout << (std::hex) << (unsigned int) type << std::endl;
    std::cout << (std::dec) <<(unsigned int) len << std::endl;
    std::cout << (std::dec) << timestamp << std::endl;
    std::cout << (std::hex) << code << std::endl;


//    (*(runtimeEnvironment.getSubLevels()[0].getLogTypes().find(type))).getName();

    file.close();
}
