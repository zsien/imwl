#ifndef INPUTMETHODV2_H
#define INPUTMETHODV2_H

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

    void init(struct ::wl_client *client, uint32_t id);
    void init(struct ::wl_display *display);
    void init(struct ::wl_resource *resource);

private:
    std::unique_ptr<InputMethodV2Private> d;
};

#endif // !INPUTMETHODV2_H
