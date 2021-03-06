/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2017 Rekols
 *
 * Author:     Rekols <rekols@foxmail.com>
 * Maintainer: Rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tabbar.h"

TabBar::TabBar(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    tabBar = new QTabBar();
    icon = new QSvgWidget(":/images/logo.svg");

    layout->setMargin(0);
    layout->addSpacing(5);
    layout->addWidget(icon);
    layout->addSpacing(5);
    layout->addWidget(tabBar);
    layout->addStretch();

    tabBar->addTab("Home");
    tabBar->addTab("Cleaner");

    icon->setFixedSize(22, 22);

    connect(tabBar, &QTabBar::currentChanged, this, &TabBar::tabBarCurrentChanged);
}

void TabBar::tabBarCurrentChanged()
{
    emit currentChanged(tabBar->currentIndex());
}
