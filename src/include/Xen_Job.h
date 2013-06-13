// Copyright (C) 2006 IBM Corporation
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Lesser General Public
//    License as published by the Free Software Foundation; either
//    version 2.1 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef XEN_JOB_H
#define XEN_JOB_H

#include "cmpiutil.h"
#include "cmpitrace.h"
#include "provider_common.h"
#include "xen_utils.h"

bool jobs_running();
int jobs_initialize();
int jobs_uninitialize();

typedef void (*async_task)(void *job_context);

typedef struct _job {
    const CMPIBroker* broker;
    CMPIContext *call_context;
    xen_utils_session *session;
    char        *job_name;
    char        *domain_name;
    char        *ref_cn;
    char        *ref_ns;
    char        uuid[UUID_LEN + 1];
    xen_task    task_handle;
    async_task  callback;
    void        *job_context;
} Xen_job;

int job_create(
    const CMPIBroker    *broker,
    const CMPIContext   *call_context,
    xen_utils_session   *session,
    char                *job_name,
    char                *domain_name,
    async_task          callback,
    void                *job_context,
    CMPIObjectPath      **job_instance_op,   /* out */
    CMPIStatus          *status);            /* out */

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

typedef enum _JobState{
    JobState_New=2,
    JobState_Starting=3,
    JobState_Running=4,
    JobState_Suspended=5,
    JobState_Shutting_Down=6,
    JobState_Completed=7,
    JobState_Terminated=8,
    JobState_Killed=9,
    JobState_Exception=10,
    JobState_Service=11,
    JobState_Query_Pending=12,
    /*JobState_DMTF_Reserved=13..32767,*/
    /*JobState_Vendor_Reserved=32768..65535,*/
}JobState;

typedef enum _LocalOrUtcTime{
    LocalOrUtcTime_Local_Time=1,
    LocalOrUtcTime_UTC_Time=2,
}LocalOrUtcTime;

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

typedef enum _RecoveryAction{
    RecoveryAction_Unknown=0,
    RecoveryAction_Other=1,
    RecoveryAction_Do_Not_Continue=2,
    RecoveryAction_Continue_With_Next_Job=3,
    RecoveryAction_Re_run_Job=4,
    RecoveryAction_Run_Recovery_Job=5,
}RecoveryAction;

typedef enum _RunDayOfWeek{
    RunDayOfWeek__Saturday=-7,
    RunDayOfWeek__Friday=-6,
    RunDayOfWeek__Thursday=-5,
    RunDayOfWeek__Wednesday=-4,
    RunDayOfWeek__Tuesday=-3,
    RunDayOfWeek__Monday=-2,
    RunDayOfWeek__Sunday=-1,
    RunDayOfWeek_ExactDayOfMonth=0,
    RunDayOfWeek_Sunday=1,
    RunDayOfWeek_Monday=2,
    RunDayOfWeek_Tuesday=3,
    RunDayOfWeek_Wednesday=4,
    RunDayOfWeek_Thursday=5,
    RunDayOfWeek_Friday=6,
    RunDayOfWeek_Saturday=7,
}RunDayOfWeek;

typedef enum _RunMonth{
    RunMonth_January=0,
    RunMonth_February=1,
    RunMonth_March=2,
    RunMonth_April=3,
    RunMonth_May=4,
    RunMonth_June=5,
    RunMonth_July=6,
    RunMonth_August=7,
    RunMonth_September=8,
    RunMonth_October=9,
    RunMonth_November=10,
    RunMonth_December=11,
}RunMonth;

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

/* End generated code */
void job_change_state(
    Xen_job* job, 
    xen_utils_session *session,
    JobState state, 
    int percent_complete, 
    int error_code,
    char* description);

#endif /* XEN_JOB_H */