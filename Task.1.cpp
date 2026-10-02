#include <iostream>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Get current process path to create a child copy
    char szPath[MAX_PATH];
    GetModuleFileName(NULL, szPath, MAX_PATH);

    // Command line argument to distinguish child
    char szCmd[MAX_PATH + 10];
    wsprintf(szCmd, "%s child", szPath);

    // If running as child
    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        std::cout << "Child Process: PID = " << GetCurrentProcessId() << std::endl;
        return 0;
    }

    // Parent process creates child
    if (!CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cout << "Process creation failed. Error: " << GetLastError() << std::endl;
    } else {
        std::cout << "Parent Process: PID = " << GetCurrentProcessId() 
                  << ", Created Child PID = " << pi.dwProcessId << std::endl;
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}