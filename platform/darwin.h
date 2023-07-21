#ifndef __ARDILLO_PLATFORM_DARWIN_H
#define __ARDILLO_PLATFORM_DARWIN_H

void ardillo_darwin_on_stream_event(CFSocketRef sock, CFSocketCallBackType type, CFDataRef addr, void const *data, void *ctx);

#endif /* __ARDILLO_PLATFORM_DARWIN_H */
