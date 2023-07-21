/* ardillo extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_ardillo.h"
#include "ardillo_arginfo.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "app/menu.h"
#include "app/task.h"
#include "app/stream.h"
#include "util/common.h"
#include "util/debug.h"

zend_class_entry *ce_Ardillo_Align;
zend_class_entry *ce_Ardillo_At;
zend_class_entry *ce_Ardillo_DrawFillMode;
zend_class_entry *ce_Ardillo_ExtKey;
zend_class_entry *ce_Ardillo_Modifiers;
zend_class_entry *ce_Ardillo_DrawBrushType;
zend_class_entry *ce_Ardillo_DrawLineCap;
zend_class_entry *ce_Ardillo_DrawLineJoin;
zend_class_entry *ce_Ardillo_DrawTextAlign;
zend_class_entry *ce_Ardillo_SortIndicator;
zend_class_entry *ce_Ardillo_TableSelectionMode;
zend_class_entry *ce_Ardillo_TableModelColumn;
zend_class_entry *ce_Ardillo_TableValueType;
zend_class_entry *ce_Ardillo_TextItalic;
zend_class_entry *ce_Ardillo_TextStretch;
zend_class_entry *ce_Ardillo_TextWeight;

zend_class_entry *ce_Ardillo_Color;
zend_class_entry *ce_Ardillo_Point;
zend_class_entry *ce_Ardillo_Size;

zend_class_entry *ce_Ardillo_Area;
zend_class_entry *ce_Ardillo_Control;

zend_class_entry *ce_Ardillo_AreaDrawParams;
zend_class_entry *ce_Ardillo_AreaHandler;
zend_class_entry *ce_Ardillo_AreaKeyEvent;
zend_class_entry *ce_Ardillo_AreaMouseEvent;
zend_class_entry *ce_Ardillo_Box;
zend_class_entry *ce_Ardillo_Button;
zend_class_entry *ce_Ardillo_Checkbox;
zend_class_entry *ce_Ardillo_ColorButton;
zend_class_entry *ce_Ardillo_Combobox;
zend_class_entry *ce_Ardillo_DateTimePicker;
zend_class_entry *ce_Ardillo_DrawBrush;
zend_class_entry *ce_Ardillo_DrawBrushGradientStop;
zend_class_entry *ce_Ardillo_DrawMatrix;
zend_class_entry *ce_Ardillo_DrawStrokeParams;
zend_class_entry *ce_Ardillo_DrawTextLayoutParams;
zend_class_entry *ce_Ardillo_EditableCombobox;
zend_class_entry *ce_Ardillo_Entry;
zend_class_entry *ce_Ardillo_FontButton;
zend_class_entry *ce_Ardillo_FontDescriptor;
zend_class_entry *ce_Ardillo_Form;
zend_class_entry *ce_Ardillo_Grid;
zend_class_entry *ce_Ardillo_Group;
zend_class_entry *ce_Ardillo_Image;
zend_class_entry *ce_Ardillo_Label;
zend_class_entry *ce_Ardillo_MultilineEntry;
zend_class_entry *ce_Ardillo_ProgressBar;
zend_class_entry *ce_Ardillo_RadioButtons;
zend_class_entry *ce_Ardillo_Separator;
zend_class_entry *ce_Ardillo_Slider;
zend_class_entry *ce_Ardillo_Spinbox;
zend_class_entry *ce_Ardillo_Tab;
zend_class_entry *ce_Ardillo_Table;
zend_class_entry *ce_Ardillo_TableModel;
zend_class_entry *ce_Ardillo_TableModelHandler;
zend_class_entry *ce_Ardillo_TableParams;
zend_class_entry *ce_Ardillo_TableTextColumnOptionalParams;
zend_class_entry *ce_Ardillo_TableValue;
zend_class_entry *ce_Ardillo_Window;
zend_class_entry *ce_Ardillo_Area;
zend_class_entry *ce_Ardillo_DrawPath;
zend_class_entry *ce_Ardillo_HorizontalBox;
zend_class_entry *ce_Ardillo_VerticalBox;
zend_class_entry *ce_Ardillo_DatePicker;
zend_class_entry *ce_Ardillo_TimePicker;
zend_class_entry *ce_Ardillo_PasswordEntry;
zend_class_entry *ce_Ardillo_SearchEntry;
zend_class_entry *ce_Ardillo_NonWrappingMultilineEntry;
zend_class_entry *ce_Ardillo_HorizontalSeparator;
zend_class_entry *ce_Ardillo_VerticalSeparator;
zend_class_entry *ce_Ardillo_TableValueString;
zend_class_entry *ce_Ardillo_TableValueImage;
zend_class_entry *ce_Ardillo_TableValueInt;
zend_class_entry *ce_Ardillo_TableValueColor;

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif

PHP_MINIT_FUNCTION(ardillo)
{
    uiInitOptions o = {0};

    ardillo_debug("MINIT: About to run uiInit()\n");
    const char *err = uiInit(&o);
    ardillo_debug("MINIT: Done running uiInit()\n");

    if (err) {
        zend_error(E_CORE_ERROR, "Cannot initialize libui: %s", err);

        return FAILURE;
    }

    PHP_MINIT(Ardillo_App)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(Ardillo_Menu)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(Ardillo_Task)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(Ardillo_StreamEventHandler)(INIT_FUNC_ARGS_PASSTHRU);

    ce_Ardillo_Align = register_class_Ardillo_Align();
    ce_Ardillo_At = register_class_Ardillo_At();
    ce_Ardillo_DrawFillMode = register_class_Ardillo_DrawFillMode();
    ce_Ardillo_ExtKey = register_class_Ardillo_ExtKey();
    ce_Ardillo_Modifiers = register_class_Ardillo_Modifiers();
    ce_Ardillo_DrawBrushType = register_class_Ardillo_DrawBrushType();
    ce_Ardillo_DrawLineCap = register_class_Ardillo_DrawLineCap();
    ce_Ardillo_DrawLineJoin = register_class_Ardillo_DrawLineJoin();
    ce_Ardillo_DrawTextAlign = register_class_Ardillo_DrawTextAlign();
    ce_Ardillo_SortIndicator = register_class_Ardillo_SortIndicator();
    ce_Ardillo_TableSelectionMode = register_class_Ardillo_TableSelectionMode();
    ce_Ardillo_TableModelColumn = register_class_Ardillo_TableModelColumn();
    ce_Ardillo_TableValueType = register_class_Ardillo_TableValueType();
    ce_Ardillo_TextItalic = register_class_Ardillo_TextItalic();
    ce_Ardillo_TextStretch = register_class_Ardillo_TextStretch();
    ce_Ardillo_TextWeight = register_class_Ardillo_TextWeight();

    ce_Ardillo_Color = register_class_Ardillo_Color();
    ce_Ardillo_Point = register_class_Ardillo_Point();
    ce_Ardillo_Size = register_class_Ardillo_Size();

    ce_Ardillo_Control = register_class_Ardillo_Control();
    ce_Ardillo_Control->create_object = ardillo_create_Control_object;
    ce_Ardillo_AreaDrawParams = register_class_Ardillo_AreaDrawParams();
    ce_Ardillo_AreaDrawParams->create_object = ardillo_create_AreaDrawParams_object;
    ce_Ardillo_AreaHandler = register_class_Ardillo_AreaHandler();
    ce_Ardillo_AreaHandler->create_object = ardillo_create_AreaHandler_object;
    ce_Ardillo_AreaKeyEvent = register_class_Ardillo_AreaKeyEvent();
    ce_Ardillo_AreaKeyEvent->create_object = ardillo_create_AreaKeyEvent_object;
    ce_Ardillo_AreaMouseEvent = register_class_Ardillo_AreaMouseEvent();
    ce_Ardillo_AreaMouseEvent->create_object = ardillo_create_AreaMouseEvent_object;
    ce_Ardillo_Box = register_class_Ardillo_Box(ce_Ardillo_Control);
    ce_Ardillo_Box->create_object = ardillo_create_Box_object;
    ce_Ardillo_Button = register_class_Ardillo_Button(ce_Ardillo_Control);
    ce_Ardillo_Button->create_object = ardillo_create_Button_object;
    ce_Ardillo_Checkbox = register_class_Ardillo_Checkbox(ce_Ardillo_Control);
    ce_Ardillo_Checkbox->create_object = ardillo_create_Checkbox_object;
    ce_Ardillo_ColorButton = register_class_Ardillo_ColorButton(ce_Ardillo_Control);
    ce_Ardillo_ColorButton->create_object = ardillo_create_ColorButton_object;
    ce_Ardillo_Combobox = register_class_Ardillo_Combobox(ce_Ardillo_Control);
    ce_Ardillo_Combobox->create_object = ardillo_create_Combobox_object;
    ce_Ardillo_DateTimePicker = register_class_Ardillo_DateTimePicker(ce_Ardillo_Control);
    ce_Ardillo_DateTimePicker->create_object = ardillo_create_DateTimePicker_object;
    ce_Ardillo_DrawBrush = register_class_Ardillo_DrawBrush();
    ce_Ardillo_DrawBrush->create_object = ardillo_create_DrawBrush_object;
    ce_Ardillo_DrawBrushGradientStop = register_class_Ardillo_DrawBrushGradientStop();
    ce_Ardillo_DrawBrushGradientStop->create_object = ardillo_create_DrawBrushGradientStop_object;
    ce_Ardillo_DrawMatrix = register_class_Ardillo_DrawMatrix();
    ce_Ardillo_DrawMatrix->create_object = ardillo_create_DrawMatrix_object;
    ce_Ardillo_DrawStrokeParams = register_class_Ardillo_DrawStrokeParams();
    ce_Ardillo_DrawStrokeParams->create_object = ardillo_create_DrawStrokeParams_object;
    ce_Ardillo_DrawTextLayoutParams = register_class_Ardillo_DrawTextLayoutParams();
    ce_Ardillo_DrawTextLayoutParams->create_object = ardillo_create_DrawTextLayoutParams_object;
    ce_Ardillo_EditableCombobox = register_class_Ardillo_EditableCombobox(ce_Ardillo_Control);
    ce_Ardillo_EditableCombobox->create_object = ardillo_create_EditableCombobox_object;
    ce_Ardillo_Entry = register_class_Ardillo_Entry(ce_Ardillo_Control);
    ce_Ardillo_Entry->create_object = ardillo_create_Entry_object;
    ce_Ardillo_FontButton = register_class_Ardillo_FontButton(ce_Ardillo_Control);
    ce_Ardillo_FontButton->create_object = ardillo_create_FontButton_object;
    ce_Ardillo_FontDescriptor = register_class_Ardillo_FontDescriptor();
    ce_Ardillo_FontDescriptor->create_object = ardillo_create_FontDescriptor_object;
    ce_Ardillo_Form = register_class_Ardillo_Form(ce_Ardillo_Control);
    ce_Ardillo_Form->create_object = ardillo_create_Form_object;
    ce_Ardillo_Grid = register_class_Ardillo_Grid(ce_Ardillo_Control);
    ce_Ardillo_Grid->create_object = ardillo_create_Grid_object;
    ce_Ardillo_Group = register_class_Ardillo_Group(ce_Ardillo_Control);
    ce_Ardillo_Group->create_object = ardillo_create_Group_object;
    ce_Ardillo_Image = register_class_Ardillo_Image();
    ce_Ardillo_Image->create_object = ardillo_create_Image_object;
    ce_Ardillo_Label = register_class_Ardillo_Label(ce_Ardillo_Control);
    ce_Ardillo_Label->create_object = ardillo_create_Label_object;
    ce_Ardillo_MultilineEntry = register_class_Ardillo_MultilineEntry(ce_Ardillo_Control);
    ce_Ardillo_MultilineEntry->create_object = ardillo_create_MultilineEntry_object;
    ce_Ardillo_ProgressBar = register_class_Ardillo_ProgressBar(ce_Ardillo_Control);
    ce_Ardillo_ProgressBar->create_object = ardillo_create_ProgressBar_object;
    ce_Ardillo_RadioButtons = register_class_Ardillo_RadioButtons(ce_Ardillo_Control);
    ce_Ardillo_RadioButtons->create_object = ardillo_create_RadioButtons_object;
    ce_Ardillo_Separator = register_class_Ardillo_Separator(ce_Ardillo_Control);
    ce_Ardillo_Separator->create_object = ardillo_create_Separator_object;
    ce_Ardillo_Slider = register_class_Ardillo_Slider(ce_Ardillo_Control);
    ce_Ardillo_Slider->create_object = ardillo_create_Slider_object;
    ce_Ardillo_Spinbox = register_class_Ardillo_Spinbox(ce_Ardillo_Control);
    ce_Ardillo_Spinbox->create_object = ardillo_create_Spinbox_object;
    ce_Ardillo_Tab = register_class_Ardillo_Tab(ce_Ardillo_Control);
    ce_Ardillo_Tab->create_object = ardillo_create_Tab_object;
    ce_Ardillo_Table = register_class_Ardillo_Table(ce_Ardillo_Control);
    ce_Ardillo_Table->create_object = ardillo_create_Table_object;
    ce_Ardillo_TableModel = register_class_Ardillo_TableModel();
    ce_Ardillo_TableModel->create_object = ardillo_create_TableModel_object;
    ce_Ardillo_TableModelHandler = register_class_Ardillo_TableModelHandler();
    ce_Ardillo_TableModelHandler->create_object = ardillo_create_TableModelHandler_object;
    ce_Ardillo_TableParams = register_class_Ardillo_TableParams();
    ce_Ardillo_TableParams->create_object = ardillo_create_TableParams_object;
    ce_Ardillo_TableTextColumnOptionalParams = register_class_Ardillo_TableTextColumnOptionalParams();
    ce_Ardillo_TableTextColumnOptionalParams->create_object = ardillo_create_TableTextColumnOptionalParams_object;
    ce_Ardillo_TableValue = register_class_Ardillo_TableValue();
    ce_Ardillo_TableValue->create_object = ardillo_create_TableValue_object;
    ce_Ardillo_Window = register_class_Ardillo_Window(ce_Ardillo_Control);
    ce_Ardillo_Window->create_object = ardillo_create_Window_object;
    ce_Ardillo_Area = register_class_Ardillo_Area(ce_Ardillo_Control);
    ce_Ardillo_Area->create_object = ardillo_create_Area_object;
    ce_Ardillo_DrawPath = register_class_Ardillo_DrawPath();
    ce_Ardillo_DrawPath->create_object = ardillo_create_DrawPath_object;
    ce_Ardillo_HorizontalBox = register_class_Ardillo_HorizontalBox(ce_Ardillo_Box);
    ce_Ardillo_HorizontalBox->create_object = ardillo_create_HorizontalBox_object;
    ce_Ardillo_VerticalBox = register_class_Ardillo_VerticalBox(ce_Ardillo_Box);
    ce_Ardillo_VerticalBox->create_object = ardillo_create_VerticalBox_object;
    ce_Ardillo_DatePicker = register_class_Ardillo_DatePicker(ce_Ardillo_DateTimePicker);
    ce_Ardillo_DatePicker->create_object = ardillo_create_DatePicker_object;
    ce_Ardillo_TimePicker = register_class_Ardillo_TimePicker(ce_Ardillo_DateTimePicker);
    ce_Ardillo_TimePicker->create_object = ardillo_create_TimePicker_object;
    ce_Ardillo_PasswordEntry = register_class_Ardillo_PasswordEntry(ce_Ardillo_Entry);
    ce_Ardillo_PasswordEntry->create_object = ardillo_create_PasswordEntry_object;
    ce_Ardillo_SearchEntry = register_class_Ardillo_SearchEntry(ce_Ardillo_Entry);
    ce_Ardillo_SearchEntry->create_object = ardillo_create_SearchEntry_object;
    ce_Ardillo_NonWrappingMultilineEntry = register_class_Ardillo_NonWrappingMultilineEntry(ce_Ardillo_MultilineEntry);
    ce_Ardillo_NonWrappingMultilineEntry->create_object = ardillo_create_NonWrappingMultilineEntry_object;
    ce_Ardillo_HorizontalSeparator = register_class_Ardillo_HorizontalSeparator(ce_Ardillo_Separator);
    ce_Ardillo_HorizontalSeparator->create_object = ardillo_create_HorizontalSeparator_object;
    ce_Ardillo_VerticalSeparator = register_class_Ardillo_VerticalSeparator(ce_Ardillo_Separator);
    ce_Ardillo_VerticalSeparator->create_object = ardillo_create_VerticalSeparator_object;
    ce_Ardillo_TableValueString = register_class_Ardillo_TableValueString(ce_Ardillo_TableValue);
    ce_Ardillo_TableValueString->create_object = ardillo_create_TableValueString_object;
    ce_Ardillo_TableValueImage = register_class_Ardillo_TableValueImage(ce_Ardillo_TableValue);
    ce_Ardillo_TableValueImage->create_object = ardillo_create_TableValueImage_object;
    ce_Ardillo_TableValueInt = register_class_Ardillo_TableValueInt(ce_Ardillo_TableValue);
    ce_Ardillo_TableValueInt->create_object = ardillo_create_TableValueInt_object;
    ce_Ardillo_TableValueColor = register_class_Ardillo_TableValueColor(ce_Ardillo_TableValue);
    ce_Ardillo_TableValueColor->create_object = ardillo_create_TableValueColor_object;

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(ardillo)
{
#if defined(ZTS) && defined(COMPILE_DL_ARDILLO)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    ardillo_debug("MSHUTDOWN: About to run uiUninit()\n");
    uiUninit();
    ardillo_debug("MSHUTDOWN: done running uiUninit()\n");

    return SUCCESS;
}

PHP_RINIT_FUNCTION(ardillo)
{
#if defined(ZTS) && defined(COMPILE_DL_ARDILLO)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif

    return SUCCESS;
}

PHP_MINFO_FUNCTION(ardillo)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Ardillo", "enabled");
    php_info_print_table_end();
}

zend_module_entry ardillo_module_entry = {
    STANDARD_MODULE_HEADER,
    "ardillo", /* Extension name */
    NULL, /* zend_function_entry */
    PHP_MINIT(ardillo), /* PHP_MINIT - Module initialization */
    PHP_MSHUTDOWN(ardillo), /* PHP_MSHUTDOWN - Module shutdown */
    PHP_RINIT(ardillo), /* PHP_RINIT - Request initialization */
    NULL, /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(ardillo), /* PHP_MINFO - Module info */
    PHP_ARDILLO_VERSION, /* Version */
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_ARDILLO
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(ardillo)
#endif
