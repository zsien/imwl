#ifndef INPUTMETHODMANAGERV2_H
#define INPUTMETHODMANAGERV2_H

#include "common.h"

#include <QObject>

struct wl_client;
struct wl_display;
struct wl_resource;

class InputMethodV2;
class InputMethodManagerV2Private;

class InputMethodManagerV2 : public QObject
{
    Q_OBJECT

    friend class InputMethodManagerV2Private;

public:
    InputMethodManagerV2(QObject *parent);
    ~InputMethodManagerV2();

    INIT_FUNCS_DEF

private:
    std::unique_ptr<InputMethodManagerV2Private> d;
    std::unordered_map<struct ::wl_resource * /* seat */, InputMethodV2 *> m_inputmethods;
};

#endif // !INPUTMETHODMANAGERV2_H
