////////////////////////////////////////////////
// File:	ADLGPU.h
//
// Author:	Liam Russell (A.K.A. BitSlapper)
//
// Copyright: 2014-2015 Liam Russell
//
// License:	GNU GENERAL PUBLIC LICENSE V3
//////////////////////////////////////////////


#ifndef _ADLGPU_H_
#define _ADLGPU_H_

#if defined (__unix__)
#define LINUX  // apparently not defined correctly somewhere...
#include "../ADL_SDK/adl_sdk.h"
#include <dlfcn.h>	//dyopen, dlsym, dlclose
#include <stdlib.h>	
#include <string.h>	//memeset
#include <unistd.h>	//sleep

#else /* WIN32 */
#include <windows.h>
#include "../ADL_SDK/adl_sdk.h"
#include <tchar.h>
#endif

#include "BaseGPU.h"


class ADLGPU : public BaseGPU
{
private:

	ADLTemperature			m_lpTemperature;
	ADLPMActivity			m_lpActivity;
	ADLODParameters			m_lpOdParameters;
	ADLODPerformanceLevels*	m_pDefPerfLev;
	ADLFanSpeedInfo			m_lpFanSpeedInfo;
	ADLFanSpeedValue		m_lpFanSpeedValue;
	ADLFanSpeedValue		m_lpDefFanSpeedValue;

	int						m_nLPAdapterID;
	
public:

	///////////////////////////////////////////////////////////////////////////////
	//Constructor
	///////////////////////////////////////////////////////////////////////////////
	ADLGPU();

	///////////////////////////////////////////////////////////////////////////////
	//Copy Constructor
	///////////////////////////////////////////////////////////////////////////////
	ADLGPU(const ADLGPU& adlGPU);

	///////////////////////////////////////////////////////////////////////////////
	//Assignment Operator
	///////////////////////////////////////////////////////////////////////////////
	ADLGPU& operator=(const ADLGPU& adlGPU);

	///////////////////////////////////////////////////////////////////////////////
	//Destructor
	///////////////////////////////////////////////////////////////////////////////
	~ADLGPU();

	ADLGPU* Clone();
	ADLGPU* DeepCopy();

	///////////////////////////////////////////////////////////////////////////////
	//Accessors
	///////////////////////////////////////////////////////////////////////////////
	const ADLTemperature&			GetADLTemperature()			const										{	return this->m_lpTemperature;						}
	const ADLPMActivity&			GetADLPMActivity()			const										{	return this->m_lpActivity;							}
	const ADLODParameters&			GetADLODParameters()		const										{	return this->m_lpOdParameters;						}
	ADLODPerformanceLevels*			GetADLODPerformanceLevels()	const										{	return this->m_pDefPerfLev;							}	
	const ADLFanSpeedInfo&			GetADLFanSpeedInfo()		const										{	return this->m_lpFanSpeedInfo;						}
	const ADLFanSpeedValue&			GetADLFanSpeedValue()		const										{	return this->m_lpFanSpeedValue;						}
	const ADLFanSpeedValue&			GetADLDefFanSpeedValue()	const										{	return this->m_lpDefFanSpeedValue;					}
	const int						GetLPAdapterID()			const										{	return this->m_nLPAdapterID;						}

	///////////////////////////////////////////////////////////////////////////////
	//Mutators
	///////////////////////////////////////////////////////////////////////////////
	void							SetADLTemperature(const ADLTemperature& lpTemperature)					{	this->m_lpTemperature = lpTemperature;				}
	void							SetADLPMActivity(const ADLPMActivity& lpActivity)						{	this->m_lpActivity = lpActivity;					}
	void							SetADLODParameters(const ADLODParameters& lpOdParameters)				{	this->m_lpOdParameters = lpOdParameters;			}
	void							SetADLODPerformanceLevels(ADLODPerformanceLevels* pDefPerfLev)			{	this->m_pDefPerfLev = pDefPerfLev;					}	
	void							SetADLFanSpeedInfo(const ADLFanSpeedInfo& lpFanSpeedInfo)				{	this->m_lpFanSpeedInfo = lpFanSpeedInfo;			}	
	void							SetADLFanSpeedValue(const ADLFanSpeedValue& lpFanSpeedValue)			{	this->m_lpFanSpeedValue = lpFanSpeedValue;			}
	void							SetADLDefFanSpeedValue(const ADLFanSpeedValue& lpDefFanSpeedValue)		{	this->m_lpDefFanSpeedValue = lpDefFanSpeedValue;	}
	void							SetLPAdapterID(const int nLPAdapterID)									{	this->m_nLPAdapterID = nLPAdapterID;				}
};


#endif //_ADLGPU_H_
