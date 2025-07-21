#include "Cpuid.h"
#include <intrin.h>
#include <string.h>

VOID
VmHandleCpuid(
    _In_ PGUEST_REGS GuestRegs
    )
{
    INT32 CpuInfo[4] = { 0 };
    __cpuid(CpuInfo, (INT32)GuestRegs->Rax);

    if (GuestRegs->Rax == 0x0)
    {
        CpuInfo[1] = 'htuA';  // EBX = "Auth"
        CpuInfo[3] = 'itne';  // EDX = "enti"
        CpuInfo[2] = 'DMAc';  // ECX = "cAMD"
    }
    else if (GuestRegs->Rax >= 0x80000002 && GuestRegs->Rax <= 0x80000004)
    {
        const char* fakeName = "AMD Ryzen 7 5800X 8-Core Processor";
        memcpy(CpuInfo, fakeName + (GuestRegs->Rax - 0x80000002) * 16, 16);
    }

    GuestRegs->Rax = CpuInfo[0];
    GuestRegs->Rbx = CpuInfo[1];
    GuestRegs->Rcx = CpuInfo[2];
    GuestRegs->Rdx = CpuInfo[3];
}
