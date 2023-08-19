<?php

/**
 * @generate-class-entries
 */

namespace Ardillo;

/**
 * Ardillo App base class
 */
class App
{
    /* Signals */
    /** @var int */ public const SIGHUP = 1;
    /** @var int */ public const SIGINT = 2;
    /** @var int */ public const SIGQUIT = 3;
    /** @var int */ public const SIGILL = 4;
    /** @var int */ public const SIGTRAP = 5;
    /** @var int */ public const SIGABRT = 6;
    /** @var int */ public const SIGFPE = 8;
    /** @var int */ public const SIGKILL = 9;
    /** @var int */ public const SIGSEGV = 11;
    /** @var int */ public const SIGPIPE = 13;
    /** @var int */ public const SIGALRM = 14;
    /** @var int */ public const SIGTERM = 15;

    /**
     * Returns the current App instance, or null if one is not instantiated
     *
     * @return App|null
     */
    public static function get(): ?App {}

    /**
     * Initiates the internal Ardillo event loop for the current App instance.
     * Please note the internal event loop is the one provided by libui-ng, not the one provided by ReactPHP.
     */
    public function run(): void {}

    /**
     * Stops the internal Ardillo event loop for the current App instance.
     */
    public function stop(): void {}

    /**
     * Appends a menu entry for the current App instance.
     *
     * @param Menu|null $parent The parent menu, or null if this is a top-level menu
     * @param int $type The type of menu entry to append (use the Menu class integer constants)
     * @param int $id The ID of the menu entry (this is passed to the onMenuItemClicked() callback)
     * @param string|null $label The label of the menu entry, or null if this is a separator or an OS managed menu entry
     * @return Menu
     */
    public function appendMenu(?Menu $parent, int $type, int $id, ?string $label): Menu {}

    /**
     * Schedules a task to be executed in a future internal loop tick or periodically.
     *
     * @param Task $task The task to be scheduled
     * @param int $interval Execution interval in milliseconds or 0 for a one-time execution
     */
    public function scheduleTask(Task $task, int $interval): void {}

    /**
     * Adds a readable stream to the internal event loop watcher
     *
     * @param resource $stream The stream to be watched
     * @param StreamEventHandler $handler Handler to be invoked when the stream registers read events
     * @return int The file descriptor of the stream
     */
    public function addReadStream(mixed $stream, StreamEventHandler $handler): int {}

    /**
     * Adds a writable stream to the internal event loop watcher
     *
     * @param resource $stream The stream to be watched
     * @param StreamEventHandler $handler Handler to be invoked when the stream registers write events
     * @return int The file descriptor of the stream
     */
    public function addWriteStream(mixed $stream, StreamEventHandler $handler): int {}

    /**
     * Removes a readable stream from the internal event loop watcher
     *
     * @param int $fd The file descriptor of the stream as returned by addReadStream()
     */
    public function removeReadStream(int $fd): void {}

    /**
     * Removes a writable stream from the internal event loop watcher
     *
     * @param int $fd The file descriptor of the stream as returned by addWriteStream()
     */
    public function removeWriteStream(int $fd): void {}

    /**
     * Adds a signal to the internal event loop watcher
     *
     * @param int $signo The signal number to be watched (use the App class integer constants)
     */
    public function addSignal(int $signo): void {}

    /**
     * Removes a signal from the internal event loop watcher
     *
     * @param int $signo The signal number to be removed (use the App class integer constants)
     */
    public function removeSignal(int $signo): void {}
}

/**
 * Ardillo Menu base class
 */
abstract class Menu
{
    /** @var int */ public const Top = 0;
    /** @var int */ public const Separator = 1;
    /** @var int */ public const Quit = 2;
    /** @var int */ public const Preferences = 3;
    /** @var int */ public const About = 4;
    /** @var int */ public const CheckItem = 5;
    /** @var int */ public const Item = 6;
}

/**
 * Ardillo Task base class
 */
class Task
{
    /** @var bool Whether the Task is suspended or not */
    public bool $suspended = false;

    /**
     * Task's execution handler
     */
    public function onExecute(): void {}
}

/**
 * Ardillo StreamEventHandler interface
 */
interface StreamEventHandler
{
    /**
     * Handler to be invoked when the stream registers read events
     *
     * @param int $fd The file descriptor of the affected stream as returned by App::addReadStream()
     */
    public function onReadEvent(int $fd): void {}

    /**
     * Handler to be invoked when the stream registers write events
     *
     * @param int $fd The file descriptor of the affected stream as returned by App::addWriteStream()
     */
    public function onWriteEvent(int $fd): void {}
}

/**
 * Ardillo Align parameter constants
 */
class Align
{
    /** @var int */ public const Fill = 0;
    /** @var int */ public const Start = 1;
    /** @var int */ public const Center = 2;
    /** @var int */ public const End = 3;
}

/**
 * Ardillo At parameter constants
 */
class At
{
    /** @var int */ public const Leading = 0;
    /** @var int */ public const Top = 1;
    /** @var int */ public const Trailing = 2;
    /** @var int */ public const Bottom = 3;
}

/**
 * Ardillo DrawFillMode parameter constants
 */
class DrawFillMode
{
    /** @var int */ public const Winding = 0;
    /** @var int */ public const Alternate = 1;
}

/**
 * Ardillo ExtKey parameter constants
 */
class ExtKey
{
    /** @var int */ public const Escape = 1;
    /** @var int */ public const Insert = 2;
    /** @var int */ public const Delete = 3;
    /** @var int */ public const Home = 4;
    /** @var int */ public const End = 5;
    /** @var int */ public const PageUp = 6;
    /** @var int */ public const PageDown = 7;
    /** @var int */ public const Up = 8;
    /** @var int */ public const Down = 9;
    /** @var int */ public const Left = 10;
    /** @var int */ public const Right = 11;
    /** @var int */ public const F1 = 12;
    /** @var int */ public const F2 = 13;
    /** @var int */ public const F3 = 14;
    /** @var int */ public const F4 = 15;
    /** @var int */ public const F5 = 16;
    /** @var int */ public const F6 = 17;
    /** @var int */ public const F7 = 18;
    /** @var int */ public const F8 = 19;
    /** @var int */ public const F9 = 20;
    /** @var int */ public const F10 = 21;
    /** @var int */ public const F11 = 22;
    /** @var int */ public const F12 = 23;
    /** @var int */ public const N0 = 24;
    /** @var int */ public const N1 = 25;
    /** @var int */ public const N2 = 26;
    /** @var int */ public const N3 = 27;
    /** @var int */ public const N4 = 28;
    /** @var int */ public const N5 = 29;
    /** @var int */ public const N6 = 30;
    /** @var int */ public const N7 = 31;
    /** @var int */ public const N8 = 32;
    /** @var int */ public const N9 = 33;
    /** @var int */ public const NDot = 34;
    /** @var int */ public const NEnter = 35;
    /** @var int */ public const NAdd = 36;
    /** @var int */ public const NSubtract = 37;
    /** @var int */ public const NMultiply = 38;
    /** @var int */ public const NDivide = 39;
}

