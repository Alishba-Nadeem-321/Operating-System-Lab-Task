#include <iostream>
#include <windows.h>

int main() {
    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        std::cout << "Child replacing its binary with '/bin/ls'..." << std::endl;
        std::cout << "-rwxr-xr-x 1 user group 16024 Sep 30 09:00 program" << std::endl;
        std::cout << "-rw-r--r-- 1 user group 450 Sep 30 08:55 program.cpp" << std::endl;
        return 0;
    }

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 10];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child", szPath);

    if (CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        std::cout << "Parent reaped replaced child image" << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}