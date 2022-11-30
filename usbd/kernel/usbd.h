/**
        vitausb
        Copyright (C) 2022 Cat (Ivan Epifanov)

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/**
 * \kernelgroup{SceUsbd}
 * \usage{psp2kern/usbd.h,SceUsbdForDriver_stub}
 */


#ifndef _PSP2KERN_USBD_H_
#define _PSP2KERN_USBD_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SCE_USBD_PROBE_SUCCEEDED       (0)
#define SCE_USBD_PROBE_FAILED          (-1)
#define SCE_USBD_ATTACH_SUCCEEDED      (0)
#define SCE_USBD_ATTACH_FAILED         (-1)
#define SCE_USBD_DETACH_SUCCEEDED      (0)
#define SCE_USBD_DETACH_FAILED         (-1)

#define SCE_USBD_MAX_LS_CONTROL_PACKET_SIZE      8
#define SCE_USBD_MAX_FS_CONTROL_PACKET_SIZE      64
#define SCE_USBD_MAX_ISOCHRONOUS_PACKET_SIZE     1023
#define SCE_USBD_MAX_LS_INTERRUPT_PACKET_SIZE    8
#define SCE_USBD_MAX_FS_INTERRUPT_PACKET_SIZE    64
#define SCE_USBD_MAX_BULK_PACKET_SIZE            64

#define SCE_USBD_FEATURE_ENDPOINT_HALT               0x00
#define SCE_USBD_FEATURE_DEVICE_REMOTE_WAKEUP        0x01

#define SCE_USBD_CLASS_PER_INTERFACE                 0x00
#define SCE_USBD_CLASS_AUDIO                         0x01
#define SCE_USBD_CLASS_COMMUNICATIONS                0x02
#define SCE_USBD_CLASS_HID                           0x03
#define SCE_USBD_CLASS_MONITOR                       0x04
#define SCE_USBD_CLASS_PHYSICAL                      0x05
#define SCE_USBD_CLASS_POWER                         0x06
#define SCE_USBD_CLASS_PRINTER                       0x07
#define SCE_USBD_CLASS_STORAGE                       0x08
#define SCE_USBD_CLASS_HUB                           0x09
#define SCE_USBD_CLASS_DATA                          0x0a
#define SCE_USBD_CLASS_VENDOR_SPECIFIC               0xff

typedef enum SceUsbdDescriptorType {
    SCE_USBD_DESCRIPTOR_DEVICE            = 0x01,    // bDescriptorType for a Device Descriptor.
    SCE_USBD_DESCRIPTOR_CONFIGURATION     = 0x02,    // bDescriptorType for a Configuration Descriptor.
    SCE_USBD_DESCRIPTOR_STRING            = 0x03,    // bDescriptorType for a String Descriptor.
    SCE_USBD_DESCRIPTOR_INTERFACE         = 0x04,    // bDescriptorType for an Interface Descriptor.
    SCE_USBD_DESCRIPTOR_ENDPOINT          = 0x05,    // bDescriptorType for an Endpoint Descriptor.

    SCE_USBD_DESCRIPTOR_DEVICE_QUALIFIER  = 0x06,    // bDescriptorType for a Device Qualifier.
    SCE_USBD_DESCRIPTOR_OTHER_SPEED       = 0x07,    // bDescriptorType for a Other Speed Configuration.
    SCE_USBD_DESCRIPTOR_INTERFACE_POWER   = 0x08,    // bDescriptorType for Interface Power.
    SCE_USBD_DESCRIPTOR_OTG               = 0x09,    // bDescriptorType for an OTG Descriptor.
    SCE_USBD_DESCRIPTOR_HID               = 0x21,    // bDescriptorType for an HID descriptor.
    SCE_USBD_DESCRIPTOR_REPORT            = 0x22     // bDescriptorType for an HID report descriptor.
} SceUsbdDescriptorType;

typedef enum SceUsbdErrorCode {
    SCE_USBD_ERROR_NOT_INITIALIZED     = 0x80240001,
    SCE_USBD_ERROR_ALREADY_INITIALIZED = 0x80240002,
    SCE_USBD_ERROR_INVALID_PARAM       = 0x80240003,

    SCE_USBD_ERROR_PIPE_NOT_FOUND      = 0x80240004,

    SCE_USBD_ERROR_NO_MEMORY           = 0x80240005,
    SCE_USBD_ERROR_DEVICE_NOT_FOUND    = 0x80240006,

    SCE_USBD_ERROR_80240007            = 0x80240007, //

    SCE_USBD_ERROR_80240009            = 0x80240009, //
    SCE_USBD_ERROR_8024000A            = 0x8024000A, //


    SCE_USBD_ERROR_FATAL               = 0x802400FF
} SceUsbdErrorCode;

