#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "FileOperation.h"

int _exec_rfs_cmd_return_str(char *cmd, char *reply, int reply_len)
{
	int ret = 0;
	FILE *fp = NULL;
	//int cmdlen = 0;

	if((!cmd) || (!reply))
	{
		printf("Invalid pointer");
		return (-1);
	}

	fp = popen(cmd, "r");
	if(fp == NULL)
	{
		printf("%s: can't open pipe\n", __func__);
		return (-1);
	}

	while(fgets(reply, reply_len, fp) != NULL)
	{}

	//printf("reply=%s\n", reply);
	//ret = atoi(reply);
	reply[strlen(reply) - 1] = '\0';
	pclose(fp);
	fp = NULL;

	return ret;
}

int _exec_rfs_cmd_return_int32(char *cmd, char *reply, int reply_len)
{
	int ret = 0;
	FILE *fp = NULL;
	//int cmdlen = 0;

	if((!cmd) || (!reply))
	{
		printf("Invalid pointer");
		return (-1);
	}

	fp = popen(cmd, "r");
	if(fp == NULL)
	{
		printf("%s: can't open pipe\n", __func__);
		return (-1);
	}

	while(fgets(reply, reply_len, fp) != NULL)
	{}

	//printf("reply=%s\n", reply);
	ret = atoi(reply);

	pclose(fp);
	fp = NULL;

	return ret;
}

/* read 16 characters */
int _read_file_16_return_int(const char *path)
{
	int ret = 0;
	FILE *fp = NULL;
	char buf[32] = {0};
	
	fp = fopen(path, "r");
	if(!fp)
	{
		printf("Can't open %s", path);
		ret = -1;
		goto out;
	}

	if(!fgets(buf, sizeof(buf), fp))
	{
		printf("Read %s fail", path);
		ret = (-1);
		goto out;
	}

	//ret = atoi(buf);
	ret = strtol(buf, NULL, 0);
	
out:

	if(fp)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}

int _write_int_to_file(const char *path, int val)
{
	int ret = 0;
	FILE *fp = NULL;

	if(!path)
	{
		printf("Invalid file path: %s", path);
		return (-1);
	}

	fp = fopen(path, "w");
	if(!fp)
	{
		printf("%s can't be opened", path);
		return (-1);
	}

	fprintf(fp, "%d", val);
	fclose(fp);
	fp = NULL;

	return ret;
}


int _query_input_event_num_by_name(char *name, char *event_name, int elen)
{
	int ret = 0;
	char cmd[256] = {0};
	//int len = 0;

#define PROC_INPUT_DEVICES_PATH 	"/proc/bus/input/devices"
#define QUERY_INPUT_EVENT_CMD	"sed -n -e '/%s/,/PROP/p' /proc/bus/input/devices | grep Handler | awk '{print $NF}' | sed 's/Handlers=//g'"

	if(!name)
	{
		printf("Invalid pointer --> name\n");
		return (-1);
	}

	if(!event_name)
	{
		printf("Invalid pointer --> event_name\n");
		return (-1);
	}

	if(access("/proc/bus/input/devices", F_OK) != 0)
	{
		printf("/proc/bus/input/devices doesn't exit\n");
		return (-1);
	}

	//len = ((strlen(QUERY_INPUT_EVENT_CMD) + strlen(name) + 1)/32 + 1) * 32;
	//cmd = (char *) malloc(len);
	//if(!cmd)
	//{
	//	printf("%s: can't allocate memory\n", __func__);
	//	return (-1);
	//}

	//memset(cmd, 0, len);
	sprintf(cmd, QUERY_INPUT_EVENT_CMD, name);
	//printf("%s\n", cmd);

	memset(event_name, '\0', elen);
	ret = _exec_rfs_cmd_return_str(cmd, event_name, elen);
	if(ret < 0)
		printf("cmd error\n");
	else
	{
		if(strlen(event_name) == 0)
		{
			printf("%s: can't find %s\n", __func__, name);
			ret = (-1);
		}
	}

	//free(cmd);
	//cmd = NULL;

	return ret;
}
