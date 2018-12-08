#include <QCoreApplication>
#include <QThread>

#include "broadcastutil.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QThread thread;

  BroadcastUtil* bu = new BroadcastUtil();
  bu->moveToThread(&thread);

  QObject::connect(&thread, &QThread::started, bu, &BroadcastUtil::process);

  thread.start();

    return a.exec();
}