typedef struct SceUsbdDeviceDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubclass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
} SceUsbdDeviceDescriptor;

typedef struct SceUsbdConfigurationDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttributes;
    uint8_t MaxPower;
} SceUsbdConfigurationDescriptor;

#define SCE_USBD_CONFIGURATION_RESERVED_ZERO         0x1f
#define SCE_USBD_CONFIGURATION_REMOTE_WAKEUP         0x20
#define SCE_USBD_CONFIGURATION_SELF_POWERED          0x40
#define SCE_USBD_CONFIGURATION_RESERVED_ONE          0x80

typedef struct SceUsbdInterfaceDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bInterfaceNumber;
    uint8_t bAlternateSetting;
    uint8_t bNumEndpoints;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubclass;
    uint8_t bInterfaceProtocol;
    uint8_t iInterface;
} SceUsbdInterfaceDescriptor;

typedef struct SceUsbdEndpointDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
} SceUsbdEndpointDescriptor;

/* bmAttributes */
#define SCE_USBD_ENDPOINT_TRANSFER_TYPE_BITS         0x03
#define SCE_USBD_ENDPOINT_TRANSFER_TYPE_SHIFT        0
#define SCE_USBD_ENDPOINT_TRANSFER_TYPE_CONTROL      0x00

#define SCE_USBD_ENDPOINT_TRANSFER_TYPE_ISOCHRONOUS  0x01
#define SCE_USBD_ENDPOINT_TRANSFER_TYPE_BULK         0x02
#define SCE_USBD_ENDPOINT_TRANSFER_TYPE_INTERRUPT    0x03

/* bEndpointAddress */
#define SCE_USBD_ENDPOINT_NUMBER_BITS                0x1f
#define SCE_USBD_ENDPOINT_NUMBER_SHIFT               0
#define SCE_USBD_ENDPOINT_DIRECTION_BITS             0x80
#define SCE_USBD_ENDPOINT_DIRECTION_SHIFT            7
#define SCE_USBD_ENDPOINT_DIRECTION_OUT              0x00
#define SCE_USBD_ENDPOINT_DIRECTION_IN               0x80


typedef struct SceUsbdStringDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bString[0];
} SceUsbdStringDescriptor;

typedef struct SceUsbdHidSubDescriptorInfo {
    uint8_t bDescriptorType;
    uint8_t wDescriptorLength0;
    uint8_t wDescriptorLength1;
} SceUsbdHidSubDescriptorInfo;

typedef struct SceUsbdHidDescriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bcdHID0;
    uint8_t bcdHID1;
    uint8_t bCountryCode;
    uint8_t bNumDescriptors;  /* SubDescriptor count */
    SceUsbdHidSubDescriptorInfo SubDescriptorInfo[0];
} SceUsbdHidDescriptor;

typedef struct SceUsbdDeviceAddress {
    uint32_t unk0;
    uint16_t unk1;
} SceUsbdDeviceAddress;

typedef struct SceUsbdDriver {
    const char *name;
    int (*probe)(int device_id);
    int (*attach)(int device_id);
    int (*detach)(int device_id);
} SceUsbdDriver;

typedef struct SceUsbdCompositeDriver {
    const char *name;
    int (*probe)(int device_id, SceUsbdEndpointDescriptor* desc); // endpoint descriptor should be interface one
    int (*attach)(int device_id);
    int (*detach)(int device_id);
} SceUsbdCompositeDriver;

typedef struct SceUsbdDeviceRequest {
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} SceUsbdDeviceRequest;

typedef enum SceUsbdReqtype {
    SCE_USBD_REQTYPE_DIR_BITS                  = 0x80,
    SCE_USBD_REQTYPE_DIR_TO_DEVICE             = 0x00,
    SCE_USBD_REQTYPE_DIR_TO_HOST               = 0x80,
    SCE_USBD_REQTYPE_TYPE_BITS                 = 0x60,
    SCE_USBD_REQTYPE_TYPE_STANDARD             = 0x00,
    SCE_USBD_REQTYPE_TYPE_CLASS                = 0x20,
    SCE_USBD_REQTYPE_TYPE_VENDOR               = 0x40,
    SCE_USBD_REQTYPE_TYPE_RESERVED             = 0x60,
    SCE_USBD_REQTYPE_RECIP_BITS                = 0x1f,
    SCE_USBD_REQTYPE_RECIP_DEVICE              = 0x00,
    SCE_USBD_REQTYPE_RECIP_INTERFACE           = 0x01,
    SCE_USBD_REQTYPE_RECIP_ENDPOINT            = 0x02,
    SCE_USBD_REQTYPE_RECIP_OTHER               = 0x03
} SceUsbdReqtype;