/**
 * Ardillo Modifiers parameter constants
 */
class Modifiers
{
    /** @var int */ public const Ctrl = 1 << 0;
    /** @var int */ public const Alt = 1 << 1;
    /** @var int */ public const Shift = 1 << 2;
    /** @var int */ public const Super = 1 << 3;
}

/**
 * Ardillo DrawBrushType parameter constants
 */
class DrawBrushType
{
    /** @var int */ public const Solid = 0;
    /** @var int */ public const LinearGradient = 1;
    /** @var int */ public const RadialGradient = 2;
    /** @var int */ public const Image = 3;
}

/**
 * Ardillo DrawLineCap parameter constants
 */
class DrawLineCap
{
    /** @var int */ public const Flat = 0;
    /** @var int */ public const Round = 1;
    /** @var int */ public const Square = 2;
}

/**
 * Ardillo DrawLineJoin parameter constants
 */
class DrawLineJoin
{
    /** @var int */ public const Miter = 0;
    /** @var int */ public const Round = 1;
    /** @var int */ public const Bevel = 2;
}

/**
 * Ardillo DrawTextAlign parameter constants
 */
class DrawTextAlign
{
    /** @var int */ public const Left = 0;
    /** @var int */ public const Center = 1;
    /** @var int */ public const Right = 2;
}

/**
 * Ardillo TextItalic parameter constants
 */
class TextItalic
{
    /** @var int */ public const Normal = 0;
    /** @var int */ public const Oblique = 1;
    /** @var int */ public const Italic = 2;
}

/**
 * Ardillo SortIndicator parameter constants
 */
class SortIndicator
{
    /** @var int */ public const None = 0;
    /** @var int */ public const Ascending = 1;
    /** @var int */ public const Descending = 2;
}

/**
 * Ardillo TableSelectionMode parameter constants
 */
class TableSelectionMode
{
    /** @var int */ public const None = 0;
    /** @var int */ public const ZeroOrOne = 1;
    /** @var int */ public const One = 2;
    /** @var int */ public const ZeroOrMany = 2;
}

/**
 * Ardillo TableModelColumn parameter constants
 */
class TableModelColumn
{
    /** @var int */ public const NeverEditable = -1;
    /** @var int */ public const AlwaysEditable = -2;
}

/**
 * Ardillo TableValueType parameter constants
 */
class TableValueType
{
    /** @var int */ public const Str = 0;
    /** @var int */ public const Image = 1;
    /** @var int */ public const Number = 2;
    /** @var int */ public const Color = 2;
}

/**
 * Ardillo TextStretch parameter constants
 */
class TextStretch
{
    /** @var int */ public const UltraCondensed = 0;
    /** @var int */ public const ExtraCondensed = 1;
    /** @var int */ public const Condensed = 2;
    /** @var int */ public const SemiCondensed = 3;
    /** @var int */ public const Normal = 4;
    /** @var int */ public const SemiExpanded = 5;
    /** @var int */ public const Expanded = 6;
    /** @var int */ public const ExtraExpanded = 7;
    /** @var int */ public const UltraExpanded = 8;
}

/**
 * Ardillo Color base class
 */
class Color
{
    /** @var float Red channel intensity, 0 through 1 */
    public float $red = 0.0;

    /** @var float Green channel intensity, 0 through 1 */
    public float $green = 0.0;

    /** @var float Blue channel intensity, 0 through 1 */
    public float $blue = 0.0;

    /** @var float Alpha channel intensity, 0 through 1 */
    public float $alpha = 1.0;

    /**
     * Creates a new Color instance from a hexadecimal RGBA value
     *
     * @param int $hex The hexadecimal RGBA value
     */
    static public function fromRGBA(int $hex): Color {}

    /**
     * Creates a new Color instance from a hexadecimal RGB value
     *
     * @param int $hex The hexadecimal RGB value
     */
    static public function fromRGB(int $hex): Color {}

    /**
     * Creates a new Color instance
     *
     * @param float $red Red channel intensity, 0 through 1
     * @param float $green Green channel intensity, 0 through 1
     * @param float $blue Blue channel intensity, 0 through 1
     * @param float $alpha Alpha channel intensity, 0 through 1
     */
    public function __construct(float $red = 0.0, float $green = 0.0, float $blue = 0.0, float $alpha = 1.0) {}
}

/**
 * Ardillo Point base class
 */
class Point
{
    /** @var float X coordinate */
    public float $x = 0.0;

    /** @var float Y coordinate */
    public float $y = 0.0;

    /**
     * Creates a new Point instance
     *
     * @param float $x X coordinate
     * @param float $y Y coordinate
     */
    public function __construct(float $x = 0.0, float $y = 0.0) {}
}

/**
 * Ardillo Size base class
 */
class Size
{
    /** @var float Width */
    public float $width = 0.0;

    /** @var float Height */
    public float $height = 0.0;

    /**
     * Creates a new Size instance
     *
     * @param float $width Width
     * @param float $height Height
     */
    public function __construct(float $width = 0.0, float $height = 0.0) {}
}

/**
 * Ardillo AreaDrawParams base class
 */
abstract class AreaDrawParams
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the area size
     *
     * @return Size
     */
    public function getAreaSize(): Size {}

    /**
     * Returns the clip point
     *
     * @return Point
     */
    public function getClipPoint(): Point {}

    /**
     * Returns the clip size
     *
     * @return Size
     */
    public function getClipSize(): Size {}

    /**
     * Fills the area using the specified brush
     *
     * @param DrawPath $path The path to be followed
     * @param DrawBrush $brush The brush to be used
     */
    public function fill(DrawPath $path, DrawBrush $brush): void {}

    /**
     * Apllies a stroke the area (its outline) using the specified brush
     *
     * @param DrawPath $path The path to be followed
     * @param DrawBrush $brush The brush to be used
     * @param DrawStrokeParams $sp The stroke parameters
     */
    public function stroke(DrawPath $path, DrawBrush $brush, DrawStrokeParams $sp): void {}

    /**
     * Applies a transformation matrix to the area
     *
     * @param DrawMatrix $matrix The transformation matrix
     */
    public function transform(DrawMatrix $matrix): void {}
}

/**
 * Ardillo AreaHandler base class
 */
