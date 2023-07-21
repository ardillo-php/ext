PHP_ARG_ENABLE([ardillo],
    [whether to enable ardillo support],
    [AS_HELP_STRING([--enable-ardillo],
        [Enable ardillo support])],
    [no])

PHP_ARG_ENABLE(ardillo-debug, whether to enable debugging support in Ardillo,
[ --enable-ardillo-debug Enable debugging support in Ardillo], no, no)

PHP_ARG_ENABLE(ardillo-objects-debug, whether to enable object debugging support in Ardillo,
[ --enable-ardillo-objects-debug Enable object debugging support in Ardillo], no, no)

PHP_ARG_ENABLE(ardillo-reference-debug, whether to enable object reference debugging support in Ardillo,
[ --enable-ardillo-reference-debug Enable object reference debugging support in Ardillo], no, no)

if test "$PHP_ARDILLO_DEBUG" != "no"; then
    AC_DEFINE(CONFIG_ARDILLO_DEBUG, 1, [Include debugging support in Ardillo])

    CFLAGS="$CFLAGS -O0 -g"
fi

if test "$PHP_ARDILLO_OBJECTS_DEBUG" != "no"; then
    AC_DEFINE(CONFIG_ARDILLO_OBJECTS_DEBUG, 1, [Include object debugging support in Ardillo])
fi

if test "$PHP_ARDILLO_REFERENCE_DEBUG" != "no"; then
    AC_DEFINE(CONFIG_ARDILLO_REFERENCE_DEBUG, 1, [Include object reference debugging support in Ardillo])
fi

IS_OSX=`uname -a | grep Darwin`

if test "$IS_OSX" != ""; then
    ARDILLO_OSX="yes"
    PLATFORM="platform/darwin.c"
else
    ARDILLO_OSX="no"
    PLATFORM="platform/unix.c"
fi

if test "$PHP_ARDILLO" != "no"; then
    AC_DEFINE(HAVE_ARDILLO, 1, [ Have ardillo support ])

    if test ! -e "./libui-ng/ui.h"; then
        git submodule init
        git submodule update
    fi

    if test ! -e "./libui-ng/build/meson-out"; then
        cd ./libui-ng && meson setup --default-library=static build && ninja -C build && cd ..
    fi

    ARDILLO_CFLAGS="-I./libui-ng"
    UI_LIB="-L./libui-ng/build/meson-out -Wl,-Bstatic -lui"

    if test "$ARDILLO_OSX" == "no"; then
        UI_LIB="`pkg-config --cflags --libs gtk+-3.0` $UI_LIB"
        ARDILLO_CFLAGS="`pkg-config --cflags gtk+-3.0` $ARDILLO_CFLAGS"
    else
        LDFLAGS="-framework Foundation -framework AppKit -undefined dynamic_lookup $CFLAGS"
    fi

    PHP_EVAL_INCLINE($ARDILLO_CFLAGS)
    PHP_EVAL_LIBLINE($UI_LIB, ARDILLO_SHARED_LIBADD)
    PHP_SUBST(ARDILLO_SHARED_LIBADD)

    PHP_NEW_EXTENSION(ardillo, ardillo.c app/app.c app/menu.c app/task.c app/stream.c $PLATFORM ui/area_draw_params.c ui/area_handler.c ui/area_key_event.c ui/area_mouse_event.c ui/box.c ui/button.c ui/checkbox.c ui/color_button.c ui/combobox.c ui/control.c ui/date_time_picker.c ui/draw_brush.c ui/draw_brush_gradient_stop.c ui/draw_matrix.c ui/draw_stroke_params.c ui/draw_text_layout_params.c ui/editable_combobox.c ui/entry.c ui/font_button.c ui/font_descriptor.c ui/form.c ui/grid.c ui/group.c ui/image.c ui/label.c ui/multiline_entry.c ui/progress_bar.c ui/radio_buttons.c ui/separator.c ui/slider.c ui/spinbox.c ui/tab.c ui/table.c ui/table_model.c ui/table_model_handler.c ui/table_params.c ui/table_text_column_optional_params.c ui/table_value.c ui/window.c ui/area.c ui/draw_path.c ui/horizontal_box.c ui/vertical_box.c ui/date_picker.c ui/time_picker.c ui/password_entry.c ui/search_entry.c ui/non_wrapping_multiline_entry.c ui/horizontal_separator.c ui/vertical_separator.c ui/table_value_string.c ui/table_value_image.c ui/table_value_int.c ui/table_value_color.c ui/uix.c, $ext_shared)
fi
