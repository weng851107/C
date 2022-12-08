#ifndef __FILEOPERATION_H__
#define __FILEOPERATION_H__

#define ARRAY_SIZE(arr)								\
	(sizeof(arr) / sizeof(((typeof(arr)){})[0]))

#define ZERO(arr)									\
do{														\
	memset(arr, 0, ARRAY_SIZE(arr));		\
}while(0)

int _exec_rfs_cmd_return_str(char *cmd, char *reply, int reply_len);
int _exec_rfs_cmd_return_int32(char *cmd, char *reply, int reply_len);
int _read_file_16_return_int(const char *path);
int _write_int_to_file(const char *path, int val);
int _query_input_event_num_by_name(char *name, char *event, int elen);


#endif