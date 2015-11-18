/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.deepin.daemon.Audio.Sink2.xml -c VolumeDbus -p volumedbus
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef VOLUMEDBUS_H_1446626207
#define VOLUMEDBUS_H_1446626207

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.daemon.Audio.Sink
 */
class VolumeDbus: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.daemon.Audio.Sink")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        foreach(const QString &prop, changedProps.keys()) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
 	            Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.Audio.Sink"; }

public:
    VolumeDbus(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~VolumeDbus();

    Q_PROPERTY(double Volume READ volume NOTIFY VolumeChanged)
    inline double volume() const
    { return qvariant_cast< double >(property("Volume")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
// begin property changed signals
void VolumeChanged();
};

namespace com {
  namespace deepin {
    namespace daemon {
      namespace Audio {
        typedef ::VolumeDbus Sink;
      }
    }
  }
}
#endif