#ifndef __ARDILLO_UI_TYPES_H
#define __ARDILLO_UI_TYPES_H

#include "ui.h"
#include "ext/date/php_date.h"

void ardillo_call_Control_onFree(uiControl *uis, void *this);

extern zend_class_entry *ce_Ardillo_Align;
extern zend_class_entry *ce_Ardillo_At;
extern zend_class_entry *ce_Ardillo_ExtKey;
extern zend_class_entry *ce_Ardillo_Modifiers;
extern zend_class_entry *ce_Ardillo_DrawBrushType;
extern zend_class_entry *ce_Ardillo_DrawLineCap;
extern zend_class_entry *ce_Ardillo_DrawLineJoin;
extern zend_class_entry *ce_Ardillo_DrawTextAlign;
extern zend_class_entry *ce_Ardillo_SortIndicator;
extern zend_class_entry *ce_Ardillo_TableSelectionMode;
extern zend_class_entry *ce_Ardillo_TableValueType;
extern zend_class_entry *ce_Ardillo_TextItalic;
extern zend_class_entry *ce_Ardillo_TextStretch;
extern zend_class_entry *ce_Ardillo_TextWeight;

extern zend_class_entry *ce_Ardillo_Color;
extern zend_class_entry *ce_Ardillo_Point;
extern zend_class_entry *ce_Ardillo_Size;

extern zend_class_entry *ce_Ardillo_AreaDrawParams;

