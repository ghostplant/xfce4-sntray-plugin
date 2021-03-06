/*
 * Copyright (C) 2017 <davidedmundson@kde.org> David Edmundson
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef XCBUTILS_H
#define XCBUTILS_H

#include <gdk/gdkx.h>
#include <stdbool.h>
#include <xcb/xcb.h>

/* X11 data types */
extern xcb_atom_t a_UTF8_STRING;
extern xcb_atom_t a_XROOTPMAP_ID;
/* SYSTEM TRAY spec */
extern xcb_atom_t a_KDE_NET_WM_SYSTEM_TRAY_WINDOW_FOR;
extern xcb_atom_t a_NET_SYSTEM_TRAY_OPCODE;
extern xcb_atom_t a_NET_SYSTEM_TRAY_MESSAGE_DATA;
extern xcb_atom_t a_NET_SYSTEM_TRAY_ORIENTATION;
extern xcb_atom_t a_NET_SYSTEM_TRAY_VISUAL;
extern xcb_atom_t a_MANAGER;

/* SYSTEM TRAY Protocol constants. */
#define SYSTEM_TRAY_REQUEST_DOCK 0
#define SYSTEM_TRAY_BEGIN_MESSAGE 1
#define SYSTEM_TRAY_CANCEL_MESSAGE 2

#define SYSTEM_TRAY_ORIENTATION_HORZ 0
#define SYSTEM_TRAY_ORIENTATION_VERT 1

void resolve_atoms(xcb_connection_t *con);
xcb_connection_t *gdk_x11_get_default_xcb_connection();
xcb_connection_t *gdk_x11_display_get_xcb_connection(GdkX11Display *display);
void gdk_x11_display_set_composited_for_xcb_window(GdkX11Display *display, xcb_window_t win,
                                                   bool composited);
xcb_screen_t *xcb_screen_of_display(xcb_connection_t *c, int screen);

#endif // XCBUTILS_H
