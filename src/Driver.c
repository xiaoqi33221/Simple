#include <ntddk.h>
#include "Vmx.h"

VOID DriverUnload(_In_ PDRIVER_OBJECT DriverObject)
{
    UNREFERENCED_PARAMETER(DriverObject);
    DbgPrint("SimpleVisor driver unloaded.\n");
}

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);
    DriverObject->DriverUnload = DriverUnload;

    DbgPrint("SimpleVisor driver loaded.\n");

    // 这里调用启动VMX的初始化代码（示例，需自行实现）
    // VmInit();

    return STATUS_SUCCESS;
}
