/* GStreamer
 * Copyright (C) 2007 Sebastien Moutte <sebastien@moutte.net>
 *
 * gstdshow.h:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef _GSTDSHOW_
#define _GSTDSHOW_

#ifdef __cplusplus
#include <streams.h>
#endif
#include <windows.h>
#include <objbase.h>
#include <dshow.h>
#include <Rpc.h>

#include <glib.h>

typedef struct _GstCapturePinMediaType
{
  AM_MEDIA_TYPE *mediatype;
  IPin *capture_pin;
} GstCapturePinMediaType;

#ifdef  __cplusplus
extern "C" {
#endif

/* register fake filters as COM object and as Direct Show filters in the registry */
//HRESULT gst_dshow_register_fakefilters ();

/* free memory of the input pin mediatype */
void gst_dshow_free_pin_mediatype (gpointer pt);

/* free memory of the input dshow mediatype */
void gst_dshow_free_mediatype (AM_MEDIA_TYPE *pmt);

/* free the memory of all mediatypes of the input list if pin mediatype */
void gst_dshow_free_pins_mediatypes (GList *mediatypes);

/* get a pin from directshow filter */
gboolean gst_dshow_get_pin_from_filter (IBaseFilter *filter, PIN_DIRECTION pindir, IPin **pin);

/* find and return a filter according to the input and output types */
gboolean gst_dshow_find_filter(CLSID input_majortype, CLSID input_subtype, 
                               CLSID output_majortype, CLSID output_subtype,
                               gchar * prefered_filter_name, IBaseFilter **filter);

/* get the dshow device path from device friendly name. 
If friendly name is not set, it will return the first available device */
gchar *gst_dshow_getdevice_from_devicename (const GUID *device_category, gchar **device_name);

/* show the capture filter property page (generally used to setup the device). the page is modal*/
gboolean gst_dshow_show_propertypage (IBaseFilter *base_filter);

#ifdef  __cplusplus
}
#endif

#endif /* _GSTDSHOW_ */