class AreaHandler
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Area drag broken event handler
     *
     * @param Area $area The affected Area instance
     */
    abstract public function dragBrokenHandler(Area $area): void {}

    /**
     * Area draw event handler
     *
     * @param Area $area The affected Area instance
     * @param AreaDrawParams $params The draw parameters
     */
    abstract public function drawHandler(Area $area, AreaDrawParams $params): void {}

    /**
     * Area key event handler
     *
     * @param Area $area The affected Area instance
     * @param AreaKeyEvent $event The key event
     * @return int The key event result
     */
    abstract public function keyEventHandler(Area $area, AreaKeyEvent $event): int {}

    /**
     * Area crossed mouse event handler
     *
     * @param Area $area The affected Area instance
     * @param AreaMouseEvent $event The mouse event
     */
    abstract public function mouseCrossedHandler(Area $area, int $left): void {}

    /**
     * Area mouse event handler
     *
     * @param Area $area The affected Area instance
     * @param AreaMouseEvent $event The mouse event
     */
    abstract public function mouseEventHandler(Area $area, AreaMouseEvent $event): void {}
}

/**
 * Ardillo AreaKeyEvent base class
 */
class AreaKeyEvent
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the key code
     *
     * @return int
     */
    public function getKey(): int {}

    /**
     * Returns the extended key code
     *
     * @return int
     */
    public function getExtKey(): int {}

    /**
     * Returns the modifier flags
     *
     * @return Modifiers
     */
    public function getModifier(): Modifiers {}

    /**
     * Returns the modifiers flags
     *
     * @return Modifiers
     */
    public function getModifiers(): Modifiers {}

    /**
     * Returns the key up flag
     *
     * @return int
     */
    public function getUp(): int {}
}

/**
 * Ardillo AreaMouseEvent base class
 */
class AreaMouseEvent
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the coordinates of the mouse pointer
     *
     * @return Point
     */
    public function getPoint(): Point {}

    /**
     * Returns the selection area
     *
     * @return Size
     */
    public function getAreaSize(): Size {}

    /**
     * Returns the down mouse button state
     *
     * @return int
     */
    public function getDown(): int {}

    /**
     * Returns the up mouse button state
     *
     * @return int
     */
    public function getUp(): int {}

    /**
     * Returns the count (needs to be better documented in the upstream)
     *
     * @return int
     */
    public function getCount(): int {}

    /**
     * Returns the event modifier flags
     *
     * @return Modifiers
     */
    public function getModifiers(): Modifiers {}

    /**
     * Returns the event held1To64 flag (needs to be better documented in the upstream)
     *
     * @return int
     */
    public function getHeld1To64(): int {}
}

/**
 * Ardillo Box base class
 */
abstract class Box extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the whether the box is padded or not
     *
     * @return bool
     */
    public function getPadded(): bool {}

    /**
     * Sets whether the box is padded or not
     *
     * @param bool $padded
     */
    public function setPadded(bool $padded): void {}

    /**
     * Appends a child control to the box
     *
     * @param Control $child The child control to be appended
     * @param bool $stretchy Whether the child should be stretched or not
     */
    public function append(Control $child, bool $stretchy): void {}

    /**
     * Deletes a child at a given index
     *
     * @param int $index The index of the child to be deleted
     */
    public function delete(int $index): void {}

    /**
     * Returns the current children count
     *
     * @return int
     */
    public function childrenCount(): int {}
}

/**
 * Ardillo Button base class
 */
class Button extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Button instance
     *
     * @param string $text The button text
     */
    public function __construct(string $text) {}

    /**
     * Returns whether the button is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current button text
     *
     * @return string
     */
    public function getText(): string {}

    /**
     * Sets the button text
     *
     * @param string $text The button text
     */
    public function setText(string $text): void {}

    /**
     * Callback to be executed when the button is clicked
     */
    public function onClicked(): void {}
}

/**
 * Ardillo Checkbox base class
 */
class Checkbox extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Checkbox instance
     *
     * @param string $text The checkbox text
     */
    public function __construct(string $text) {}

    /**
     * Returns whether the checkbox is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the checkbox is checked or not
     *
     * @return bool
     */
    public function getChecked(): bool {}

    /**
     * Sets whether the checkbox is checked or not
     *
     * @param bool $checked
     */
    public function setChecked(bool $checked): void {}

    /**
     * Returns the current checkbox text
     *
     * @return string
     */
    public function getText(): string {}

    /**
     * Sets the checkbox text
     *
     * @param string $text The checkbox text
     */
    public function setText(string $text): void {}

    /**
     * Callback to be executed when the checkbox is toggled
     */
    public function onToggled(): void {}
}

/**
 * Ardillo ColorButton base class
 */
class ColorButton extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new ColorButton instance
     */
    public function __construct() {}

    /**
     * Returns whether the color button is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current selected color
     *
     * @return Color
     */
    public function getColor(): Color {}

    /**
     * Sets the color
     *
     * @param Color $color The color to be set
     */
    public function setColor(Color $color): void {}

    /**
     * Callback to be executed when the color selection is changed
     */
    public function onChanged(): void {}
}

/**
 * Ardillo Combobox base class
 */
class Combobox extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Combobox instance
     */
    public function __construct() {}

    /**
     * Returns whether the combobox is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current selection index
     *
     * @return int
     */
    public function getSelected(): int {}

    /**
     * Sets the selection index
     *
     * @param int $index The index of the item to be set
     */
    public function setSelected(int $index): void {}

    /**
     * Callback to be executed when the selection is changed
     */
    public function onSelected(): void {}

    /**
     * Appends a new item to the combobox
     *
     * @param string $text Item's text
     */
    public function append(string $text): void {}

    /**
     * Clears all items from the combobox
     */
    public function clear(): void {}

    /**
     * Deletes an item at a given index
     */
    public function delete(int $index): void {}

    /**
     * Inserts a new item at a given index
     *
     * @param int $index The index where the item is to be inserted
     * @param string $text Item's text
     */
    public function insertAt(int $index, string $text): void {}

    /**
     * Returns the number of items in the combobox
     *
     * @return int
     */
    public function numItems(): int {}
}

/**
 * Base class for all controls
 */
abstract class Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Disables the control
     */
    public function disable(): void {}

    /**
     * Enables the control
     */
    public function enable(): void {}

    /**
     * Returns whether the control is enabled or not
     *
     * @return bool
     */
    public function isEnabled(): bool {}

    /**
     * Returns whether the control is enabled to the user or not
     *
     * @return bool
     */
    public function isEnabledToUser(): bool {}

    /**
     * Hides the control
     */
    public function hide(): void {}

    /**
     * Shows the control
     */
    public function show(): void {}

    /**
     * Returns whether the control is a top-level control or not
     *
     * @return bool
     */
    public function isTopLevel(): bool {}

    /**
     * Returns whether the control is visible or not
     *
     * @return bool
     */
    public function isVisible(): bool {}
}

/**
 * Ardillo DateTimePicker base class
 */
