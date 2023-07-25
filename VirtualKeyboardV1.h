#ifndef VIRTUALKEYBOARDV1_H
#define VIRTUALKEYBOARDV1_H

#include "qwayland-server-virtual-keyboard-unstable-v1.h"

class VirtualKeyboardV1 : public QtWaylandServer::zwp_virtual_keyboard_v1
{
public:
    using zwp_virtual_keyboard_v1::zwp_virtual_keyboard_v1;

protected:
    void zwp_virtual_keyboard_v1_keymap(Resource *resource, uint32_t format, int32_t fd, uint32_t size) override;
    void zwp_virtual_keyboard_v1_key(Resource *resource, uint32_t time, uint32_t key, uint32_t state) override;
    void zwp_virtual_keyboard_v1_modifiers(Resource *resource, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group) override;
    void zwp_virtual_keyboard_v1_destroy(Resource *resource) override;
};

#endif // !VIRTUALKEYBOARDV1_H
