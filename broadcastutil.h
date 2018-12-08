#ifndef BROADCASTUTIL_H
#define BROADCASTUTIL_H

#include <QObject>

class BroadcastUtil : public QObject
{
  Q_OBJECT
public:
  explicit BroadcastUtil(QObject *parent = nullptr);

signals:

public slots:
  void process();
};

#endif // BROADCASTUTIL_H
