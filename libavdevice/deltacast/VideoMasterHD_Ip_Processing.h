
/*! VideomasterHD_IP_Processing.h

    Copyright (c) 2015, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : ja                             Date: 2016/06/16

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_IP_PROCESSING_H_
#define _VIDEOMASTERHD_IP_PROCESSING_H_

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

/*_ VHD_IP_PROC_STREAMTYPE ___________________________________________________*/
/*!
   Summary
   VideoMaster IP stream types
   Description
   The VHD_IP_PROC_STREAMTYPE enumeration lists all the IP stream types.
   
   These values are used during VHD_OpenStreamHandle function
   calls.
   See Also
   VHD_OpenStreamHandle           
*/

typedef enum _VHD_IP_PROC_STREAMTYPE
{
   VHD_IP_PROC_ST_SDI_EXTRACTOR=ENUMBASE_IP_PROC,   /*! Extracts SDI content from IP stream */ 
   VHD_IP_PROC_ST_SDI_INJECTOR,    			          /*! Injects SDI content into IP stream */
   NB_VHD_IP_PROC_STREAMTYPES
} VHD_IP_PROC_STREAMTYPE;

/*_ VHD_IP_PROC_DATA_TYPE ______________________________________________*/
/*!
Summary
VideoMaster IP data type value

Description
The VHD_IP_PROC_DATA_TYPE enumeration lists all the available IP data type value.

These values are used as value for the IPDataType parameter of VHD_PushIPData and VHD_PullIPData functions.

See Also
VHD_PushIPData
VHD_PullIPData

*/
typedef enum _VHD_IP_PROC_DATA_TYPE 
{
   VHD_IP_PROC_DATA_TYPE_S2022_6,                         /*! SMPTE ST 2022-6 data type */
   NB_VHD_IP_PROC_DATA_TYPES
} VHD_IP_PROC_DATA_TYPE;

/*_ VHD_IP_PROC_DATA_PROTOCOL ______________________________________________*/
/*!
Summary
VideoMaster IP data protocol value

Description
The VHD_IP_PROC_DATA_PROTOCOL enumeration lists all the available IP data protocol value.

See Also
VHD_GetStreamProperty
VHD_SetStreamProperty
*/
typedef enum _VHD_IP_PROC_DATA_PROTOCOL 
{
   VHD_IP_PROC_DATA_PROTOCOL_S2022_6,                         /*! SMPTE ST 2022-6 data protocol */
   NB_VHD_IP_PROC_DATA_PROTOCOLS
}VHD_IP_PROC_DATA_PROTOCOL;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_IP_Processing
*/

/*_ VHD_IP_PROC_PARAM ____________________________________________________*/
/*!
   Summary
   IP Processing stream parameters

   Description
   This structure contains the parameters requires for stream initialization. 
*/
typedef struct _VHD_IP_PROC_PARAM
{
   ULONG Size;                                  /*! This size must be set by user to the VHD_IPPROC_PARAM size (=sizeof(VHD_IPPROC_PARAM)). This will allow the API to detect the structure version.*/
   VHD_IP_PROC_DATA_PROTOCOL IpDataProtocol;    /*! Defines the IP data protocol that will be used */
}VHD_IP_PROC_PARAM;

/*_ VHD_S2022_STATUS _______________________________________________________*/
/*!
  Summary
  S2022 IP slot status structure
  Description
  The VHD_S2022_STATUS structure is used to report the status
  of an S2022-6 IP slot.
  See Also
  VHD_GetSlotStatus
*/
typedef struct _VHD_S2022_STATUS 
{
  ULONG Size;                               /*! The size, in bytes, of this data structure. */
  ULONG FrameCount;                         /*!_VHD_S2022_STATUS::FrameCount
                                                   Frame count of the given slot found in the ST2022-6 datagram headers, it is a 8-bit frame counter. */
} VHD_S2022_STATUS;

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_IP_Processing
*/

