#include <iostream>
#include "Windows.h"

int main(int argc, char** argv)
{
    // windows
    Windows wnd;
    wnd.Create();

    // Loop
    while (true)
    {
wnd.Update();
    }
    

    // Shutdown
    wnd.Destroy();

    return 0;
}