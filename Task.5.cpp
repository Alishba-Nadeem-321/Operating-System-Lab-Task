#include <iostream>
#include <windows.h>

int shared_counter = 100;

int main() {
    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        shared_counter += 50;
        std::cout << "Child sees shared_counter = " << shared_counter << std::endl;
        return 0;
    }

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 10];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child", szPath);

    if (CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        std::cout << "Parent sees shared_counter = " << shared_counter << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}