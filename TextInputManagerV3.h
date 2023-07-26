#ifndef TEXTINPUTMANAGERV3_H
#define TEXTINPUTMANAGERV3_H

#include "common.h"

#include <QObject>

struct wl_client;
struct wl_display;
struct wl_resource;

class TextInputManagerV3Private;
class TextInputV3;

class TextInputManagerV3 : public QObject
{
    Q_OBJECT

    friend class TextInputManagerV3Private;

public:
    TextInputManagerV3(QObject *parent);
    ~TextInputManagerV3();

    INIT_FUNCS_DEF

private:
    std::unique_ptr<TextInputManagerV3Private> d;
    std::unordered_map<struct ::wl_resource * /* seat */, TextInputV3 *> m_textInputs;
};

#endif // !TEXTINPUTMANAGERV3_H
