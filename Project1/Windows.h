#pragma once
#include<windows.h>
class  Windows
{
public:
	 Windows();
	~ Windows();
	void Create();
	void Update();
	void Destroy();


		 

private:
	HWND m_WndHandle;
};


