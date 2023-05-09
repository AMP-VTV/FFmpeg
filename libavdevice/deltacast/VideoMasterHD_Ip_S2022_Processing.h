/*! VideomasterHD_Ip_S2022_Processing.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

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


#ifndef _VIDEOMASTERHD_IP_S2022_PROCESSING_H_
#define _VIDEOMASTERHD_IP_S2022_PROCESSING_H_

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_S2022_Processing
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_S2022_Processing
*/

/*_ VHD_S2022_PROC_STREAMPROPERTY ______________________________________________*/
/*!
   Summary
   VideoMaster S2022 streams properties
   Description
   The VHD_S2022_PROC_STREAMPROPERTY enumeration lists all the
   S2022 stream properties available on IP board.
   
   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_S2022_PROC_STREAMPROPERTY
{
	VHD_S2022_PROC_SP_6_DATAGRAM_COUNT=ENUMBASE_S2022_PROC,	      /*! RX only. Received datagram packet counter */
   VHD_S2022_PROC_SP_6_CHECK_VIDEO_TIMESTAMP,                     /*! RX only. If TRUE, the library checks the "Video Timestamp" field of the SMPTE ST 2022-6 datagram headers 
                                                                      and increments VHD_S2022_PROC_SP_6_VIDEO_TIMESTAMP_DISCONTINUITY_COUNT property when a discontinuity is detected (default is FALSE) */
   VHD_S2022_PROC_SP_6_VIDEO_TIMESTAMP_DISCONTINUITY_COUNT,       /*! RX only. Timestamp discontinuity counter. Enabled if VHD_S2022_PROC_SP_6_CHECK_VIDEO_TIMESTAMP is TRUE. 
                                                                      This counter is incremented when the "Video Timestamp" field of the SMPTE ST 2022-6 datagram header 
                                                                      doesn't increment correctly between 2 consecutive received packets */
   VHD_S2022_PROC_SP_6_INSERT_VIDEO_TIMESTAMP,                    /*! TX only. Insert "Video Timestamp" in the SMPTE ST 2022-6 datagram header field. When set to TRUE, the library inserts timestamp 
                                                                      in SMPTE ST 2022-6 datagram headers. This parameter will impact on the SMPTE ST 2022-6 datagram header size. If TRUE,
                                                                      datagram header size is 12 bytes. If FALSE, datagram header size is 8 bytes (default is TRUE) */
   VHD_S2022_PROC_SP_6_DISCARDED_FRAME_COUNT,                     /*! RX only. Discarded frame counter. A frame is discarded if an error in EAV or SAV is detected and also if a EAV or SAV is misplaced */
   VHD_S2022_PROC_SP_6_DISCARDED_DATAGRAM_COUNT,                  /*! RX only. Discarded datagram packet counter. A packet is discarded if it belongs to an incompleted frame */ 	
   VHD_S2022_PROC_SP_6_LOST_DATAGRAM_COUNT,                       /*! RX only. Lost datagram packet counter. A lost packet is a packet which has not be received */
  NB_VHD_S2022_PROC_STREAMPROPERTY
}VHD_S2022_PROC_STREAMPROPERTY ;

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

#endif //_VIDEOMASTERHD_IP_S2022_PROCESSING_H_