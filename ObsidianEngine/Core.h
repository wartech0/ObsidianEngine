#pragma once

#include <d3d12.h>
#include <dxgi1_4.h>
#include <cassert>

namespace Obsidian
{
	namespace DirectX
	{
		class D3D
		{
		public:
			explicit D3D();

			void CreateAndEnumerateSwapChain(unsigned int width, unsigned int height, HWND hwnd, bool fullscreen, bool vsync);

		private:
			ID3D12Device* _device;
			ID3D12CommandQueue* _commandQueue;
			IDXGISwapChain3* _swapChain;
		};
	}
}