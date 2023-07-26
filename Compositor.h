// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <QtWaylandCompositor/QWaylandCompositor>

class TextInputManagerV3;
class InputMethodManagerV2;
class VirtualKeyboardManagerV1;

class Compositor : public QWaylandCompositor
{
    Q_OBJECT

public:
    Compositor();
    ~Compositor() override;

    void create() override;

private:
    TextInputManagerV3 *m_textInputManager;
    InputMethodManagerV2 *m_textInputMethodManager;
    VirtualKeyboardManagerV1 *m_virtualKeyboardManager;
};

#endif // COMPOSITOR_H
