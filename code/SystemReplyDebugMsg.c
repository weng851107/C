#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

#define AbstractPrint printf
#define DebugPrint(kstrFmt, strArgs...) AbstractPrint("\033[37;44m#%d:%s()# "kstrFmt"\033[0m\n", __LINE__, __FUNCTION__, ##strArgs)
#define NormalPrint(kstrFmt, strArgs...) AbstractPrint(kstrFmt"\n", ##strArgs)

#define MAX_CMD_BUFFER_SIZE (512)
#define MAX_RESPONSE_SIZE (256)

#define SystemReplyDebugMsg(pOutput, nOutputSize, kstrFmt, strArgs...) SystemReplyMsg(1, __FUNCTION__, __LINE__, pOutput, nOutputSize, kstrFmt, ##strArgs)

int SystemReplyMsg(int nDbg, const char *kstrFuncName, int nLine, char *pOutput, int nOutputSize, const char *kstrFmt, ...)
{
	if (!kstrFuncName || !pOutput || !kstrFmt) {
		DebugPrint("[ERROR] !kstrFuncName || !pOutput || !kstrFmt");
		return -1;
	}

	char *pCmdBuf = (char *)malloc(MAX_CMD_BUFFER_SIZE);
	if (!pCmdBuf) {
		DebugPrint("[ERROR] !pCmdBuf");
		return -2;
	}

	if (nOutputSize <= 0) {
		DebugPrint("[ERROR] nOutputSize=%d", nOutputSize);
		return -3;
	}

	memset(pOutput, 0, nOutputSize);

	va_list valList;
	va_start(valList, kstrFmt);
	vsnprintf(pCmdBuf, MAX_CMD_BUFFER_SIZE, kstrFmt, valList);
	va_end(valList);

	if (0 == strlen(pCmdBuf)) {
		DebugPrint("[ERROR] strlen(pCmdBuf)=%ld", strlen(pCmdBuf));
		goto GOTO_SYSTEM_REPLY_MSG_ERR;
	}

	if (nDbg) {
		DebugPrint("#%d:%s()# pCmdBuf(%d)=%s", nLine, kstrFuncName, (int)strlen(pCmdBuf), pCmdBuf);
	}

	FILE *pfFile = NULL;
	pfFile = popen(pCmdBuf, "r");
	if (!pfFile) {
		DebugPrint("[ERROR] !pfFile");
		goto GOTO_SYSTEM_REPLY_MSG_ERR;
	} else {
#if 0
		int nReadLen = fread(pOutput, 1, nOutputSize - 1, pfFile);
		if (nReadLen > 0) {
			if (pOutput[nReadLen - 1] == '\r' || pOutput[nReadLen - 1] == '\n') { pOutput[nReadLen - 1] = '\0'; }
			else { pOutput[nReadLen] = '\0'; }
		}

		DebugPrint("nReadLen=%d, strRead(%d)=%s", nReadLen, strlen(pOutput), pOutput);
#else
		char strRsp[MAX_RESPONSE_SIZE];
		int nReadLen = 0, nPos = 0;
		while (fgets(strRsp, MAX_RESPONSE_SIZE, pfFile)) {
			nReadLen = strlen(strRsp);
			if (nPos + nReadLen > nOutputSize) {
				//DebugPrint("[INFO] nPos=%d + nReadLen=%d > nOutputSize=%d", nPos, nReadLen, nOutputSize);
				break;
			} else {
				memcpy(pOutput + nPos, strRsp, nReadLen);
				nPos += nReadLen;
			}
		}

		nReadLen = strlen(pOutput);
		if (nReadLen > nOutputSize) { nReadLen = nOutputSize; }
		if (nReadLen > 0) {
			if (pOutput[nReadLen - 1] == '\r' || pOutput[nReadLen - 1] == '\n') { pOutput[nReadLen - 1] = '\0'; }
			else { pOutput[nReadLen] = '\0'; }
		}
#endif
	}

	int nResult = pclose(pfFile);
	if (-1 == nResult) {
		DebugPrint("[ERROR] -1 == nResult, errno=%d(%s)", errno, strerror(errno));
		goto GOTO_SYSTEM_REPLY_MSG_ERR;
	}

	if (WIFEXITED(nResult)) {
		if (WEXITSTATUS(nResult)) {
			DebugPrint("[ERROR] WEXITSTATUS(nResult=%d)=%d", nResult, WEXITSTATUS(nResult));
			goto GOTO_SYSTEM_REPLY_MSG_ERR;
		}
	} else {
		DebugPrint("[WARNING] WIFEXITED(nResult=%d)=%d", nResult, WIFEXITED(nResult));
	}

	if (WIFSIGNALED(nResult)) {
		DebugPrint("[ERROR] WTERMSIG(nResult=%d)=%d", nResult, WTERMSIG(nResult));
		goto GOTO_SYSTEM_REPLY_MSG_ERR;
	}

	if (nDbg) {
		DebugPrint("#%d:%s()# pOutput(%ld)=%s", nLine, kstrFuncName, strlen(pOutput), pOutput);
	}

	if (pCmdBuf) { free(pCmdBuf); pCmdBuf = NULL; }

	return 1;

GOTO_SYSTEM_REPLY_MSG_ERR:
	if (pCmdBuf) { free(pCmdBuf); pCmdBuf = NULL; }

	return -4;
}

int main(int argc, char **argv)
{
    int nResult = 0;
    char strCmd[MAX_CMD_BUFFER_SIZE];
    char strResp[MAX_RESPONSE_SIZE];
    memset(strCmd, 0, MAX_CMD_BUFFER_SIZE);
    memset(strResp, 0, MAX_RESPONSE_SIZE);

    sprintf(strCmd, "cec_eeprom.sh | grep EEPROM: | cut -c 8-11");
    nResult = SystemReplyDebugMsg(strResp, MAX_RESPONSE_SIZE, strCmd);

    printf("---------------\n");
	printf("nResult = %d\n", nResult);
    printf("strResp = %s\n", strResp);
    printf("---------------\n");

    return 0;
}
