#include "InputMethodManagerV2.h"

#include "InputMethodV2.h"

#include <QtWaylandCompositor/QWaylandSeat>

void InputMethodManagerV2::zwp_input_method_manager_v2_get_input_method(Resource *resource,
                                                                        struct ::wl_resource *seat,
                                                                        uint32_t input_method)
{
    auto *im = new InputMethodV2(resource->client(), input_method, InputMethodV2::interface()->version);
    m_inputmethods.emplace(seat, im);
}

void InputMethodManagerV2::zwp_input_method_manager_v2_destroy(Resource *resource) { }
