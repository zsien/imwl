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

    m_textInputManager = new TextInputManagerV3(this);
    m_textInputManager->init(display());

    m_textInputMethodManager = new InputMethodManagerV2(this);
    m_textInputMethodManager->init(display());

    m_virtualKeyboardManager = new VirtualKeyboardManagerV1(this);
    m_virtualKeyboardManager->init(display());
}
