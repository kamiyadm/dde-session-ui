/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#include <QDebug>
#include <QGSettings>

#include "backgroundlabel.h"
#include "shutdownframe.h"

const QString WallpaperKey = "pictureUri";

ShutdownFrame::ShutdownFrame(QWidget *parent)
    : BoxFrame(parent),
      m_gsettings(new QGSettings("com.deepin.wrap.gnome.desktop.background",
                                 "/com/deepin/wrap/gnome/desktop/background/"))
{
    this->move(0, 0);
    this->setFixedSize(qApp->desktop()->size());

    qDebug() << "this geometry:" << geometry();

    initShutdownManager();
    initBackground();
}

void ShutdownFrame::updateScreenPosition() {
    m_shutdownManager->updateGeometry();
}

void ShutdownFrame::keyPressEvent(QKeyEvent *e) {
    Q_UNUSED(e);
}

void ShutdownFrame::initShutdownManager()
{
    m_shutdownManager = new ShutdownManager(this);
    QPoint mousePoint = QCursor::pos();

    QList<QScreen *> screenList = qApp->screens();
    for (int i = 0; i < screenList.length(); i++) {
        const QRect rect = screenList[i]->geometry();
        if (rect.contains(mousePoint)) {
            m_shutdownManager->setFixedSize(rect.size());
            m_shutdownManager->move(rect.x(), rect.y());
            qDebug() << "shutdownManager:" << m_shutdownManager->geometry();
            updateScreenPosition();
            continue;
        }
    }
}

void ShutdownFrame::initBackground()
{
//    const QString username = qgetenv("USER");
//    const QSettings settings("/var/lib/AccountsService/users/" + username, QSettings::IniFormat);
//    const QString background = settings.value("User/Background").toString();

//    qDebug() << "update background for user: " << username << " background: " << background;
//    setBackground(background);

    auto callback = [this] {
        const QString background = QUrl(m_gsettings->get(WallpaperKey).toString()).toLocalFile();
        setBackground(background);
    };

    callback();
    connect(m_gsettings, &QGSettings::changed, callback);
}

ShutdownFrame::~ShutdownFrame()
{
}

ShutdownFrontDBus::ShutdownFrontDBus(ShutdownFrame *parent):
    QDBusAbstractAdaptor(parent),
    m_parent(parent)
{
}

ShutdownFrontDBus::~ShutdownFrontDBus()
{
}

void ShutdownFrontDBus::Ping()
{
}

void ShutdownFrontDBus::Show()
{
    if (m_parent) {
        m_parent->show();
    }
}
