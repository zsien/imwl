#include "VirtualKeyboardV1.h"

#include "qwayland-server-virtual-keyboard-unstable-v1.h"

#include <QKeyEvent>
#include <QWaylandSeat>

class VirtualKeyboardV1Private : public QtWaylandServer::zwp_virtual_keyboard_v1
{
public:
    VirtualKeyboardV1Private(VirtualKeyboardV1 *q)
        : q(q)
    {
    }

    ~VirtualKeyboardV1Private() { }

protected:
    void zwp_virtual_keyboard_v1_keymap(Resource *resource,
                                        uint32_t format,
                                        int32_t fd,
                                        uint32_t size) override
    {
    }

    void zwp_virtual_keyboard_v1_key(Resource *resource,
                                     uint32_t time,
                                     uint32_t key,
                                     uint32_t state) override
    {
    }

    void zwp_virtual_keyboard_v1_modifiers(Resource *resource,
                                           uint32_t mods_depressed,
                                           uint32_t mods_latched,
                                           uint32_t mods_locked,
                                           uint32_t group) override
    {
    }

    void zwp_virtual_keyboard_v1_destroy(Resource *resource) override
    {
        wl_resource_destroy(resource->handle);
    }

private:
    VirtualKeyboardV1 *q;
};

VirtualKeyboardV1::VirtualKeyboardV1(struct ::wl_resource *seat, QObject *parent)
    : QObject(parent)
    , d(new VirtualKeyboardV1Private(this))
    , m_seat(QWaylandSeat::fromSeatResource(seat))
{
}

VirtualKeyboardV1::~VirtualKeyboardV1() { }

INIT_FUNCS(VirtualKeyboardV1)
