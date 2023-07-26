#ifndef TEXTINPUTV3_H
#define TEXTINPUTV3_H

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

    void init(struct ::wl_client *client, uint32_t id);
    void init(struct ::wl_display *display);
    void init(struct ::wl_resource *resource);

private:
    std::unique_ptr<TextInputV3Private> d;
};

#endif // !TEXTINPUTV3_H
