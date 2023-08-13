/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: c9f5556122b49ae00ba60d1eefc0c3c6a6c4e3b4 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_App_get, 0, 0, Ardillo\\App, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_App_run, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_App_stop arginfo_class_Ardillo_App_run

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_App_appendMenu, 0, 4, Ardillo\\Menu, 0)
	ZEND_ARG_OBJ_INFO(0, parent, Ardillo\\Menu, 1)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_App_scheduleTask, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, task, Ardillo\\Task, 0)
	ZEND_ARG_TYPE_INFO(0, interval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_App_addReadStream, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stream, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Ardillo\\StreamEventHandler, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_App_addWriteStream arginfo_class_Ardillo_App_addReadStream

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_App_removeReadStream, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_App_removeWriteStream arginfo_class_Ardillo_App_removeReadStream

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_App_addSignal, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, signo, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_App_removeSignal arginfo_class_Ardillo_App_addSignal

#define arginfo_class_Ardillo_Task_onExecute arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_StreamEventHandler_onReadEvent arginfo_class_Ardillo_App_removeReadStream

#define arginfo_class_Ardillo_StreamEventHandler_onWriteEvent arginfo_class_Ardillo_App_removeReadStream

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_Color_fromRGBA, 0, 1, Ardillo\\Color, 0)
	ZEND_ARG_TYPE_INFO(0, hex, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Color_fromRGB arginfo_class_Ardillo_Color_fromRGBA

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Color___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, red, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, green, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, blue, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, alpha, IS_DOUBLE, 0, "1.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Point___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Size___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, width, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, height, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_AreaDrawParams_getAreaSize, 0, 0, Ardillo\\Size, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_AreaDrawParams_getClipPoint, 0, 0, Ardillo\\Point, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_AreaDrawParams_getClipSize arginfo_class_Ardillo_AreaDrawParams_getAreaSize

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaDrawParams_fill, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, Ardillo\\DrawPath, 0)
	ZEND_ARG_OBJ_INFO(0, brush, Ardillo\\DrawBrush, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaDrawParams_stroke, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, Ardillo\\DrawPath, 0)
	ZEND_ARG_OBJ_INFO(0, brush, Ardillo\\DrawBrush, 0)
	ZEND_ARG_OBJ_INFO(0, sp, Ardillo\\DrawStrokeParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaDrawParams_transform, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, Ardillo\\DrawMatrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaHandler_dragBrokenHandler, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, area, Ardillo\\Area, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaHandler_drawHandler, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, area, Ardillo\\Area, 0)
	ZEND_ARG_OBJ_INFO(0, params, Ardillo\\AreaDrawParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaHandler_keyEventHandler, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, area, Ardillo\\Area, 0)
	ZEND_ARG_OBJ_INFO(0, event, Ardillo\\AreaKeyEvent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaHandler_mouseCrossedHandler, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, area, Ardillo\\Area, 0)
	ZEND_ARG_TYPE_INFO(0, left, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaHandler_mouseEventHandler, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, area, Ardillo\\Area, 0)
	ZEND_ARG_OBJ_INFO(0, event, Ardillo\\AreaMouseEvent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_AreaKeyEvent_getKey, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_AreaKeyEvent_getExtKey arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_AreaKeyEvent_getModifier, 0, 0, Ardillo\\Modifiers, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_AreaKeyEvent_getModifiers arginfo_class_Ardillo_AreaKeyEvent_getModifier

#define arginfo_class_Ardillo_AreaKeyEvent_getUp arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_AreaMouseEvent_getPoint arginfo_class_Ardillo_AreaDrawParams_getClipPoint

#define arginfo_class_Ardillo_AreaMouseEvent_getAreaSize arginfo_class_Ardillo_AreaDrawParams_getAreaSize

#define arginfo_class_Ardillo_AreaMouseEvent_getDown arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_AreaMouseEvent_getUp arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_AreaMouseEvent_getCount arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_AreaMouseEvent_getModifiers arginfo_class_Ardillo_AreaKeyEvent_getModifier

#define arginfo_class_Ardillo_AreaMouseEvent_getHeld1To64 arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Box_getPadded, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Box_setPadded, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, padded, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Box_append, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, Ardillo\\Control, 0)
	ZEND_ARG_TYPE_INFO(0, stretchy, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Box_delete, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Box_childrenCount arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Button___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Button_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Button_getText, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Button_setText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Button_onClicked arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Checkbox___construct arginfo_class_Ardillo_Button___construct

#define arginfo_class_Ardillo_Checkbox_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Checkbox_getChecked arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Checkbox_setChecked, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, checked, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Checkbox_getText arginfo_class_Ardillo_Button_getText

#define arginfo_class_Ardillo_Checkbox_setText arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_Checkbox_onToggled arginfo_class_Ardillo_App_run

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_ColorButton___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_ColorButton_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_ColorButton_getColor, 0, 0, Ardillo\\Color, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_ColorButton_setColor, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, color, Ardillo\\Color, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_ColorButton_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Combobox___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_Combobox_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Combobox_getSelected arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_Combobox_setSelected arginfo_class_Ardillo_Box_delete

#define arginfo_class_Ardillo_Combobox_onSelected arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Combobox_append arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_Combobox_clear arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Combobox_delete arginfo_class_Ardillo_Box_delete

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Combobox_insertAt, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Combobox_numItems arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_Control_disable arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Control_enable arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Control_isEnabled arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Control_isEnabledToUser arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Control_hide arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Control_show arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Control_isTopLevel arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Control_isVisible arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_DateTimePicker___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_DateTimePicker_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_DateTimePicker_getTime, 0, 0, DateTimeImmutable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DateTimePicker_setTime, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, time, DateTimeInterface, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DateTimePicker_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_DrawBrush_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_DrawBrush_getType arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrush_setType, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawBrush_getColor arginfo_class_Ardillo_ColorButton_getColor

#define arginfo_class_Ardillo_DrawBrush_setColor arginfo_class_Ardillo_ColorButton_setColor

#define arginfo_class_Ardillo_DrawBrush_getPoint0 arginfo_class_Ardillo_AreaDrawParams_getClipPoint

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrush_setPoint0, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, point, Ardillo\\Point, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawBrush_getPoint1 arginfo_class_Ardillo_AreaDrawParams_getClipPoint

#define arginfo_class_Ardillo_DrawBrush_setPoint1 arginfo_class_Ardillo_DrawBrush_setPoint0

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrush_getOuterRadius, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrush_setOuterRadius, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, outerRadius, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_DrawBrush_getStops, 0, 0, Ardillo\\DrawBrushGradientStop, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrush_setStops, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, stops, Ardillo\\DrawBrushGradientStop, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawBrush_getNumStops arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrush_setNumStops, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, numStops, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawBrushGradientStop_getPos arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawBrushGradientStop_setPos, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawBrushGradientStop_getColor arginfo_class_Ardillo_ColorButton_getColor

#define arginfo_class_Ardillo_DrawBrushGradientStop_setColor arginfo_class_Ardillo_ColorButton_setColor

#define arginfo_class_Ardillo_DrawMatrix_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_DrawMatrix_setIdentity arginfo_class_Ardillo_App_run

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawMatrix_translate, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_DrawStrokeParams_getCap arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setCap, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_getJoin arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setJoin, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, join, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_getThickness arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setThickness, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, thickness, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_getMiterLimit arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setMiterLimit, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, miterLimit, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_getDashes arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setDashes, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, dashes, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_getNumDashes arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setNumDashes, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, numDashes, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawStrokeParams_getDashPhase arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawStrokeParams_setDashPhase, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, dashPhase, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_DrawTextLayoutParams_getDefaultFont, 0, 0, Ardillo\\FontDescriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawTextLayoutParams_setDefaultFont, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, defaultFont, Ardillo\\FontDescriptor, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawTextLayoutParams_getWidth arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawTextLayoutParams_setWidth, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawTextLayoutParams_getAlign arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawTextLayoutParams_setAlign, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, align, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_EditableCombobox___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_EditableCombobox_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_EditableCombobox_getText arginfo_class_Ardillo_Button_getText

#define arginfo_class_Ardillo_EditableCombobox_setText arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_EditableCombobox_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_EditableCombobox_append arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_Entry___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_Entry_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Entry_getReadOnly arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Entry_setReadOnly, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, readonly, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Entry_getText arginfo_class_Ardillo_Button_getText

#define arginfo_class_Ardillo_Entry_setText arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_Entry_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_FontButton___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_FontButton_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_FontButton_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_FontButton_getFont arginfo_class_Ardillo_DrawTextLayoutParams_getDefaultFont

#define arginfo_class_Ardillo_FontDescriptor_getFamily arginfo_class_Ardillo_Button_getText

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_FontDescriptor_setFamily, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_FontDescriptor_getSize arginfo_class_Ardillo_DrawBrush_getOuterRadius

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_FontDescriptor_setSize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_FontDescriptor_getWeight arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_FontDescriptor_setWeight, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, weight, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_FontDescriptor_getItalic arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_FontDescriptor_setItalic, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, italic, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_FontDescriptor_getStretch arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_FontDescriptor_setStretch, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, stretch, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Form___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_Form_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Form_getPadded arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Form_setPadded arginfo_class_Ardillo_Box_setPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Form_append, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, c, Ardillo\\Control, 0)
	ZEND_ARG_TYPE_INFO(0, stretchy, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Form_delete arginfo_class_Ardillo_Box_delete

#define arginfo_class_Ardillo_Form_childrenCount arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_Grid___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_Grid_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Grid_getPadded arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Grid_setPadded arginfo_class_Ardillo_Box_setPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Grid_append, 0, 9, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, c, Ardillo\\Control, 0)
	ZEND_ARG_TYPE_INFO(0, left, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, top, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xspan, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yspan, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hexpand, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, halign, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vexpand, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, valign, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Grid_insertAt, 0, 9, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, c, Ardillo\\Control, 0)
	ZEND_ARG_OBJ_INFO(0, existing, Ardillo\\Control, 0)
	ZEND_ARG_OBJ_INFO(0, at, Ardillo\\At, 0)
	ZEND_ARG_TYPE_INFO(0, xspan, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yspan, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hexpand, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, halign, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vexpand, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, valign, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Group___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Group_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Group_getMargined arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Group_setMargined, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, margined, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Group_getTitle arginfo_class_Ardillo_Button_getText

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Group_setTitle, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Group_setChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, c, Ardillo\\Control, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Image___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Image_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Image_append, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, size, Ardillo\\Size, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Label___construct arginfo_class_Ardillo_Button___construct

#define arginfo_class_Ardillo_Label_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Label_getText arginfo_class_Ardillo_Button_getText

#define arginfo_class_Ardillo_Label_setText arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_MultilineEntry___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_MultilineEntry_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_MultilineEntry_getReadOnly arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_MultilineEntry_setReadOnly arginfo_class_Ardillo_Entry_setReadOnly

#define arginfo_class_Ardillo_MultilineEntry_getText arginfo_class_Ardillo_Button_getText

#define arginfo_class_Ardillo_MultilineEntry_setText arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_MultilineEntry_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_MultilineEntry_append arginfo_class_Ardillo_Button_setText

#define arginfo_class_Ardillo_ProgressBar___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_ProgressBar_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_ProgressBar_getValue arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_ProgressBar_setValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_RadioButtons___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_RadioButtons_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_RadioButtons_getSelected arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_RadioButtons_setSelected arginfo_class_Ardillo_Box_delete

#define arginfo_class_Ardillo_RadioButtons_onSelected arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_RadioButtons_append arginfo_class_Ardillo_Button_setText

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Slider___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Slider_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Slider_getHasToolTip arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Slider_setHasToolTip, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hasToolTip, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Slider_getValue arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Slider_setValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Slider_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Slider_onReleased arginfo_class_Ardillo_App_run

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Slider_setRange, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Spinbox___construct arginfo_class_Ardillo_Slider___construct

#define arginfo_class_Ardillo_Spinbox_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Spinbox_getValue arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_Spinbox_setValue arginfo_class_Ardillo_Slider_setValue

#define arginfo_class_Ardillo_Spinbox_onChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Tab___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_Tab_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Tab_getMargined, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Tab_setMargined, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, margined, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Tab_append, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, c, Ardillo\\Control, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Tab_delete arginfo_class_Ardillo_Box_delete

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Tab_insertAt, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, c, Ardillo\\Control, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Tab_pageCount arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Table___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, params, Ardillo\\TableParams, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Table_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_getColumnWidth, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_setColumnWidth, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Table_getHeaderSortIndicator arginfo_class_Ardillo_Table_getColumnWidth

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_setHeaderSortIndicator, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indicator, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Table_getHeaderVisible arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_setHeaderVisible, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Table_getSelectionMode arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_setSelectionMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_onHeaderClicked, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_onRowClicked, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Table_onRowDoubleClicked arginfo_class_Ardillo_Table_onRowClicked

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendButtonColumn, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, buttonModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buttonClickableModelColumn, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendCheckboxColumn, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, checkboxModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, checkboxEditableModelColumn, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendCheckboxTextColumn, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, checkboxModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, checkboxEditableModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textEditableModelColumn, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, textParams, Ardillo\\TableTextColumnOptionalParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendImageColumn, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, imageModelColumn, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendImageTextColumn, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, imageModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textEditableModelColumn, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, textParams, Ardillo\\TableTextColumnOptionalParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendProgressBarColumn, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, progressModelColumn, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_appendTextColumn, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, textModelColumn, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textEditableModelColumn, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, textParams, Ardillo\\TableTextColumnOptionalParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Table_onSelectionChanged, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, selection, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Table_setSelection arginfo_class_Ardillo_Table_onSelectionChanged

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_TableModel___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mh, Ardillo\\TableModelHandler, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableModel_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_TableModel_rowChanged arginfo_class_Ardillo_Box_delete

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableModel_rowDeleted, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, oldIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableModel_rowInserted, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, newIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableModelHandler_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_TableModelHandler_cellValueHandler, 0, 3, Ardillo\\TableValue, 0)
	ZEND_ARG_OBJ_INFO(0, m, Ardillo\\TableModel, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableModelHandler_columnTypeHandler, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, model, Ardillo\\TableModel, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableModelHandler_numColumnsHandler, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, model, Ardillo\\TableModel, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableModelHandler_numRowsHandler arginfo_class_Ardillo_TableModelHandler_numColumnsHandler

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableModelHandler_setCellValueHandler, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, Ardillo\\TableModel, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, value, Ardillo\\TableValue, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableParams_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_TableParams_getModel, 0, 0, Ardillo\\TableModel, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableParams_setModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, Ardillo\\TableModel, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableParams_getRowBackgroundColorModelColumn arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableParams_setRowBackgroundColorModelColumn, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, rowBackgroundColorModelColumn, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableTextColumnOptionalParams_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_TableTextColumnOptionalParams_getColorModelColumn arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_TableTextColumnOptionalParams_setColorModelColumn, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, colorModelColumn, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableValue_getType arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Window___construct, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, size, Ardillo\\Size, 0)
	ZEND_ARG_TYPE_INFO(0, hasMenubar, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Window_getBorderless arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_setBorderless, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, borderless, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_getContentSize arginfo_class_Ardillo_AreaDrawParams_getAreaSize

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_setContentSize, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, size, Ardillo\\Size, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_getFullscreen arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_setFullscreen, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, fullscreen, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_getMargined arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Window_setMargined arginfo_class_Ardillo_Group_setMargined

#define arginfo_class_Ardillo_Window_getPosition arginfo_class_Ardillo_AreaDrawParams_getClipPoint

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_setPosition, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pos, Ardillo\\Point, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_getResizeable arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_setResizeable, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, resizeable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_getTitle arginfo_class_Ardillo_Button_getText

#define arginfo_class_Ardillo_Window_setTitle arginfo_class_Ardillo_Group_setTitle

#define arginfo_class_Ardillo_Window_onClosing arginfo_class_Ardillo_AreaKeyEvent_getKey

#define arginfo_class_Ardillo_Window_onContentSizeChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Window_onFocusChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Window_onPositionChanged arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_Window_isFocused arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_setChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, Ardillo\\Control, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_messageBox, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_Window_openFolder, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Window_openFile arginfo_class_Ardillo_Window_openFolder

#define arginfo_class_Ardillo_Window_saveFile arginfo_class_Ardillo_Window_openFolder

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_Area___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, ah, Ardillo\\AreaHandler, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_Area_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_Area_queueRedrawAll arginfo_class_Ardillo_App_run

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_DrawPath___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, fillMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawPath_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ardillo_DrawPath_addRectangle, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pt, Ardillo\\Point, 0)
	ZEND_ARG_OBJ_INFO(0, size, Ardillo\\Size, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_DrawPath_newFigure arginfo_class_Ardillo_DrawMatrix_translate

#define arginfo_class_Ardillo_DrawPath_closeFigure arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_DrawPath_lineTo arginfo_class_Ardillo_DrawMatrix_translate

#define arginfo_class_Ardillo_DrawPath_end arginfo_class_Ardillo_App_run

#define arginfo_class_Ardillo_HorizontalBox___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_HorizontalBox_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_VerticalBox___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_VerticalBox_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_DatePicker___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_DatePicker_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_TimePicker___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_TimePicker_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_PasswordEntry___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_PasswordEntry_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_SearchEntry___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_SearchEntry_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_NonWrappingMultilineEntry___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_NonWrappingMultilineEntry_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_HorizontalSeparator___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_HorizontalSeparator_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_VerticalSeparator___construct arginfo_class_Ardillo_ColorButton___construct

#define arginfo_class_Ardillo_VerticalSeparator_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_TableValueString___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableValueString_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_TableValueString_get arginfo_class_Ardillo_Button_getText

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_TableValueImage___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, img, Ardillo\\Image, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableValueImage_isValid arginfo_class_Ardillo_Box_getPadded

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ardillo_TableValueImage_get, 0, 0, Ardillo\\Image, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_TableValueInt___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, i, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableValueInt_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_TableValueInt_get arginfo_class_Ardillo_AreaKeyEvent_getKey

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ardillo_TableValueColor___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, color, Ardillo\\Color, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ardillo_TableValueColor_isValid arginfo_class_Ardillo_Box_getPadded

#define arginfo_class_Ardillo_TableValueColor_get arginfo_class_Ardillo_ColorButton_getColor


ZEND_METHOD(Ardillo_App, get);
ZEND_METHOD(Ardillo_App, run);
ZEND_METHOD(Ardillo_App, stop);
ZEND_METHOD(Ardillo_App, appendMenu);
ZEND_METHOD(Ardillo_App, scheduleTask);
ZEND_METHOD(Ardillo_App, addReadStream);
ZEND_METHOD(Ardillo_App, addWriteStream);
ZEND_METHOD(Ardillo_App, removeReadStream);
ZEND_METHOD(Ardillo_App, removeWriteStream);
ZEND_METHOD(Ardillo_App, addSignal);
ZEND_METHOD(Ardillo_App, removeSignal);
ZEND_METHOD(Ardillo_Task, onExecute);
ZEND_METHOD(Ardillo_Color, fromRGBA);
ZEND_METHOD(Ardillo_Color, fromRGB);
ZEND_METHOD(Ardillo_Color, __construct);
ZEND_METHOD(Ardillo_Point, __construct);
ZEND_METHOD(Ardillo_Size, __construct);
ZEND_METHOD(Ardillo_AreaDrawParams, getAreaSize);
ZEND_METHOD(Ardillo_AreaDrawParams, getClipPoint);
ZEND_METHOD(Ardillo_AreaDrawParams, getClipSize);
ZEND_METHOD(Ardillo_AreaDrawParams, fill);
ZEND_METHOD(Ardillo_AreaDrawParams, stroke);
ZEND_METHOD(Ardillo_AreaDrawParams, transform);
ZEND_METHOD(Ardillo_AreaKeyEvent, getKey);
ZEND_METHOD(Ardillo_AreaKeyEvent, getExtKey);
ZEND_METHOD(Ardillo_AreaKeyEvent, getModifier);
ZEND_METHOD(Ardillo_AreaKeyEvent, getModifiers);
ZEND_METHOD(Ardillo_AreaKeyEvent, getUp);
ZEND_METHOD(Ardillo_AreaMouseEvent, getPoint);
ZEND_METHOD(Ardillo_AreaMouseEvent, getAreaSize);
ZEND_METHOD(Ardillo_AreaMouseEvent, getDown);
ZEND_METHOD(Ardillo_AreaMouseEvent, getUp);
ZEND_METHOD(Ardillo_AreaMouseEvent, getCount);
ZEND_METHOD(Ardillo_AreaMouseEvent, getModifiers);
ZEND_METHOD(Ardillo_AreaMouseEvent, getHeld1To64);
ZEND_METHOD(Ardillo_Box, getPadded);
ZEND_METHOD(Ardillo_Box, setPadded);
ZEND_METHOD(Ardillo_Box, append);
ZEND_METHOD(Ardillo_Box, delete);
ZEND_METHOD(Ardillo_Box, childrenCount);
ZEND_METHOD(Ardillo_Button, __construct);
ZEND_METHOD(Ardillo_Button, isValid);
ZEND_METHOD(Ardillo_Button, getText);
ZEND_METHOD(Ardillo_Button, setText);
ZEND_METHOD(Ardillo_Button, onClicked);
ZEND_METHOD(Ardillo_Checkbox, __construct);
ZEND_METHOD(Ardillo_Checkbox, isValid);
ZEND_METHOD(Ardillo_Checkbox, getChecked);
ZEND_METHOD(Ardillo_Checkbox, setChecked);
ZEND_METHOD(Ardillo_Checkbox, getText);
ZEND_METHOD(Ardillo_Checkbox, setText);
ZEND_METHOD(Ardillo_Checkbox, onToggled);
ZEND_METHOD(Ardillo_ColorButton, __construct);
ZEND_METHOD(Ardillo_ColorButton, isValid);
ZEND_METHOD(Ardillo_ColorButton, getColor);
ZEND_METHOD(Ardillo_ColorButton, setColor);
ZEND_METHOD(Ardillo_ColorButton, onChanged);
ZEND_METHOD(Ardillo_Combobox, __construct);
ZEND_METHOD(Ardillo_Combobox, isValid);
ZEND_METHOD(Ardillo_Combobox, getSelected);
ZEND_METHOD(Ardillo_Combobox, setSelected);
ZEND_METHOD(Ardillo_Combobox, onSelected);
ZEND_METHOD(Ardillo_Combobox, append);
ZEND_METHOD(Ardillo_Combobox, clear);
ZEND_METHOD(Ardillo_Combobox, delete);
ZEND_METHOD(Ardillo_Combobox, insertAt);
ZEND_METHOD(Ardillo_Combobox, numItems);
ZEND_METHOD(Ardillo_Control, disable);
ZEND_METHOD(Ardillo_Control, enable);
ZEND_METHOD(Ardillo_Control, isEnabled);
ZEND_METHOD(Ardillo_Control, isEnabledToUser);
ZEND_METHOD(Ardillo_Control, hide);
ZEND_METHOD(Ardillo_Control, show);
ZEND_METHOD(Ardillo_Control, isTopLevel);
ZEND_METHOD(Ardillo_Control, isVisible);
ZEND_METHOD(Ardillo_DateTimePicker, __construct);
ZEND_METHOD(Ardillo_DateTimePicker, isValid);
ZEND_METHOD(Ardillo_DateTimePicker, getTime);
ZEND_METHOD(Ardillo_DateTimePicker, setTime);
ZEND_METHOD(Ardillo_DateTimePicker, onChanged);
ZEND_METHOD(Ardillo_DrawBrush, isValid);
ZEND_METHOD(Ardillo_DrawBrush, getType);
ZEND_METHOD(Ardillo_DrawBrush, setType);
ZEND_METHOD(Ardillo_DrawBrush, getColor);
ZEND_METHOD(Ardillo_DrawBrush, setColor);
ZEND_METHOD(Ardillo_DrawBrush, getPoint0);
ZEND_METHOD(Ardillo_DrawBrush, setPoint0);
ZEND_METHOD(Ardillo_DrawBrush, getPoint1);
ZEND_METHOD(Ardillo_DrawBrush, setPoint1);
ZEND_METHOD(Ardillo_DrawBrush, getOuterRadius);
ZEND_METHOD(Ardillo_DrawBrush, setOuterRadius);
ZEND_METHOD(Ardillo_DrawBrush, getStops);
ZEND_METHOD(Ardillo_DrawBrush, setStops);
ZEND_METHOD(Ardillo_DrawBrush, getNumStops);
ZEND_METHOD(Ardillo_DrawBrush, setNumStops);
ZEND_METHOD(Ardillo_DrawBrushGradientStop, getPos);
ZEND_METHOD(Ardillo_DrawBrushGradientStop, setPos);
ZEND_METHOD(Ardillo_DrawBrushGradientStop, getColor);
ZEND_METHOD(Ardillo_DrawBrushGradientStop, setColor);
ZEND_METHOD(Ardillo_DrawMatrix, isValid);
ZEND_METHOD(Ardillo_DrawMatrix, setIdentity);
ZEND_METHOD(Ardillo_DrawMatrix, translate);
ZEND_METHOD(Ardillo_DrawStrokeParams, isValid);
ZEND_METHOD(Ardillo_DrawStrokeParams, getCap);
ZEND_METHOD(Ardillo_DrawStrokeParams, setCap);
ZEND_METHOD(Ardillo_DrawStrokeParams, getJoin);
ZEND_METHOD(Ardillo_DrawStrokeParams, setJoin);
ZEND_METHOD(Ardillo_DrawStrokeParams, getThickness);
ZEND_METHOD(Ardillo_DrawStrokeParams, setThickness);
ZEND_METHOD(Ardillo_DrawStrokeParams, getMiterLimit);
ZEND_METHOD(Ardillo_DrawStrokeParams, setMiterLimit);
ZEND_METHOD(Ardillo_DrawStrokeParams, getDashes);
ZEND_METHOD(Ardillo_DrawStrokeParams, setDashes);
ZEND_METHOD(Ardillo_DrawStrokeParams, getNumDashes);
ZEND_METHOD(Ardillo_DrawStrokeParams, setNumDashes);
ZEND_METHOD(Ardillo_DrawStrokeParams, getDashPhase);
ZEND_METHOD(Ardillo_DrawStrokeParams, setDashPhase);
ZEND_METHOD(Ardillo_DrawTextLayoutParams, getDefaultFont);
ZEND_METHOD(Ardillo_DrawTextLayoutParams, setDefaultFont);
ZEND_METHOD(Ardillo_DrawTextLayoutParams, getWidth);
ZEND_METHOD(Ardillo_DrawTextLayoutParams, setWidth);
ZEND_METHOD(Ardillo_DrawTextLayoutParams, getAlign);
ZEND_METHOD(Ardillo_DrawTextLayoutParams, setAlign);
ZEND_METHOD(Ardillo_EditableCombobox, __construct);
ZEND_METHOD(Ardillo_EditableCombobox, isValid);
ZEND_METHOD(Ardillo_EditableCombobox, getText);
ZEND_METHOD(Ardillo_EditableCombobox, setText);
ZEND_METHOD(Ardillo_EditableCombobox, onChanged);
ZEND_METHOD(Ardillo_EditableCombobox, append);
ZEND_METHOD(Ardillo_Entry, __construct);
ZEND_METHOD(Ardillo_Entry, isValid);
ZEND_METHOD(Ardillo_Entry, getReadOnly);
ZEND_METHOD(Ardillo_Entry, setReadOnly);
ZEND_METHOD(Ardillo_Entry, getText);
ZEND_METHOD(Ardillo_Entry, setText);
ZEND_METHOD(Ardillo_Entry, onChanged);
ZEND_METHOD(Ardillo_FontButton, __construct);
ZEND_METHOD(Ardillo_FontButton, isValid);
ZEND_METHOD(Ardillo_FontButton, onChanged);
ZEND_METHOD(Ardillo_FontButton, getFont);
ZEND_METHOD(Ardillo_FontDescriptor, getFamily);
ZEND_METHOD(Ardillo_FontDescriptor, setFamily);
ZEND_METHOD(Ardillo_FontDescriptor, getSize);
ZEND_METHOD(Ardillo_FontDescriptor, setSize);
ZEND_METHOD(Ardillo_FontDescriptor, getWeight);
ZEND_METHOD(Ardillo_FontDescriptor, setWeight);
ZEND_METHOD(Ardillo_FontDescriptor, getItalic);
ZEND_METHOD(Ardillo_FontDescriptor, setItalic);
ZEND_METHOD(Ardillo_FontDescriptor, getStretch);
ZEND_METHOD(Ardillo_FontDescriptor, setStretch);
ZEND_METHOD(Ardillo_Form, __construct);
ZEND_METHOD(Ardillo_Form, isValid);
ZEND_METHOD(Ardillo_Form, getPadded);
ZEND_METHOD(Ardillo_Form, setPadded);
ZEND_METHOD(Ardillo_Form, append);
ZEND_METHOD(Ardillo_Form, delete);
ZEND_METHOD(Ardillo_Form, childrenCount);
ZEND_METHOD(Ardillo_Grid, __construct);
ZEND_METHOD(Ardillo_Grid, isValid);
ZEND_METHOD(Ardillo_Grid, getPadded);
ZEND_METHOD(Ardillo_Grid, setPadded);
ZEND_METHOD(Ardillo_Grid, append);
ZEND_METHOD(Ardillo_Grid, insertAt);
ZEND_METHOD(Ardillo_Group, __construct);
ZEND_METHOD(Ardillo_Group, isValid);
ZEND_METHOD(Ardillo_Group, getMargined);
ZEND_METHOD(Ardillo_Group, setMargined);
ZEND_METHOD(Ardillo_Group, getTitle);
ZEND_METHOD(Ardillo_Group, setTitle);
ZEND_METHOD(Ardillo_Group, setChild);
ZEND_METHOD(Ardillo_Image, __construct);
ZEND_METHOD(Ardillo_Image, isValid);
ZEND_METHOD(Ardillo_Image, append);
ZEND_METHOD(Ardillo_Label, __construct);
ZEND_METHOD(Ardillo_Label, isValid);
ZEND_METHOD(Ardillo_Label, getText);
ZEND_METHOD(Ardillo_Label, setText);
ZEND_METHOD(Ardillo_MultilineEntry, __construct);
ZEND_METHOD(Ardillo_MultilineEntry, isValid);
ZEND_METHOD(Ardillo_MultilineEntry, getReadOnly);
ZEND_METHOD(Ardillo_MultilineEntry, setReadOnly);
ZEND_METHOD(Ardillo_MultilineEntry, getText);
ZEND_METHOD(Ardillo_MultilineEntry, setText);
ZEND_METHOD(Ardillo_MultilineEntry, onChanged);
ZEND_METHOD(Ardillo_MultilineEntry, append);
ZEND_METHOD(Ardillo_ProgressBar, __construct);
ZEND_METHOD(Ardillo_ProgressBar, isValid);
ZEND_METHOD(Ardillo_ProgressBar, getValue);
ZEND_METHOD(Ardillo_ProgressBar, setValue);
ZEND_METHOD(Ardillo_RadioButtons, __construct);
ZEND_METHOD(Ardillo_RadioButtons, isValid);
ZEND_METHOD(Ardillo_RadioButtons, getSelected);
ZEND_METHOD(Ardillo_RadioButtons, setSelected);
ZEND_METHOD(Ardillo_RadioButtons, onSelected);
ZEND_METHOD(Ardillo_RadioButtons, append);
ZEND_METHOD(Ardillo_Slider, __construct);
ZEND_METHOD(Ardillo_Slider, isValid);
ZEND_METHOD(Ardillo_Slider, getHasToolTip);
ZEND_METHOD(Ardillo_Slider, setHasToolTip);
ZEND_METHOD(Ardillo_Slider, getValue);
ZEND_METHOD(Ardillo_Slider, setValue);
ZEND_METHOD(Ardillo_Slider, onChanged);
ZEND_METHOD(Ardillo_Slider, onReleased);
ZEND_METHOD(Ardillo_Slider, setRange);
ZEND_METHOD(Ardillo_Spinbox, __construct);
ZEND_METHOD(Ardillo_Spinbox, isValid);
ZEND_METHOD(Ardillo_Spinbox, getValue);
ZEND_METHOD(Ardillo_Spinbox, setValue);
ZEND_METHOD(Ardillo_Spinbox, onChanged);
ZEND_METHOD(Ardillo_Tab, __construct);
ZEND_METHOD(Ardillo_Tab, isValid);
ZEND_METHOD(Ardillo_Tab, getMargined);
ZEND_METHOD(Ardillo_Tab, setMargined);
ZEND_METHOD(Ardillo_Tab, append);
ZEND_METHOD(Ardillo_Tab, delete);
ZEND_METHOD(Ardillo_Tab, insertAt);
ZEND_METHOD(Ardillo_Tab, pageCount);
ZEND_METHOD(Ardillo_Table, __construct);
ZEND_METHOD(Ardillo_Table, isValid);
ZEND_METHOD(Ardillo_Table, getColumnWidth);
ZEND_METHOD(Ardillo_Table, setColumnWidth);
ZEND_METHOD(Ardillo_Table, getHeaderSortIndicator);
ZEND_METHOD(Ardillo_Table, setHeaderSortIndicator);
ZEND_METHOD(Ardillo_Table, getHeaderVisible);
ZEND_METHOD(Ardillo_Table, setHeaderVisible);
ZEND_METHOD(Ardillo_Table, getSelectionMode);
ZEND_METHOD(Ardillo_Table, setSelectionMode);
ZEND_METHOD(Ardillo_Table, onHeaderClicked);
ZEND_METHOD(Ardillo_Table, onRowClicked);
ZEND_METHOD(Ardillo_Table, onRowDoubleClicked);
ZEND_METHOD(Ardillo_Table, appendButtonColumn);
ZEND_METHOD(Ardillo_Table, appendCheckboxColumn);
ZEND_METHOD(Ardillo_Table, appendCheckboxTextColumn);
ZEND_METHOD(Ardillo_Table, appendImageColumn);
ZEND_METHOD(Ardillo_Table, appendImageTextColumn);
ZEND_METHOD(Ardillo_Table, appendProgressBarColumn);
ZEND_METHOD(Ardillo_Table, appendTextColumn);
ZEND_METHOD(Ardillo_Table, onSelectionChanged);
ZEND_METHOD(Ardillo_Table, setSelection);
ZEND_METHOD(Ardillo_TableModel, __construct);
ZEND_METHOD(Ardillo_TableModel, isValid);
ZEND_METHOD(Ardillo_TableModel, rowChanged);
ZEND_METHOD(Ardillo_TableModel, rowDeleted);
ZEND_METHOD(Ardillo_TableModel, rowInserted);
ZEND_METHOD(Ardillo_TableModelHandler, isValid);
ZEND_METHOD(Ardillo_TableParams, isValid);
ZEND_METHOD(Ardillo_TableParams, getModel);
ZEND_METHOD(Ardillo_TableParams, setModel);
ZEND_METHOD(Ardillo_TableParams, getRowBackgroundColorModelColumn);
ZEND_METHOD(Ardillo_TableParams, setRowBackgroundColorModelColumn);
ZEND_METHOD(Ardillo_TableTextColumnOptionalParams, isValid);
ZEND_METHOD(Ardillo_TableTextColumnOptionalParams, getColorModelColumn);
ZEND_METHOD(Ardillo_TableTextColumnOptionalParams, setColorModelColumn);
ZEND_METHOD(Ardillo_TableValue, getType);
ZEND_METHOD(Ardillo_Window, __construct);
ZEND_METHOD(Ardillo_Window, isValid);
ZEND_METHOD(Ardillo_Window, getBorderless);
ZEND_METHOD(Ardillo_Window, setBorderless);
ZEND_METHOD(Ardillo_Window, getContentSize);
ZEND_METHOD(Ardillo_Window, setContentSize);
ZEND_METHOD(Ardillo_Window, getFullscreen);
ZEND_METHOD(Ardillo_Window, setFullscreen);
ZEND_METHOD(Ardillo_Window, getMargined);
ZEND_METHOD(Ardillo_Window, setMargined);
ZEND_METHOD(Ardillo_Window, getPosition);
ZEND_METHOD(Ardillo_Window, setPosition);
ZEND_METHOD(Ardillo_Window, getResizeable);
ZEND_METHOD(Ardillo_Window, setResizeable);
ZEND_METHOD(Ardillo_Window, getTitle);
ZEND_METHOD(Ardillo_Window, setTitle);
ZEND_METHOD(Ardillo_Window, onClosing);
ZEND_METHOD(Ardillo_Window, onContentSizeChanged);
ZEND_METHOD(Ardillo_Window, onFocusChanged);
ZEND_METHOD(Ardillo_Window, onPositionChanged);
ZEND_METHOD(Ardillo_Window, isFocused);
ZEND_METHOD(Ardillo_Window, setChild);
ZEND_METHOD(Ardillo_Window, messageBox);
ZEND_METHOD(Ardillo_Window, openFolder);
ZEND_METHOD(Ardillo_Window, openFile);
ZEND_METHOD(Ardillo_Window, saveFile);
ZEND_METHOD(Ardillo_Area, __construct);
ZEND_METHOD(Ardillo_Area, isValid);
ZEND_METHOD(Ardillo_Area, queueRedrawAll);
ZEND_METHOD(Ardillo_DrawPath, __construct);
ZEND_METHOD(Ardillo_DrawPath, isValid);
ZEND_METHOD(Ardillo_DrawPath, addRectangle);
ZEND_METHOD(Ardillo_DrawPath, newFigure);
ZEND_METHOD(Ardillo_DrawPath, closeFigure);
ZEND_METHOD(Ardillo_DrawPath, lineTo);
ZEND_METHOD(Ardillo_DrawPath, end);
ZEND_METHOD(Ardillo_HorizontalBox, __construct);
ZEND_METHOD(Ardillo_HorizontalBox, isValid);
ZEND_METHOD(Ardillo_VerticalBox, __construct);
ZEND_METHOD(Ardillo_VerticalBox, isValid);
ZEND_METHOD(Ardillo_DatePicker, __construct);
ZEND_METHOD(Ardillo_DatePicker, isValid);
ZEND_METHOD(Ardillo_TimePicker, __construct);
ZEND_METHOD(Ardillo_TimePicker, isValid);
ZEND_METHOD(Ardillo_PasswordEntry, __construct);
ZEND_METHOD(Ardillo_PasswordEntry, isValid);
ZEND_METHOD(Ardillo_SearchEntry, __construct);
ZEND_METHOD(Ardillo_SearchEntry, isValid);
ZEND_METHOD(Ardillo_NonWrappingMultilineEntry, __construct);
ZEND_METHOD(Ardillo_NonWrappingMultilineEntry, isValid);
ZEND_METHOD(Ardillo_HorizontalSeparator, __construct);
ZEND_METHOD(Ardillo_HorizontalSeparator, isValid);
ZEND_METHOD(Ardillo_VerticalSeparator, __construct);
ZEND_METHOD(Ardillo_VerticalSeparator, isValid);
ZEND_METHOD(Ardillo_TableValueString, __construct);
ZEND_METHOD(Ardillo_TableValueString, isValid);
ZEND_METHOD(Ardillo_TableValueString, get);
ZEND_METHOD(Ardillo_TableValueImage, __construct);
ZEND_METHOD(Ardillo_TableValueImage, isValid);
ZEND_METHOD(Ardillo_TableValueImage, get);
ZEND_METHOD(Ardillo_TableValueInt, __construct);
ZEND_METHOD(Ardillo_TableValueInt, isValid);
ZEND_METHOD(Ardillo_TableValueInt, get);
ZEND_METHOD(Ardillo_TableValueColor, __construct);
ZEND_METHOD(Ardillo_TableValueColor, isValid);
ZEND_METHOD(Ardillo_TableValueColor, get);


static const zend_function_entry class_Ardillo_App_methods[] = {
	ZEND_ME(Ardillo_App, get, arginfo_class_Ardillo_App_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ardillo_App, run, arginfo_class_Ardillo_App_run, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, stop, arginfo_class_Ardillo_App_stop, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, appendMenu, arginfo_class_Ardillo_App_appendMenu, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, scheduleTask, arginfo_class_Ardillo_App_scheduleTask, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, addReadStream, arginfo_class_Ardillo_App_addReadStream, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, addWriteStream, arginfo_class_Ardillo_App_addWriteStream, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, removeReadStream, arginfo_class_Ardillo_App_removeReadStream, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, removeWriteStream, arginfo_class_Ardillo_App_removeWriteStream, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, addSignal, arginfo_class_Ardillo_App_addSignal, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_App, removeSignal, arginfo_class_Ardillo_App_removeSignal, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Menu_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Task_methods[] = {
	ZEND_ME(Ardillo_Task, onExecute, arginfo_class_Ardillo_Task_onExecute, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_StreamEventHandler_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_StreamEventHandler, onReadEvent, arginfo_class_Ardillo_StreamEventHandler_onReadEvent, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_StreamEventHandler, onWriteEvent, arginfo_class_Ardillo_StreamEventHandler_onWriteEvent, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Align_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_At_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawFillMode_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_ExtKey_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Modifiers_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawBrushType_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawLineCap_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawLineJoin_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawTextAlign_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TextItalic_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_SortIndicator_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableSelectionMode_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableModelColumn_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableValueType_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TextStretch_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TextStretch_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Color_methods[] = {
	ZEND_ME(Ardillo_Color, fromRGBA, arginfo_class_Ardillo_Color_fromRGBA, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ardillo_Color, fromRGB, arginfo_class_Ardillo_Color_fromRGB, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ardillo_Color, __construct, arginfo_class_Ardillo_Color___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Point_methods[] = {
	ZEND_ME(Ardillo_Point, __construct, arginfo_class_Ardillo_Point___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Size_methods[] = {
	ZEND_ME(Ardillo_Size, __construct, arginfo_class_Ardillo_Size___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_AreaDrawParams_methods[] = {
	ZEND_ME(Ardillo_AreaDrawParams, getAreaSize, arginfo_class_Ardillo_AreaDrawParams_getAreaSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaDrawParams, getClipPoint, arginfo_class_Ardillo_AreaDrawParams_getClipPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaDrawParams, getClipSize, arginfo_class_Ardillo_AreaDrawParams_getClipSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaDrawParams, fill, arginfo_class_Ardillo_AreaDrawParams_fill, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaDrawParams, stroke, arginfo_class_Ardillo_AreaDrawParams_stroke, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaDrawParams, transform, arginfo_class_Ardillo_AreaDrawParams_transform, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_AreaHandler_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_AreaHandler, dragBrokenHandler, arginfo_class_Ardillo_AreaHandler_dragBrokenHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_AreaHandler, drawHandler, arginfo_class_Ardillo_AreaHandler_drawHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_AreaHandler, keyEventHandler, arginfo_class_Ardillo_AreaHandler_keyEventHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_AreaHandler, mouseCrossedHandler, arginfo_class_Ardillo_AreaHandler_mouseCrossedHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_AreaHandler, mouseEventHandler, arginfo_class_Ardillo_AreaHandler_mouseEventHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_AreaKeyEvent_methods[] = {
	ZEND_ME(Ardillo_AreaKeyEvent, getKey, arginfo_class_Ardillo_AreaKeyEvent_getKey, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaKeyEvent, getExtKey, arginfo_class_Ardillo_AreaKeyEvent_getExtKey, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaKeyEvent, getModifier, arginfo_class_Ardillo_AreaKeyEvent_getModifier, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaKeyEvent, getModifiers, arginfo_class_Ardillo_AreaKeyEvent_getModifiers, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaKeyEvent, getUp, arginfo_class_Ardillo_AreaKeyEvent_getUp, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_AreaMouseEvent_methods[] = {
	ZEND_ME(Ardillo_AreaMouseEvent, getPoint, arginfo_class_Ardillo_AreaMouseEvent_getPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaMouseEvent, getAreaSize, arginfo_class_Ardillo_AreaMouseEvent_getAreaSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaMouseEvent, getDown, arginfo_class_Ardillo_AreaMouseEvent_getDown, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaMouseEvent, getUp, arginfo_class_Ardillo_AreaMouseEvent_getUp, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaMouseEvent, getCount, arginfo_class_Ardillo_AreaMouseEvent_getCount, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaMouseEvent, getModifiers, arginfo_class_Ardillo_AreaMouseEvent_getModifiers, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_AreaMouseEvent, getHeld1To64, arginfo_class_Ardillo_AreaMouseEvent_getHeld1To64, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Box_methods[] = {
	ZEND_ME(Ardillo_Box, getPadded, arginfo_class_Ardillo_Box_getPadded, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Box, setPadded, arginfo_class_Ardillo_Box_setPadded, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Box, append, arginfo_class_Ardillo_Box_append, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Box, delete, arginfo_class_Ardillo_Box_delete, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Box, childrenCount, arginfo_class_Ardillo_Box_childrenCount, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Button_methods[] = {
	ZEND_ME(Ardillo_Button, __construct, arginfo_class_Ardillo_Button___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Button, isValid, arginfo_class_Ardillo_Button_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Button, getText, arginfo_class_Ardillo_Button_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Button, setText, arginfo_class_Ardillo_Button_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Button, onClicked, arginfo_class_Ardillo_Button_onClicked, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Checkbox_methods[] = {
	ZEND_ME(Ardillo_Checkbox, __construct, arginfo_class_Ardillo_Checkbox___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Checkbox, isValid, arginfo_class_Ardillo_Checkbox_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Checkbox, getChecked, arginfo_class_Ardillo_Checkbox_getChecked, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Checkbox, setChecked, arginfo_class_Ardillo_Checkbox_setChecked, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Checkbox, getText, arginfo_class_Ardillo_Checkbox_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Checkbox, setText, arginfo_class_Ardillo_Checkbox_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Checkbox, onToggled, arginfo_class_Ardillo_Checkbox_onToggled, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_ColorButton_methods[] = {
	ZEND_ME(Ardillo_ColorButton, __construct, arginfo_class_Ardillo_ColorButton___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ColorButton, isValid, arginfo_class_Ardillo_ColorButton_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ColorButton, getColor, arginfo_class_Ardillo_ColorButton_getColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ColorButton, setColor, arginfo_class_Ardillo_ColorButton_setColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ColorButton, onChanged, arginfo_class_Ardillo_ColorButton_onChanged, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Combobox_methods[] = {
	ZEND_ME(Ardillo_Combobox, __construct, arginfo_class_Ardillo_Combobox___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, isValid, arginfo_class_Ardillo_Combobox_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, getSelected, arginfo_class_Ardillo_Combobox_getSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, setSelected, arginfo_class_Ardillo_Combobox_setSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, onSelected, arginfo_class_Ardillo_Combobox_onSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, append, arginfo_class_Ardillo_Combobox_append, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, clear, arginfo_class_Ardillo_Combobox_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, delete, arginfo_class_Ardillo_Combobox_delete, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, insertAt, arginfo_class_Ardillo_Combobox_insertAt, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Combobox, numItems, arginfo_class_Ardillo_Combobox_numItems, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Control_methods[] = {
	ZEND_ME(Ardillo_Control, disable, arginfo_class_Ardillo_Control_disable, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, enable, arginfo_class_Ardillo_Control_enable, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, isEnabled, arginfo_class_Ardillo_Control_isEnabled, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, isEnabledToUser, arginfo_class_Ardillo_Control_isEnabledToUser, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, hide, arginfo_class_Ardillo_Control_hide, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, show, arginfo_class_Ardillo_Control_show, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, isTopLevel, arginfo_class_Ardillo_Control_isTopLevel, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Control, isVisible, arginfo_class_Ardillo_Control_isVisible, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DateTimePicker_methods[] = {
	ZEND_ME(Ardillo_DateTimePicker, __construct, arginfo_class_Ardillo_DateTimePicker___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DateTimePicker, isValid, arginfo_class_Ardillo_DateTimePicker_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DateTimePicker, getTime, arginfo_class_Ardillo_DateTimePicker_getTime, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DateTimePicker, setTime, arginfo_class_Ardillo_DateTimePicker_setTime, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DateTimePicker, onChanged, arginfo_class_Ardillo_DateTimePicker_onChanged, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawBrush_methods[] = {
	ZEND_ME(Ardillo_DrawBrush, isValid, arginfo_class_Ardillo_DrawBrush_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getType, arginfo_class_Ardillo_DrawBrush_getType, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setType, arginfo_class_Ardillo_DrawBrush_setType, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getColor, arginfo_class_Ardillo_DrawBrush_getColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setColor, arginfo_class_Ardillo_DrawBrush_setColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getPoint0, arginfo_class_Ardillo_DrawBrush_getPoint0, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setPoint0, arginfo_class_Ardillo_DrawBrush_setPoint0, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getPoint1, arginfo_class_Ardillo_DrawBrush_getPoint1, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setPoint1, arginfo_class_Ardillo_DrawBrush_setPoint1, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getOuterRadius, arginfo_class_Ardillo_DrawBrush_getOuterRadius, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setOuterRadius, arginfo_class_Ardillo_DrawBrush_setOuterRadius, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getStops, arginfo_class_Ardillo_DrawBrush_getStops, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setStops, arginfo_class_Ardillo_DrawBrush_setStops, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, getNumStops, arginfo_class_Ardillo_DrawBrush_getNumStops, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrush, setNumStops, arginfo_class_Ardillo_DrawBrush_setNumStops, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawBrushGradientStop_methods[] = {
	ZEND_ME(Ardillo_DrawBrushGradientStop, getPos, arginfo_class_Ardillo_DrawBrushGradientStop_getPos, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrushGradientStop, setPos, arginfo_class_Ardillo_DrawBrushGradientStop_setPos, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrushGradientStop, getColor, arginfo_class_Ardillo_DrawBrushGradientStop_getColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawBrushGradientStop, setColor, arginfo_class_Ardillo_DrawBrushGradientStop_setColor, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawMatrix_methods[] = {
	ZEND_ME(Ardillo_DrawMatrix, isValid, arginfo_class_Ardillo_DrawMatrix_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawMatrix, setIdentity, arginfo_class_Ardillo_DrawMatrix_setIdentity, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawMatrix, translate, arginfo_class_Ardillo_DrawMatrix_translate, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawStrokeParams_methods[] = {
	ZEND_ME(Ardillo_DrawStrokeParams, isValid, arginfo_class_Ardillo_DrawStrokeParams_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getCap, arginfo_class_Ardillo_DrawStrokeParams_getCap, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setCap, arginfo_class_Ardillo_DrawStrokeParams_setCap, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getJoin, arginfo_class_Ardillo_DrawStrokeParams_getJoin, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setJoin, arginfo_class_Ardillo_DrawStrokeParams_setJoin, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getThickness, arginfo_class_Ardillo_DrawStrokeParams_getThickness, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setThickness, arginfo_class_Ardillo_DrawStrokeParams_setThickness, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getMiterLimit, arginfo_class_Ardillo_DrawStrokeParams_getMiterLimit, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setMiterLimit, arginfo_class_Ardillo_DrawStrokeParams_setMiterLimit, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getDashes, arginfo_class_Ardillo_DrawStrokeParams_getDashes, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setDashes, arginfo_class_Ardillo_DrawStrokeParams_setDashes, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getNumDashes, arginfo_class_Ardillo_DrawStrokeParams_getNumDashes, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setNumDashes, arginfo_class_Ardillo_DrawStrokeParams_setNumDashes, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, getDashPhase, arginfo_class_Ardillo_DrawStrokeParams_getDashPhase, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawStrokeParams, setDashPhase, arginfo_class_Ardillo_DrawStrokeParams_setDashPhase, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawTextLayoutParams_methods[] = {
	ZEND_ME(Ardillo_DrawTextLayoutParams, getDefaultFont, arginfo_class_Ardillo_DrawTextLayoutParams_getDefaultFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawTextLayoutParams, setDefaultFont, arginfo_class_Ardillo_DrawTextLayoutParams_setDefaultFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawTextLayoutParams, getWidth, arginfo_class_Ardillo_DrawTextLayoutParams_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawTextLayoutParams, setWidth, arginfo_class_Ardillo_DrawTextLayoutParams_setWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawTextLayoutParams, getAlign, arginfo_class_Ardillo_DrawTextLayoutParams_getAlign, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawTextLayoutParams, setAlign, arginfo_class_Ardillo_DrawTextLayoutParams_setAlign, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_EditableCombobox_methods[] = {
	ZEND_ME(Ardillo_EditableCombobox, __construct, arginfo_class_Ardillo_EditableCombobox___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_EditableCombobox, isValid, arginfo_class_Ardillo_EditableCombobox_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_EditableCombobox, getText, arginfo_class_Ardillo_EditableCombobox_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_EditableCombobox, setText, arginfo_class_Ardillo_EditableCombobox_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_EditableCombobox, onChanged, arginfo_class_Ardillo_EditableCombobox_onChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_EditableCombobox, append, arginfo_class_Ardillo_EditableCombobox_append, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Entry_methods[] = {
	ZEND_ME(Ardillo_Entry, __construct, arginfo_class_Ardillo_Entry___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Entry, isValid, arginfo_class_Ardillo_Entry_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Entry, getReadOnly, arginfo_class_Ardillo_Entry_getReadOnly, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Entry, setReadOnly, arginfo_class_Ardillo_Entry_setReadOnly, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Entry, getText, arginfo_class_Ardillo_Entry_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Entry, setText, arginfo_class_Ardillo_Entry_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Entry, onChanged, arginfo_class_Ardillo_Entry_onChanged, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_FontButton_methods[] = {
	ZEND_ME(Ardillo_FontButton, __construct, arginfo_class_Ardillo_FontButton___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontButton, isValid, arginfo_class_Ardillo_FontButton_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontButton, onChanged, arginfo_class_Ardillo_FontButton_onChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontButton, getFont, arginfo_class_Ardillo_FontButton_getFont, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_FontDescriptor_methods[] = {
	ZEND_ME(Ardillo_FontDescriptor, getFamily, arginfo_class_Ardillo_FontDescriptor_getFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, setFamily, arginfo_class_Ardillo_FontDescriptor_setFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, getSize, arginfo_class_Ardillo_FontDescriptor_getSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, setSize, arginfo_class_Ardillo_FontDescriptor_setSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, getWeight, arginfo_class_Ardillo_FontDescriptor_getWeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, setWeight, arginfo_class_Ardillo_FontDescriptor_setWeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, getItalic, arginfo_class_Ardillo_FontDescriptor_getItalic, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, setItalic, arginfo_class_Ardillo_FontDescriptor_setItalic, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, getStretch, arginfo_class_Ardillo_FontDescriptor_getStretch, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_FontDescriptor, setStretch, arginfo_class_Ardillo_FontDescriptor_setStretch, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Form_methods[] = {
	ZEND_ME(Ardillo_Form, __construct, arginfo_class_Ardillo_Form___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Form, isValid, arginfo_class_Ardillo_Form_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Form, getPadded, arginfo_class_Ardillo_Form_getPadded, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Form, setPadded, arginfo_class_Ardillo_Form_setPadded, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Form, append, arginfo_class_Ardillo_Form_append, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Form, delete, arginfo_class_Ardillo_Form_delete, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Form, childrenCount, arginfo_class_Ardillo_Form_childrenCount, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Grid_methods[] = {
	ZEND_ME(Ardillo_Grid, __construct, arginfo_class_Ardillo_Grid___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Grid, isValid, arginfo_class_Ardillo_Grid_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Grid, getPadded, arginfo_class_Ardillo_Grid_getPadded, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Grid, setPadded, arginfo_class_Ardillo_Grid_setPadded, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Grid, append, arginfo_class_Ardillo_Grid_append, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Grid, insertAt, arginfo_class_Ardillo_Grid_insertAt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Group_methods[] = {
	ZEND_ME(Ardillo_Group, __construct, arginfo_class_Ardillo_Group___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Group, isValid, arginfo_class_Ardillo_Group_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Group, getMargined, arginfo_class_Ardillo_Group_getMargined, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Group, setMargined, arginfo_class_Ardillo_Group_setMargined, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Group, getTitle, arginfo_class_Ardillo_Group_getTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Group, setTitle, arginfo_class_Ardillo_Group_setTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Group, setChild, arginfo_class_Ardillo_Group_setChild, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Image_methods[] = {
	ZEND_ME(Ardillo_Image, __construct, arginfo_class_Ardillo_Image___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Image, isValid, arginfo_class_Ardillo_Image_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Image, append, arginfo_class_Ardillo_Image_append, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Label_methods[] = {
	ZEND_ME(Ardillo_Label, __construct, arginfo_class_Ardillo_Label___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Label, isValid, arginfo_class_Ardillo_Label_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Label, getText, arginfo_class_Ardillo_Label_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Label, setText, arginfo_class_Ardillo_Label_setText, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_MultilineEntry_methods[] = {
	ZEND_ME(Ardillo_MultilineEntry, __construct, arginfo_class_Ardillo_MultilineEntry___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, isValid, arginfo_class_Ardillo_MultilineEntry_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, getReadOnly, arginfo_class_Ardillo_MultilineEntry_getReadOnly, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, setReadOnly, arginfo_class_Ardillo_MultilineEntry_setReadOnly, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, getText, arginfo_class_Ardillo_MultilineEntry_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, setText, arginfo_class_Ardillo_MultilineEntry_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, onChanged, arginfo_class_Ardillo_MultilineEntry_onChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_MultilineEntry, append, arginfo_class_Ardillo_MultilineEntry_append, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_ProgressBar_methods[] = {
	ZEND_ME(Ardillo_ProgressBar, __construct, arginfo_class_Ardillo_ProgressBar___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ProgressBar, isValid, arginfo_class_Ardillo_ProgressBar_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ProgressBar, getValue, arginfo_class_Ardillo_ProgressBar_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_ProgressBar, setValue, arginfo_class_Ardillo_ProgressBar_setValue, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_RadioButtons_methods[] = {
	ZEND_ME(Ardillo_RadioButtons, __construct, arginfo_class_Ardillo_RadioButtons___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_RadioButtons, isValid, arginfo_class_Ardillo_RadioButtons_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_RadioButtons, getSelected, arginfo_class_Ardillo_RadioButtons_getSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_RadioButtons, setSelected, arginfo_class_Ardillo_RadioButtons_setSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_RadioButtons, onSelected, arginfo_class_Ardillo_RadioButtons_onSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_RadioButtons, append, arginfo_class_Ardillo_RadioButtons_append, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Separator_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Slider_methods[] = {
	ZEND_ME(Ardillo_Slider, __construct, arginfo_class_Ardillo_Slider___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, isValid, arginfo_class_Ardillo_Slider_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, getHasToolTip, arginfo_class_Ardillo_Slider_getHasToolTip, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, setHasToolTip, arginfo_class_Ardillo_Slider_setHasToolTip, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, getValue, arginfo_class_Ardillo_Slider_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, setValue, arginfo_class_Ardillo_Slider_setValue, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, onChanged, arginfo_class_Ardillo_Slider_onChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, onReleased, arginfo_class_Ardillo_Slider_onReleased, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Slider, setRange, arginfo_class_Ardillo_Slider_setRange, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Spinbox_methods[] = {
	ZEND_ME(Ardillo_Spinbox, __construct, arginfo_class_Ardillo_Spinbox___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Spinbox, isValid, arginfo_class_Ardillo_Spinbox_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Spinbox, getValue, arginfo_class_Ardillo_Spinbox_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Spinbox, setValue, arginfo_class_Ardillo_Spinbox_setValue, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Spinbox, onChanged, arginfo_class_Ardillo_Spinbox_onChanged, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Tab_methods[] = {
	ZEND_ME(Ardillo_Tab, __construct, arginfo_class_Ardillo_Tab___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, isValid, arginfo_class_Ardillo_Tab_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, getMargined, arginfo_class_Ardillo_Tab_getMargined, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, setMargined, arginfo_class_Ardillo_Tab_setMargined, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, append, arginfo_class_Ardillo_Tab_append, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, delete, arginfo_class_Ardillo_Tab_delete, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, insertAt, arginfo_class_Ardillo_Tab_insertAt, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Tab, pageCount, arginfo_class_Ardillo_Tab_pageCount, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Table_methods[] = {
	ZEND_ME(Ardillo_Table, __construct, arginfo_class_Ardillo_Table___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, isValid, arginfo_class_Ardillo_Table_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, getColumnWidth, arginfo_class_Ardillo_Table_getColumnWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, setColumnWidth, arginfo_class_Ardillo_Table_setColumnWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, getHeaderSortIndicator, arginfo_class_Ardillo_Table_getHeaderSortIndicator, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, setHeaderSortIndicator, arginfo_class_Ardillo_Table_setHeaderSortIndicator, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, getHeaderVisible, arginfo_class_Ardillo_Table_getHeaderVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, setHeaderVisible, arginfo_class_Ardillo_Table_setHeaderVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, getSelectionMode, arginfo_class_Ardillo_Table_getSelectionMode, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, setSelectionMode, arginfo_class_Ardillo_Table_setSelectionMode, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, onHeaderClicked, arginfo_class_Ardillo_Table_onHeaderClicked, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, onRowClicked, arginfo_class_Ardillo_Table_onRowClicked, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, onRowDoubleClicked, arginfo_class_Ardillo_Table_onRowDoubleClicked, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendButtonColumn, arginfo_class_Ardillo_Table_appendButtonColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendCheckboxColumn, arginfo_class_Ardillo_Table_appendCheckboxColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendCheckboxTextColumn, arginfo_class_Ardillo_Table_appendCheckboxTextColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendImageColumn, arginfo_class_Ardillo_Table_appendImageColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendImageTextColumn, arginfo_class_Ardillo_Table_appendImageTextColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendProgressBarColumn, arginfo_class_Ardillo_Table_appendProgressBarColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, appendTextColumn, arginfo_class_Ardillo_Table_appendTextColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, onSelectionChanged, arginfo_class_Ardillo_Table_onSelectionChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Table, setSelection, arginfo_class_Ardillo_Table_setSelection, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableModel_methods[] = {
	ZEND_ME(Ardillo_TableModel, __construct, arginfo_class_Ardillo_TableModel___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableModel, isValid, arginfo_class_Ardillo_TableModel_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableModel, rowChanged, arginfo_class_Ardillo_TableModel_rowChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableModel, rowDeleted, arginfo_class_Ardillo_TableModel_rowDeleted, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableModel, rowInserted, arginfo_class_Ardillo_TableModel_rowInserted, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableModelHandler_methods[] = {
	ZEND_ME(Ardillo_TableModelHandler, isValid, arginfo_class_Ardillo_TableModelHandler_isValid, ZEND_ACC_PUBLIC)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_TableModelHandler, cellValueHandler, arginfo_class_Ardillo_TableModelHandler_cellValueHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_TableModelHandler, columnTypeHandler, arginfo_class_Ardillo_TableModelHandler_columnTypeHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_TableModelHandler, numColumnsHandler, arginfo_class_Ardillo_TableModelHandler_numColumnsHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_TableModelHandler, numRowsHandler, arginfo_class_Ardillo_TableModelHandler_numRowsHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ABSTRACT_ME_WITH_FLAGS(Ardillo_TableModelHandler, setCellValueHandler, arginfo_class_Ardillo_TableModelHandler_setCellValueHandler, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableParams_methods[] = {
	ZEND_ME(Ardillo_TableParams, isValid, arginfo_class_Ardillo_TableParams_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableParams, getModel, arginfo_class_Ardillo_TableParams_getModel, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableParams, setModel, arginfo_class_Ardillo_TableParams_setModel, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableParams, getRowBackgroundColorModelColumn, arginfo_class_Ardillo_TableParams_getRowBackgroundColorModelColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableParams, setRowBackgroundColorModelColumn, arginfo_class_Ardillo_TableParams_setRowBackgroundColorModelColumn, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableTextColumnOptionalParams_methods[] = {
	ZEND_ME(Ardillo_TableTextColumnOptionalParams, isValid, arginfo_class_Ardillo_TableTextColumnOptionalParams_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableTextColumnOptionalParams, getColorModelColumn, arginfo_class_Ardillo_TableTextColumnOptionalParams_getColorModelColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableTextColumnOptionalParams, setColorModelColumn, arginfo_class_Ardillo_TableTextColumnOptionalParams_setColorModelColumn, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableValue_methods[] = {
	ZEND_ME(Ardillo_TableValue, getType, arginfo_class_Ardillo_TableValue_getType, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Window_methods[] = {
	ZEND_ME(Ardillo_Window, __construct, arginfo_class_Ardillo_Window___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, isValid, arginfo_class_Ardillo_Window_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getBorderless, arginfo_class_Ardillo_Window_getBorderless, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setBorderless, arginfo_class_Ardillo_Window_setBorderless, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getContentSize, arginfo_class_Ardillo_Window_getContentSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setContentSize, arginfo_class_Ardillo_Window_setContentSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getFullscreen, arginfo_class_Ardillo_Window_getFullscreen, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setFullscreen, arginfo_class_Ardillo_Window_setFullscreen, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getMargined, arginfo_class_Ardillo_Window_getMargined, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setMargined, arginfo_class_Ardillo_Window_setMargined, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getPosition, arginfo_class_Ardillo_Window_getPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setPosition, arginfo_class_Ardillo_Window_setPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getResizeable, arginfo_class_Ardillo_Window_getResizeable, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setResizeable, arginfo_class_Ardillo_Window_setResizeable, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, getTitle, arginfo_class_Ardillo_Window_getTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setTitle, arginfo_class_Ardillo_Window_setTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, onClosing, arginfo_class_Ardillo_Window_onClosing, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, onContentSizeChanged, arginfo_class_Ardillo_Window_onContentSizeChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, onFocusChanged, arginfo_class_Ardillo_Window_onFocusChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, onPositionChanged, arginfo_class_Ardillo_Window_onPositionChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, isFocused, arginfo_class_Ardillo_Window_isFocused, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, setChild, arginfo_class_Ardillo_Window_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, messageBox, arginfo_class_Ardillo_Window_messageBox, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, openFolder, arginfo_class_Ardillo_Window_openFolder, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, openFile, arginfo_class_Ardillo_Window_openFile, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Window, saveFile, arginfo_class_Ardillo_Window_saveFile, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_Area_methods[] = {
	ZEND_ME(Ardillo_Area, __construct, arginfo_class_Ardillo_Area___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Area, isValid, arginfo_class_Ardillo_Area_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_Area, queueRedrawAll, arginfo_class_Ardillo_Area_queueRedrawAll, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DrawPath_methods[] = {
	ZEND_ME(Ardillo_DrawPath, __construct, arginfo_class_Ardillo_DrawPath___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawPath, isValid, arginfo_class_Ardillo_DrawPath_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawPath, addRectangle, arginfo_class_Ardillo_DrawPath_addRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawPath, newFigure, arginfo_class_Ardillo_DrawPath_newFigure, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawPath, closeFigure, arginfo_class_Ardillo_DrawPath_closeFigure, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawPath, lineTo, arginfo_class_Ardillo_DrawPath_lineTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DrawPath, end, arginfo_class_Ardillo_DrawPath_end, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_HorizontalBox_methods[] = {
	ZEND_ME(Ardillo_HorizontalBox, __construct, arginfo_class_Ardillo_HorizontalBox___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_HorizontalBox, isValid, arginfo_class_Ardillo_HorizontalBox_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_VerticalBox_methods[] = {
	ZEND_ME(Ardillo_VerticalBox, __construct, arginfo_class_Ardillo_VerticalBox___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_VerticalBox, isValid, arginfo_class_Ardillo_VerticalBox_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_DatePicker_methods[] = {
	ZEND_ME(Ardillo_DatePicker, __construct, arginfo_class_Ardillo_DatePicker___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_DatePicker, isValid, arginfo_class_Ardillo_DatePicker_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TimePicker_methods[] = {
	ZEND_ME(Ardillo_TimePicker, __construct, arginfo_class_Ardillo_TimePicker___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TimePicker, isValid, arginfo_class_Ardillo_TimePicker_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_PasswordEntry_methods[] = {
	ZEND_ME(Ardillo_PasswordEntry, __construct, arginfo_class_Ardillo_PasswordEntry___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_PasswordEntry, isValid, arginfo_class_Ardillo_PasswordEntry_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_SearchEntry_methods[] = {
	ZEND_ME(Ardillo_SearchEntry, __construct, arginfo_class_Ardillo_SearchEntry___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_SearchEntry, isValid, arginfo_class_Ardillo_SearchEntry_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_NonWrappingMultilineEntry_methods[] = {
	ZEND_ME(Ardillo_NonWrappingMultilineEntry, __construct, arginfo_class_Ardillo_NonWrappingMultilineEntry___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_NonWrappingMultilineEntry, isValid, arginfo_class_Ardillo_NonWrappingMultilineEntry_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_HorizontalSeparator_methods[] = {
	ZEND_ME(Ardillo_HorizontalSeparator, __construct, arginfo_class_Ardillo_HorizontalSeparator___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_HorizontalSeparator, isValid, arginfo_class_Ardillo_HorizontalSeparator_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_VerticalSeparator_methods[] = {
	ZEND_ME(Ardillo_VerticalSeparator, __construct, arginfo_class_Ardillo_VerticalSeparator___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_VerticalSeparator, isValid, arginfo_class_Ardillo_VerticalSeparator_isValid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableValueString_methods[] = {
	ZEND_ME(Ardillo_TableValueString, __construct, arginfo_class_Ardillo_TableValueString___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueString, isValid, arginfo_class_Ardillo_TableValueString_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueString, get, arginfo_class_Ardillo_TableValueString_get, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableValueImage_methods[] = {
	ZEND_ME(Ardillo_TableValueImage, __construct, arginfo_class_Ardillo_TableValueImage___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueImage, isValid, arginfo_class_Ardillo_TableValueImage_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueImage, get, arginfo_class_Ardillo_TableValueImage_get, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableValueInt_methods[] = {
	ZEND_ME(Ardillo_TableValueInt, __construct, arginfo_class_Ardillo_TableValueInt___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueInt, isValid, arginfo_class_Ardillo_TableValueInt_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueInt, get, arginfo_class_Ardillo_TableValueInt_get, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ardillo_TableValueColor_methods[] = {
	ZEND_ME(Ardillo_TableValueColor, __construct, arginfo_class_Ardillo_TableValueColor___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueColor, isValid, arginfo_class_Ardillo_TableValueColor_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ardillo_TableValueColor, get, arginfo_class_Ardillo_TableValueColor_get, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ardillo_App(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "App", class_Ardillo_App_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_SIGHUP_value;
	ZVAL_LONG(&const_SIGHUP_value, 1);
	zend_string *const_SIGHUP_name = zend_string_init_interned("SIGHUP", sizeof("SIGHUP") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGHUP_name, &const_SIGHUP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGHUP_name);

	zval const_SIGINT_value;
	ZVAL_LONG(&const_SIGINT_value, 2);
	zend_string *const_SIGINT_name = zend_string_init_interned("SIGINT", sizeof("SIGINT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGINT_name, &const_SIGINT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGINT_name);

	zval const_SIGQUIT_value;
	ZVAL_LONG(&const_SIGQUIT_value, 3);
	zend_string *const_SIGQUIT_name = zend_string_init_interned("SIGQUIT", sizeof("SIGQUIT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGQUIT_name, &const_SIGQUIT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGQUIT_name);

	zval const_SIGILL_value;
	ZVAL_LONG(&const_SIGILL_value, 4);
	zend_string *const_SIGILL_name = zend_string_init_interned("SIGILL", sizeof("SIGILL") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGILL_name, &const_SIGILL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGILL_name);

	zval const_SIGTRAP_value;
	ZVAL_LONG(&const_SIGTRAP_value, 5);
	zend_string *const_SIGTRAP_name = zend_string_init_interned("SIGTRAP", sizeof("SIGTRAP") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGTRAP_name, &const_SIGTRAP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGTRAP_name);

	zval const_SIGABRT_value;
	ZVAL_LONG(&const_SIGABRT_value, 6);
	zend_string *const_SIGABRT_name = zend_string_init_interned("SIGABRT", sizeof("SIGABRT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGABRT_name, &const_SIGABRT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGABRT_name);

	zval const_SIGFPE_value;
	ZVAL_LONG(&const_SIGFPE_value, 8);
	zend_string *const_SIGFPE_name = zend_string_init_interned("SIGFPE", sizeof("SIGFPE") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGFPE_name, &const_SIGFPE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGFPE_name);

	zval const_SIGKILL_value;
	ZVAL_LONG(&const_SIGKILL_value, 9);
	zend_string *const_SIGKILL_name = zend_string_init_interned("SIGKILL", sizeof("SIGKILL") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGKILL_name, &const_SIGKILL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGKILL_name);

	zval const_SIGSEGV_value;
	ZVAL_LONG(&const_SIGSEGV_value, 11);
	zend_string *const_SIGSEGV_name = zend_string_init_interned("SIGSEGV", sizeof("SIGSEGV") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGSEGV_name, &const_SIGSEGV_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGSEGV_name);

	zval const_SIGPIPE_value;
	ZVAL_LONG(&const_SIGPIPE_value, 13);
	zend_string *const_SIGPIPE_name = zend_string_init_interned("SIGPIPE", sizeof("SIGPIPE") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGPIPE_name, &const_SIGPIPE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGPIPE_name);

	zval const_SIGALRM_value;
	ZVAL_LONG(&const_SIGALRM_value, 14);
	zend_string *const_SIGALRM_name = zend_string_init_interned("SIGALRM", sizeof("SIGALRM") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGALRM_name, &const_SIGALRM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGALRM_name);

	zval const_SIGTERM_value;
	ZVAL_LONG(&const_SIGTERM_value, 15);
	zend_string *const_SIGTERM_name = zend_string_init_interned("SIGTERM", sizeof("SIGTERM") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SIGTERM_name, &const_SIGTERM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SIGTERM_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Menu(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Menu", class_Ardillo_Menu_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;

	zval const_Top_value;
	ZVAL_LONG(&const_Top_value, 0);
	zend_string *const_Top_name = zend_string_init_interned("Top", sizeof("Top") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Top_name, &const_Top_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Top_name);

	zval const_Separator_value;
	ZVAL_LONG(&const_Separator_value, 1);
	zend_string *const_Separator_name = zend_string_init_interned("Separator", sizeof("Separator") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Separator_name, &const_Separator_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Separator_name);

	zval const_Quit_value;
	ZVAL_LONG(&const_Quit_value, 2);
	zend_string *const_Quit_name = zend_string_init_interned("Quit", sizeof("Quit") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Quit_name, &const_Quit_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Quit_name);

	zval const_Preferences_value;
	ZVAL_LONG(&const_Preferences_value, 3);
	zend_string *const_Preferences_name = zend_string_init_interned("Preferences", sizeof("Preferences") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Preferences_name, &const_Preferences_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Preferences_name);

	zval const_About_value;
	ZVAL_LONG(&const_About_value, 4);
	zend_string *const_About_name = zend_string_init_interned("About", sizeof("About") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_About_name, &const_About_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_About_name);

	zval const_CheckItem_value;
	ZVAL_LONG(&const_CheckItem_value, 5);
	zend_string *const_CheckItem_name = zend_string_init_interned("CheckItem", sizeof("CheckItem") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_CheckItem_name, &const_CheckItem_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_CheckItem_name);

	zval const_Item_value;
	ZVAL_LONG(&const_Item_value, 6);
	zend_string *const_Item_name = zend_string_init_interned("Item", sizeof("Item") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Item_name, &const_Item_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Item_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Task(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Task", class_Ardillo_Task_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_suspended_default_value;
	ZVAL_FALSE(&property_suspended_default_value);
	zend_string *property_suspended_name = zend_string_init("suspended", sizeof("suspended") - 1, 1);
	zend_declare_typed_property(class_entry, property_suspended_name, &property_suspended_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_suspended_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_StreamEventHandler(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "StreamEventHandler", class_Ardillo_StreamEventHandler_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Align(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Align", class_Ardillo_Align_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Fill_value;
	ZVAL_LONG(&const_Fill_value, 0);
	zend_string *const_Fill_name = zend_string_init_interned("Fill", sizeof("Fill") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Fill_name, &const_Fill_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Fill_name);

	zval const_Start_value;
	ZVAL_LONG(&const_Start_value, 1);
	zend_string *const_Start_name = zend_string_init_interned("Start", sizeof("Start") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Start_name, &const_Start_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Start_name);

	zval const_Center_value;
	ZVAL_LONG(&const_Center_value, 2);
	zend_string *const_Center_name = zend_string_init_interned("Center", sizeof("Center") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Center_name, &const_Center_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Center_name);

	zval const_End_value;
	ZVAL_LONG(&const_End_value, 3);
	zend_string *const_End_name = zend_string_init_interned("End", sizeof("End") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_End_name, &const_End_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_End_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_At(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "At", class_Ardillo_At_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Leading_value;
	ZVAL_LONG(&const_Leading_value, 0);
	zend_string *const_Leading_name = zend_string_init_interned("Leading", sizeof("Leading") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Leading_name, &const_Leading_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Leading_name);

	zval const_Top_value;
	ZVAL_LONG(&const_Top_value, 1);
	zend_string *const_Top_name = zend_string_init_interned("Top", sizeof("Top") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Top_name, &const_Top_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Top_name);

	zval const_Trailing_value;
	ZVAL_LONG(&const_Trailing_value, 2);
	zend_string *const_Trailing_name = zend_string_init_interned("Trailing", sizeof("Trailing") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Trailing_name, &const_Trailing_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Trailing_name);

	zval const_Bottom_value;
	ZVAL_LONG(&const_Bottom_value, 3);
	zend_string *const_Bottom_name = zend_string_init_interned("Bottom", sizeof("Bottom") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Bottom_name, &const_Bottom_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Bottom_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawFillMode(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawFillMode", class_Ardillo_DrawFillMode_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Winding_value;
	ZVAL_LONG(&const_Winding_value, 0);
	zend_string *const_Winding_name = zend_string_init_interned("Winding", sizeof("Winding") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Winding_name, &const_Winding_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Winding_name);

	zval const_Alternate_value;
	ZVAL_LONG(&const_Alternate_value, 1);
	zend_string *const_Alternate_name = zend_string_init_interned("Alternate", sizeof("Alternate") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Alternate_name, &const_Alternate_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Alternate_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_ExtKey(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "ExtKey", class_Ardillo_ExtKey_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Escape_value;
	ZVAL_LONG(&const_Escape_value, 1);
	zend_string *const_Escape_name = zend_string_init_interned("Escape", sizeof("Escape") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Escape_name, &const_Escape_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Escape_name);

	zval const_Insert_value;
	ZVAL_LONG(&const_Insert_value, 2);
	zend_string *const_Insert_name = zend_string_init_interned("Insert", sizeof("Insert") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Insert_name, &const_Insert_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Insert_name);

	zval const_Delete_value;
	ZVAL_LONG(&const_Delete_value, 3);
	zend_string *const_Delete_name = zend_string_init_interned("Delete", sizeof("Delete") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Delete_name, &const_Delete_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Delete_name);

	zval const_Home_value;
	ZVAL_LONG(&const_Home_value, 4);
	zend_string *const_Home_name = zend_string_init_interned("Home", sizeof("Home") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Home_name, &const_Home_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Home_name);

	zval const_End_value;
	ZVAL_LONG(&const_End_value, 5);
	zend_string *const_End_name = zend_string_init_interned("End", sizeof("End") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_End_name, &const_End_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_End_name);

	zval const_PageUp_value;
	ZVAL_LONG(&const_PageUp_value, 6);
	zend_string *const_PageUp_name = zend_string_init_interned("PageUp", sizeof("PageUp") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_PageUp_name, &const_PageUp_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_PageUp_name);

	zval const_PageDown_value;
	ZVAL_LONG(&const_PageDown_value, 7);
	zend_string *const_PageDown_name = zend_string_init_interned("PageDown", sizeof("PageDown") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_PageDown_name, &const_PageDown_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_PageDown_name);

	zval const_Up_value;
	ZVAL_LONG(&const_Up_value, 8);
	zend_string *const_Up_name = zend_string_init_interned("Up", sizeof("Up") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Up_name, &const_Up_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Up_name);

	zval const_Down_value;
	ZVAL_LONG(&const_Down_value, 9);
	zend_string *const_Down_name = zend_string_init_interned("Down", sizeof("Down") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Down_name, &const_Down_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Down_name);

	zval const_Left_value;
	ZVAL_LONG(&const_Left_value, 10);
	zend_string *const_Left_name = zend_string_init_interned("Left", sizeof("Left") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Left_name, &const_Left_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Left_name);

	zval const_Right_value;
	ZVAL_LONG(&const_Right_value, 11);
	zend_string *const_Right_name = zend_string_init_interned("Right", sizeof("Right") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Right_name, &const_Right_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Right_name);

	zval const_F1_value;
	ZVAL_LONG(&const_F1_value, 12);
	zend_string *const_F1_name = zend_string_init_interned("F1", sizeof("F1") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F1_name, &const_F1_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F1_name);

	zval const_F2_value;
	ZVAL_LONG(&const_F2_value, 13);
	zend_string *const_F2_name = zend_string_init_interned("F2", sizeof("F2") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F2_name, &const_F2_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F2_name);

	zval const_F3_value;
	ZVAL_LONG(&const_F3_value, 14);
	zend_string *const_F3_name = zend_string_init_interned("F3", sizeof("F3") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F3_name, &const_F3_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F3_name);

	zval const_F4_value;
	ZVAL_LONG(&const_F4_value, 15);
	zend_string *const_F4_name = zend_string_init_interned("F4", sizeof("F4") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F4_name, &const_F4_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F4_name);

	zval const_F5_value;
	ZVAL_LONG(&const_F5_value, 16);
	zend_string *const_F5_name = zend_string_init_interned("F5", sizeof("F5") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F5_name, &const_F5_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F5_name);

	zval const_F6_value;
	ZVAL_LONG(&const_F6_value, 17);
	zend_string *const_F6_name = zend_string_init_interned("F6", sizeof("F6") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F6_name, &const_F6_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F6_name);

	zval const_F7_value;
	ZVAL_LONG(&const_F7_value, 18);
	zend_string *const_F7_name = zend_string_init_interned("F7", sizeof("F7") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F7_name, &const_F7_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F7_name);

	zval const_F8_value;
	ZVAL_LONG(&const_F8_value, 19);
	zend_string *const_F8_name = zend_string_init_interned("F8", sizeof("F8") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F8_name, &const_F8_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F8_name);

	zval const_F9_value;
	ZVAL_LONG(&const_F9_value, 20);
	zend_string *const_F9_name = zend_string_init_interned("F9", sizeof("F9") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F9_name, &const_F9_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F9_name);

	zval const_F10_value;
	ZVAL_LONG(&const_F10_value, 21);
	zend_string *const_F10_name = zend_string_init_interned("F10", sizeof("F10") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F10_name, &const_F10_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F10_name);

	zval const_F11_value;
	ZVAL_LONG(&const_F11_value, 22);
	zend_string *const_F11_name = zend_string_init_interned("F11", sizeof("F11") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F11_name, &const_F11_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F11_name);

	zval const_F12_value;
	ZVAL_LONG(&const_F12_value, 23);
	zend_string *const_F12_name = zend_string_init_interned("F12", sizeof("F12") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_F12_name, &const_F12_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_F12_name);

	zval const_N0_value;
	ZVAL_LONG(&const_N0_value, 24);
	zend_string *const_N0_name = zend_string_init_interned("N0", sizeof("N0") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N0_name, &const_N0_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N0_name);

	zval const_N1_value;
	ZVAL_LONG(&const_N1_value, 25);
	zend_string *const_N1_name = zend_string_init_interned("N1", sizeof("N1") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N1_name, &const_N1_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N1_name);

	zval const_N2_value;
	ZVAL_LONG(&const_N2_value, 26);
	zend_string *const_N2_name = zend_string_init_interned("N2", sizeof("N2") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N2_name, &const_N2_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N2_name);

	zval const_N3_value;
	ZVAL_LONG(&const_N3_value, 27);
	zend_string *const_N3_name = zend_string_init_interned("N3", sizeof("N3") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N3_name, &const_N3_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N3_name);

	zval const_N4_value;
	ZVAL_LONG(&const_N4_value, 28);
	zend_string *const_N4_name = zend_string_init_interned("N4", sizeof("N4") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N4_name, &const_N4_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N4_name);

	zval const_N5_value;
	ZVAL_LONG(&const_N5_value, 29);
	zend_string *const_N5_name = zend_string_init_interned("N5", sizeof("N5") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N5_name, &const_N5_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N5_name);

	zval const_N6_value;
	ZVAL_LONG(&const_N6_value, 30);
	zend_string *const_N6_name = zend_string_init_interned("N6", sizeof("N6") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N6_name, &const_N6_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N6_name);

	zval const_N7_value;
	ZVAL_LONG(&const_N7_value, 31);
	zend_string *const_N7_name = zend_string_init_interned("N7", sizeof("N7") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N7_name, &const_N7_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N7_name);

	zval const_N8_value;
	ZVAL_LONG(&const_N8_value, 32);
	zend_string *const_N8_name = zend_string_init_interned("N8", sizeof("N8") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N8_name, &const_N8_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N8_name);

	zval const_N9_value;
	ZVAL_LONG(&const_N9_value, 33);
	zend_string *const_N9_name = zend_string_init_interned("N9", sizeof("N9") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_N9_name, &const_N9_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_N9_name);

	zval const_NDot_value;
	ZVAL_LONG(&const_NDot_value, 34);
	zend_string *const_NDot_name = zend_string_init_interned("NDot", sizeof("NDot") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NDot_name, &const_NDot_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NDot_name);

	zval const_NEnter_value;
	ZVAL_LONG(&const_NEnter_value, 35);
	zend_string *const_NEnter_name = zend_string_init_interned("NEnter", sizeof("NEnter") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NEnter_name, &const_NEnter_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NEnter_name);

	zval const_NAdd_value;
	ZVAL_LONG(&const_NAdd_value, 36);
	zend_string *const_NAdd_name = zend_string_init_interned("NAdd", sizeof("NAdd") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NAdd_name, &const_NAdd_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NAdd_name);

	zval const_NSubtract_value;
	ZVAL_LONG(&const_NSubtract_value, 37);
	zend_string *const_NSubtract_name = zend_string_init_interned("NSubtract", sizeof("NSubtract") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NSubtract_name, &const_NSubtract_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NSubtract_name);

	zval const_NMultiply_value;
	ZVAL_LONG(&const_NMultiply_value, 38);
	zend_string *const_NMultiply_name = zend_string_init_interned("NMultiply", sizeof("NMultiply") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NMultiply_name, &const_NMultiply_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NMultiply_name);

	zval const_NDivide_value;
	ZVAL_LONG(&const_NDivide_value, 39);
	zend_string *const_NDivide_name = zend_string_init_interned("NDivide", sizeof("NDivide") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NDivide_name, &const_NDivide_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NDivide_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Modifiers(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Modifiers", class_Ardillo_Modifiers_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Ctrl_value;
	ZVAL_LONG(&const_Ctrl_value, 1);
	zend_string *const_Ctrl_name = zend_string_init_interned("Ctrl", sizeof("Ctrl") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Ctrl_name, &const_Ctrl_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Ctrl_name);

	zval const_Alt_value;
	ZVAL_LONG(&const_Alt_value, 2);
	zend_string *const_Alt_name = zend_string_init_interned("Alt", sizeof("Alt") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Alt_name, &const_Alt_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Alt_name);

	zval const_Shift_value;
	ZVAL_LONG(&const_Shift_value, 4);
	zend_string *const_Shift_name = zend_string_init_interned("Shift", sizeof("Shift") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Shift_name, &const_Shift_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Shift_name);

	zval const_Super_value;
	ZVAL_LONG(&const_Super_value, 8);
	zend_string *const_Super_name = zend_string_init_interned("Super", sizeof("Super") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Super_name, &const_Super_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Super_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawBrushType(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawBrushType", class_Ardillo_DrawBrushType_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Solid_value;
	ZVAL_LONG(&const_Solid_value, 0);
	zend_string *const_Solid_name = zend_string_init_interned("Solid", sizeof("Solid") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Solid_name, &const_Solid_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Solid_name);

	zval const_LinearGradient_value;
	ZVAL_LONG(&const_LinearGradient_value, 1);
	zend_string *const_LinearGradient_name = zend_string_init_interned("LinearGradient", sizeof("LinearGradient") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_LinearGradient_name, &const_LinearGradient_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_LinearGradient_name);

	zval const_RadialGradient_value;
	ZVAL_LONG(&const_RadialGradient_value, 2);
	zend_string *const_RadialGradient_name = zend_string_init_interned("RadialGradient", sizeof("RadialGradient") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_RadialGradient_name, &const_RadialGradient_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_RadialGradient_name);

	zval const_Image_value;
	ZVAL_LONG(&const_Image_value, 3);
	zend_string *const_Image_name = zend_string_init_interned("Image", sizeof("Image") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Image_name, &const_Image_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Image_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawLineCap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawLineCap", class_Ardillo_DrawLineCap_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Flat_value;
	ZVAL_LONG(&const_Flat_value, 0);
	zend_string *const_Flat_name = zend_string_init_interned("Flat", sizeof("Flat") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Flat_name, &const_Flat_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Flat_name);

	zval const_Round_value;
	ZVAL_LONG(&const_Round_value, 1);
	zend_string *const_Round_name = zend_string_init_interned("Round", sizeof("Round") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Round_name, &const_Round_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Round_name);

	zval const_Square_value;
	ZVAL_LONG(&const_Square_value, 2);
	zend_string *const_Square_name = zend_string_init_interned("Square", sizeof("Square") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Square_name, &const_Square_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Square_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawLineJoin(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawLineJoin", class_Ardillo_DrawLineJoin_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Miter_value;
	ZVAL_LONG(&const_Miter_value, 0);
	zend_string *const_Miter_name = zend_string_init_interned("Miter", sizeof("Miter") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Miter_name, &const_Miter_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Miter_name);

	zval const_Round_value;
	ZVAL_LONG(&const_Round_value, 1);
	zend_string *const_Round_name = zend_string_init_interned("Round", sizeof("Round") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Round_name, &const_Round_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Round_name);

	zval const_Bevel_value;
	ZVAL_LONG(&const_Bevel_value, 2);
	zend_string *const_Bevel_name = zend_string_init_interned("Bevel", sizeof("Bevel") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Bevel_name, &const_Bevel_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Bevel_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawTextAlign(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawTextAlign", class_Ardillo_DrawTextAlign_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Left_value;
	ZVAL_LONG(&const_Left_value, 0);
	zend_string *const_Left_name = zend_string_init_interned("Left", sizeof("Left") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Left_name, &const_Left_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Left_name);

	zval const_Center_value;
	ZVAL_LONG(&const_Center_value, 1);
	zend_string *const_Center_name = zend_string_init_interned("Center", sizeof("Center") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Center_name, &const_Center_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Center_name);

	zval const_Right_value;
	ZVAL_LONG(&const_Right_value, 2);
	zend_string *const_Right_name = zend_string_init_interned("Right", sizeof("Right") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Right_name, &const_Right_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Right_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TextItalic(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TextItalic", class_Ardillo_TextItalic_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Normal_value;
	ZVAL_LONG(&const_Normal_value, 0);
	zend_string *const_Normal_name = zend_string_init_interned("Normal", sizeof("Normal") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Normal_name, &const_Normal_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Normal_name);

	zval const_Oblique_value;
	ZVAL_LONG(&const_Oblique_value, 1);
	zend_string *const_Oblique_name = zend_string_init_interned("Oblique", sizeof("Oblique") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Oblique_name, &const_Oblique_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Oblique_name);

	zval const_Italic_value;
	ZVAL_LONG(&const_Italic_value, 2);
	zend_string *const_Italic_name = zend_string_init_interned("Italic", sizeof("Italic") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Italic_name, &const_Italic_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Italic_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_SortIndicator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "SortIndicator", class_Ardillo_SortIndicator_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_None_value;
	ZVAL_LONG(&const_None_value, 0);
	zend_string *const_None_name = zend_string_init_interned("None", sizeof("None") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_None_name, &const_None_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_None_name);

	zval const_Ascending_value;
	ZVAL_LONG(&const_Ascending_value, 1);
	zend_string *const_Ascending_name = zend_string_init_interned("Ascending", sizeof("Ascending") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Ascending_name, &const_Ascending_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Ascending_name);

	zval const_Descending_value;
	ZVAL_LONG(&const_Descending_value, 2);
	zend_string *const_Descending_name = zend_string_init_interned("Descending", sizeof("Descending") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Descending_name, &const_Descending_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Descending_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableSelectionMode(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableSelectionMode", class_Ardillo_TableSelectionMode_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_None_value;
	ZVAL_LONG(&const_None_value, 0);
	zend_string *const_None_name = zend_string_init_interned("None", sizeof("None") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_None_name, &const_None_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_None_name);

	zval const_ZeroOrOne_value;
	ZVAL_LONG(&const_ZeroOrOne_value, 1);
	zend_string *const_ZeroOrOne_name = zend_string_init_interned("ZeroOrOne", sizeof("ZeroOrOne") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_ZeroOrOne_name, &const_ZeroOrOne_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_ZeroOrOne_name);

	zval const_One_value;
	ZVAL_LONG(&const_One_value, 2);
	zend_string *const_One_name = zend_string_init_interned("One", sizeof("One") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_One_name, &const_One_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_One_name);

	zval const_ZeroOrMany_value;
	ZVAL_LONG(&const_ZeroOrMany_value, 2);
	zend_string *const_ZeroOrMany_name = zend_string_init_interned("ZeroOrMany", sizeof("ZeroOrMany") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_ZeroOrMany_name, &const_ZeroOrMany_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_ZeroOrMany_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableModelColumn(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableModelColumn", class_Ardillo_TableModelColumn_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_NeverEditable_value;
	ZVAL_LONG(&const_NeverEditable_value, -1);
	zend_string *const_NeverEditable_name = zend_string_init_interned("NeverEditable", sizeof("NeverEditable") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_NeverEditable_name, &const_NeverEditable_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_NeverEditable_name);

	zval const_AlwaysEditable_value;
	ZVAL_LONG(&const_AlwaysEditable_value, -2);
	zend_string *const_AlwaysEditable_name = zend_string_init_interned("AlwaysEditable", sizeof("AlwaysEditable") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_AlwaysEditable_name, &const_AlwaysEditable_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_AlwaysEditable_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableValueType(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableValueType", class_Ardillo_TableValueType_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Str_value;
	ZVAL_LONG(&const_Str_value, 0);
	zend_string *const_Str_name = zend_string_init_interned("Str", sizeof("Str") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Str_name, &const_Str_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Str_name);

	zval const_Image_value;
	ZVAL_LONG(&const_Image_value, 1);
	zend_string *const_Image_name = zend_string_init_interned("Image", sizeof("Image") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Image_name, &const_Image_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Image_name);

	zval const_Number_value;
	ZVAL_LONG(&const_Number_value, 2);
	zend_string *const_Number_name = zend_string_init_interned("Number", sizeof("Number") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Number_name, &const_Number_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Number_name);

	zval const_Color_value;
	ZVAL_LONG(&const_Color_value, 2);
	zend_string *const_Color_name = zend_string_init_interned("Color", sizeof("Color") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Color_name, &const_Color_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Color_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TextStretch(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TextStretch", class_Ardillo_TextStretch_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_UltraCondensed_value;
	ZVAL_LONG(&const_UltraCondensed_value, 0);
	zend_string *const_UltraCondensed_name = zend_string_init_interned("UltraCondensed", sizeof("UltraCondensed") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_UltraCondensed_name, &const_UltraCondensed_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_UltraCondensed_name);

	zval const_ExtraCondensed_value;
	ZVAL_LONG(&const_ExtraCondensed_value, 1);
	zend_string *const_ExtraCondensed_name = zend_string_init_interned("ExtraCondensed", sizeof("ExtraCondensed") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_ExtraCondensed_name, &const_ExtraCondensed_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_ExtraCondensed_name);

	zval const_Condensed_value;
	ZVAL_LONG(&const_Condensed_value, 2);
	zend_string *const_Condensed_name = zend_string_init_interned("Condensed", sizeof("Condensed") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Condensed_name, &const_Condensed_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Condensed_name);

	zval const_SemiCondensed_value;
	ZVAL_LONG(&const_SemiCondensed_value, 3);
	zend_string *const_SemiCondensed_name = zend_string_init_interned("SemiCondensed", sizeof("SemiCondensed") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SemiCondensed_name, &const_SemiCondensed_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SemiCondensed_name);

	zval const_Normal_value;
	ZVAL_LONG(&const_Normal_value, 4);
	zend_string *const_Normal_name = zend_string_init_interned("Normal", sizeof("Normal") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Normal_name, &const_Normal_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Normal_name);

	zval const_SemiExpanded_value;
	ZVAL_LONG(&const_SemiExpanded_value, 5);
	zend_string *const_SemiExpanded_name = zend_string_init_interned("SemiExpanded", sizeof("SemiExpanded") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SemiExpanded_name, &const_SemiExpanded_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SemiExpanded_name);

	zval const_Expanded_value;
	ZVAL_LONG(&const_Expanded_value, 6);
	zend_string *const_Expanded_name = zend_string_init_interned("Expanded", sizeof("Expanded") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Expanded_name, &const_Expanded_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Expanded_name);

	zval const_ExtraExpanded_value;
	ZVAL_LONG(&const_ExtraExpanded_value, 7);
	zend_string *const_ExtraExpanded_name = zend_string_init_interned("ExtraExpanded", sizeof("ExtraExpanded") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_ExtraExpanded_name, &const_ExtraExpanded_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_ExtraExpanded_name);

	zval const_UltraExpanded_value;
	ZVAL_LONG(&const_UltraExpanded_value, 8);
	zend_string *const_UltraExpanded_name = zend_string_init_interned("UltraExpanded", sizeof("UltraExpanded") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_UltraExpanded_name, &const_UltraExpanded_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_UltraExpanded_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TextStretch(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TextStretch", class_Ardillo_TextStretch_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_Minimum_value;
	ZVAL_LONG(&const_Minimum_value, 0);
	zend_string *const_Minimum_name = zend_string_init_interned("Minimum", sizeof("Minimum") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Minimum_name, &const_Minimum_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Minimum_name);

	zval const_Thin_value;
	ZVAL_LONG(&const_Thin_value, 100);
	zend_string *const_Thin_name = zend_string_init_interned("Thin", sizeof("Thin") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Thin_name, &const_Thin_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Thin_name);

	zval const_UltraLight_value;
	ZVAL_LONG(&const_UltraLight_value, 200);
	zend_string *const_UltraLight_name = zend_string_init_interned("UltraLight", sizeof("UltraLight") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_UltraLight_name, &const_UltraLight_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_UltraLight_name);

	zval const_Light_value;
	ZVAL_LONG(&const_Light_value, 300);
	zend_string *const_Light_name = zend_string_init_interned("Light", sizeof("Light") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Light_name, &const_Light_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Light_name);

	zval const_Book_value;
	ZVAL_LONG(&const_Book_value, 350);
	zend_string *const_Book_name = zend_string_init_interned("Book", sizeof("Book") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Book_name, &const_Book_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Book_name);

	zval const_Normal_value;
	ZVAL_LONG(&const_Normal_value, 400);
	zend_string *const_Normal_name = zend_string_init_interned("Normal", sizeof("Normal") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Normal_name, &const_Normal_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Normal_name);

	zval const_Medium_value;
	ZVAL_LONG(&const_Medium_value, 500);
	zend_string *const_Medium_name = zend_string_init_interned("Medium", sizeof("Medium") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Medium_name, &const_Medium_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Medium_name);

	zval const_SemiBold_value;
	ZVAL_LONG(&const_SemiBold_value, 600);
	zend_string *const_SemiBold_name = zend_string_init_interned("SemiBold", sizeof("SemiBold") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SemiBold_name, &const_SemiBold_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SemiBold_name);

	zval const_Bold_value;
	ZVAL_LONG(&const_Bold_value, 700);
	zend_string *const_Bold_name = zend_string_init_interned("Bold", sizeof("Bold") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Bold_name, &const_Bold_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Bold_name);

	zval const_UltraBold_value;
	ZVAL_LONG(&const_UltraBold_value, 800);
	zend_string *const_UltraBold_name = zend_string_init_interned("UltraBold", sizeof("UltraBold") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_UltraBold_name, &const_UltraBold_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_UltraBold_name);

	zval const_Heavy_value;
	ZVAL_LONG(&const_Heavy_value, 900);
	zend_string *const_Heavy_name = zend_string_init_interned("Heavy", sizeof("Heavy") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Heavy_name, &const_Heavy_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Heavy_name);

	zval const_UltraHeavy_value;
	ZVAL_LONG(&const_UltraHeavy_value, 950);
	zend_string *const_UltraHeavy_name = zend_string_init_interned("UltraHeavy", sizeof("UltraHeavy") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_UltraHeavy_name, &const_UltraHeavy_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_UltraHeavy_name);

	zval const_Maximum_value;
	ZVAL_LONG(&const_Maximum_value, 1000);
	zend_string *const_Maximum_name = zend_string_init_interned("Maximum", sizeof("Maximum") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_Maximum_name, &const_Maximum_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_Maximum_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Color(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Color", class_Ardillo_Color_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_red_default_value;
	ZVAL_DOUBLE(&property_red_default_value, 0);
	zend_string *property_red_name = zend_string_init("red", sizeof("red") - 1, 1);
	zend_declare_typed_property(class_entry, property_red_name, &property_red_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_red_name);

	zval property_green_default_value;
	ZVAL_DOUBLE(&property_green_default_value, 0);
	zend_string *property_green_name = zend_string_init("green", sizeof("green") - 1, 1);
	zend_declare_typed_property(class_entry, property_green_name, &property_green_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_green_name);

	zval property_blue_default_value;
	ZVAL_DOUBLE(&property_blue_default_value, 0);
	zend_string *property_blue_name = zend_string_init("blue", sizeof("blue") - 1, 1);
	zend_declare_typed_property(class_entry, property_blue_name, &property_blue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_blue_name);

	zval property_alpha_default_value;
	ZVAL_DOUBLE(&property_alpha_default_value, 1);
	zend_string *property_alpha_name = zend_string_init("alpha", sizeof("alpha") - 1, 1);
	zend_declare_typed_property(class_entry, property_alpha_name, &property_alpha_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_alpha_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Point(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Point", class_Ardillo_Point_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_x_default_value;
	ZVAL_DOUBLE(&property_x_default_value, 0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_DOUBLE(&property_y_default_value, 0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Size(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Size", class_Ardillo_Size_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_width_default_value;
	ZVAL_DOUBLE(&property_width_default_value, 0);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_DOUBLE(&property_height_default_value, 0);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_height_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_AreaDrawParams(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "AreaDrawParams", class_Ardillo_AreaDrawParams_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_AreaHandler(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "AreaHandler", class_Ardillo_AreaHandler_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_AreaKeyEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "AreaKeyEvent", class_Ardillo_AreaKeyEvent_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_AreaMouseEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "AreaMouseEvent", class_Ardillo_AreaMouseEvent_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Box(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Box", class_Ardillo_Box_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Button(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Button", class_Ardillo_Button_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Checkbox(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Checkbox", class_Ardillo_Checkbox_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_ColorButton(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "ColorButton", class_Ardillo_ColorButton_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Combobox(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Combobox", class_Ardillo_Combobox_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Control(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Control", class_Ardillo_Control_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DateTimePicker(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DateTimePicker", class_Ardillo_DateTimePicker_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawBrush(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawBrush", class_Ardillo_DrawBrush_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawBrushGradientStop(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawBrushGradientStop", class_Ardillo_DrawBrushGradientStop_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawMatrix(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawMatrix", class_Ardillo_DrawMatrix_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawStrokeParams(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawStrokeParams", class_Ardillo_DrawStrokeParams_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval const_DEFAULT_MITER_LIMIT_value;
	ZVAL_DOUBLE(&const_DEFAULT_MITER_LIMIT_value, 10);
	zend_string *const_DEFAULT_MITER_LIMIT_name = zend_string_init_interned("DEFAULT_MITER_LIMIT", sizeof("DEFAULT_MITER_LIMIT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_DEFAULT_MITER_LIMIT_name, &const_DEFAULT_MITER_LIMIT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_DEFAULT_MITER_LIMIT_name);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawTextLayoutParams(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawTextLayoutParams", class_Ardillo_DrawTextLayoutParams_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_EditableCombobox(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "EditableCombobox", class_Ardillo_EditableCombobox_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Entry(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Entry", class_Ardillo_Entry_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_FontButton(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "FontButton", class_Ardillo_FontButton_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_FontDescriptor(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "FontDescriptor", class_Ardillo_FontDescriptor_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Form(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Form", class_Ardillo_Form_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Grid(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Grid", class_Ardillo_Grid_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Group(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Group", class_Ardillo_Group_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Image(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Image", class_Ardillo_Image_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Label(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Label", class_Ardillo_Label_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_MultilineEntry(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "MultilineEntry", class_Ardillo_MultilineEntry_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_ProgressBar(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "ProgressBar", class_Ardillo_ProgressBar_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_RadioButtons(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "RadioButtons", class_Ardillo_RadioButtons_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Separator(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Separator", class_Ardillo_Separator_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Slider(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Slider", class_Ardillo_Slider_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Spinbox(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Spinbox", class_Ardillo_Spinbox_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Tab(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Tab", class_Ardillo_Tab_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Table(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Table", class_Ardillo_Table_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableModel(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableModel", class_Ardillo_TableModel_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableModelHandler(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableModelHandler", class_Ardillo_TableModelHandler_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableParams(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableParams", class_Ardillo_TableParams_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableTextColumnOptionalParams(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableTextColumnOptionalParams", class_Ardillo_TableTextColumnOptionalParams_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableValue(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableValue", class_Ardillo_TableValue_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Window(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Window", class_Ardillo_Window_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zval const_MESSAGE_BOX_DEFAULT_value;
	ZVAL_LONG(&const_MESSAGE_BOX_DEFAULT_value, 0);
	zend_string *const_MESSAGE_BOX_DEFAULT_name = zend_string_init_interned("MESSAGE_BOX_DEFAULT", sizeof("MESSAGE_BOX_DEFAULT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_MESSAGE_BOX_DEFAULT_name, &const_MESSAGE_BOX_DEFAULT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_MESSAGE_BOX_DEFAULT_name);

	zval const_MESSAGE_BOX_ERROR_value;
	ZVAL_LONG(&const_MESSAGE_BOX_ERROR_value, 1);
	zend_string *const_MESSAGE_BOX_ERROR_name = zend_string_init_interned("MESSAGE_BOX_ERROR", sizeof("MESSAGE_BOX_ERROR") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_MESSAGE_BOX_ERROR_name, &const_MESSAGE_BOX_ERROR_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_MESSAGE_BOX_ERROR_name);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_Area(zend_class_entry *class_entry_Ardillo_Control)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "Area", class_Ardillo_Area_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Control);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DrawPath(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DrawPath", class_Ardillo_DrawPath_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_HorizontalBox(zend_class_entry *class_entry_Ardillo_Box)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "HorizontalBox", class_Ardillo_HorizontalBox_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Box);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_VerticalBox(zend_class_entry *class_entry_Ardillo_Box)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "VerticalBox", class_Ardillo_VerticalBox_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Box);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_DatePicker(zend_class_entry *class_entry_Ardillo_DateTimePicker)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "DatePicker", class_Ardillo_DatePicker_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_DateTimePicker);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TimePicker(zend_class_entry *class_entry_Ardillo_DateTimePicker)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TimePicker", class_Ardillo_TimePicker_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_DateTimePicker);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_PasswordEntry(zend_class_entry *class_entry_Ardillo_Entry)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "PasswordEntry", class_Ardillo_PasswordEntry_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Entry);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_SearchEntry(zend_class_entry *class_entry_Ardillo_Entry)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "SearchEntry", class_Ardillo_SearchEntry_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Entry);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_NonWrappingMultilineEntry(zend_class_entry *class_entry_Ardillo_MultilineEntry)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "NonWrappingMultilineEntry", class_Ardillo_NonWrappingMultilineEntry_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_MultilineEntry);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_HorizontalSeparator(zend_class_entry *class_entry_Ardillo_Separator)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "HorizontalSeparator", class_Ardillo_HorizontalSeparator_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Separator);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_VerticalSeparator(zend_class_entry *class_entry_Ardillo_Separator)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "VerticalSeparator", class_Ardillo_VerticalSeparator_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_Separator);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableValueString(zend_class_entry *class_entry_Ardillo_TableValue)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableValueString", class_Ardillo_TableValueString_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_TableValue);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableValueImage(zend_class_entry *class_entry_Ardillo_TableValue)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableValueImage", class_Ardillo_TableValueImage_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_TableValue);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableValueInt(zend_class_entry *class_entry_Ardillo_TableValue)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableValueInt", class_Ardillo_TableValueInt_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_TableValue);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}

static zend_class_entry *register_class_Ardillo_TableValueColor(zend_class_entry *class_entry_Ardillo_TableValue)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ardillo", "TableValueColor", class_Ardillo_TableValueColor_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Ardillo_TableValue);

	zend_string *property_app_class_Ardillo_App = zend_string_init("Ardillo\\App", sizeof("Ardillo\\App")-1, 1);
	zval property_app_default_value;
	ZVAL_UNDEF(&property_app_default_value);
	zend_string *property_app_name = zend_string_init("app", sizeof("app") - 1, 1);
	zend_declare_typed_property(class_entry, property_app_name, &property_app_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_app_class_Ardillo_App, 0, 0));
	zend_string_release(property_app_name);

	return class_entry;
}
