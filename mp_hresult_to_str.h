/*
 * copied from mpv windows_utils.h (e26462599bc272f7e90c2c6e820d5d9ec1c801d6)
 * Original copyright header follows:
 *
 * This file is part of mpv.
 *
 * mpv is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * mpv is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with mpv.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <windows.h>
char *mp_HRESULT_to_str_buf(char *buf, size_t buf_size, HRESULT hr);
#define mp_HRESULT_to_str(hr) mp_HRESULT_to_str_buf((char[256]){0}, 256, (hr))
