# parse_hresult

This is a utility to help make sense of the cryptic HRESULT error codes commonly
used by Microsoft Windows APIs and programs interfacing with them. It is based
on the information available on
[Wikipedia](https://en.wikipedia.org/wiki/HRESULT) and
[MSDN](https://msdn.microsoft.com/en-us/library/cc231198.aspx).

# Usage

Simply run the command with the hexidecimal error code as the argument. The
program will disect the bits of the resulting 32 bit integer and provide
resulting analysis. For example

    ./parse_hresult 0x80070005

will produce the output

     HRESULT = Access is denied. (0x80070005) (-2147024891)
        8    0    0    7    0    0    0    5
     1000 0000 0000 0111 0000 0000 0000 0101
     SRCN X--- ---- ---- ---- ---- ---- ----
           | FACILITY  | |      CODE       |

     32    S: Severity (status)              = 1 (failure)
     31    R: Reserved (actual severity)     = 0 (normal)
     30    C: Customer (defined by)          = 0 (Microsoft)
     29    N: NT mapped status value         = 0
     28    X: Is message ID?                 = 0
     27-17 FACILITY: The source of the error = 7 (FACILITY_WIN32: Win32 Error codes)
     16-01 CODE: The error code              = 5 (Access is denied. (0x5))

# Compiling

The only dependencies other than standard Windows libraries and headers are make
and a c complier (only gcc has been tested). On MSYS2 or Cygwin, the
`parse_hresult.exe` executable can be produced by typing

    make

To remove the executable and object files, run

    make clean
