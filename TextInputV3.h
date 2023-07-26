#ifndef TEXTINPUTV3_H
#define TEXTINPUTV3_H

#include "common.h"

#include <QObject>

struct wl_client;
struct wl_display;
struct wl_resource;

class TextInputV3Private;

class TextInputV3 : public QObject
{
    Q_OBJECT

public:
    TextInputV3(QObject *parent);
    ~TextInputV3();

    INIT_FUNCS_DEF

private:
    std::unique_ptr<TextInputV3Private> d;
};

#endif // !TEXTINPUTV3_H
