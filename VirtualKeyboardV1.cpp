#include "VirtualKeyboardV1.h"

void VirtualKeyboardV1::zwp_virtual_keyboard_v1_keymap(Resource *resource,
                                                       uint32_t format,
                                                       int32_t fd,
                                                       uint32_t size)
{
}

void VirtualKeyboardV1::zwp_virtual_keyboard_v1_key(Resource *resource,
                                                    uint32_t time,
                                                    uint32_t key,
                                                    uint32_t state)
{
}

void VirtualKeyboardV1::zwp_virtual_keyboard_v1_modifiers(Resource *resource,
                                                          uint32_t mods_depressed,
                                                          uint32_t mods_latched,
                                                          uint32_t mods_locked,
                                                          uint32_t group)
{
}

void VirtualKeyboardV1::zwp_virtual_keyboard_v1_destroy(Resource *resource) { }