/*** VHD_OpenIpProcessingStreamHandle ****************************************************/
/*!VHD_OpenIpProcessingStreamHandle@VHD_IP_PROC_PARAM *@VHD_IP_PROC_STREAMTYPE@VHD_SDI_STREAMPROCMODE@BOOL32 *@HANDLE *@HANDLE
   Summary
   VideoMaster stream handle opening
   Description
   This function opens a handle to the specified logical stream

   Parameters
   VHD_IP_PROC_PARAM:   Parameters requires for stream initialization
   StrmType :           Type of logical stream to open
   ProcessingMode :     Mode the stream is processed
   pSetupLock :         Pointer to a boolean variable if must lock
                        configuration on that stream, or NULL
                        otherwise. If not NULL, then the boolean
                        is updated by VideoMaster to signal if
                        the handle owns the configuration lock or
                        not
   pStrmHandle :        Pointer to a caller\-allocated variable
                        receiving the stream handle
   OnDataReadyEvent :   Handle of an caller\-created event. Must be NULL if not used.

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   See Also
   VHD_IPPROC_PARAM VHD_IPPROC_STREAMTYPE
   VHD_SDI_STREAMPROCMODE                                                                 */
VIDEOMASTER_HD_API ULONG VHD_OpenIpProcessingStreamHandle( VHD_IP_PROC_PARAM *pIpProcessingParam, VHD_IP_PROC_STREAMTYPE StrmType, VHD_SDI_STREAMPROCMODE ProcessingMode, BOOL32 *pSetupLock, HANDLE *pStrmHandle, HANDLE OnDataReadyEvent );

/*** VHD_PushIpData **********************************************************/
/*!
   Summary
   VideoMaster push IP data function
   The function expects to receive entire numbers of IP packet.
	The function is blocking until free buffer space is available or until the timeout value is reached.
   If the timeout is reached, the function will return a timeout error and the number of ingested data 
   through the *pDataBuffer field.

   Parameters
   StreamHandle :       Handle of the stream to operate on
	IpDataType :         IP data type. See VHD_IP_PROC_DATA_TYPE  
   pDataBuffer :        Data buffer pointer with IP data packets
   pDataSize :          Size of Data buffer 
   pPacketSystemTime :  System time buffer pointer
   Timeout :            Timeout interval, in milliseconds

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
                                        */
VIDEOMASTER_HD_API ULONG VHD_PushIpData (HANDLE StreamHandle, VHD_IP_PROC_DATA_TYPE IpDataType, BYTE *pDataBuffer, ULONG *pDataSize, LONGLONG *pPacketSystemTime, ULONG Timeout);

/*** VHD_PullIpData **************************************************/
/*!
   Summary
   VideoMaster pull IP data function
   
	Description
   The function expects to pull entire numbers of IP packet.
	If Timeout is not null, the function is blocking until IP   
   data packets are available or until the Timeout value is elapsed  
	If *pNumberOfPackets is zero, the function returns the number of packet ready to be 
	pulled in *pNumberOfPackets and the corresponding buffer size in *pDataSize.
	If *pNumberOfPackets is not zero and *pDataSize is less than the corresponding data size,
	the function returns the corresponding data size in *pDataSize.
	If *pNumberOfPackets is not zero and *pDataSize is greater or equal than 
   the corresponding data size and *pNumberOfPackets packets are available before timeout, 
	the function returns the corresponding data size in *pDataSize and fill *pDataBuffer with *pNumberOfPackets packets.
	If *pNumberOfPackets is not zero and *pDataSize is greater or equal than 
   the corresponding data size but *pNumberOfPackets packets are not available before timeout, 
	the function returns the number of available packet in *pNumberOfPackets, 
   the corresponding data size in *pDataSize and fill *pDataBuffer with *pNumberOfPackets packets.

   Parameters
   StreamHandle :       Handle of the stream to operate on
	IpDataType :         IP data type. See VHD_IP_PROC_DATA_TYPE  
   pNumberOfPackets :   Number of IP data packet   
   pDataBuffer :        Data buffer pointer receiving IP data packets
   pDataSize :          Size of data buffer
	Timeout :            Timeout interval, in milliseconds 
	
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
                                        */
VIDEOMASTER_HD_API ULONG VHD_PullIpData (HANDLE StreamHandle, VHD_IP_PROC_DATA_TYPE IpDataType, ULONG *pNumberOfPackets, BYTE *pDataBuffer, ULONG *pDataSize, ULONG Timeout);

#ifdef __cplusplus
}
#endif

#endif // EXCLUDE_API_FUNCTIONS

#endif // _VIDEOMASTERHD_IP_PROCESSING_H_




