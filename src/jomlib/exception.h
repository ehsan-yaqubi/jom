/****************************************************************************
 **
 ** Copyright (C) 2008-2010 Nokia Corporation and/or its subsidiary(-ies).
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the jom project on Trolltech Labs.
 **
 ** This file may be used under the terms of the GNU General Public
 ** License version 2.0 or 3.0 as published by the Free Software Foundation
 ** and appearing in the file LICENSE.GPL included in the packaging of
 ** this file.  Please review the following information to ensure GNU
 ** General Public Licensing requirements will be met:
 ** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
 ** http://www.gnu.org/copyleft/gpl.html.
 **
 ** If you are unsure which license is appropriate for your use, please
 ** contact the sales department at qt-sales@nokia.com.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/
#pragma once

#include <QString>

namespace NMakeFile {

class Exception
{
public:
    explicit Exception(const QString& message = QString());

    const QString& message() const { return m_message; }
    virtual const QString toString() const;

protected:
    QString m_message;
};

class FileException : public Exception
{
public:
    explicit FileException(const QString& message = QString(), const QString& fileName = QString(), int line = 0);

    const QString& fileName() const { return m_fileName; }
    int line() const { return m_line; }
    const QString toString() const;

protected:
    QString m_fileName;
    int     m_line;
};

} // namespace NMakeFile