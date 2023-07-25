#include "InputMethodManagerV2.h"

#include "InputMethodV2.h"

void InputMethodManagerV2::zwp_input_method_manager_v2_get_input_method(Resource *resource,
                                                                      struct ::wl_resource *seat,
                                                                      uint32_t input_method)
{
    new InputMethodV2(resource->client(), input_method, InputMethodV2::interface()->version);
}

void InputMethodManagerV2::zwp_input_method_manager_v2_destroy(Resource *resource) { }
