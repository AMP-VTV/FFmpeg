
/*! VideomasterHD_IP_S2022_Stack.h

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
#ifndef _VIDEOMASTERHD_IP_S2022_STACK_H
#define _VIDEOMASTERHD_IP_S2022_STACK_H

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_S2022_Processing
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_S2022_Processing
*/

/*_ VHD_S2022_STACK_STREAMPROPERTY ______________________________________________*/
/*!
   Summary
   VideoMaster S2022 streams properties
   Description
   The VHD_S2022_STACK_STREAMPROPERTY enumeration lists all the
   S2022 stream properties available
   
   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_S2022_STACK_STREAMPROPERTY
{
	VHD_S2022_STACK_SP_6_DATAGRAM_COUNT=ENUMBASE_S2022_STACK,	      /*! RX only. Number of received IP packet counter */
   VHD_S2022_STACK_SP_6_CHECK_VIDEO_TIMESTAMP,                     /*! RX only. If TRUE, the library checks the "Video Timestamp field" of the SMPTE 2022 payload 
                                                                      and increments VHD_S2022_STACK_SP_6_VIDEO_TIMESTAMP_DISCONTINUITY_COUNT property when a discontinuity is detected (default is FALSE) */
   VHD_S2022_STACK_SP_6_VIDEO_TIMESTAMP_DISCONTINUITY_COUNT,       /*! RX only. Timestamp discontinuity counter. Enabled if VHD_S2022_STACK_SP_6_CHECK_VIDEO_TIMESTAMP is TRUE. 
                                                                      This counter is incremented when the "Video Timestamp" field of the SEPMTE 2022 payload	header field 
                                                                      doesn't increment correctly between 2 consecutive received packet */
   VHD_S2022_STACK_SP_6_INSERT_VIDEO_TIMESTAMP,                    /*! TX only. Insert SMPTE 2022 "Video Timestamp field". When set to TRUE, the library inserts timestamp 
                                                                      in SMPTE 2022 datagram header. This parameter will impact on the SMPTE2022 header size. If TRUE,
                                                                      header datagram size is 12 bytes. If FALSE, header datagram size is 8 bytes (default is TRUE) */
   VHD_S2022_STACK_SP_6_DISCARDED_FRAME_COUNT,                     /*! RX only. Number of discarded frame counter. A frame is discarded if an error is EAV or SAV is misplaced. */
   VHD_S2022_STACK_SP_6_DISCARDED_DATAGRAM_COUNT,                  /*! RX only. Discarded IP packet counter. A packets is discarded if it belongs to an uncompleted frame */ 	
   VHD_S2022_STACK_SP_6_LOST_DATAGRAM_COUNT,                       /*! RX only. Lost IP packet counter. A lost packet is a packet which has not be received */
  NB_VHD_S2022_STACK_STREAMPROPERTY
}VHD_S2022_STACK_STREAMPROPERTY ;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Ip_S2022_Processing
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS


#endif //_VIDEOMASTERHD_IP_S2022_STACK_H