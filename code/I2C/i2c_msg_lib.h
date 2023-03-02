#ifndef _I2C_MSG_LIB_H_
#define _I2C_MSG_LIB_H_

#define I2C_PORT_0      "/dev/i2c-0"	/* IDC1 */
#define I2C_PORT_1      "/dev/i2c-1"	/* IDC2 */
#define I2C_PORT_2      "/dev/i2c-2"	/* IDC3 */

/*function declaration*/
int open_i2c_dev(char *path);
void close_i2c_dev(int fd);
int i2c_write_reg(char *port, unsigned char i2c_addr, int reg_addr, int reg_len, int val, int val_len);
int i2c_write_reg_array(char *port, unsigned char i2c_addr, int reg_addr, int reg_len, char *data, int data_len);
int i2c_read_reg(char *port, unsigned char i2c_addr, int reg_addr, int reg_len, char *data, int data_len);

#endif