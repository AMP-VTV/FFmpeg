
/*! VideomasterHD_IP_Stack.h

    Copyright (c) 2015, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : ja                             Date: 2016/07/07

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_IP_STACK_H_
#define _VIDEOMASTERHD_IP_STACK_H_

#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Sdi.h"

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_IP_Processing
*/



/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_IP_Processing
*/

/*_ VHD_IP_STACK_PROTOCOL ______________________________________________*/
/*!
Summary
VideoMaster IP stack protocol value

Description
The VHD_IP_STACK_PROTOCOL enumeration lists all the available IP data protocol value.
*/
typedef enum _VHD_IP_STACK_PROTOCOL 
{
   VHD_IP_STACK_PROTOCOL_S2022_6,                         /*! SMPTE 2022-6 data protocol */
   NB_VHD_IP_STACK_PROTOCOLS
}VHD_IP_STACK_PROTOCOL;

/*_ VHD_IP_STACK_STREAMTYPE ___________________________________________________*/
/*!
   Summary
   VideoMaster IP stack stream types
   Description
   The VHD_IP_STACK_STREAMTYPE enumeration lists all the IP stream types.
   
   These values are used during VHD_OpenIpStackStreamHandle function
   calls.
   See Also
   VHD_OpenIpStackStreamHandle           
*/
typedef enum _VHD_IP_STACK_STREAMTYPE 
{
   VHD_IP_STACK_ST_RX,  /*! Input IP stack stream */ 
   VHD_IP_STACK_ST_TX,	/*! Output IP stack stream */
   NB_VHD_IP_STACK_STREAMTYPE
}VHD_IP_STACK_STREAMTYPE;

/*_ VHD_IP_STACK_STREAMPROPERTY ______________________________________________*/
/*!
   Summary
   VideoMaster ip stack streams properties
   Description
   The VHD_IP_STACK_STREAMPROPERTY enumeration lists all the
   ip stack stream properties available.
   
   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_IP_STACK_STREAMPROPERTY
{
   VHD_IP_STACK_SP_PACKET_COUNT=ENUMBASE_IP_STACK,       /*! In RX, defines the number of UDP packets received (reset at stream start). In TX, defines the number of UDP packets transmitted */ 
   VHD_IP_STACK_SP_PACKET_DISCARDED,                     /*! In RX, defines the number of UDP packets blocked by the input filter (reset at stream start). Input filters check that UDP packet contains RTP, contains the good SSRC and contains selected protocol. Meaningless in TX */ 
   VHD_IP_STACK_SP_PACKET_DROPPED,                       /*! In RX, defines the number of UDP packets dropped because the slot buffer queue is full (reset at stream start). Meaningless in TX */ 
   VHD_IP_STACK_SP_REORDERING_QUEUE_FILLING,             /*! In RX, defines the reordering buffer queue filling. This is equal to the number of packets waiting for reordering in the buffer queue. Meaningless in TX */ 
   VHD_IP_STACK_SP_REORDERING_PACKET_DROP,               /*! In RX, defines the number of packets dropped by the reordering process (reseted at stream start). Miss ordered packets are dropped when the reordering FIFO buffer queue is full. Meaningless in TX */ 
   NB_VHD_IP_STACK_STREAMPROPERTY
}VHD_IP_STACK_STREAMPROPERTY ;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_IP_Processing
*/

