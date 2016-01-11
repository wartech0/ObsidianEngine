#pragma once

#include <atlbase.h>
#include <atlwin.h>

#include "Event.h"

namespace Obsidian
{
	class Engine;

	namespace System
	{
		class GameWindow : public CWindowImpl<GameWindow>
		{
		public:
			GameWindow(Engine* engine);
			void PumpWindowsMessages();
		private:
			BEGIN_MSG_MAP(GameWindow)
				MESSAGE_HANDLER(WM_CLOSE, OnClose)
				MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
			END_MSG_MAP()

			LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL&);
			LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);

			Engine* _engine;
		};
	}
}