// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "Compositor.h"

#include "InputMethodManagerV2.h"
#include "TextInputManagerV3.h"
#include "VirtualKeyboardManagerV1.h"

Compositor::Compositor()
    : QWaylandCompositor()
{
}

Compositor::~Compositor() { }

void Compositor::create()
{
    QWaylandCompositor::create();

    m_textInputManager = new TextInputManagerV3(display(), TextInputManagerV3::interface()->version);
    m_textInputMethodManager =
        new InputMethodManagerV2(display(), InputMethodManagerV2::interface()->version);
    m_virtualKeyboardManager =
        new VirtualKeyboardManagerV1(display(), VirtualKeyboardManagerV1::interface()->version);
}
