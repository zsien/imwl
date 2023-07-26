#ifndef INPUTMETHODV2_H
#define INPUTMETHODV2_H

#include "common.h"

#include <QObject>

struct wl_client;
struct wl_display;
struct wl_resource;

class InputMethodV2Private;

class InputMethodV2 : public QObject
{
    Q_OBJECT

public:
    InputMethodV2(QObject *parent);
    ~InputMethodV2();

    INIT_FUNCS_DEF

private:
    std::unique_ptr<InputMethodV2Private> d;
};

#endif // !INPUTMETHODV2_H
