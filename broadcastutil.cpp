#include <QtNetwork>
#include <QDebug>
#include <QByteArray>
#include <QString>

#include "broadcastutil.h"

const QString DISCOVERY_PROTOCOL_VERSION = "discovery_protocol_version=";
const QString MODEL = "model=";
const QString SERIAL = "serial=";
const QString VERSION = "version=";
const QString NICKNAME = "nickname=";
const QString CALLSIGN = "callsign=";
const QString IP = "ip=";
const QString PORT = "port=";
const QString STATUS = "status=";
const QString INUSE_IP = "inuse_ip=";
const QString INUSE_HOST = "inuse_host=";
const QString MAX_LICANSED_VERSION = "max_licensed_version=;";
const QString RADIO_LICANSE_ID = "radio_license_id=";
const QString REQUEST_ADDITIONAL_LICENSE = "requires_additional_license=";
const QString FPC_MAC = "fpc_mac=";
const QString WAN_CONNECTED = "wan_connected=";




BroadcastUtil::BroadcastUtil(QObject *parent) : QObject(parent)
{

}

void BroadcastUtil::process()
{
  QUdpSocket socket;
  QByteArray datagram;
  datagram.append((char)0x38);
  datagram.append((char)0x59);
  datagram.append((char)0x00);
  datagram.append((char)0x54);
  datagram.append((char)0x00);
  datagram.append((char)0x00);

  datagram.append((char)0x08);
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x1c);
  datagram.append((char)0x2d);
  datagram.append((char)0x53);
  datagram.append((char)0x4c);
  datagram.append((char)0xff);
  datagram.append((char)0xff);
  datagram.append((char)0x5b);
  datagram.append((char)0xfe);
  datagram.append((char)0xe9);
  datagram.append((char)0xe9);
  datagram.append((char)0x00);
  datagram.append((char)0x00);

  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);

  datagram.append(DISCOVERY_PROTOCOL_VERSION);
  datagram.append("2.0.0.3");
  datagram.append((char)0x20);

  datagram.append(MODEL);
  datagram.append("FLEX-6400");
  datagram.append((char)0x20);

  datagram.append(SERIAL);
  datagram.append("3918-0512-6400-6259");
  datagram.append((char)0x20);

  datagram.append(VERSION);
  datagram.append("2.4.9.115");
  datagram.append((char)0x20);

  datagram.append(NICKNAME);
  datagram.append("Nick");
  datagram.append((char)0x20);

  datagram.append(CALLSIGN);
  datagram.append("Rn3kk");
  datagram.append((char)0x20);

  datagram.append(IP);
  datagram.append("192.168.17.22");
  datagram.append((char)0x20);

  datagram.append(PORT);
  datagram.append("4992");
  datagram.append((char)0x20);

  datagram.append(STATUS);
  datagram.append("Available");
  datagram.append((char)0x20);

  datagram.append(INUSE_IP);
  datagram.append((char)0x20);

  datagram.append(INUSE_HOST);
  datagram.append((char)0x20);

  datagram.append(MAX_LICANSED_VERSION);
  datagram.append("v2");
  datagram.append((char)0x20);

  datagram.append(RADIO_LICANSE_ID);
  datagram.append("00-1C-2D-05-0B-06");
  datagram.append((char)0x20);

  datagram.append(REQUEST_ADDITIONAL_LICENSE);
  datagram.append("0");
  datagram.append((char)0x20);

  datagram.append(FPC_MAC);
  datagram.append((char)0x20);

  datagram.append(WAN_CONNECTED);
  datagram.append("0");
  datagram.append((char)0x20);

  //end zero
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);
  datagram.append((char)0x00);



  while(true)
  {
    qint64 num = socket.writeDatagram(datagram, QHostAddress::Broadcast, 4992);
    qDebug() << "Send " << num << " byte";
    thread()->msleep(1000);
  }
}