typedef enum SceUsbdRequest {
    SCE_USBD_REQUEST_GET_STATUS                = 0x00,
    SCE_USBD_REQUEST_CLEAR_FEATURE             = 0x01,
    SCE_USBD_REQUEST_SET_FEATURE               = 0x03,
    SCE_USBD_REQUEST_SET_ADDRESS               = 0x05,
    SCE_USBD_REQUEST_GET_DESCRIPTOR            = 0x06,
    SCE_USBD_REQUEST_SET_DESCRIPTOR            = 0x07,
    SCE_USBD_REQUEST_GET_CONFIGURATION         = 0x08,
    SCE_USBD_REQUEST_SET_CONFIGURATION         = 0x09,
    SCE_USBD_REQUEST_GET_INTERFACE             = 0x0a,
    SCE_USBD_REQUEST_SET_INTERFACE             = 0x0b,
    SCE_USBD_REQUEST_SYNCH_FRAME               = 0x0c
} SceUsbdRequest;

typedef struct ksceUsbdIsochPswLen {
    uint16_t len:12;
    uint16_t PSW:4;
} ksceUsbdIsochPswLen;

typedef struct ksceUsbdIsochTransfer {
    void *buffer_base;
    int32_t relative_start_frame;
    int32_t num_packets;
    ksceUsbdIsochPswLen packets[8];
} ksceUsbdIsochTransfer;

int ksceUsbdRegisterDriver(const SceUsbdDriver *driver);
int ksceUsbdRegisterCompositeLdd(const SceUsbdCompositeDriver *driver);
int ksceUsbdUnregisterDriver(const SceUsbdDriver *driver);
int ksceUsbdUnregisterCompositeLdd(const SceUsbdCompositeDriver *driver);

void *ksceUsbdScanStaticDescriptor(int device_id, void *start, unsigned char type);

// pipe = NULL to open the default control pipe
int ksceUsbdOpenPipe(int device_id, SceUsbdEndpointDescriptor *endpoint);
int ksceUsbdClosePipe(int pipe_id);

typedef void (*ksceUsbdDoneCallback)(int32_t result, int32_t count, void* arg);
typedef void (*ksceUsbdIsochDoneCallback)(int32_t result, ksceUsbdIsochTransfer *req, void *arg);

int ksceUsbdControlTransfer(
    int pipe_id,
    const SceUsbdDeviceRequest *req,
    unsigned char *buffer,
    ksceUsbdDoneCallback cb,
    void *user_data
);

int ksceUsbdInterruptTransfer(
    int pipe_id,
    unsigned char *buffer,
    unsigned int length,
    ksceUsbdDoneCallback cb,
    void *user_data
);

int ksceUsbdIsochronousTransfer(
    int pipe_id,
    ksceUsbdIsochTransfer* transfer,
    ksceUsbdIsochDoneCallback cb,
    void *user_data
);

int ksceUsbdBulkTransfer(
    int pipe_id,
    unsigned char *buffer,
    unsigned int length,
    ksceUsbdDoneCallback cb,
    void *user_data
);

int ksceUsbdBulkTransfer2(
    int pipe_id,
    unsigned char *buffer,
    unsigned int length,
    ksceUsbdDoneCallback cb,
    void *user_data
);

int ksceUsbdGetDeviceLocation(int device_id, uint8_t *location);

int ksceUsbdSuspend(int port);
int ksceUsbdSuspendPhase2(int port, int flag);
int ksceUsbdResume(int port);

int ksceUsbdHostStop(int port);
int ksceUsbdHostStart(int port);

int ksceUsbdGetDeviceSpeed(int device_id, uint8_t *speed);
#define SCE_USBD_DEVICE_SPEED_LS   (0)
#define SCE_USBD_DEVICE_SPEED_FS   (1)
#define SCE_USBD_DEVICE_SPEED_HS   (2)


#define ksceUsbdSetConfiguration(pid, config, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x00; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_CONFIGURATION; \
  _dr.wValue = (config); \
  _dr.wIndex = 0; \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })


