#include "TextInputManagerV3.h"

#include "TextInputV3.h"
#include "common.h"
#include "qwayland-server-text-input-unstable-v3.h"

#include <QtWaylandCompositor/QWaylandSeat>

class TextInputManagerV3Private : public QtWaylandServer::zwp_text_input_manager_v3
{
public:
    TextInputManagerV3Private(TextInputManagerV3 *q)
        : q(q)
    {
    }

protected:
    void zwp_text_input_manager_v3_destroy(Resource *resource) override { }

    void zwp_text_input_manager_v3_get_text_input(Resource *resource,
                                                  uint32_t id,
                                                  struct ::wl_resource *seat) override
    {
        auto *ti = new TextInputV3(q);
        ti->init(resource->client(), id);
        auto [iter, r] = q->m_textInputs.emplace(seat, ti);

        QObject::connect(q, &TextInputV3::destroyed, q, [this, iter = iter]() {
            q->m_textInputs.erase(iter);
        });
    }

private:
    TextInputManagerV3 *q;
};

TextInputManagerV3::TextInputManagerV3(QObject *parent)
    : QObject(parent)
    , d(new TextInputManagerV3Private(this))
{
}

TextInputManagerV3::~TextInputManagerV3() { }

INIT_FUNCS(TextInputManagerV3)