class DateTimePicker extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new DateTimePicker instance
     */
    public function __construct() {}

    /**
     * Returns whether the date time picker is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current date time selection
     *
     * @return \DateTimeImmutable
     */
    public function getTime(): \DateTimeImmutable {}

    /**
     * Sets the date time selection
     *
     * @param \DateTimeInterface $time The date time to be set
     */
    public function setTime(\DateTimeInterface $time): void {}

    /**
     * Callback to be executed when the date time selection is changed
     */
    public function onChanged(): void {}
}

/**
 * Ardillo DrawBrush base class
 */
class DrawBrush
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns whether the brush is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the brush type
     *
     * @return int
     */
    public function getType(): int {}

    /**
     * Sets the brush type
     *
     * @param int $type The brush type (use the DrawBrushType class integer constants)
     */
    public function setType(int $type): void {}

    /**
     * Returns the brush color
     *
     * @return Color
     */
    public function getColor(): Color {}

    /**
     * Sets the brush color
     *
     * @param Color $color The brush color
     */
    public function setColor(Color $color): void {}

    /**
     * Return the brush's point0 (needs to be better documented in the upstream)
     *
     * @return Point
     */
    public function getPoint0(): Point {}

    /**
     * Sets the brush's point0
     *
     * @param Point $point The brush's point0 (needs to be better documented in the upstream)
     */
    public function setPoint0(Point $point): void {}

    /**
     * Return the brush's point1 (needs to be better documented in the upstream)
     *
     * @return Point
     */
    public function getPoint1(): Point {}

    /**
     * Sets the brush's point1
     *
     * @param Point $point The brush's point1 (needs to be better documented in the upstream)
     */
    public function setPoint1(Point $point): void {}

    /**
     * Returns brush's outer radius
     *
     * @return float
     */
    public function getOuterRadius(): float {}

    /**
     * Sets the brush's outer radius
     *
     * @param float $outerRadius The brush's outer radius
     */
    public function setOuterRadius(float $outerRadius): void {}

    /**
     * Returns brush's grandient stops
     *
     * @return DrawBrushGradientStop
     */
    public function getStops(): DrawBrushGradientStop {}

    /**
     * Sets the brush's gradient stops
     *
     * @param DrawBrushGradientStop $stops The brush's gradient stops
     */
    public function setStops(DrawBrushGradientStop $stops): void {}

    /**
     * Returns brush's grandient stop count
     *
     * @return int
     */
    public function getNumStops(): int {}

    /**
     * Sets the brush's gradient stop count
     *
     * @param int $numStops The brush's gradient stop count
     */
    public function setNumStops(int $numStops): void {}
}

/**
 * Ardillo DrawBrushGradientStop base class
 */
class DrawBrushGradientStop
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns stop's position
     *
     * @return float
     */
    public function getPos(): float {}

    /**
     * Sets the stop's position
     *
     * @param float $pos The stop's position
     */
    public function setPos(float $pos): void {}

    /**
     * Returns stop's color
     *
     * @return Color
     */
    public function getColor(): Color {}

    /**
     * Sets the stop's color
     *
     * @param Color $color The stop's color
     */
    public function setColor(Color $color): void {}
}

/**
 * Ardillo DrawMatrix base class
 */
class DrawMatrix
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns whether the matrix is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Sets the matrix to the identity matrix
     */
    public function setIdentity(): void {}

    /**
     * Applies a translation to the matrix
     *
     * @param float $x The X coordinate of the translation
     * @param float $y The Y coordinate of the translation
     */
    public function translate(float $x, float $y): void {}
}

/**
 * Ardillo DrawStrokeParams base class
 */
class DrawStrokeParams
{
    /** @var float */ public const DEFAULT_MITER_LIMIT = 10.0;

    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns whether the stroke parameters are valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the stroke cap
     *
     * @return int
     */
    public function getCap(): int {}

    /**
     * Sets the stroke cap
     *
     * @param int $cap The stroke cap (use the DrawLineCap class integer constants)
     */
    public function setCap(int $cap): void {}

    /**
     * Returns the stroke join
     *
     * @return int
     */
    public function getJoin(): int {}

    /**
     * Sets the stroke join
     *
     * @param int $join The stroke join (use the DrawLineJoin class integer constants)
     */
    public function setJoin(int $join): void {}

    /**
     * Returns the stroke thickness
     *
     * @return float
     */
    public function getThickness(): float {}

    /**
     * Sets the stroke thickness
     *
     * @param float $thickness The stroke thickness
     */
    public function setThickness(float $thickness): void {}

    /**
     * Returns the stroke miter limit
     *
     * @return float
     */
    public function getMiterLimit(): float {}

    /**
     * Sets the stroke miter limit
     *
     * @param float $miterLimit The stroke miter limit
     */
    public function setMiterLimit(float $miterLimit): void {}

    /**
     * Returns the stroke dash
     *
     * @return float
     */
    public function getDashes(): float {}

    /**
     * Sets the stroke dash
     *
     * @param float $dashes The stroke dash phase
     */
    public function setDashes(float $dashes): void {}

    /**
     * Returns the stroke dash count
     *
     * @return int
     */
    public function getNumDashes(): int {}

    /**
     * Sets the stroke dash count
     *
     * @param int $numDashes The stroke dash count
     */
    public function setNumDashes(int $numDashes): void {}

    /**
     * Returns the stroke dash phase
     *
     * @return float
     */
    public function getDashPhase(): float {}

    /**
     * Sets the stroke dash phase
     *
     * @param float $dashPhase The stroke dash phase
     */
    public function setDashPhase(float $dashPhase): void {}
}

/**
 * Ardillo DrawTextLayoutParams base class
 */
class DrawTextLayoutParams
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the default font
     *
     * @return FontDescriptor
     */
    public function getDefaultFont(): FontDescriptor {}

    /**
     * Sets the default font
     *
     * @param FontDescriptor $defaultFont The default font
     */
    public function setDefaultFont(FontDescriptor $defaultFont): void {}

    /**
     * Returns the width
     *
     * @return float
     */
    public function getWidth(): float {}

    /**
     * Sets the width
     *
     * @param float $width The width
     */
    public function setWidth(float $width): void {}

    /**
     * Returns the alignment setting
     *
     * @return int
     */
    public function getAlign(): int {}

    /**
     * Sets the alignment setting
     *
     * @param int $align The alignment setting (use the DrawTextAlign class integer constants)
     */
    public function setAlign(int $align): void {}
}

/**
 * Ardillo EditableCombobox base class
 */
class EditableCombobox extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new EditableCombobox instance
     */
    public function __construct() {}

    /**
     * Returns whether the editable combobox is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current text
     *
     * @return string
     */
    public function getText(): string {}

    /**
     * Sets the text
     *
     * @param string $text The text to be set
     */
    public function setText(string $text): void {}

    /**
     * Callback to be executed when the text is changed
     */
    public function onChanged(): void {}

    /**
     * Appends a new item to the editable combobox
     *
     * @param string $text Item's text
     */
    public function append(string $text): void {}
}

