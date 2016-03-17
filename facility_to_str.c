/*
 * This file is part of parse_hresult.
 *
 * parse_hresult is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * parse_hresult is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with parse_hresult.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <winerror.h>
#include "facility_to_str.h"

char *facility_to_str(uint32_t facility)
{
#define F(facility, desc) case (facility) : return # facility ": " desc;
    switch (facility) {
        F(FACILITY_NULL, "default facility code");
        F(FACILITY_RPC, "RPC subsystem");
        F(FACILITY_DISPATCH, "COM Dispatch");
        F(FACILITY_STORAGE, "OLE Storage");
        F(FACILITY_ITF, "COM/OLE Interface management");
        F(FACILITY_WIN32, "Win32 Error codes");
        F(FACILITY_WINDOWS, "Windows subsystem");
        F(FACILITY_SECURITY, "Security API layer");
        F(FACILITY_CONTROL, "control mechanism");
        F(FACILITY_CERT, "certificate client or server");
        F(FACILITY_INTERNET, "Wininet related");
        F(FACILITY_MEDIASERVER, "Windows Media Server");
        F(FACILITY_MSMQ, "Microsoft Message Queue");
        F(FACILITY_SETUPAPI, "Setup API");
        F(FACILITY_SCARD, "Smart-card subsystem");
        F(FACILITY_COMPLUS, "COM+");
        F(FACILITY_AAF, "Microsoft agent");
        F(FACILITY_URT, ".NET CLR");
        F(FACILITY_ACS, "audit collection service");
        F(FACILITY_DPLAY, "Direct Play");
        F(FACILITY_UMI, "ubiquitous memoryintrospection service");
        F(FACILITY_SXS, "Side-by-side servicing");
        F(FACILITY_WINDOWS_CE, "specific to Windows CE");
        F(FACILITY_HTTP, "HTTP support");
        F(FACILITY_USERMODE_FILTER_MANAGER, "the user mode filter manager");
        F(FACILITY_BACKGROUNDCOPY, "background copy control");
        F(FACILITY_CONFIGURATION, "configuration services");
        F(FACILITY_STATE_MANAGEMENT, "state management services");
        F(FACILITY_METADIRECTORY, "Microsoft Identity Server");
        F(FACILITY_WINDOWSUPDATE, "Windows update");
        F(FACILITY_DIRECTORYSERVICE, "Active Directory");
        F(FACILITY_AUDCLNT, "WASAPI");
#undef F
        // stuff not defined in winerror.h
#define NF(n, desc) case (n): return (desc);
        NF(26, "FACILITY_USERMODE_COMMONLOG: common Logging support");
        NF(38, "FACILITY_GRAPHICS: graphics drivers");
        NF(39, "FACILITY_SHELL: user Shell");
        NF(40, "FACILITY_TPM_SERVICES: Trusted Platform Module services");
        NF(41, "FACILITY_TPM_SOFTWARE: Trusted Platform Module applications");
        NF(48, "FACILITY_PLA: Performance Logs and Alerts");
        NF(49, "FACILITY_FVE: Full volume encryption");
        NF(50, "FACILITY_FWP: Firewall Platform");
        NF(51, "FACILITY_WINRM: Windows Resource Manager");
        NF(52, "FACILITY_NDIS: Network Driver Interface");
        NF(53, "FACILITY_USERMODE_HYPERVISOR: Usermode Hypervisor components");
        NF(54, "FACILITY_CMI: Configuration Management Infrastructure");
        NF(55, "FACILITY_USERMODE_VIRTUALIZATION: user mode virtualization subsystem");
        NF(56, "FACILITY_USERMODE_VOLMGR: user mode volume manager");
        NF(57, "FACILITY_BCD: Boot Configuration Database");
        NF(58, "FACILITY_USERMODE_VHD: user mode virtual hard disk support");
        NF(60, "FACILITY_SDIAG: System Diagnostics");
        NF(61, "FACILITY_WEBSERVICES: Web Services");
        NF(80, "FACILITY_WINDOWS_DEFENDER: Windows Defender component");
        NF(81, "FACILITY_OPC: open connectivity service");
#undef NF
    default: return "<unknown>";
    }

}
