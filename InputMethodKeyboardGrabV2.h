#ifndef INPUTMETHODKEYBOARDGRABV2_H
#define INPUTMETHODKEYBOARDGRABV2_H

#include "common.h"

#include <xcb/xcb.h>

#include <QObject>
#include <QSocketNotifier>

struct wl_client;
struct wl_display;
struct wl_resource;

template<auto Func>
class Deleter
{
public:
    template<typename T>
    void operator()(T *ptr) const
    {
        if (ptr) {
            Func(ptr);
        }
    }
};

class InputMethodKeyboardGrabV2Private;

class InputMethodKeyboardGrabV2 : public QObject
{
    Q_OBJECT

    friend class InputMethodKeyboardGrabV2Private;

public:
    InputMethodKeyboardGrabV2(QObject *parent);
    ~InputMethodKeyboardGrabV2();

    INIT_FUNCS_DEF

private:
    std::unique_ptr<InputMethodKeyboardGrabV2Private> d;

    std::unique_ptr<xcb_connection_t, Deleter<xcb_disconnect>> m_xconn;
    int m_xcbFd;
    QSocketNotifier *m_socketNotifier;
    const xcb_setup_t *m_setup;
    xcb_screen_t *m_screen;
    uint8_t m_xinput2OPCode;

    xcb_screen_t *screenOfDisplay(int screen);
    void onXCBEvent(QSocketDescriptor socket, QSocketNotifier::Type activationEvent);
    void initXinputExtension();
};

#endif // !INPUTMETHODKEYBOARDGRABV2_H