/**
 * Ardillo Entry base class
 */
class Entry extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Entry instance
     */
    public function __construct() {}

    /**
     * Returns whether the text entry is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the text entry is read-only or not
     *
     * @return bool
     */
    public function getReadOnly(): bool {}

    /**
     * Sets whether the text entry is read-only or not
     *
     * @param bool $readonly
     */
    public function setReadOnly(bool $readonly): void {}

    /**
     * Returns the current text
     *
     * @return string
     */
    public function getText(): string {}

    /**
     * Sets the text
     *
     * @param string $text The text to be set
     */
    public function setText(string $text): void {}

    /**
     * Callback to be executed when the text is changed
     */
    public function onChanged(): void {}
}

/**
 * Ardillo FontButton base class
 */
class FontButton extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new FontButton instance
     */
    public function __construct() {}

    /**
     * Returns whether the font button is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Callback to be executed when the font selection is changed
     */
    public function onChanged(): void {}

    /**
     * Returns the current selected font
     *
     * @return FontDescriptor
     */
    public function getFont(): FontDescriptor {}
}

/**
 * Ardillo FontDescriptor base class
 */
class FontDescriptor
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the font's family
     */
    public function getFamily(): string {}

    /**
     * Sets the font's family
     *
     * @param string $family The font's family
     */
    public function setFamily(string $family): void {}

    /**
     * Returns the font's size
     */
    public function getSize(): float {}

    /**
     * Sets the font's size
     *
     * @param float $size The font's size
     */
    public function setSize(float $size): void {}

    /**
     * Returns the font's weight
     */
    public function getWeight(): int {}

    /**
     * Sets the font's weight (use the FontWeight class integer constants)
     *
     * @param int $weight The font's weight
     */
    public function setWeight(int $weight): void {}

    /**
     * Returns the font's italic flag
     */
    public function getItalic(): int {}

    /**
     * Sets the font's italic flag (use the FontItalic class integer constants)
     *
     * @param int $italic The font's italic flag
     */
    public function setItalic(int $italic): void {}

    /**
     * Returns the font's stretch flag
     */
    public function getStretch(): int {}

    /**
     * Sets the font's stretch flag (use the FontStretch class integer constants)
     *
     * @param int $stretch The font's stretch flag
     */
    public function setStretch(int $stretch): void {}
}

/**
 * Ardillo Form base class
 */
class Form extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Form instance
     */
    public function __construct() {}

    /**
     * Returns whether the form is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the form is padded or not
     *
     * @return bool
     */
    public function getPadded(): bool {}

    /**
     * Sets whether the form is padded or not
     *
     * @param bool $padded
     */
    public function setPadded(bool $padded): void {}

    /**
     * Appends a child control to the form
     *
     * @param string $label The label to be used
     * @param Control $child The child control to be appended
     * @param bool $stretchy Whether the child should be stretched or not
     */
    public function append(string $label, Control $c, bool $stretchy): void {}

    /**
     * Deletes a child at a given index
     *
     * @param int $index The index of the child to be deleted
     */
    public function delete(int $index): void {}

    /**
     * Returns the current children count
     *
     * @return int
     */
    public function childrenCount(): int {}
}

/**
 * Ardillo Grid base class
 */
class Grid extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Grid instance
     */
    public function __construct() {}

    /**
     * Returns whether the grid is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the grid is padded or not
     *
     * @return bool
     */
    public function getPadded(): bool {}

    /**
     * Sets whether the grid is padded or not
     *
     * @param bool $padded
     */
    public function setPadded(bool $padded): void {}

    /**
     * Appends a child control to the grid
     *
     * @param Control $child The child control to be appended
     * @param int $left The left position
     * @param int $top The top position
     * @param int $xspan The horizontal span
     * @param int $yspan The vertical span
     * @param bool $hexpand Whether the child should be horizontally expanded or not
     * @param int $halign The horizontal alignment (use the Align class integer constants)
     * @param bool $vexpand Whether the child should be vertically expanded or not
     * @param int $valign The vertical alignment (use the Align class integer constants)
     */
    public function append(Control $c, int $left, int $top, int $xspan, int $yspan, bool $hexpand, int $halign, bool $vexpand, int $valign): void {}
    public function insertAt(Control $c, Control $existing, At $at, int $xspan, int $yspan, bool $hexpand, int $halign, bool $vexpand, int $valign): void {}
}

/**
 * Ardillo Group base class
 */
class Group extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Group instance
     *
     * @param string $title The group title
     */
    public function __construct(string $title) {}

    /**
     * Returns whether the group is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the group is margined or not
     *
     * @return bool
     */
    public function getMargined(): bool {}

    /**
     * Sets whether the group is margined or not
     *
     * @param bool $margined
     */
    public function setMargined(bool $margined): void {}

    /**
     * Returns the group title
     *
     * @return string
     */
    public function getTitle(): string {}

    /**
     * Sets the group title
     *
     * @param string $title The group title
     */
    public function setTitle(string $title): void {}

    /**
     * Appends a child control to the group
     *
     * @param Control $child The child control to be appended
     */
    public function setChild(Control $c): void {}
}

/**
 * Ardillo Image base class
 */
class Image
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Image instance
     *
     * @param float $width The image width
     * @param float $height The image height
     */
    public function __construct(float $width, float $height) {}

    /**
     * Returns whether the image is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Appends a binary representation of the image
     *
     * @param array $pixels Array of image representation pixels (as Color objects)
     * @param Size $size Size of the image representation
     */
    public function append(array $pixels, Size $size): void {}
}

/**
 * Ardillo Label base class
 */
class Label extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Label instance
     *
     * @param string $text The label text
     */
    public function __construct(string $text) {}

    /**
     * Returns whether the label is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current label text
     *
     * @return string
     */
    public function getText(): string {}

    /**
     * Sets the label text
     *
     * @param string $text The label text
     */
    public function setText(string $text): void {}
}

/**
 * Ardillo MultilineEntry base class
 */
class MultilineEntry extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new MultilineEntry instance
     */
    public function __construct() {}

    /**
     * Returns whether the multiline entry is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the multiline entry is read-only or not
     *
     * @return bool
     */
    public function getReadOnly(): bool {}

    /**
     * Sets whether the multiline entry is read-only or not
     *
     * @param bool $readonly
     */
    public function setReadOnly(bool $readonly): void {}

    /**
     * Returns the current text
     *
     * @return string
     */
    public function getText(): string {}

    /**
     * Sets the text
     *
     * @param string $text The text to be set
     */
    public function setText(string $text): void {}

    /**
     * Callback to be executed when the text is changed
     */
    public function onChanged(): void {}

    /**
     * Appends a string to the multiline entry
     *
     * @param string $text The text to be appended
     */
    public function append(string $text): void {}
}

