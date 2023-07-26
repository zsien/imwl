#include "InputMethodManagerV2.h"

#include "InputMethodV2.h"
#include "common.h"
#include "qwayland-server-input-method-unstable-v2.h"

class InputMethodManagerV2Private : public QtWaylandServer::zwp_input_method_manager_v2
{
public:
    InputMethodManagerV2Private(InputMethodManagerV2 *q)
        : q(q)
    {
    }

    ~InputMethodManagerV2Private() { }

protected:
    void zwp_input_method_manager_v2_get_input_method(Resource *resource,
                                                      struct ::wl_resource *seat,
                                                      uint32_t input_method) override
    {
        auto *im = new InputMethodV2(q);
        im->init(resource->client(), input_method);
        auto [iter, r] = q->m_inputmethods.emplace(seat, im);

        QObject::connect(im, &InputMethodV2::destroyed, q, [this, iter = iter]() {
            q->m_inputmethods.erase(iter);
        });
    }

    void zwp_input_method_manager_v2_destroy(Resource *resource) override { q->deleteLater(); }

private:
    InputMethodManagerV2 *q;
};

InputMethodManagerV2::InputMethodManagerV2(QObject *parent)
    : QObject(parent)
    , d(new InputMethodManagerV2Private(this))
{
}

InputMethodManagerV2::~InputMethodManagerV2() { }

INIT_FUNCS(InputMethodManagerV2)
