#pragma once

namespace Obsidian
{
	class Configuration
	{
	public:
		explicit Configuration();

		void SetWidth(unsigned int width);
		void SetHeight(unsigned int height);
		void SetTitle(const char* title);

		unsigned int GetWidth() const;
		unsigned int GetHeight() const;
		const char* GetTitle() const;

	private:
		unsigned int	_resWidth;
		unsigned int	_resHeight;
		const char*		_title;
	};
}