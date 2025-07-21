#pragma once

typedef struct _GUEST_REGS {
    unsigned __int64 Rax;
    unsigned __int64 Rbx;
    unsigned __int64 Rcx;
    unsigned __int64 Rdx;
    unsigned __int64 Rip;
    // 其他寄存器可以按需添加
} GUEST_REGS, *PGUEST_REGS;

void VmHandleCpuid(PGUEST_REGS GuestRegs);