#define ksceUsbdClearDeviceFeature(pid, fs, cb, arg) ({  \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x00; \
  _dr.bRequest = SCE_USBD_REQUEST_CLEAR_FEATURE; \
  _dr.wValue = (fs); \
  _dr.wIndex = 0; \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdClearInterfaceFeature(pid, fs, interface, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x01; \
  _dr.bRequest = SCE_USBD_REQUEST_CLEAR_FEATURE; \
  _dr.wValue = (fs); \
  _dr.wIndex = (interface); \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdClearEndpointFeature(pid, fs, endpoint, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x02; \
  _dr.bRequest = SCE_USBD_REQUEST_CLEAR_FEATURE; \
  _dr.wValue = (fs); \
  _dr.wIndex = (endpoint); \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdGetConfiguration(pid, ptr, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x80; \
  _dr.bRequest = SCE_USBD_REQUEST_GET_CONFIGURATION; \
  _dr.wValue = 0; \
  _dr.wIndex = 0; \
  _dr.wLength = 1; \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdGetDescriptor(pid, type, index, lang_id, ptr, len, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x80; \
  _dr.bRequest = SCE_USBD_REQUEST_GET_DESCRIPTOR; \
  _dr.wValue = ((type) << 8) | (index); \
  _dr.wIndex = (lang_id); \
  _dr.wLength = (len); \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdGetInterface(pid, interface, ptr, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x81; \
  _dr.bRequest = SCE_USBD_REQUEST_GET_INTERFACE; \
  _dr.wValue = 0; \
  _dr.wIndex = (interface); \
  _dr.wLength = 1; \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdGetDeviceStatus(pid, ptr, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x80; \
  _dr.bRequest = SCE_USBD_REQUEST_GET_STATUS; \
  _dr.wValue = 0; \
  _dr.wIndex = 0; \
  _dr.wLength = 2; \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdGetInterfaceStatus(pid, interface, ptr, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x81; \
  _dr.bRequest = SCE_USBD_REQUEST_GET_STATUS; \
  _dr.wValue = 0; \
  _dr.wIndex = (interface); \
  _dr.wLength = 2; \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdGetEndpointStatus(pid, endpoint, ptr, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x82; \
  _dr.bRequest = SCE_USBD_REQUEST_GET_STATUS; \
  _dr.wValue = 0; \
  _dr.wIndex = (endpoint); \
  _dr.wLength = 2; \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdSetAddress(pid, address, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x00; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_ADDRESS; \
  _dr.wValue = (address); \
  _dr.wIndex = 0; \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdSetConfiguration(pid, config, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x00; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_CONFIGURATION; \
  _dr.wValue = (config); \
  _dr.wIndex = 0; \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdSetDeviceDescriptor(pid, type, index, lang_id, ptr, len, \
              cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x00; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_DESCRIPTOR; \
  _dr.wValue = ((type) << 8) | (index); \
  _dr.wIndex = (lang_id); \
  _dr.wLength = (len); \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdSetInterfaceDescriptor(pid, type, index, lang_id, ptr, len, \
              cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x01; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_DESCRIPTOR; \
  _dr.wValue = ((type) << 8) | (index); \
  _dr.wIndex = (lang_id); \
  _dr.wLength = (len); \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdSetEndpointDescriptor(pid, type, index, lang_id, ptr, len, \
                cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x02; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_DESCRIPTOR; \
  _dr.wValue = ((type) << 8) | (index); \
  _dr.wIndex = (lang_id); \
  _dr.wLength = (len); \
  ksceUsbdControlTransfer((pid), (&_dr), (ptr), (cb), (arg)); })

#define ksceUsbdSetDeviceFeature(pid, fs, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x00; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_FEATURE; \
  _dr.wValue = (fs); \
  _dr.wIndex = 0; \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdSetInterfaceFeature(pid, fs, interface, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x01; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_FEATURE; \
  _dr.wValue = (fs); \
  _dr.wIndex = (interface); \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdSetEndpointFeature(pid, fs, endpoint, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x02; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_FEATURE; \
  _dr.wValue = (fs); \
  _dr.wIndex = (endpoint); \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdSetInterface(pid, interface, alt_setting, cb, arg) ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x01; \
  _dr.bRequest = SCE_USBD_REQUEST_SET_INTERFACE; \
  _dr.wValue = (alt_setting); \
  _dr.wIndex = (interface); \
  _dr.wLength = 0; \
  ksceUsbdControlTransfer((pid), (&_dr), NULL, (cb), (arg)); })

#define ksceUsbdSynchFrame(pid, endpoint, pfn, cb, arg)  ({ \
  SceUsbdDeviceRequest _dr; \
  _dr.bmRequestType = 0x82; \
  _dr.bRequest = SCE_USBD_REQUEST_SYNCH_FRAME; \
  _dr.wValue = 0; \
  _dr.wIndex = (endpoint); \
  _dr.wLength = 2; \
  ksceUsbdControlTransfer((pid), (&_dr), pfn, (cb), (arg)); })

// OHCI/EHCI completion codes
#define OHCI_CC_NO_ERROR                      0x0
#define OHCI_CC_CRC                           0x1
#define OHCI_CC_BIT_STUFFING                  0x2
#define OHCI_CC_DATA_TOGGLE_MISMATCH          0x3
#define OHCI_CC_STALL                         0x4
#define OHCI_CC_DEVICE_NOT_RESPONDING         0x5
#define OHCI_CC_PID_CHECK_FAILURE             0x6
#define OHCI_CC_UNEXPECTED_PID                0x7
#define OHCI_CC_DATA_OVERRUN                  0x8
#define OHCI_CC_DATA_UNDERRUN                 0x9
#define OHCI_CC_BUFFER_OVERRUN                0xc
#define OHCI_CC_BUFFER_UNDERRUN               0xd
#define OHCI_CC_NOT_ACCESSED1                 0xe
#define OHCI_CC_NOT_ACCESSED2                 0xf
#define EHCI_CC_MISSED_MICRO_FRAME            0x10
#define EHCI_CC_XACT                          0x20
#define EHCI_CC_BABBLE                        0x30
#define EHCI_CC_DATABUF                       0x40
#define EHCI_CC_HALTED                        0x50

// Isochronous transfer(PSW) completion codes
#define USBD_CC_NOERR               0x0
#define USBD_CC_MISSED_MICRO_FRAME  0x1
#define USBD_CC_XACTERR             0x2
#define USBD_CC_BABBLE              0x4
#define USBD_CC_DATABUF             0x8


//0x05073925 SceUsbdForDriver_05073925 // 0.990 - 3.74 (device_id, int*, int*) - // not sceUsbdGetDeviceAddressForDriver() // or set??
//0x0e73d253 SceUsbdForDriver_0E73D253 // 0.931 - 3.74, sceUsbdGetBusNumberForDriver(int device_id, uint8_t *bus); / or sceUsbdGetDeviceLocationForDriver?
//0x206634f9 SceUsbdForDriver_206634F9 // 0.931 - 3.74, int sceUsbdResumeForDriver(int device_id or port?), called by _sceUsbServResume,// OFFICIAL
//0x2249bf99 SceUsbdForDriver_2249BF99 // 0.931 - 3.74, // sceUsbdIsochronousTransferForDriver(int pipe_id, ksceUsbdIsochTransfer*, ksceUsbdIsochDoneCallback cb, void *user_data) ?? //  sets some flag to 1, used by usbaudio
//0x235c094a SceUsbdForDriver_235C094A // 0.931 - 3.74, sceUsbdBulkTransferForDriver(int pipe_id, unsigned char *buffer, unsigned int length,  void (*cb)(int, int, int*), void *user_data) // 0.931 - 3.74, // sceUsbdBulkTransferForDriver() ?? //  sets some flag to 1, used by umass, rtl, smsc (0.94), bbmc
//0x3c3396bb SceUsbdForDriver_3C3396BB // 0.931 - 3.74, sceUsbdHostStop(int port) // called by Usbserv when disabling host mode // OFFICIAL
//0x3ebf5ffe SceUsbdForDriver_3EBF5FFE // 0.931 - 3.74, // int sceUsbdSuspendForDriver(int device_id or port?) ?? // called by _sceUsbServSuspend // OFFICIAL
//0x470d5289 SceUsbdForDriver_470D5289 // 0.990 - 3.74  // sceUsbdBulkTransferForDriver2(int pipe_id, unsigned char *buffer, unsigned int length,  void (*cb)(int, int, int*), void *user_data) ?? //  sets some flag to 0, used by rtl, smsc
//0x5e301e18 SceUsbdForDriver_5E301E18 // 0.931 - 3.74, sceUsbdHostStart(int port) // called by Usbserv when enabling host mode // OFFICIAL
//0x7934bb4a SceUsbdForDriver_7934BB4A // 0.931 - 3.74, sceUsbdUnregisterCompositeLddForDriver(const SceUsbdCompositeDriver *driver);
//0x7938dac7 SceUsbdForDriver_7938DAC7 // 3.10 - 3.74, (int pipe_id) usb-audio related // clear halt?
//0xc3becf5f SceUsbdForDriver_C3BECF5F // 0.931 - 3.74, sceUsbdGetDeviceSpeedForDriver(int device_id, uint8_t *speed);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2KERN_USBD_H_ */
