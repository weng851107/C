#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include "i2c_msg_lib.h"

int open_i2c_dev(char *path)
{
    int fd = -1;

    if(path == NULL)
    {
        fprintf(stderr, "Invalid I2C device\n");
        return (-1);
    }

    //fprintf(stderr, "Open %s\n", path);

    fd = open(path, O_RDWR);
    if(fd > 0)
    {

        ioctl(fd, I2C_TIMEOUT, 10);
        ioctl(fd, I2C_RETRIES, 3);		
        //fprintf(stderr, "Open %s OK\n", path);
    }
    else fprintf(stderr, "Open %s NG\n", path);

    return fd;
}


void close_i2c_dev(int fd)
{
    close(fd);
}

static int _i2c_write_reg(int fd, unsigned char addr, unsigned char *reg, int reg_len, unsigned char *data, int data_len)
{
    int ret = -1;
    struct i2c_msg msgs[1];
    struct i2c_rdwr_ioctl_data i2c_data;

    int w_data_len = reg_len + data_len;
    unsigned char *w_data = (unsigned char *) malloc(w_data_len*sizeof(unsigned char));
    if(w_data == NULL)
    {
        fprintf(stderr, "Can't allocate write buffer\n");
        return (-1);
    }

    for (int i = 0;i < reg_len;i++) {
        w_data[i] = reg[i];
    }

    for (int i = reg_len;i < w_data_len;i++) {
        w_data[i] = data[i-reg_len];
    }

    printf("reg_len=%d, data_len=%d\n", reg_len, data_len);
    for(int i = 0; i < w_data_len; i++)
        printf("%d %#x\n", i, w_data[i]);

    msgs[0].addr = addr;
    msgs[0].flags = 0;	/*Write*/
    msgs[0].len = w_data_len;
    msgs[0].buf = w_data;

    i2c_data.msgs = msgs;
    i2c_data.nmsgs = 1;

    ret = ioctl(fd, I2C_RDWR, &i2c_data);
    if(ret < 0)
    {
        printf("I2C write fail\n");
        free(w_data);
        w_data = NULL;
        return ret;
    }

    free(w_data);
    w_data = NULL;

    return 0;
}

static int _i2c_read_reg(int fd, unsigned char addr, unsigned char *reg, int reg_len, unsigned char *data, int data_len)
{
    int ret = -1;
    int i = 0;
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data i2c_data;

    msgs[0].addr = addr;
    msgs[0].flags = 0;	/*Write*/
    msgs[0].len = reg_len;
    msgs[0].buf = reg;

    msgs[1].addr = addr;
    msgs[1].flags = I2C_M_RD;	/*Read*/
    msgs[1].len = data_len;
    msgs[1].buf = data;

    i2c_data.msgs = msgs;
    i2c_data.nmsgs = 2;

    ret = ioctl(fd, I2C_RDWR, &i2c_data);
    if(ret < 0)
    {
        printf("I2C read fail\n");
        return ret;
    }

    return 0;
}

int i2c_write_reg(char *port, unsigned char i2c_addr, int reg_addr, int reg_len, int val, int val_len)
{
    int ret = 0;
    int fd = -1;

    unsigned char *reg = (unsigned char *)malloc(reg_len*sizeof(unsigned char));
    unsigned char *data = (unsigned char *)malloc(val_len*sizeof(unsigned char));

    for (int i = reg_len-1;i >= 0;i--) {
        reg[i] = (reg_addr & (0xff << (8*i))) >> (8*i);
    }

    for (int i = val_len-1;i >= 0;i--) {
        data[i] = (val & (0xff << (8*i))) >> (8*i);
    }

    // open i2c device
    fd = open_i2c_dev(port);
    if(fd < 0)
    {
        fprintf(stderr, "Open %s fail\n", port);
        return (-1);
    }

    ret = _i2c_write_reg(fd, i2c_addr, reg, reg_len, data, val_len);

    close_i2c_dev(fd);
}

int i2c_write_reg_array(char *port, unsigned char i2c_addr, int reg_addr, int reg_len, char *data, int data_len)
{
    int ret = 0;
    int fd = -1;

    unsigned char *reg = (unsigned char *)malloc(reg_len*sizeof(unsigned char));

    for (int i = reg_len-1;i >= 0;i--) {
        reg[i] = (reg_addr & (0xff << (8*i))) >> (8*i);
    }

    // open i2c device
    fd = open_i2c_dev(port);
    if(fd < 0)
    {
        fprintf(stderr, "Open %s fail\n", port);
        return (-1);
    }

    ret = _i2c_write_reg(fd, i2c_addr, reg, reg_len, data, data_len);

    close_i2c_dev(fd);
}

int i2c_read_reg(char *port, unsigned char i2c_addr, int reg_addr, int reg_len, char *data, int data_len)
{
	int ret = 0;
	int fd = -1;

    unsigned char *reg = (unsigned char *)malloc(reg_len*sizeof(unsigned char));

    for (int i = reg_len-1;i >= 0;i--) {
        reg[i] = (reg_addr & (0xff << (8*i))) >> (8*i);
    }

	fd = open_i2c_dev(port);
	if (fd < 0)
	{
		fprintf(stderr, "Can't open %s\n", port);
		return (-1);
	}

    ret = _i2c_read_reg(fd, i2c_addr, reg, reg_len, data, data_len);
    if(ret == 0)
    {
        for (int i = 0;i < data_len;i++) {
            printf("data[%d] = %02x, ", i, data[i]);
        }
        printf("\n");
    }

	close_i2c_dev(fd);

	return ret;
}

