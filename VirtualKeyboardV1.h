#ifndef VIRTUALKEYBOARDV1_H
#define VIRTUALKEYBOARDV1_H

#include <QObject>

struct wl_client;
struct wl_display;
struct wl_resource;

class VirtualKeyboardV1Private;

class VirtualKeyboardV1 : public QObject
{
    Q_OBJECT

public:
    VirtualKeyboardV1(QObject *paernt);
    ~VirtualKeyboardV1();

    void init(struct ::wl_client *client, uint32_t id);
    void init(struct ::wl_display *display);
    void init(struct ::wl_resource *resource);

private:
    std::unique_ptr<VirtualKeyboardV1Private> d;
};

#endif // !VIRTUALKEYBOARDV1_H
