#include <iostream>
#include <windows.h>

int main() {
    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        std::cout << "Initial Parent PID: " << __argv[2] << std::endl;
        Sleep(3000);
        std::cout << "After parent dies, child process continues running independently." << std::endl;
        return 0;
    }

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 30];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child %lu", szPath, GetCurrentProcessId());

    if (CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cout << "Parent PID: " << GetCurrentProcessId() << " exiting immediately" << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}