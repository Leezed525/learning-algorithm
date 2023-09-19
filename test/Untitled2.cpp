#include <windows.h>

#include <iostream>
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow) {
    DWORD dwIdThis = ::GetCurrentProcessId();

    DWORD dwVerReq = ::GetProcessVersion(dwIdThis);
    WORD wMajorReq = (WORD)dwVerReq > 16;
    WORD wMinorReq = (WORD)(dwVerReq & 0xffff);
    cout << "ProcessID:" << dwIdThis << ",requireOS:" << wMajorReq << wMinorReq << endl;
    OSVERSIONINFOEX osvix;
    ::ZeroMemory(&osvix, sizeof(osvix));
    osvix.dwOSVersionInfoSize = sizeof(osvix);
    if (!GetVersionEx((OSVERSIONINFO *)&osvix)) {
        cout << "Get version fail" << endl;
    }
    cout << "Running on OS:" << osvix.dwMajorVersion << "." << osvix.dwMinorVersion << endl;

    return 0;
}
