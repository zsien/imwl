#include "InputMethodV2.h"

#include "common.h"
#include "qwayland-server-input-method-unstable-v2.h"

class InputMethodV2Private : public QtWaylandServer::zwp_input_method_v2
{
public:
    InputMethodV2Private(InputMethodV2 *q)
        : q(q)
    {
    }

    ~InputMethodV2Private() { }

protected:
    void zwp_input_method_v2_commit_string(Resource *resource, const QString &text) override { }

    void zwp_input_method_v2_set_preedit_string(Resource *resource,
                                                const QString &text,
                                                int32_t cursor_begin,
                                                int32_t cursor_end) override
    {
    }

    void zwp_input_method_v2_delete_surrounding_text(Resource *resource,
                                                     uint32_t before_length,
                                                     uint32_t after_length) override
    {
    }

    void zwp_input_method_v2_commit(Resource *resource, uint32_t serial) override { }

    void zwp_input_method_v2_get_input_popup_surface(Resource *resource,
                                                     uint32_t id,
                                                     struct ::wl_resource *surface) override
    {
    }

    void zwp_input_method_v2_grab_keyboard(Resource *resource, uint32_t keyboard) override { }

    void zwp_input_method_v2_destroy(Resource *resource) override { }

private:
    InputMethodV2 *q;
};

InputMethodV2::InputMethodV2(QObject *parent)
    : QObject(parent)
{
}

InputMethodV2::~InputMethodV2() { }

INIT_FUNCS(InputMethodV2)
