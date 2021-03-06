/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ICONDATA_H
#define ICONDATA_H

#include <QDBusArgument>
/*!
 * \~chinese \class IconData
 * \~chinese \brief 描述Icon属性的数据结构
 */
class IconData
{
public:
    friend QDebug operator<<(QDebug arg, const IconData &data);
    friend QDBusArgument &operator<<(QDBusArgument &arg, const IconData &data);
    friend const QDBusArgument &operator>>(const QDBusArgument &arg, IconData &data);

public:
    int width;
    int height;
    int rowstride;
    bool alpha;
    int bit;
    int cannel;
    QByteArray array;
};

#endif // ICONDATA_H
