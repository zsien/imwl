#ifndef VIRTUALKEYBOARDMANAGERV1_H
#define VIRTUALKEYBOARDMANAGERV1_H

#include <QObject>

struct wl_client;
struct wl_display;
struct wl_resource;

class VirtualKeyboardManagerV1Private;
class VirtualKeyboardV1;

class VirtualKeyboardManagerV1 : public QObject
{
    Q_OBJECT

    friend class VirtualKeyboardManagerV1Private;

public:
    VirtualKeyboardManagerV1(QObject *parent);
    ~VirtualKeyboardManagerV1();

    void init(struct ::wl_client *client, uint32_t id);
    void init(struct ::wl_display *display);
    void init(struct ::wl_resource *resource);

private:
    std::unique_ptr<VirtualKeyboardManagerV1Private> d;
    std::unordered_map<struct ::wl_resource *, VirtualKeyboardV1 *> m_virtualKeyboards;
};

#endif // !VIRTUALKEYBOARDMANAGERV1_H
