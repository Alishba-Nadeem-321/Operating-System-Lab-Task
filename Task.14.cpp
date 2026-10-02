#include <iostream>
#include <windows.h>

int main() {
    const char* szName = "Local\\shm_os_lab";
    const int BUF_SIZE = 1024;

    if (__argc > 1 && strcmp(__argv[1], "child") == 0) {
        Sleep(500);
        HANDLE hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, szName);
        if (hMapFile != NULL) {
            char* pBuf = (char*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
            std::cout << "Child read from SHM: " << pBuf << std::endl;
            UnmapViewOfFile(pBuf);
            CloseHandle(hMapFile);
        }
        return 0;
    }

    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, BUF_SIZE, szName);
    char* pBuf = (char*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
    
    strcpy_s(pBuf, BUF_SIZE, "OS Shared Memory Payload");

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char szPath[MAX_PATH], szCmd[MAX_PATH + 10];
    GetModuleFileName(NULL, szPath, MAX_PATH);
    wsprintf(szCmd, "%s child", szPath);

    if (CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return 0;
}