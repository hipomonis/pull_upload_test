#include<stdio.h>
#include<windows.h>
int main() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb=sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL, "C:\\WINDOWS\\system32\\cmd.exe",NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		fprintf(stderr, "create Process Failed");
		return -1;
	} else {
		int n, i;
		int last = 0;
		int sum = 1;
		scanf("%d", &n);
		if (n>0) {
				printf("0 ");
				for (i=2; i <= n; ++i) {
				int temp = sum;
				printf("%d ", sum);
				sum = sum + last;
				last = temp;
		    	} 
		    	}else {
		    		printf("You input a wrong value of n");
				}
		}
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("\nChild Complete");
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
