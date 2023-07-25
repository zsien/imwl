#include "TextInputManagerV3.h"

#include "TextInputV3.h"

#include <QtWaylandCompositor/QWaylandSeat>

void TextInputManagerV3::zwp_text_input_manager_v3_destroy(Resource *resource) { }

void TextInputManagerV3::zwp_text_input_manager_v3_get_text_input(Resource *resource,
                                                                  uint32_t id,
                                                                  struct ::wl_resource *seat)
{
    new TextInputV3(resource->client(), TextInputV3::interface()->version, id);
}
