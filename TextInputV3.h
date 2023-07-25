#ifndef TEXTINPUTV3_H
#define TEXTINPUTV3_H

#include "qwayland-server-text-input-unstable-v3.h"

#include <QObject>

class TextInputV3 : public QtWaylandServer::zwp_text_input_v3, public QObject
{
    Q_OBJECT

public:
    using zwp_text_input_v3::zwp_text_input_v3;

protected:
    void zwp_text_input_v3_destroy(Resource *resource) override;
    void zwp_text_input_v3_enable(Resource *resource) override;
    void zwp_text_input_v3_disable(Resource *resource) override;
    void zwp_text_input_v3_set_surrounding_text(Resource *resource,
                                                const QString &text,
                                                int32_t cursor,
                                                int32_t anchor) override;
    void zwp_text_input_v3_set_text_change_cause(Resource *resource, uint32_t cause) override;
    void zwp_text_input_v3_set_content_type(Resource *resource,
                                            uint32_t hint,
                                            uint32_t purpose) override;
    void zwp_text_input_v3_set_cursor_rectangle(
        Resource *resource, int32_t x, int32_t y, int32_t width, int32_t height) override;
    void zwp_text_input_v3_commit(Resource *resource) override;
};

#endif // !TEXTINPUTV3_H