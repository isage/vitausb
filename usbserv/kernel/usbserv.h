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

int ksceUsbServEtherEnable(); // 0x30AE5F66
int ksceUsbServEtherDisable(); // 0xD787B191
int ksceUsbServAccessoryActivate(); // AA6D4409
int ksceUsbServAccessoryDeactivate(); // 0x853CB8E4
int ksceUsbServMacSelect(uint32_t usbPort, uint32_t clientMode); // 0x7AD36284
SceBool ksceUsbServMacGet(uint32_t usbPort); // 0xF0553A69

int ksceUsbServDisableEtherSuspend(); // 0x6D738018, guessed name

#ifdef __cplusplus
}
#endif

#endif /* _PSP2KERN_USBSERV_H_ */
