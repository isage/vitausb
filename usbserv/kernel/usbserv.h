/**
 Copyright 2022 Cat (Epifanov Ivan)

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
 Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/**
 * \kernelgroup{SceUsbServ}
 * \usage{psp2kernel/usbserv.h,SceUsbServForDriver_stub}
 */


#ifndef _PSP2KERN_USBSERV_H_
#define _PSP2KERN_USBSERV_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SceUsbservErrorCode {
    SCE_USBSERV_ERROR_UNAVAILABLE   = 0x80248002,
    SCE_USBSERV_ERROR_INVALID_PARAM = 0x80248003,
    SCE_USBSERV_ERROR_NOT_SUPPORTED = 0x80248004,

    SCE_USBSERV_ERROR_FATAL         = 0x802480FF
} SceUsbservErrorCode;

int ksceUsbServEtherEnable(void); // 0x30AE5F66
int ksceUsbServEtherDisable(void); // 0xD787B191
int ksceUsbServAccessoryActivate(void); // AA6D4409
int ksceUsbServAccessoryDeactivate(void); // 0x853CB8E4
int ksceUsbServMacSelect(uint32_t usbPort, uint32_t clientMode); // 0x7AD36284
SceBool ksceUsbServMacGet(uint32_t usbPort); // 0xF0553A69

int ksceUsbServDisableEtherSuspend(); // 0x6D738018, guessed name

#ifdef __cplusplus
}
#endif

#endif /* _PSP2KERN_USBSERV_H_ */
