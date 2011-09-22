/****************************************************************************
 **
 ** Copyright (C) 2008-2011 Nokia Corporation and/or its subsidiary(-ies).
 ** Contact: Nokia Corporation (info@qt.nokia.com)
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

#include "stable.h"
#include "consolecolorrestorer.h"
#include <qt_windows.h>

namespace NMakeFile {

struct ConsoleColorRestorerPrivate
{
    HANDLE hStdOut;
    WORD wAttributes;
};

ConsoleColorRestorer::ConsoleColorRestorer()
:   d(new ConsoleColorRestorerPrivate)
{
    d->hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    if (d->hStdOut != INVALID_HANDLE_VALUE) {
        if (GetConsoleScreenBufferInfo(d->hStdOut, &csbiInfo))
            d->wAttributes = csbiInfo.wAttributes;
        else
            d->hStdOut = INVALID_HANDLE_VALUE;
    }
}

ConsoleColorRestorer::~ConsoleColorRestorer()
{
    delete d;
}

void ConsoleColorRestorer::restore()
{
    if (d->hStdOut == INVALID_HANDLE_VALUE)
        return;

    SetConsoleTextAttribute(d->hStdOut, d->wAttributes);
}

} // namespace NMakeFile