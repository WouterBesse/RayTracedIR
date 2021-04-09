#include <iostream>
#include "../headers/3D_Demo.h"
#include "../headers/olcConsoleGameEngine.h"

int main()
{
    olcEngine3D demo;
    if (demo.ConstructConsole(256, 256, 1, 1))
        demo.Start();
    return 0;
}