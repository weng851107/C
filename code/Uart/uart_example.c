#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#if 0
typedef struct _speedAttr_s {
    char name[16];
    int speed;
} speedAttr_t;

speedAttr_t speed[] = {
    {.name =}
};

int speedAttr[] =
    { B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300,
    B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300,
};

int nameAttr[] = { 115200, 38400, 19200, 9600, 4800, 2400, 1200, 300,
    115200, 38400, 19200, 9600, 4800, 2400, 1200, 300,
};
#endif

int set_speed(int fd, int speed)
{
    int i;
    int status;
    struct termios Opt;
    tcgetattr(fd, &Opt);

    //  for( i= 0;  i < sizeof(speedAttr) / sizeof(int);  i++)
    {
	//    if(speed == name_arr[i])
	{
	    tcflush(fd, TCIOFLUSH);
	    cfsetispeed(&Opt, speed);
	    cfsetospeed(&Opt, speed);

	    status = tcsetattr(fd, TCSANOW, &Opt);

	    //if(status != 0)
	    //  perror("tcsetattr fd1");

	    //  return;
	}

	tcflush(fd, TCIOFLUSH);
    }

    return 0;
}

int set_Parity(int fd, int databits, int stopbits, int parity)
{
    struct termios options;

    if (tcgetattr(fd, &options) != 0) {
        perror("SetupSerial 1");
        return (-1);
    }

    options.c_cflag &= ~CSIZE;

    switch (databits) {		/*設置數據位元數 */
    case 7:
        options.c_cflag |= CS7;
        break;

    case 8:
        options.c_cflag |= CS8;
        break;

    default:
        fprintf(stderr, "Unsupported data size\n");
        return (-1);
    }

    switch (parity) {
    case 'n':
    case 'N':
        options.c_cflag &= ~PARENB;	/* Clear parity enable */
        options.c_iflag &= ~INPCK;	/* Enable parity checking */
        break;

    case 'o':
    case 'O':
        options.c_cflag |= (PARODD | PARENB);	/* 設置為奇效驗 */
        options.c_iflag |= INPCK;	/* Disnable parity checking */
        break;

    case 'e':
    case 'E':
        options.c_cflag |= PARENB;	/* Enable parity */
        options.c_cflag &= ~PARODD;	/* 轉換為偶效驗 */
        options.c_iflag |= INPCK;	/* Disnable parity checking */
        break;

    case 'S':
    case 's':			/*as no parity */
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
        break;

    default:
        fprintf(stderr, "Unsupported parity\n");
        return (-1);
    }

    /* 設置停止位 */
    switch (stopbits) {
    case 1:
        options.c_cflag &= ~CSTOPB;
        break;

    case 2:
        options.c_cflag |= CSTOPB;
        break;

    default:
        fprintf(stderr, "Unsupported stop bits\n");
        return (-1);
    }

    /* Set input parity option */
    if (parity != 'n')
        options.c_iflag |= INPCK;

    options.c_cc[VTIME] = 150;	// 15 seconds
    options.c_cc[VMIN] = 0;


    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);	/*Input */
    options.c_oflag &= ~OPOST;	/*Output */

    tcflush(fd, TCIFLUSH);	/* Update the options and do it NOW */
    if (tcsetattr(fd, TCSANOW, &options) != 0) {
        perror("SetupSerial 3");
        return (-1);
    }

    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    int nread;
    int nbytes;
    int i = 0;
    char fw_query[] = { 0x55, 0xaa, 0x00, 0x07 };
    char fw_respn[] = { 0x55, 0xaa, 0x00, 0x09 };
    char start[2] = { 0 };
    char found = 0;
    char buff[512];
    char *dev = "/dev/ttyS1";

    fd = open(dev, O_RDWR | O_NOCTTY);
    if (fd <= 0) {
        perror("Cant open RADAR COM");
        return (-1);
    }


    if (fd > 0)
        set_speed(fd, B115200);
    else {
        printf("Can't Open Serial Port!\n");
        exit(0);
    }

    if (set_Parity(fd, 8, 1, 'N') < 0) {
        printf("Set Parity Error\n");
        exit(1);
    }

    /*
    .......................main code.............................
    */

    close(fd);

    return 0;
}
