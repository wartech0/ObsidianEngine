#pragma once
#include <Windows.h>

namespace Obsidian
{

	class Event
	{
	public:
		Event() {};

		Event(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			_hwnd = hwnd;
			_msg = msg;
			_wParam = wParam;
			_lParam = lParam;
		};

		UINT GetMessageType() {
			return _msg;
		}

	protected:
		HWND _hwnd;
		UINT _msg;
		WPARAM _wParam;
		LPARAM _lParam;
	};
}