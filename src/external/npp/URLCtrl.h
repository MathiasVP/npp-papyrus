// This file is part of Notepad++ project
// Copyright (C)2021 Don HO <don.h@free.fr>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#pragma once

#include "Window.h"
#include "Common.h"

class URLCtrl : public Window {
public:
  URLCtrl():_hfUnderlined(0),_hCursor(0), _msgDest(NULL), _cmdID(0), _oldproc(NULL), \
  _linkColor(), _visitedColor(), _clicking(false), _URL(TEXT("")){};

  void create(HWND itemHandle, const TCHAR * link = nullptr, COLORREF linkColor = RGB(0,0,255)); // PapyrusPlugin modification -- add nullptr as default value for link
  void create(HWND itemHandle, int cmd, HWND msgDest = NULL);
  void destroy();
private:
  void action();
protected :
  generic_string _URL;
  HFONT  _hfUnderlined;
  HCURSOR  _hCursor;

  HWND _msgDest;
  unsigned long _cmdID;

  WNDPROC  _oldproc;
  COLORREF _linkColor;      
  COLORREF _visitedColor;
  bool  _clicking;

  static LRESULT CALLBACK URLCtrlProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
      return ((URLCtrl *)(::GetWindowLongPtr(hwnd, GWLP_USERDATA)))->runProc(hwnd, Message, wParam, lParam);
  };
  LRESULT runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
};