/**
 * Ardillo ProgressBar base class
 */
class ProgressBar extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new ProgressBar instance
     */
    public function __construct() {}

    /**
     * Returns whether the progress bar is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current progress value
     *
     * @return int
     */
    public function getValue(): int {}

    /**
     * Sets the progress value
     *
     * @param int $value The progress value
     */
    public function setValue(int $n): void {}
}

/**
 * Ardillo RadioButtons base class
 */
class RadioButtons extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new RadioButtons instance
     */
    public function __construct() {}

    /**
     * Returns whether the radio buttons are valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current selection index
     *
     * @return int
     */
    public function getSelected(): int {}

    /**
     * Sets the selection index
     *
     * @param int $index The index of the radio button to be set
     */
    public function setSelected(int $index): void {}

    /**
     * Callback to be executed when the selection is changed
     */
    public function onSelected(): void {}

    /**
     * Appends a new radio button item
     *
     * @param string $text Item's text
     */
    public function append(string $text): void {}
}

/**
 * Ardillo Separator base class
 */
class Separator extends Control
{
    /** @var App Associated App instance */
    public App $app;
}

/**
 * Ardillo Slider base class
 */
class Slider extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Slider instance
     *
     * @param int $min The minimum value
     * @param int $max The maximum value
     */
    public function __construct(int $min, int $max) {}

    /**
     * Returns whether the slider is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the slider has tooltips enabled or not
     *
     * @return bool
     */
    public function getHasToolTip(): bool {}

    /**
     * Sets whether the slider has tooltips enabled or not
     *
     * @param bool $hasToolTip
     */
    public function setHasToolTip(bool $hasToolTip): void {}

    /**
     * Returns the current value
     *
     * @return int
     */
    public function getValue(): int {}

    /**
     * Sets the value
     *
     * @param int $value The value to be set
     */
    public function setValue(int $value): void {}

    /**
     * Callback to be executed when the value is changed
     */
    public function onChanged(): void {}

    /**
     * Callback to be executed when the slider button is being released
     */
    public function onReleased(): void {}

    /**
     * Updates the slider range
     *
     * @param int $min The minimum value
     * @param int $max The maximum value
     */
    public function setRange(int $min, int $max): void {}
}

/**
 * Ardillo Spinbox base class
 */
class Spinbox extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Spinbox instance
     *
     * @param int $min The minimum value
     * @param int $max The maximum value
     */
    public function __construct(int $min, int $max) {}

    /**
     * Returns whether the spinbox is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the current value
     *
     * @return int
     */
    public function getValue(): int {}

    /**
     * Sets the value
     *
     * @param int $value The value to be set
     */
    public function setValue(int $value): void {}

    /**
     * Callback to be executed when the value is changed
     */
    public function onChanged(): void {}
}

/**
 * Ardillo Tab base class
 */
class Tab extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Tab instance
     */
    public function __construct() {}

    /**
     * Returns whether the tab is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether a tab at a given index is margined or not
     *
     * @return bool
     */
    public function getMargined(int $index): bool {}

    /**
     * Sets whether a tab at a given index is margined or not
     *
     * @param bool $margined
     */
    public function setMargined(int $index, bool $margined): void {}

    /**
     * Appends a control in form of a page/tab with label
     *
     * @param string $label The label to be used
     * @param Control $child The child control to be appended
     */
    public function append(string $name, Control $c): void {}

    /**
     * Deletes a child at a given index
     *
     * @param int $index The index of the child to be deleted
     */
    public function delete(int $index): void {}

    /**
     * Inserts a control in form of a page/tab with label at a given index
     *
     * @param string $label The label to be used
     * @param int $index The index where the child should be inserted
     * @param Control $child The child control to be appended
     */
    public function insertAt(string $name, int $index, Control $c): void {}

    /**
     * Returns the current tab/page count
     *
     * @return int
     */
    public function pageCount(): int {}
}

/**
 * Ardillo Table base class
 */
class Table extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Table instance
     *
     * @param TableParams $params The table parameters
     */
    public function __construct(TableParams $params) {}

    /**
     * Returns whether the table is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the width of a column at a given index
     *
     * @param int $column The column index
     * @return int
     */
    public function getColumnWidth(int $column): int {}

    /**
     * Sets the width of a column at a given index
     *
     * @param int $column The column index
     * @param int $width The width to be set
     */
    public function setColumnWidth(int $column, int $width): void {}

    /**
     * Returns the sort indicator of a column at a given index
     *
     * @param int $column The column index
     * @return int
     */
    public function getHeaderSortIndicator(int $column): int {}

    /**
     * Sets the sort indicator of a column at a given index
     *
     * @param int $column The column index
     * @param int $indicator The sort indicator to be set (use the TableSortIndicator class integer constants)
     */
    public function setHeaderSortIndicator(int $column, int $indicator): void {}

    /**
     * Returns whether the table header is visible or not
     *
     * @return bool
     */
    public function getHeaderVisible(): bool {}

    /**
     * Sets whether the table header is visible or not
     *
     * @param bool $visible
     */
    public function setHeaderVisible(bool $visible): void {}

    /**
     * Returns the current table selection mode
     *
     * @return int
     */
    public function getSelectionMode(): int {}

    /**
     * Sets the table selection mode
     *
     * @param int $mode The selection mode to be set (use the TableSelectionMode class integer constants)
     */
    public function setSelectionMode(int $mode): void {}

    /**
     * Callback to be executed when the table header is clicked
     *
     * @param int $column The index of the column that was clicked
     */
    public function onHeaderClicked(int $column): void {}

    /**
     * Callback to be executed when a row is clicked
     *
     * @param int $row The index of the row that was clicked
     */
    public function onRowClicked(int $row): void {}

    /**
     * Callback to be executed when a row is double-clicked
     *
     * @param int $row The index of the row that was double-clicked
     */
    public function onRowDoubleClicked(int $row): void {}

    /**
     * Appends a button columnt to the table
     *
     * @param string $name The column name
     * @param int $buttonModelColumn The model column that will be used to get the button text
     * @param int $buttonClickableModelColumn Use TableModelColumn class integer constants
     */
    public function appendButtonColumn(string $name, int $buttonModelColumn, int $buttonClickableModelColumn): void {}

    /**
     * Appends a checkbox column to the table
     *
     * @param string $name The column name
     * @param int $checkboxModelColumn The model column that will be used to get the checkbox state
     * @param int $checkboxEditableModelColumn Use TableModelColumn class integer constants
     */
    public function appendCheckboxColumn(string $name, int $checkboxModelColumn, int $checkboxEditableModelColumn): void {}

    /**
     * Appends a checkbox text column to the table
     *
     * @param string $name The column name
     * @param int $checkboxModelColumn The model column that will be used to get the checkbox state
     * @param int $checkboxEditableModelColumn Use TableModelColumn class integer constants
     * @param int $textModelColumn The model column that will be used to get the text
     * @param int $textEditableModelColumn Use TableModelColumn class integer constants
     * @param TableTextColumnOptionalParams $textParams The text column optional parameters
     */
    public function appendCheckboxTextColumn(string $name, int $checkboxModelColumn, int $checkboxEditableModelColumn, int $textModelColumn, int $textEditableModelColumn, ?TableTextColumnOptionalParams $textParams): void {}

    /**
     * Appends an image column to the table
     *
     * @param string $name The column name
     * @param int $imageModelColumn The model column that will be used to get the image
     */
    public function appendImageColumn(string $name, int $imageModelColumn): void {}

    /**
     * Appends an image text column to the table
     *
     * @param string $name The column name
     * @param int $imageModelColumn The model column that will be used to get the image
     * @param int $textModelColumn The model column that will be used to get the text
     * @param int $textEditableModelColumn Use TableModelColumn class integer constants
     * @param TableTextColumnOptionalParams $textParams The text column optional parameters
     */
    public function appendImageTextColumn(string $name, int $imageModelColumn, int $textModelColumn, int $textEditableModelColumn, ?TableTextColumnOptionalParams $textParams): void {}

    /**
     * Appends a progress bar column to the table
     *
     * @param string $name The column name
     * @param int $progressModelColumn The model column that will be used to get the progress value
     */
    public function appendProgressBarColumn(string $name, int $progressModelColumn): void {}

    /**
     * Appends a text column to the table
     *
     * @param string $name The column name
     * @param int $textModelColumn The model column that will be used to get the text
     * @param int $textEditableModelColumn Use TableModelColumn class integer constants
     * @param TableTextColumnOptionalParams $textParams The text column optional parameters
     */
    public function appendTextColumn(string $name, int $textModelColumn, int $textEditableModelColumn, ?TableTextColumnOptionalParams $textParams): void {}

    /**
     * Callback to be executed when the table selection is updated
     *
     * @param array $selection List of row indices which are selected
     */
    public function onSelectionChanged(array $selection): void {}

    /**
     * Sets the current table selection
     *
     * @param array $selection List of row indices to be selected
     */
    public function setSelection(array $selection): void {}
}

