#ifndef TEXTINPUTMANAGERV3_H
#define TEXTINPUTMANAGERV3_H

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

    void init(struct ::wl_client *client, uint32_t id);
    void init(struct ::wl_display *display);
    void init(struct ::wl_resource *resource);

private:
    std::unique_ptr<TextInputManagerV3Private> d;
    std::unordered_map<struct ::wl_resource *, TextInputV3 *> m_textInputs;
};

#endif // !TEXTINPUTMANAGERV3_H
