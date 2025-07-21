// 修改后的 Vmx.c 示例代码
#include "Vmx.h"
#include <ntddk.h> // 需要 WDK 环境

// 临时声明函数，若你没有头文件
VOID VmVmExitHandler(_Inout_ PGUEST_REGS GuestRegs);

// 示例实现
VOID VmVmExitHandler(_Inout_ PGUEST_REGS GuestRegs)
{
    // 检查是否是 CPUID 指令引起的 VM-Exit
    ULONG ExitReason = __vmx_vmread(0x4402); // VM_EXIT_REASON

    if ((ExitReason & 0xFFFF) == 10)  // 10 = CPUID
    {
        VmHandleCpuid(GuestRegs);  // 调用你自定义的 CPUID 伪造处理
        __vmx_vmwrite(0x440E, __vmx_vmread(0x681E) + __vmx_vmread(0x440C)); // VM_RIP += VM_EXIT_INSTRUCTION_LENGTH
    }
}
