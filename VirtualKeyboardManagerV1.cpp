#include "VirtualKeyboardManagerV1.h"

#include "VirtualKeyboardV1.h"

void VirtualKeyboardManagerV1::zwp_virtual_keyboard_manager_v1_create_virtual_keyboard(
    Resource *resource, struct ::wl_resource *seat, uint32_t id)
{
    new VirtualKeyboardV1(resource->client(), id, VirtualKeyboardV1::interface()->version);
}
