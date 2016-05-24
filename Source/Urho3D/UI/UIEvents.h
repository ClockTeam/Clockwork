//
// Copyright (c) 2008-2016 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "../Core/Object.h"

namespace Urho3D
{

/// Global mouse click in the UI. Sent by the UI subsystem.
CLOCKWORK_EVENT(E_UIMOUSECLICK, UIMouseClick)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Global mouse click end in the UI. Sent by the UI subsystem.
CLOCKWORK_EVENT(E_UIMOUSECLICKEND, UIMouseClickEnd)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_BEGINELEMENT, BeginElement);    // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Global mouse double click in the UI. Sent by the UI subsystem.
CLOCKWORK_EVENT(E_UIMOUSEDOUBLECLICK, UIMouseDoubleClick)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Mouse click on a UI element. Parameters are same as in UIMouseClick event, but is sent by the element.
CLOCKWORK_EVENT(E_CLICK, Click)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Mouse click end on a UI element. Parameters are same as in UIMouseClickEnd event, but is sent by the element.
CLOCKWORK_EVENT(E_CLICKEND, ClickEnd)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_BEGINELEMENT, BeginElement);    // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Mouse double click on a UI element. Parameters are same as in UIMouseDoubleClick event, but is sent by the element.
CLOCKWORK_EVENT(E_DOUBLECLICK, DoubleClick)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Drag and drop test.
CLOCKWORK_EVENT(E_DRAGDROPTEST, DragDropTest)
{
    CLOCKWORK_PARAM(P_SOURCE, Source);                // UIElement pointer
    CLOCKWORK_PARAM(P_TARGET, Target);                // UIElement pointer
    CLOCKWORK_PARAM(P_ACCEPT, Accept);                // bool
};

/// Drag and drop finish.
CLOCKWORK_EVENT(E_DRAGDROPFINISH, DragDropFinish)
{
    CLOCKWORK_PARAM(P_SOURCE, Source);                // UIElement pointer
    CLOCKWORK_PARAM(P_TARGET, Target);                // UIElement pointer
    CLOCKWORK_PARAM(P_ACCEPT, Accept);                // bool
};

/// Focus element changed.
CLOCKWORK_EVENT(E_FOCUSCHANGED, FocusChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_CLICKEDELEMENT, ClickedElement); // UIElement pointer
}

/// UI element name changed.
CLOCKWORK_EVENT(E_NAMECHANGED, NameChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// UI element resized.
CLOCKWORK_EVENT(E_RESIZED, Resized)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_WIDTH, Width);                  // int
    CLOCKWORK_PARAM(P_HEIGHT, Height);                // int
}

/// UI element positioned.
CLOCKWORK_EVENT(E_POSITIONED, Positioned)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
}

/// UI element visibility changed.
CLOCKWORK_EVENT(E_VISIBLECHANGED, VisibleChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_VISIBLE, Visible);              // bool
}

/// UI element focused.
CLOCKWORK_EVENT(E_FOCUSED, Focused)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_BYKEY, ByKey);                  // bool
}

/// UI element defocused.
CLOCKWORK_EVENT(E_DEFOCUSED, Defocused)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// UI element layout updated.
CLOCKWORK_EVENT(E_LAYOUTUPDATED, LayoutUpdated)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// UI button pressed.
CLOCKWORK_EVENT(E_PRESSED, Pressed)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// UI button was pressed, then released.
CLOCKWORK_EVENT(E_RELEASED, Released)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// UI checkbox toggled.
CLOCKWORK_EVENT(E_TOGGLED, Toggled)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_STATE, State);                  // bool
}

/// UI slider value changed
CLOCKWORK_EVENT(E_SLIDERCHANGED, SliderChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_VALUE, Value);                  // float
}

/// UI slider being paged.
CLOCKWORK_EVENT(E_SLIDERPAGED, SliderPaged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_OFFSET, Offset);                // int
    CLOCKWORK_PARAM(P_PRESSED, Pressed);              // bool
}

/// UI scrollbar value changed.
CLOCKWORK_EVENT(E_SCROLLBARCHANGED, ScrollBarChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_VALUE, Value);                  // float
}

/// UI scrollview position changed.
CLOCKWORK_EVENT(E_VIEWCHANGED, ViewChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
}

/// UI modal changed (currently only Window has modal flag).
CLOCKWORK_EVENT(E_MODALCHANGED, ModalChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_MODAL, Modal);                  // bool
}

/// Text entry into a LineEdit. The char can be modified in the event data.
CLOCKWORK_EVENT(E_TEXTENTRY, CharEntry)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_TEXT, Text);                    // String
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Editable text changed
CLOCKWORK_EVENT(E_TEXTCHANGED, TextChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_TEXT, Text);                    // String
}

/// Text editing finished (enter pressed on a LineEdit)
CLOCKWORK_EVENT(E_TEXTFINISHED, TextFinished)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_TEXT, Text);                    // String
    CLOCKWORK_PARAM(P_VALUE, Value);                 // Float
}