/*_ VHD_IP_STACK_SOCKET_PARAM ____________________________________________________*/
/*!
   Summary
   Ip stack socket parameters

   Description
   This structure contains the parameters requires for stream initialization. 
*/
typedef struct _VHD_IP_STACK_SOCKET_PARAM
{
	ULONG Size;					/*! This size must be set by user to the VHD_IP_STACK_TRANSPORT_PARAM size (=sizeof(VHD_IP_STACK_TRANSPORT_PARAM)). This will allow the API to detect the structure version.*/
	ULONG SocketBufferSize;     /*! Defines the maximum socket buffer size in bytes */  
	ULONG IpAddr;               /*! In RX, defines the IP address of the interface on which the packets will be received. In TX, defines the IP address destination of the packets that will be transmitted */ 
	USHORT Port;                /*! In RX, defines the port number on which the packets will be received. In TX, defines the port destination of the packets that will be transmitted */ 
	BOOL32 Multicast;           /*! In RX, defines if a multicast group must be joined. GroupAddr value will be used as multicast group address. Meaningless in TX */ 
	ULONG GroupAddr;            /*! In RX, defines the multicast group address. Meaningless in TX */ 
}VHD_IP_STACK_SOCKET_PARAM;


/*_ VHD_IP_STACK_SOCKET_PARAM_V2 ____________________________________________________*/
/*!
Summary
IP stack version 2 socket parameters for VHD_OpenIpStackStreamHandleEx function.

Description
This structure contains the parameters requires for stream initialization.
*/
typedef struct _VHD_IP_STACK_SOCKET_PARAM_V2
{
   ULONG Size;                 /*! This size must be set by user to the VHD_IP_STACK_SOCKET_PARAM_V2 size (=sizeof(VHD_IP_STACK_SOCKET_PARAM_V2)). This will allow the API to detect the structure version.*/
   ULONG SocketBufferSize;     /*! Defines the maximum socket buffer size in bytes */
   ULONG InterfaceIpAddr;      /*! In RX and TX, defines the IP address of the interface on which the packets will be received or transmitted.*/
   ULONG DestIpAddr;           /*! In TX, defines the IP address destination of the packets that will be transmitted. Meaningless in RX */
   USHORT Port;                /*! In RX, defines the port number on which the packets will be received. In TX, defines the port destination of the packets that will be transmitted */
   BOOL32 Multicast;           /*! In RX, defines if a multicast group must be joined. GroupAddr value will be used as multicast group address. Meaningless in TX */
   ULONG GroupAddr;            /*! In RX, defines the multicast group address. Meaningless in TX */

}VHD_IP_STACK_SOCKET_PARAM_V2;


/*_ VHD_IP_STACP_RTP_PARAM ____________________________________________________*/
/*!
   Summary
   Ip stack RTP parameters

   Description
   This structure contains the parameters requires for stream initialization. 
*/
typedef struct _VHD_IP_STACK_RTP_PARAM
{
	ULONG Size;                 /*! This size must be set by user to the VHD_IP_STACP_RTP_PARAM size (=sizeof(VHD_IP_STACP_RTP_PARAM)). This will allow the API to detect the structure version.*/
	ULONG ReorderingFifoSize;   /*! In RX, defines the size of the FIFO buffer used for RTP packet reordering. Meaningless in TX */  
	ULONG SSRC;                 /*! In RX, defines the SSRC on which the input packet will be filtered. IN TX, defines the SSRC of the RTP stream */ 
}VHD_IP_STACK_RTP_PARAM;

/*_ VHD_IP_STACP_RTP_PARAM_V2 ____________________________________________________*/
/*!
Summary
IP stack RTP parameters

Description
This structure contains the parameters requires for stream initialization.
*/
typedef struct _VHD_IP_STACK_RTP_PARAM_V2
{
   ULONG Size;                 /*! This size must be set by user to the VHD_IP_STACP_RTP_PARAM size (=sizeof(VHD_IP_STACP_RTP_PARAM)). This will allow the API to detect the structure version.*/
   ULONG ReorderingFifoSize;   /*! In RX, defines the size of the FIFO buffer used for RTP packet reordering. Meaningless in TX */
   ULONG SSRC;                 /*! In RX, defines the SSRC on which the input packet will be filtered. IN TX, defines the SSRC of the RTP stream */
   ULONG PayloadType;          /*! FOR FUTURE USE ONLY*/
}VHD_IP_STACK_RTP_PARAM_V2;

