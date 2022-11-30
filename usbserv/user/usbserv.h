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
 * \usergroup{SceUsbServ}
 * \usage{psp2/usbserv.h,SceUsbServ_stub}
 */


#ifndef _PSP2_USBSERV_H_
#define _PSP2_USBSERV_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SceUsbservErrorCode {
    SCE_USBSERV_ERROR_UNAVAILABLE    = 0x80248002,
    SCE_USBSERV_ERROR_INVALID_PARAM  = 0x80248003,
    SCE_USBSERV_ERROR_NOT_SUPPPORTED = 0x80248004,

    SCE_USBSERV_ERROR_FATAL          = 0x802480FF
} SceUsbservErrorCode;

int sceUsbServAccessoryActivate(void);
int sceUsbServAccessoryDeactivate(void);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_USBSERV_H_ */
