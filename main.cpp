#include <iostream> // For user prompt and console output
#include <Windows.h> // OS functions
#include <Psapi.h> // To get process info

using namespace std;

DWORD GetBaseAddress(const HANDLE hProcess) {
	if (hProcess == NULL)
		return NULL; // No access to the process

	HMODULE lphModule[1024]; // Array that receives the list of module handles
	DWORD lpcbNeeded(NULL); // Output of EnumProcessModules, giving the number of bytes requires to store all modules handles in the lphModule array

	if (!EnumProcessModules(hProcess, lphModule, sizeof(lphModule), &lpcbNeeded))
		return NULL; // Impossible to read modules

	TCHAR szModName[MAX_PATH];
	if (!GetModuleFileNameEx(hProcess, lphModule[0], szModName, sizeof(szModName) / sizeof(TCHAR)))
		return NULL; // Impossible to get module info

	return (DWORD)lphModule[0]; // Module 0 is apparently always the EXE itself, returning its address
}

int main() {
	HANDLE hProcess(NULL);
	DWORD processID(0);
	DWORD BaseAddress(NULL);

	cout << "PID to read : ";
	cin >> processID;

	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	BaseAddress = GetBaseAddress(hProcess);

	cout << "Base address: " << BaseAddress << endl;
	
	system("pause");
	return EXIT_SUCCESS;
}