typedef struct _ardillo_ui_AreaDrawParams_t {
    uiAreaDrawParams *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_AreaDrawParams_t;

zend_object * ardillo_create_AreaDrawParams_object(zend_class_entry *ce);
void ardillo_free_AreaDrawParams_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_AreaHandler;

typedef struct _ardillo_ui_AreaHandler_t {
    uiAreaHandler *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_AreaHandler_t;

zend_object * ardillo_create_AreaHandler_object(zend_class_entry *ce);
void ardillo_free_AreaHandler_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_AreaKeyEvent;

typedef struct _ardillo_ui_AreaKeyEvent_t {
    uiAreaKeyEvent *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_AreaKeyEvent_t;

zend_object * ardillo_create_AreaKeyEvent_object(zend_class_entry *ce);
void ardillo_free_AreaKeyEvent_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_AreaMouseEvent;

typedef struct _ardillo_ui_AreaMouseEvent_t {
    uiAreaMouseEvent *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_AreaMouseEvent_t;

zend_object * ardillo_create_AreaMouseEvent_object(zend_class_entry *ce);
void ardillo_free_AreaMouseEvent_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Box;

typedef struct _ardillo_ui_Box_t {
    uiBox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Box_t;

zend_object * ardillo_create_Box_object(zend_class_entry *ce);
void ardillo_free_Box_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Button;

typedef struct _ardillo_ui_Button_t {
    uiButton *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Button_t;

zend_object * ardillo_create_Button_object(zend_class_entry *ce);
void ardillo_free_Button_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Checkbox;

typedef struct _ardillo_ui_Checkbox_t {
    uiCheckbox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Checkbox_t;

zend_object * ardillo_create_Checkbox_object(zend_class_entry *ce);
void ardillo_free_Checkbox_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_ColorButton;

typedef struct _ardillo_ui_ColorButton_t {
    uiColorButton *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_ColorButton_t;

zend_object * ardillo_create_ColorButton_object(zend_class_entry *ce);
void ardillo_free_ColorButton_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Combobox;

typedef struct _ardillo_ui_Combobox_t {
    uiCombobox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Combobox_t;

zend_object * ardillo_create_Combobox_object(zend_class_entry *ce);
void ardillo_free_Combobox_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Control;

typedef struct _ardillo_ui_Control_t {
    uiControl *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Control_t;

zend_object * ardillo_create_Control_object(zend_class_entry *ce);
void ardillo_free_Control_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DateTimePicker;

typedef struct _ardillo_ui_DateTimePicker_t {
    uiDateTimePicker *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DateTimePicker_t;

zend_object * ardillo_create_DateTimePicker_object(zend_class_entry *ce);
void ardillo_free_DateTimePicker_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DrawBrush;

typedef struct _ardillo_ui_DrawBrush_t {
    uiDrawBrush *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DrawBrush_t;

zend_object * ardillo_create_DrawBrush_object(zend_class_entry *ce);
void ardillo_free_DrawBrush_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DrawBrushGradientStop;

typedef struct _ardillo_ui_DrawBrushGradientStop_t {
    uiDrawBrushGradientStop *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DrawBrushGradientStop_t;

zend_object * ardillo_create_DrawBrushGradientStop_object(zend_class_entry *ce);
void ardillo_free_DrawBrushGradientStop_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DrawMatrix;

typedef struct _ardillo_ui_DrawMatrix_t {
    uiDrawMatrix *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DrawMatrix_t;

zend_object * ardillo_create_DrawMatrix_object(zend_class_entry *ce);
void ardillo_free_DrawMatrix_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DrawStrokeParams;

typedef struct _ardillo_ui_DrawStrokeParams_t {
    uiDrawStrokeParams *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DrawStrokeParams_t;

zend_object * ardillo_create_DrawStrokeParams_object(zend_class_entry *ce);
void ardillo_free_DrawStrokeParams_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DrawTextLayoutParams;

typedef struct _ardillo_ui_DrawTextLayoutParams_t {
    uiDrawTextLayoutParams *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DrawTextLayoutParams_t;

zend_object * ardillo_create_DrawTextLayoutParams_object(zend_class_entry *ce);
void ardillo_free_DrawTextLayoutParams_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_EditableCombobox;

typedef struct _ardillo_ui_EditableCombobox_t {
    uiEditableCombobox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_EditableCombobox_t;

zend_object * ardillo_create_EditableCombobox_object(zend_class_entry *ce);
void ardillo_free_EditableCombobox_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Entry;

typedef struct _ardillo_ui_Entry_t {
    uiEntry *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Entry_t;

zend_object * ardillo_create_Entry_object(zend_class_entry *ce);
void ardillo_free_Entry_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_FontButton;

typedef struct _ardillo_ui_FontButton_t {
    uiFontButton *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_FontButton_t;

zend_object * ardillo_create_FontButton_object(zend_class_entry *ce);
void ardillo_free_FontButton_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_FontDescriptor;

typedef struct _ardillo_ui_FontDescriptor_t {
    uiFontDescriptor *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_FontDescriptor_t;

zend_object * ardillo_create_FontDescriptor_object(zend_class_entry *ce);
void ardillo_free_FontDescriptor_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Form;

typedef struct _ardillo_ui_Form_t {
    uiForm *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Form_t;

zend_object * ardillo_create_Form_object(zend_class_entry *ce);
void ardillo_free_Form_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Grid;

typedef struct _ardillo_ui_Grid_t {
    uiGrid *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Grid_t;

zend_object * ardillo_create_Grid_object(zend_class_entry *ce);
void ardillo_free_Grid_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Group;

typedef struct _ardillo_ui_Group_t {
    uiGroup *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Group_t;

zend_object * ardillo_create_Group_object(zend_class_entry *ce);
void ardillo_free_Group_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Image;

typedef struct _ardillo_ui_Image_t {
    uiImage *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Image_t;

zend_object * ardillo_create_Image_object(zend_class_entry *ce);
void ardillo_free_Image_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Label;

typedef struct _ardillo_ui_Label_t {
    uiLabel *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Label_t;

zend_object * ardillo_create_Label_object(zend_class_entry *ce);
void ardillo_free_Label_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_MultilineEntry;

typedef struct _ardillo_ui_MultilineEntry_t {
    uiMultilineEntry *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_MultilineEntry_t;

zend_object * ardillo_create_MultilineEntry_object(zend_class_entry *ce);
void ardillo_free_MultilineEntry_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_ProgressBar;

typedef struct _ardillo_ui_ProgressBar_t {
    uiProgressBar *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_ProgressBar_t;

zend_object * ardillo_create_ProgressBar_object(zend_class_entry *ce);
void ardillo_free_ProgressBar_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_RadioButtons;

typedef struct _ardillo_ui_RadioButtons_t {
    uiRadioButtons *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_RadioButtons_t;

zend_object * ardillo_create_RadioButtons_object(zend_class_entry *ce);
void ardillo_free_RadioButtons_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Separator;

typedef struct _ardillo_ui_Separator_t {
    uiSeparator *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Separator_t;

zend_object * ardillo_create_Separator_object(zend_class_entry *ce);
void ardillo_free_Separator_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Slider;

typedef struct _ardillo_ui_Slider_t {
    uiSlider *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Slider_t;

zend_object * ardillo_create_Slider_object(zend_class_entry *ce);
void ardillo_free_Slider_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Spinbox;

typedef struct _ardillo_ui_Spinbox_t {
    uiSpinbox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Spinbox_t;

zend_object * ardillo_create_Spinbox_object(zend_class_entry *ce);
void ardillo_free_Spinbox_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Tab;

typedef struct _ardillo_ui_Tab_t {
    uiTab *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Tab_t;

zend_object * ardillo_create_Tab_object(zend_class_entry *ce);
void ardillo_free_Tab_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Table;

typedef struct _ardillo_ui_Table_t {
    uiTable *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Table_t;

zend_object * ardillo_create_Table_object(zend_class_entry *ce);
void ardillo_free_Table_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableModel;

typedef struct _ardillo_ui_TableModel_t {
    uiTableModel *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableModel_t;

zend_object * ardillo_create_TableModel_object(zend_class_entry *ce);
void ardillo_free_TableModel_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableModelHandler;

typedef struct _ardillo_ui_TableModelHandler_t {
    uiTableModelHandler *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableModelHandler_t;

zend_object * ardillo_create_TableModelHandler_object(zend_class_entry *ce);
void ardillo_free_TableModelHandler_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableParams;

typedef struct _ardillo_ui_TableParams_t {
    uiTableParams *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableParams_t;

zend_object * ardillo_create_TableParams_object(zend_class_entry *ce);
void ardillo_free_TableParams_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableTextColumnOptionalParams;

typedef struct _ardillo_ui_TableTextColumnOptionalParams_t {
    uiTableTextColumnOptionalParams *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableTextColumnOptionalParams_t;

zend_object * ardillo_create_TableTextColumnOptionalParams_object(zend_class_entry *ce);
void ardillo_free_TableTextColumnOptionalParams_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableValue;

typedef struct _ardillo_ui_TableValue_t {
    uiTableValue *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableValue_t;

zend_object * ardillo_create_TableValue_object(zend_class_entry *ce);
void ardillo_free_TableValue_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Window;

typedef struct _ardillo_ui_Window_t {
    uiWindow *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Window_t;

zend_object * ardillo_create_Window_object(zend_class_entry *ce);
void ardillo_free_Window_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_Area;

typedef struct _ardillo_ui_Area_t {
    uiArea *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_Area_t;

zend_object * ardillo_create_Area_object(zend_class_entry *ce);
void ardillo_free_Area_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DrawPath;

typedef struct _ardillo_ui_DrawPath_t {
    uiDrawPath *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DrawPath_t;

zend_object * ardillo_create_DrawPath_object(zend_class_entry *ce);
void ardillo_free_DrawPath_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_HorizontalBox;

typedef struct _ardillo_ui_HorizontalBox_t {
    uiBox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_HorizontalBox_t;

zend_object * ardillo_create_HorizontalBox_object(zend_class_entry *ce);
void ardillo_free_HorizontalBox_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_VerticalBox;

typedef struct _ardillo_ui_VerticalBox_t {
    uiBox *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_VerticalBox_t;

zend_object * ardillo_create_VerticalBox_object(zend_class_entry *ce);
void ardillo_free_VerticalBox_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_DatePicker;

typedef struct _ardillo_ui_DatePicker_t {
    uiDateTimePicker *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_DatePicker_t;

zend_object * ardillo_create_DatePicker_object(zend_class_entry *ce);
void ardillo_free_DatePicker_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TimePicker;

typedef struct _ardillo_ui_TimePicker_t {
    uiDateTimePicker *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TimePicker_t;

zend_object * ardillo_create_TimePicker_object(zend_class_entry *ce);
void ardillo_free_TimePicker_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_PasswordEntry;

typedef struct _ardillo_ui_PasswordEntry_t {
    uiEntry *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_PasswordEntry_t;

zend_object * ardillo_create_PasswordEntry_object(zend_class_entry *ce);
void ardillo_free_PasswordEntry_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_SearchEntry;

typedef struct _ardillo_ui_SearchEntry_t {
    uiEntry *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_SearchEntry_t;

zend_object * ardillo_create_SearchEntry_object(zend_class_entry *ce);
void ardillo_free_SearchEntry_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_NonWrappingMultilineEntry;

typedef struct _ardillo_ui_NonWrappingMultilineEntry_t {
    uiMultilineEntry *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_NonWrappingMultilineEntry_t;

zend_object * ardillo_create_NonWrappingMultilineEntry_object(zend_class_entry *ce);
void ardillo_free_NonWrappingMultilineEntry_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_HorizontalSeparator;

typedef struct _ardillo_ui_HorizontalSeparator_t {
    uiSeparator *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_HorizontalSeparator_t;

zend_object * ardillo_create_HorizontalSeparator_object(zend_class_entry *ce);
void ardillo_free_HorizontalSeparator_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_VerticalSeparator;

typedef struct _ardillo_ui_VerticalSeparator_t {
    uiSeparator *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_VerticalSeparator_t;

zend_object * ardillo_create_VerticalSeparator_object(zend_class_entry *ce);
void ardillo_free_VerticalSeparator_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableValueString;

typedef struct _ardillo_ui_TableValueString_t {
    uiTableValue *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableValueString_t;

zend_object * ardillo_create_TableValueString_object(zend_class_entry *ce);
void ardillo_free_TableValueString_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableValueImage;

typedef struct _ardillo_ui_TableValueImage_t {
    uiTableValue *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableValueImage_t;

zend_object * ardillo_create_TableValueImage_object(zend_class_entry *ce);
void ardillo_free_TableValueImage_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableValueInt;

typedef struct _ardillo_ui_TableValueInt_t {
    uiTableValue *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableValueInt_t;

zend_object * ardillo_create_TableValueInt_object(zend_class_entry *ce);
void ardillo_free_TableValueInt_object(zend_object *object);

extern zend_class_entry *ce_Ardillo_TableValueColor;

typedef struct _ardillo_ui_TableValueColor_t {
    uiTableValue *uis;
    HashTable *refs;
    void *parent;
    zend_object std;
} ardillo_ui_TableValueColor_t;

zend_object * ardillo_create_TableValueColor_object(zend_class_entry *ce);
void ardillo_free_TableValueColor_object(zend_object *object);

#endif /* __ARDILLO_UI_TYPES_H */
