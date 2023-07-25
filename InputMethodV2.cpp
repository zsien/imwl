#include "InputMethodV2.h"

void InputMethodV2::zwp_input_method_v2_commit_string(Resource *resource, const QString &text) { }

void InputMethodV2::zwp_input_method_v2_set_preedit_string(Resource *resource,
                                                         const QString &text,
                                                         int32_t cursor_begin,
                                                         int32_t cursor_end)
{
}

void InputMethodV2::zwp_input_method_v2_delete_surrounding_text(Resource *resource,
                                                              uint32_t before_length,
                                                              uint32_t after_length)
{
}

void InputMethodV2::zwp_input_method_v2_commit(Resource *resource, uint32_t serial) { }

void InputMethodV2::zwp_input_method_v2_get_input_popup_surface(Resource *resource,
                                                              uint32_t id,
                                                              struct ::wl_resource *surface)
{
}

void InputMethodV2::zwp_input_method_v2_grab_keyboard(Resource *resource, uint32_t keyboard) { }

void InputMethodV2::zwp_input_method_v2_destroy(Resource *resource) {
}
