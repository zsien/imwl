#include "TextInputV3.h"

void TextInputV3::zwp_text_input_v3_destroy(Resource *resource) { }

void TextInputV3::zwp_text_input_v3_enable(Resource *resource) { }

void TextInputV3::zwp_text_input_v3_disable(Resource *resource) { }

void TextInputV3::zwp_text_input_v3_set_surrounding_text(Resource *resource,
                                                         const QString &text,
                                                         int32_t cursor,
                                                         int32_t anchor)
{
}

void TextInputV3::zwp_text_input_v3_set_text_change_cause(Resource *resource, uint32_t cause) { }

void TextInputV3::zwp_text_input_v3_set_content_type(Resource *resource,
                                                     uint32_t hint,
                                                     uint32_t purpose)
{
}

void TextInputV3::zwp_text_input_v3_set_cursor_rectangle(
    Resource *resource, int32_t x, int32_t y, int32_t width, int32_t height)
{
}

void TextInputV3::zwp_text_input_v3_commit(Resource *resource) { }
