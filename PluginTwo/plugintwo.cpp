#include "plugintwo.h"

PluginTwo::PluginTwo(QObject *parent)
{
    Q_UNUSED(parent);
    qInfo() << this << "created";
}

QString PluginTwo::name()
{
    return QString("Plugin Two");
}

QStringList PluginTwo::commands()
{
    //list of supported commands
    QStringList list;

    list << "antelope";
    list << "blue duiker";
    list << "royale";
    list << "giant eland";

    return list;
}

void PluginTwo::execute(QString command, QStringList args)
{
    Q_UNUSED(args);
    QStringList list = commands();
    if(list.contains(command))
    {
        qInfo() << this << "execute" << command;
    }
}