/*_ VHD_IP_STACK_PARAM ____________________________________________________*/
/*!
   Summary
   Ip stack stream parameters

   Description
   This structure contains the parameters requires for stream initialization. 
*/
typedef struct _VHD_IP_STACK_PARAM
{
   ULONG Size;										   /*! This size must be set by user to the VHD_IP_STACK_PARAM size (=sizeof(VHD_IP_STACK_PARAM)). This will allow the API to detect the structure version.*/
   VHD_IP_STACK_PROTOCOL IpStackProtocol;		/*! Defines the protocol used over IP stack */ 
   ULONG ThreadAffinityMask_UL;              /*! Defines a processor affinity mask that will be set for the receiving/transmitting thread */
   union{
	   VHD_IP_STACK_SOCKET_PARAM SocketParam;
   }TransportParam;									/*! Transport layer parameters. */ 
   union{
		VHD_IP_STACK_RTP_PARAM RTPParam;
   }AppParam;										   /*! Application layer parameters */ 
}VHD_IP_STACK_PARAM;

/*_ VHD_IP_STACK_PARAM_V2 ____________________________________________________*/
/*!
Summary
IP stack stream version 2 parameters for VHD_OpenIpStackStreamHandleEx function

Description
This structure contains the parameters requires for stream initialization.
*/
typedef struct _VHD_IP_STACK_PARAM_V2
{
   ULONG Size;                                        /*! This size must be set by user to the VHD_IP_STACK_PARAM_V2 size (=sizeof(VHD_IP_STACK_PARAM_V2)). This will allow the API to detect the structure version.*/
   VHD_IP_STACK_PROTOCOL IpStackProtocol;             /*! Defines the protocol used over IP stack */
   ULONG ThreadAffinityMask_UL;                       /*! Defines a processor affinity mask that will be set for the receiving/transmitting thread */
   union {
      VHD_IP_STACK_SOCKET_PARAM_V2 SocketParam;
   }TransportParam;                                   /*! Transport layer parameters. */
   union {
      VHD_IP_STACK_RTP_PARAM_V2 RTPParam;
   }AppParam;                                         /*! Application layer parameters */
}VHD_IP_STACK_PARAM_V2;


#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Ip_Board
*/

/*** VHD_OpenIpStackStreamHandle ****************************************************/
/*!VHD_OpenIpStackStreamHandle@VHD_IP_STACK_PARAM *@VHD_IP_STACK_STREAMTYPE@VHD_SDI_STREAMPROCMODE@BOOL32 *@HANDLE *@HANDLE
   Summary
   VideoMaster stream handle opening
   Description
   This function opens a handle to the specified logical stream
   Parameters
   VHD_IP_STACK_PARAM:   Parameters requires for stream initialization
   StrmType :          Type of logical stream to open
   ProcessingMode :    Mode the stream is processed
   pSetupLock :        Pointer to a boolean variable if must lock
                       configuration on that stream, or NULL
                       otherwise. If not NULL, then the boolean
                       is updated by VideoMaster to signal if
                       the handle owns the configuration lock or
                       not
   pStrmHandle :       Pointer to a caller\-allocated variable
                       receiving the stream handle
   OnDataReadyEvent :  Handle of an caller\-created event. Must be NULL if not used.
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_STACK_PARAM VHD_IPPROC_STREAMTYPE
   VHD_SDI_STREAMPROCMODE                                                                 */
VIDEOMASTER_HD_API ULONG VHD_OpenIpStackStreamHandle( VHD_IP_STACK_PARAM *pIpProcessingParam, VHD_IP_STACK_STREAMTYPE StrmType, VHD_SDI_STREAMPROCMODE ProcessingMode, BOOL32 *pSetupLock, HANDLE *pStrmHandle, HANDLE OnDataReadyEvent );

#ifdef __cplusplus
}
#endif

#endif // EXCLUDE_API_FUNCTIONS
#endif //_VIDEOMASTERHD_IP_STACK_H_