/// Menu selected.
CLOCKWORK_EVENT(E_MENUSELECTED, MenuSelected)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// Listview or DropDownList item selected.
CLOCKWORK_EVENT(E_ITEMSELECTED, ItemSelected)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_SELECTION, Selection);          // int
}

/// Listview item deselected.
CLOCKWORK_EVENT(E_ITEMDESELECTED, ItemDeselected)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_SELECTION, Selection);          // int
}

/// Listview selection change finished.
CLOCKWORK_EVENT(E_SELECTIONCHANGED, SelectionChanged)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// Listview item clicked. If this is a left-click, also ItemSelected event will be sent. If this is a right-click, only this event is sent.
CLOCKWORK_EVENT(E_ITEMCLICKED, ItemClicked)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_ITEM, Item);                    // UIElement pointer
    CLOCKWORK_PARAM(P_SELECTION, Selection);          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Listview item double clicked.
CLOCKWORK_EVENT(E_ITEMDOUBLECLICKED, ItemDoubleClicked)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_ITEM, Item);                    // UIElement pointer
    CLOCKWORK_PARAM(P_SELECTION, Selection);          // int
    CLOCKWORK_PARAM(P_BUTTON, Button);                // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// LineEdit or ListView unhandled key pressed.
CLOCKWORK_EVENT(E_UNHANDLEDKEY, UnhandledKey)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_KEY, Key);                      // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_QUALIFIERS, Qualifiers);        // int
}

/// Fileselector choice.
CLOCKWORK_EVENT(E_FILESELECTED, FileSelected)
{
    CLOCKWORK_PARAM(P_FILENAME, FileName);            // String
    CLOCKWORK_PARAM(P_FILTER, Filter);                // String
    CLOCKWORK_PARAM(P_OK, Ok);                        // bool
}

/// MessageBox acknowlegement.
CLOCKWORK_EVENT(E_MESSAGEACK, MessageACK)
{
    CLOCKWORK_PARAM(P_OK, Ok);                        // bool
}

/// A child element has been added to an element. Sent by the UI root element, or element-event-sender if set.
CLOCKWORK_EVENT(E_ELEMENTADDED, ElementAdded)
{
    CLOCKWORK_PARAM(P_ROOT, Root);                    // UIElement pointer
    CLOCKWORK_PARAM(P_PARENT, Parent);                // UIElement pointer
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// A child element is about to be removed from an element. Sent by the UI root element, or element-event-sender if set.
CLOCKWORK_EVENT(E_ELEMENTREMOVED, ElementRemoved)
{
    CLOCKWORK_PARAM(P_ROOT, Root);                    // UIElement pointer
    CLOCKWORK_PARAM(P_PARENT, Parent);                // UIElement pointer
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// Hovering on an UI element has started
CLOCKWORK_EVENT(E_HOVERBEGIN, HoverBegin)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_ELEMENTX, ElementX);            // int
    CLOCKWORK_PARAM(P_ELEMENTY, ElementY);            // int
}

/// Hovering on an UI element has ended
CLOCKWORK_EVENT(E_HOVEREND, HoverEnd)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
}

/// Drag behavior of a UI Element has started
CLOCKWORK_EVENT(E_DRAGBEGIN, DragBegin)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_ELEMENTX, ElementX);            // int
    CLOCKWORK_PARAM(P_ELEMENTY, ElementY);            // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_NUMBUTTONS, NumButtons);        // int
}

/// Drag behavior of a UI Element when the input device has moved
CLOCKWORK_EVENT(E_DRAGMOVE, DragMove)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_DX, DX);                        // int
    CLOCKWORK_PARAM(P_DY, DY);                        // int
    CLOCKWORK_PARAM(P_ELEMENTX, ElementX);            // int
    CLOCKWORK_PARAM(P_ELEMENTY, ElementY);            // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_NUMBUTTONS, NumButtons);        // int
}

/// Drag behavior of a UI Element has finished
CLOCKWORK_EVENT(E_DRAGEND, DragEnd)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_ELEMENTX, ElementX);            // int
    CLOCKWORK_PARAM(P_ELEMENTY, ElementY);            // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_NUMBUTTONS, NumButtons);        // int
}

/// Drag of a UI Element was canceled by pressing ESC
CLOCKWORK_EVENT(E_DRAGCANCEL, DragCancel)
{
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_ELEMENTX, ElementX);            // int
    CLOCKWORK_PARAM(P_ELEMENTY, ElementY);            // int
    CLOCKWORK_PARAM(P_BUTTONS, Buttons);              // int
    CLOCKWORK_PARAM(P_NUMBUTTONS, NumButtons);        // int
}

/// A file was drag-dropped into the application window. Includes also coordinates and UI element if applicable
CLOCKWORK_EVENT(E_UIDROPFILE, UIDropFile)
{
    CLOCKWORK_PARAM(P_FILENAME, FileName);            // String
    CLOCKWORK_PARAM(P_ELEMENT, Element);              // UIElement pointer
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
    CLOCKWORK_PARAM(P_ELEMENTX, ElementX);            // int (only if element is non-null)
    CLOCKWORK_PARAM(P_ELEMENTY, ElementY);            // int (only if element is non-null)
}

}
