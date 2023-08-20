#ifndef __ARDILLO_UTIL_DEBUG_H
#define __ARDILLO_UTIL_DEBUG_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "stdlib.h"
#include "php.h"

#define ARDILLO_STRINGIFY(x) ARDILLO_STRINGIFY_1(x)
#define ARDILLO_STRINGIFY_1(x) #x

#define ARDILLO_TERM_ANSI_ESC 0x1b
#define ARDILLO_TERM_ANSI_CSI '['

#define ARDILLO_TERM_ANSI_ESC_CSI "\x1b["

#define ARDILLO_TERM_ANSI_RESET   ARDILLO_TERM_ANSI_ESC_CSI "0m"
#define ARDILLO_TERM_ANSI_BOLD    ARDILLO_TERM_ANSI_ESC_CSI "1m"

#define ARDILLO_TERM_ANSI_BLACK   ARDILLO_TERM_ANSI_ESC_CSI "30m"
#define ARDILLO_TERM_ANSI_RED     ARDILLO_TERM_ANSI_ESC_CSI "31m"
#define ARDILLO_TERM_ANSI_GREEN   ARDILLO_TERM_ANSI_ESC_CSI "32m"
#define ARDILLO_TERM_ANSI_YELLOW  ARDILLO_TERM_ANSI_ESC_CSI "33m"
#define ARDILLO_TERM_ANSI_BLUE    ARDILLO_TERM_ANSI_ESC_CSI "34m"
#define ARDILLO_TERM_ANSI_MAGENTA ARDILLO_TERM_ANSI_ESC_CSI "35m"
#define ARDILLO_TERM_ANSI_CYAN    ARDILLO_TERM_ANSI_ESC_CSI "36m"
#define ARDILLO_TERM_ANSI_WHITE   ARDILLO_TERM_ANSI_ESC_CSI "37m"

#define ARDILLO_TERM_ANSI_BRIGHT_BLACK   ARDILLO_TERM_ANSI_ESC_CSI "30;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_RED     ARDILLO_TERM_ANSI_ESC_CSI "31;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_GREEN   ARDILLO_TERM_ANSI_ESC_CSI "32;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_YELLOW  ARDILLO_TERM_ANSI_ESC_CSI "33;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_BLUE    ARDILLO_TERM_ANSI_ESC_CSI "34;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_MAGENTA ARDILLO_TERM_ANSI_ESC_CSI "35;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_CYAN    ARDILLO_TERM_ANSI_ESC_CSI "36;1m"
#define ARDILLO_TERM_ANSI_BRIGHT_WHITE   ARDILLO_TERM_ANSI_ESC_CSI "37;1m"

#if __unix__
#if defined(CONFIG_ARDILLO_DEBUG) && CONFIG_ARDILLO_DEBUG
    #define ardillo_debug(...) \
    { \
        fprintf(stderr, __FILE__ ":" ARDILLO_STRINGIFY(__LINE__) " "); \
        fprintf(stderr, __VA_ARGS__); \
    }
#else
    #define ardillo_debug(...)
#endif

#if defined(CONFIG_DEBUG_ASSERTIONS) && CONFIG_DEBUG_ASSERTIONS
    #define ardillo_assert(x) \
    { \
        if (!(x)) { \
            fprintf(stderr, "Assertion failed @" __FILE__ ":" ARDILLO_STRINGIFY(__LINE__) "\n"); \
            exit(1); \
        } \
    }
#else
    #define ardillo_assert(x)
#endif

#define ardillo_component_debug(x, y, ...) \
{ \
    fprintf(stderr, x "" y "@" __FILE__ ":" ARDILLO_STRINGIFY(__LINE__) "> "); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, ARDILLO_TERM_ANSI_RESET); \
}

#ifdef CONFIG_ARDILLO_OBJECTS_DEBUG
    #define ardillo_debug_objects(x, ...) if (x <= CONFIG_ARDILLO_OBJECTS_DEBUG) { ardillo_component_debug(ARDILLO_TERM_ANSI_BRIGHT_MAGENTA, " objects", __VA_ARGS__); }
#else
    #define ardillo_debug_objects(x, ...)
#endif

#ifdef CONFIG_ARDILLO_REFERENCE_DEBUG
    #define ardillo_debug_references(x, ...) if (x <= CONFIG_ARDILLO_REFERENCE_DEBUG) { ardillo_component_debug(ARDILLO_TERM_ANSI_BRIGHT_CYAN, " objrefs", __VA_ARGS__); }
#else
    #define ardillo_debug_references(x, ...)
#endif
#else
    #define ardillo_debug(...)
    #define ardillo_assert(x)
    #define ardillo_debug_objects(x, ...)
    #define ardillo_debug_references(x, ...)
#endif

#endif /* __ARDILLO_UTIL_DEBUG_H */
