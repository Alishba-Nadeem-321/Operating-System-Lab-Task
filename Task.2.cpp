#include <iostream>
#include <windows.h>

int main() {
    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        std::cout << "Child executing task..." << std::endl;
        Sleep(2000); // 2 seconds
        std::cout << "Child exiting with code 42" << std::endl;
        return 42;
    }

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 10];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child", szPath);

    std::cout << "Parent waiting for child..." << std::endl;
    if (CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        DWORD exitCode = 0;
        GetExitCodeProcess(pi.hProcess, &exitCode);
        std::cout << "Parent: Child terminated with exit status " << exitCode << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}