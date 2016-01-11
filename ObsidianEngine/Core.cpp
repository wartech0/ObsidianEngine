#include "Core.h"

Obsidian::DirectX::D3D::D3D()
{
	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_12_1;
	HRESULT result = D3D12CreateDevice(NULL, featureLevel, __uuidof(ID3D12Device), (void**)&_device);
	assert(FAILED(result));

	D3D12_COMMAND_QUEUE_DESC commandQueueDesc;
	ZeroMemory(&commandQueueDesc, sizeof(D3D12_COMMAND_QUEUE_DESC));
	commandQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	commandQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
	commandQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	commandQueueDesc.NodeMask = 0;

	result = _device->CreateCommandQueue(&commandQueueDesc, __uuidof(ID3D12CommandQueue), (void**)&_commandQueue);
	assert(FAILED(result));
}

void Obsidian::DirectX::D3D::CreateAndEnumerateSwapChain(unsigned int width, unsigned int height, HWND hwnd, bool fullscreen, bool vsync)
{
	IDXGIFactory4* factory;
	HRESULT result = CreateDXGIFactory1(__uuidof(IDXGIFactory4), (void**)&factory);
	assert(FAILED(result));

	IDXGIAdapter* adapter;
	result = factory->EnumAdapters(0, &adapter);
	assert(FAILED(result));

	IDXGIOutput* adapterOutput;
	result = adapter->EnumOutputs(0, &adapterOutput);
	assert(FAILED(result));

	unsigned int numModes;
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	assert(FAILED(result));

	DXGI_MODE_DESC* displayModeList = new DXGI_MODE_DESC[numModes];

	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	assert(FAILED(result));
	ThrowIfFailed
	unsigned int numerator;
	unsigned int denominator;

	for (int i = 0; i<numModes; i++)
	{
		if (displayModeList[i].Height == height)
		{
			if (displayModeList[i].Width == width)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	delete[] displayModeList;
	adapterOutput->Release();
	adapter->Release();

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapChainDesc.BufferCount = 2;
	swapChainDesc.BufferDesc.Width = width;
	swapChainDesc.BufferDesc.Height = height;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.OutputWindow = hwnd;

	if (fullscreen) {
		swapChainDesc.Windowed = false;
	}
	else {
		swapChainDesc.Windowed = true;
	}

	if (vsync) {
		swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
	}
	else {
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	}
}