/**
 * Ardillo TableModel base class
 */
class TableModel
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new TableModel instance
     *
     * @param TableModelHandler $mh The table model handler
     */
    public function __construct(TableModelHandler $mh) {}

    /**
     * Returns whether the table model is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Informs the table model a row has changed
     *
     * @param int $index Index of the affected row
     */
    public function rowChanged(int $index): void {}

    /**
     * Informs the table model a row has been deleted
     *
     * @param int $oldIndex Index of the deleted row
     */
    public function rowDeleted(int $oldIndex): void {}

    /**
     * Informs the table model a row has been inserted
     *
     * @param int $newIndex Index of the inserted row
     */
    public function rowInserted(int $newIndex): void {}
}

/**
 * Ardillo TableModelHandler base class
 */
class TableModelHandler
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns whether the table model handler is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Method invoked to get the value of a cell
     *
     * @param TableModel $m The table model
     * @param int $row The row index
     * @param int $column The column index
     * @return TableValue
     */
    abstract public function cellValueHandler(TableModel $m, int $row, int $column): TableValue {}

    /**
     * Method invoked to get the type of a column
     *
     * @param TableModel $m The table model
     * @param int $column The column index
     * @return int use the TableValueType class integer constants
     */
    abstract public function columnTypeHandler(TableModel $model, int $column): int {}

    /**
     * Method invoked to get the number of columns
     *
     * @param TableModel $m The table model
     * @return int
     */
    abstract public function numColumnsHandler(TableModel $model): int {}

    /**
     * Method invoked to get the number of rows
     *
     * @param TableModel $m The table model
     * @return int
     */
    abstract public function numRowsHandler(TableModel $model): int {}

    /**
     * Method invoked to set the value of a cell (as updated by the user)
     *
     * @param TableModel $m The table model
     * @param int $row The row index
     * @param int $column The column index
     * @param TableValue $value New table cell value
     */
    abstract public function setCellValueHandler(TableModel $model, int $row, int $column, ?TableValue $value): void {}
}

/**
 * Ardillo TableParams base class
 */
class TableParams
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns whether the table parameters are valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the configured table model
     *
     * @return TableModel
     */
    public function getModel(): TableModel {}

    /**
     * Sets the table model
     *
     * @param TableModel $model The table model
     */
    public function setModel(TableModel $model): void {}

    /**
     * Returns the configured column background color model column
     *
     * @return int
     */
    public function getRowBackgroundColorModelColumn(): int {}

    /**
     * Sets the column background color model column
     *
     * @param int $rowBackgroundColorModelColumn The column background color model column
     */
    public function setRowBackgroundColorModelColumn(int $rowBackgroundColorModelColumn): void {}
}

/**
 * Ardillo TableTextColumnOptionalParams base class
 */
class TableTextColumnOptionalParams
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns whether the table text column optional parameters are valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the configured column color model column
     *
     * @return int
     */
    public function getColorModelColumn(): int {}

    /**
     * Sets the column color model column
     *
     * @param int $colorModelColumn The column color model column
     */
    public function setColorModelColumn(int $colorModelColumn): void {}
}

/**
 * Ardillo TableValue base class
 */
abstract class TableValue
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Returns the table value type (as a TableValueType class integer constant)
     *
     * @return int
     */
    public function getType(): int {}
}

/**
 * Ardillo Window base class
 */
class Window extends Control
{
    /** @var int */ public const MESSAGE_BOX_DEFAULT = 0;
    /** @var int */ public const MESSAGE_BOX_ERROR = 1;

    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Window instance
     *
     * @param string $title The window title
     * @param Size $size The window size
     * @param bool $hasMenubar Whether the window has a menu bar or not
     */
    public function __construct(string $title, Size $size, bool $hasMenubar) {}

    /**
     * Returns whether the window is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns whether the window is borderless or not
     *
     * @return bool
     */
    public function getBorderless(): bool {}

    /**
     * Sets whether the window is borderless or not
     *
     * @param bool $borderless
     */
    public function setBorderless(bool $borderless): void {}

    /**
     * Returns the window's size
     *
     * @return Size
     */
    public function getContentSize(): Size {}

    /**
     * Sets the window's size
     *
     * @param Size $size The window's size
     */
    public function setContentSize(Size $size): void {}

    /**
     * Returns whether the window is fullscreen or not
     *
     * @return bool
     */
    public function getFullscreen(): bool {}

