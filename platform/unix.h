#ifndef __ARDILLO_PLATFORM_UNIX_H
#define __ARDILLO_PLATFORM_UNIX_H

#include <gtk/gtk.h>
#include "app/stream.h"

gboolean ardillo_unix_on_stream_event(GIOChannel *channel, GIOCondition condition, gpointer data);

#endif /* __ARDILLO_PLATFORM_UNIX_H */
