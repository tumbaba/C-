#include "pch.h"

void MYDLL_API HelloDLL_0305()
{
    std::cout << "Hello\n";
}

FClassDLLImport::FClassDLLImport()
{
    std::cout << __FUNCTION__;
}

FClassDLLImport::~FClassDLLImport()
{
}