    /**
     * Sets whether the window is fullscreen or not
     *
     * @param bool $fullscreen
     */
    public function setFullscreen(bool $fullscreen): void {}

    /**
     * Returns whether the window is margined or not
     *
     * @return bool
     */
    public function getMargined(): bool {}

    /**
     * Sets whether the window is margined or not
     *
     * @param bool $margined
     */
    public function setMargined(bool $margined): void {}

    /**
     * Returns the window's position
     *
     * @return Point
     */
    public function getPosition(): Point {}

    /**
     * Sets the window's position
     *
     * @param Point $pos The window's position
     */
    public function setPosition(Point $pos): void {}

    /**
     * Returns whether the window is resizable or not
     *
     * @return bool
     */
    public function getResizeable(): bool {}

    /**
     * Sets whether the window is resizable or not
     *
     * @param bool $resizeable
     */
    public function setResizeable(bool $resizeable): void {}

    /**
     * Returns the window's title
     *
     * @return string
     */
    public function getTitle(): string {}

    /**
     * Sets the window's title
     *
     * @param string $title The window's title
     */
    public function setTitle(string $title): void {}

    /**
     * Callback executed when the window is being closed
     *
     * @return int Return 0 to prevent the window from closing
     */
    public function onClosing(): int {}

    /**
     * Callback executed when the window is resized
     */
    public function onContentSizeChanged(): void {}

    /**
     * Callback executed when the window loses/gains focus
     */
    public function onFocusChanged(): void {}

    /**
     * Callback executed when the window is moved
     */
    public function onPositionChanged(): void {}

    /**
     * Returns whether the window is focused or not
     *
     * @return bool
     */
    public function isFocused(): bool {}

    /**
     * Appends a control to the window
     *
     * @param Control $child The child control to be appended
     */
    public function setChild(Control $child): void {}

    /**
     * Shows a message box
     *
     * @param int $type The message box type (use the MESSAGE_BOX_* class integer constants)
     * @param string $title The message box title
     * @param string $content The message box content
     */
    public function messageBox(int $type, string $title, string $content): void {}

    /**
     * Displays OS's directory open directory dialog
     *
     * @return string|null
     */
    public function openFolder(): ?string {}

    /**
     * Displays OS's file open dialog
     *
     * @return string|null
     */
    public function openFile(): ?string {}

    /**
     * Displays OS's file save dialog
     *
     * @return string|null
     */
    public function saveFile(): ?string {}
}

/**
 * Ardillo Area base class
 */
class Area extends Control
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new Area instance
     *
     * @param AreaHandler $ah The area handler
     */
    public function __construct(AreaHandler $ah) {}

    /**
     * Returns whether the area is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Schedules a redraw of the area
     */
    public function queueRedrawAll(): void {}
}

/**
 * Ardillo DrawPath base class
 */
class DrawPath
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new DrawPath instance
     *
     * @param int $fillMode The fill mode (use the FillMode class integer constants)
     */
    public function __construct(int $fillMode) {}

    /**
     * Returns whether the draw path is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Adds a rectangle to the draw path
     *
     * @param Point $pt The rectangle's top-left point
     * @param Size $size The rectangle's size
     */
    public function addRectangle(Point $pt, Size $size): void {}

    /**
     * Adds a figure to the draw path
     *
     * @param float $x The figure's X coordinate
     * @param float $y The figure's Y coordinate
     */
    public function newFigure(float $x, float $y): void {}

    /**
     * Closes the current figure
     */
    public function closeFigure(): void {}

    /**
     * Adds a line to the draw path
     *
     * @param float $x The line's ending X coordinate
     * @param float $y The line's ending Y coordinate
     */
    public function lineTo(float $x, float $y): void {}

    /**
     * Ends the draw path
     */
    public function end(): void {}
}

/**
 * Ardillo HorizontalBox base class
 */
class HorizontalBox extends Box
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new HorizontalBox instance
     */
    public function __construct() {}

    /**
     * Returns whether the horizontal box is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo VerticalBox base class
 */
class VerticalBox extends Box
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new VerticalBox instance
     */
    public function __construct() {}

    /**
     * Returns whether the vertical box is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo DatePicker base class
 */
class DatePicker extends DateTimePicker
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new DatePicker instance
     */
    public function __construct() {}

    /**
     * Returns whether the date picker is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo DateTimePicker base class
 */
class TimePicker extends DateTimePicker
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new TimePicker instance
     */
    public function __construct() {}

    /**
     * Returns whether the time picker is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo PasswordEntry base class
 */
class PasswordEntry extends Entry
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new PasswordEntry instance
     */
    public function __construct() {}

    /**
     * Returns whether the password entry is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo SearchEntry base class
 */
class SearchEntry extends Entry
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new SearchEntry instance
     */
    public function __construct() {}

    /**
     * Returns whether the search entry is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo NonWrappingMultilineEntry base class
 */
class NonWrappingMultilineEntry extends MultilineEntry
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new NonWrappingMultilineEntry instance
     */
    public function __construct() {}

    /**
     * Returns whether the non-wrapping multiline entry is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo HorizontalSeparator base class
 */
class HorizontalSeparator extends Separator
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new HorizontalSeparator instance
     */
    public function __construct() {}

    /**
     * Returns whether the horizontal separator is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo VerticalSeparator base class
 */
class VerticalSeparator extends Separator
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new VerticalSeparator instance
     */
    public function __construct() {}

    /**
     * Returns whether the vertical separator is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}
}

/**
 * Ardillo TableValueString base class
 */
class TableValueString extends TableValue
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new TableValueString instance
     *
     * @param string $str The string value
     */
    public function __construct(string $str) {}

    /**
     * Returns whether the table value is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the table cell value
     *
     * @return string
     */
    public function get(): string {}
}

/**
 * Ardillo TableValueImage base class
 */
class TableValueImage extends TableValue
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new TableValueImage instance
     *
     * @param Image $img The image value
     */
    public function __construct(Image $img) {}

    /**
     * Returns whether the table value is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the table cell value
     *
     * @return Image
     */
    public function get(): Image {}
}

/**
 * Ardillo TableValueInt base class
 */
class TableValueInt extends TableValue
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new TableValueInt instance
     *
     * @param int $i The integer value
     */
    public function __construct(int $i) {}

    /**
     * Returns whether the table value is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the table cell value
     *
     * @return int
     */
    public function get(): int {}
}

/**
 * Ardillo TableValueColor base class
 */
class TableValueColor extends TableValue
{
    /** @var App Associated App instance */
    public App $app;

    /**
     * Creates a new TableValueColor instance
     *
     * @param Color $color The color value
     */
    public function __construct(Color $color) {}

    /**
     * Returns whether the table value is valid or not
     *
     * @return bool
     */
    public function isValid(): bool {}

    /**
     * Returns the table cell value
     *
     * @return Color
     */
    public function get(): Color {}
}
