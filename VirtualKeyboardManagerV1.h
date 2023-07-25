#ifndef VIRTUALKEYBOARDMANAGERV1_H
#define VIRTUALKEYBOARDMANAGERV1_H

#include "qwayland-server-virtual-keyboard-unstable-v1.h"

class VirtualKeyboardManagerV1 : public QtWaylandServer::zwp_virtual_keyboard_manager_v1
{
public:
    using zwp_virtual_keyboard_manager_v1::zwp_virtual_keyboard_manager_v1;

protected:
    void zwp_virtual_keyboard_manager_v1_create_virtual_keyboard(Resource *resource,
                                                                 struct ::wl_resource *seat,
                                                                 uint32_t id) override;
};

#endif // !VIRTUALKEYBOARDMANAGERV1_H
