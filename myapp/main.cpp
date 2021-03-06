#include <QCoreApplication>

/*
 What
 QPluginLoader
 Description
 Extending a Qt application with plugins
 Why
 QLibrary sucks
 Example
 Exending a command line app
 Note there is a QGenericPlugin....but it Requires Qt += GUI
 We will make our own from scratch
 Make a C++ lib and modify it
 WE ARE DOING THIS THE HARD WAY to show that we don't need Qt GUI to make a simple plugin and a easy pattern
 Create and compile the plugins
 Copy them to the plugin directory
 */

#include "loader.h"

typedef QPair<QString, QStringList> commandAndArgs;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = a.applicationDirPath();
    path.append("/plugins");

    Loader loader;
    loader.loadPlugins(path);


    QList<commandAndArgs> caal;
    caal << commandAndArgs("cats", QStringList() << "meow");
    caal << commandAndArgs("giant eland", QStringList() << "pffff");

    for (const auto& caa : caal)
    {
        loader.execute(caa.first, caa.second);
    }

    return a.exec();
}
