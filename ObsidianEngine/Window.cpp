#include "Window.h"
#include "Engine.h"

Obsidian::System::GameWindow::GameWindow(Engine * engine)
{
	_engine = engine;
}

void Obsidian::System::GameWindow::PumpWindowsMessages()
{
	MSG msg;
	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT Obsidian::System::GameWindow::OnClose(UINT, WPARAM, LPARAM, BOOL &)
{
	DestroyWindow();
	return LRESULT();
}

LRESULT Obsidian::System::GameWindow::OnDestroy(UINT, WPARAM, LPARAM, BOOL &)
{
	_engine->Shutdown();
	return LRESULT();
}
