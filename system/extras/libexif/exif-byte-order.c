/* exif-byte-order.c
 *
 * Copyright (c) 2002 Lutz Mueller <lutz@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details. 
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA.
 */

#include <exif-byte-order.h>
#include <i18n.h>

#include <stdlib.h>

const char *
exif_byte_order_get_name (ExifByteOrder order)
{
	switch (order) {
	case EXIF_BYTE_ORDER_MOTOROLA:
		return (_("Motorola"));
	case EXIF_BYTE_ORDER_INTEL:
		return (_("Intel"));
	default:
		return NULL;
	}
}
