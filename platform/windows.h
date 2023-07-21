#ifndef __ARDILLO_PLATFORM_WINDOWS_H
#define __ARDILLO_PLATFORM_WINDOWS_H

#include "platform/wepoll.h"

#define ARDILLO_MAX_IO_EVENTS 8
#define ARDILLO_EPOLL_FLAGS (EPOLLRDHUP | EPOLLPRI | EPOLLERR | EPOLLHUP)

#endif /* __ARDILLO_PLATFORM_WINDOWS_H */
