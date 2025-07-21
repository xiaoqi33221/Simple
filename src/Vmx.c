#include "Vmx.h"
#include "Cpuid.h"

// 模拟 __readvmx 宏或函数，用于读取 VMCS 字段
extern unsigned int __readvmx(unsigned int field);

#define VMCS_EXIT_REASON 0x4402
#define EXIT_REASON_CPUID 10

VOID
VmVmExitHandler(
    _In_ PGUEST_REGS GuestRegs
    )
{
    unsigned int ExitReason = __readvmx(VMCS_EXIT_REASON);

    switch (ExitReason & 0xFFFF)
    {
    case EXIT_REASON_CPUID:
        VmHandleCpuid(GuestRegs);
        // cpuid指令长度为2，跳过
        GuestRegs->Rip += 2;
        break;

    default:
        // 其他退出原因处理
        break;
    }
}
