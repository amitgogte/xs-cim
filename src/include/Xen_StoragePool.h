// ***** Generated by Codegen *****
// Copyright (C) 2008-2009 Citrix Systems Inc
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef __XEN_STORAGEPOOL_H__
#define __XEN_STORAGEPOOL_H__

/* Values for the various properties of the class */


typedef enum _HealthState{
    HealthState_Unknown=0,
    HealthState_OK=5,
    HealthState_Degraded_Warning=10,
    HealthState_Minor_failure=15,
    HealthState_Major_failure=20,
    HealthState_Critical_failure=25,
    HealthState_Non_recoverable_error=30,
    /*HealthState_DMTF_Reserved=..,*/
}HealthState;

typedef enum _OperationalStatus{
    OperationalStatus_Unknown=0,
    OperationalStatus_Other=1,
    OperationalStatus_OK=2,
    OperationalStatus_Degraded=3,
    OperationalStatus_Stressed=4,
    OperationalStatus_Predictive_Failure=5,
    OperationalStatus_Error=6,
    OperationalStatus_Non_Recoverable_Error=7,
    OperationalStatus_Starting=8,
    OperationalStatus_Stopping=9,
    OperationalStatus_Stopped=10,
    OperationalStatus_In_Service=11,
    OperationalStatus_No_Contact=12,
    OperationalStatus_Lost_Communication=13,
    OperationalStatus_Aborted=14,
    OperationalStatus_Dormant=15,
    OperationalStatus_Supporting_Entity_in_Error=16,
    OperationalStatus_Completed=17,
    OperationalStatus_Power_Mode=18,
    /*OperationalStatus_DMTF_Reserved=..,*/
    /*OperationalStatus_Vendor_Reserved=0x8000..,*/
}OperationalStatus;

#define Status_OK "OK"
#define Status_Error "Error"
#define Status_Degraded "Degraded"
#define Status_Unknown "Unknown"
#define Status_Pred_Fail "Pred_Fail"
#define Status_Starting "Starting"
#define Status_Stopping "Stopping"
#define Status_Service "Service"
#define Status_Stressed "Stressed"
#define Status_NonRecover "NonRecover"
#define Status_No_Contact "No_Contact"
#define Status_Lost_Comm "Lost_Comm"
#define Status_Stopped "Stopped"


#endif /*__XEN_STORAGEPOOL_H__*/
