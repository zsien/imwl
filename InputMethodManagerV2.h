#ifndef INPUTMETHODMANAGERV2_H
#define INPUTMETHODMANAGERV2_H

#include "qwayland-server-input-method-unstable-v2.h"

class InputMethodManagerV2 : public QtWaylandServer::zwp_input_method_manager_v2
{
public:
    using zwp_input_method_manager_v2::zwp_input_method_manager_v2;

protected:
    void zwp_input_method_manager_v2_get_input_method(Resource *resource,
                                                      struct ::wl_resource *seat,
                                                      uint32_t input_method) override;
    void zwp_input_method_manager_v2_destroy(Resource *resource) override;
};

#endif // !INPUTMETHODMANAGERV2_H
