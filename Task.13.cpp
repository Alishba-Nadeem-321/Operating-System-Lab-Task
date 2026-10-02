#include <iostream>
#include <windows.h>

int main() {
    HANDLE hRead, hWrite;
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

    if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
        return 1;
    }

    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        CloseHandle(hWrite);
        HANDLE hReadPipe = (HANDLE)std::stoull(__argv[2]);
        char buffer[128] = {0};
        DWORD bytesRead;
        ReadFile(hReadPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL);
        std::cout << "Child read from pipe: " << buffer << std::endl;
        CloseHandle(hReadPipe);
        return 0;
    }

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 50];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child %llu", szPath, (unsigned long long)hRead);

    if (CreateProcess(NULL, szCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        CloseHandle(hRead);
        const char* msg = "Hello Child from Kernel Pipe";
        DWORD bytesWritten;
        WriteFile(hWrite, msg, (DWORD)strlen(msg), &bytesWritten, NULL);
        CloseHandle(hWrite);

        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 0;
}