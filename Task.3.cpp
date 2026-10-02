#include <iostream>
#include <windows.h>

int main() {
    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        std::cout << "Child PID : " << GetCurrentProcessId() << " terminating now" << std::endl;
        return 0;
    }

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 10];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child", szPath);

    if (CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cout << "Parent sleeping for 10 s without cleanup (Handle kept open)..." << std::endl;
        Sleep(10000);
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        std::cout << "Parent cleaned up child. Exiting." << std::endl;
    }
    return 0;
}