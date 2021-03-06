/*
 * tftp.h
 *
 *  Created on: 6/04/2015
 *      Author: Cristian
 */

#ifndef SERVERS_TFTP_H_
#define SERVERS_TFTP_H_

#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/_stack.h>

/* Error codes. */
typedef enum
{
	TFTP_ERR_NONE = 	  -1,			/* no error */
	TFTP_ERR_NDEF =      0,       /* not defined */
	TFTP_ERR_NOTFOUND =  1,       /* file not found */
	TFTP_ERR_ACCESS =    2,       /* access violation */
	TFTP_ERR_NOSPACE =   3,       /* disk full or allocation exceeded */
	TFTP_ERR_BADOP =     4,       /* illegal TFTP operation */
	TFTP_ERR_BADID =     5,       /* unknown transfer ID */
	TFTP_ERR_EXISTS =    6,       /* file already exists */
	TFTP_ERR_NOUSER =	   7,       /* no such user */
} tTFTPError;

#define SEGSIZE   		512     /* data segment size */

#define PORT_TFTP 		69	 /* tftp port */

int dtask_tftp( SOCKET s, UINT32 unused );
typedef tTFTPError (*tTFTPRequest)(char *fileName, char *buffer, UINT32 *bufferSize, UINT16 block);
void tftpInit(tTFTPRequest pfnRequest);


#endif /* SERVERS_TFTP_H_ */
