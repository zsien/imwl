#ifndef TEXTINPUTMANAGERV3_H
#define TEXTINPUTMANAGERV3_H

#include "qwayland-server-text-input-unstable-v3.h"

class TextInputManagerV3 : public QtWaylandServer::zwp_text_input_manager_v3
{
public:
    using zwp_text_input_manager_v3::zwp_text_input_manager_v3;

protected:
    void zwp_text_input_manager_v3_destroy(Resource *resource) override;
    void zwp_text_input_manager_v3_get_text_input(Resource *resource,
                                                  uint32_t id,
                                                  struct ::wl_resource *seat) override;
};

#endif // !TEXTINPUTMANAGERV3_H
