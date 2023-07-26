#include "TextInputV3.h"

#include "qwayland-server-text-input-unstable-v3.h"

#include <set>

class TextInputV3Private : public QtWaylandServer::zwp_text_input_v3
{
public:
    TextInputV3Private(TextInputV3 *q)
        : q(q)
    {
    }

    ~TextInputV3Private() { }

protected:
    void zwp_text_input_v3_destroy(Resource *resource) override
    {
        m_enabled.erase(resource);
        wl_resource_destroy(resource->handle);
    }

    void zwp_text_input_v3_enable(Resource *resource) override { m_enabled.emplace(resource); }

    void zwp_text_input_v3_disable(Resource *resource) override { m_enabled.erase(resource); }

    void zwp_text_input_v3_set_surrounding_text(Resource *resource,
                                                const QString &text,
                                                int32_t cursor,
                                                int32_t anchor) override
    {
    }

    void zwp_text_input_v3_set_text_change_cause(Resource *resource, uint32_t cause) override { }

    void zwp_text_input_v3_set_content_type(Resource *resource,
                                            uint32_t hint,
                                            uint32_t purpose) override
    {
    }

    void zwp_text_input_v3_set_cursor_rectangle(
        Resource *resource, int32_t x, int32_t y, int32_t width, int32_t height) override
    {
    }

    void zwp_text_input_v3_commit(Resource *resource) override { }

private:
    TextInputV3 *q;
    std::set<Resource *> m_enabled;
};

TextInputV3::TextInputV3(QObject *parent)
    : QObject(parent)
    , d(new TextInputV3Private(this))
{
}

TextInputV3::~TextInputV3() { }

INIT_FUNCS(TextInputV3)
