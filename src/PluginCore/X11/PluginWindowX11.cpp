/**********************************************************\
Original Author: Richard Bateman (taxilian)

Created:    Nov 24, 2009
License:    Dual license model; choose one of two:
            Eclipse Public License - Version 1.0
            http://www.eclipse.org/legal/epl-v10.html
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2009 Richard Bateman, Firebreath development team
\**********************************************************/

// #include "PluginEvents/LinuxEvent.h"
#include "PluginEvents/GeneralEvents.h"
#include "PluginEvents/DrawingEvents.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginWindowLinux.h"

using namespace FB;

PluginWindowLinux::PluginWindowLinux(XWindow win)
{
    m_window = win;
}

PluginWindowLinux::~PluginWindowLinux()
{
}

void PluginWindowLinux::getWindowPosition(int &x, int &y, int &w, int &h)
{
    x = m_x;
    y = m_y;
    w = m_width;
    h = m_height;
}

void PluginWindowLinux::setWindowPosition(int x, int y, int w, int h)
{
    if (m_x != x
        || m_y != y
        || m_width != w
        || m_height != h) {
        m_x = x;
        m_y = y;
        m_width = w;
        m_height = h;
        SendEvent(&ResizedEvent());
    }
}

void PluginWindowLinux::getWindowClipping(int &t, int &l, int &b, int &r)
{
    t = m_clipTop;
    l = m_clipLeft;
    b = m_clipBottom;
    r = m_clipRight;
}

void PluginWindowLinux::setWindowClipping(int t, int l, int b, int r)
{
    if (m_clipTop != t
        || m_clipLeft != l
        || m_clipBottom != b
        || m_clipRight != r) {
        m_clipTop = t;
        m_clipLeft = l;
        m_clipBottom = b;
        m_clipRight = r;
        SendEvent(&ClipChangedEvent());
    }
}
//
// int16_t PluginWindowLinux::HandleEvent(EventRecord* evt)
// {
//     // Give the plugin a change to handle the event itself if desired
//     if (SendEvent(&MacEvent(evt))) {
//         return true;
//     }
//     switch (evt->what) {
//         case updateEvt:
//             return SendEvent(&RefreshEvent());
//             break;
//         default:
//             break;
//     }
//     return false;
// }
