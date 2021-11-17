#ifndef PLUGINTWO_H
#define PLUGINTWO_H

#include <QObject>
#include <QDebug>
#include "../myapp/interfaces/iPlugin.h"

class PluginTwo : public QObject, public iPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.company.PluginTwo")
    Q_INTERFACES(iPlugin)

public:
    explicit PluginTwo(QObject *parent = nullptr);

signals:

public slots:

    // iPlugin interface
public:
    QString name() override;
    QStringList commands() override;
    void execute(QString command, QStringList args) override;
};

#endif // PLUGINTWO_H
