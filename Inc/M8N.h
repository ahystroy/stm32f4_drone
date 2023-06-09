/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __M8N_H__
#define __M8N_H__
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

typedef struct _M8N_UBX_NAV_POLSSH
{
	unsigned char CLASS;
	unsigned char ID;
	unsigned short length;

	// 4byte = 32bit
	// 0x00 -> 8bit = 1byte
	unsigned int iTOW;
	signed int lon;
	signed int lat;
	signed int height;
	signed int hMSL;
	unsigned int hAcc;
	unsigned int vAcc;

	double lon_f64;
	double lat_f64;
}M8N_UBX_NAV_POLSSH;

extern M8N_UBX_NAV_POLSSH posllh;

unsigned char M8N_UBX_CHKSUM_Check(unsigned char* data, unsigned char len);
void M8N_UBX_NAV_POLSSH_Parsing(unsigned char* data, M8N_UBX_NAV_POLSSH* posllh);

void M8N_TransmitData(unsigned char* data, unsigned char len);
void M8N_UART4_Initialization(void);
void M8N_Initialization(void);

#ifdef __cplusplus
}
#endif
#endif /* __M8N_H__ */
