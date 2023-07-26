#ifndef COMMON_H
#define COMMON_H

#define INIT_FUNCS(CLASSNAME)                                    \
  void CLASSNAME::init(struct ::wl_client *client, uint32_t id)  \
  {                                                              \
    d->init(client, id, CLASSNAME##Private::interfaceVersion()); \
  }                                                              \
                                                                 \
  void CLASSNAME::init(struct ::wl_display *display)             \
  {                                                              \
    d->init(display, CLASSNAME##Private::interfaceVersion());    \
  }                                                              \
                                                                 \
  void CLASSNAME::init(struct ::wl_resource *resource)           \
  {                                                              \
    d->init(resource);                                           \
  }

#endif // !COMMON_H
