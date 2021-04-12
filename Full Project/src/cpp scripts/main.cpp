#include <iostream>
#include "../headers/3D_Demo.h"
#define SampleRate 48000

int main()
{
    olcEngine3D demo;
    if (demo.ConstructConsole(500, 500, 1, 1))
        demo.Start(SampleRate);
    return 0;
}