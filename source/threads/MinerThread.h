////////////////////////////////////////////////
// File:	MinerThread.h
//
// Author:	Videlicet
//			Liam Russell (A.K.A. BitSlapper)
//
// Copyright:	2014-2015 Videlicet 
//				2014-2015 Liam Russell
//
// License:	GNU GENERAL PUBLIC LICENSE V3
//////////////////////////////////////////////

#ifndef _MINERTHREAD_H_
#define _MINERTHREAD_H_

#include "../zcore/types.h"
#include "../gpu/GPUData.h"
#include <boost/thread/mutex.hpp>
 
class MinerData;

typedef bool(*HashFuncPtrType)(MinerData*);

class MinerThread
	{

	protected:

		MinerData* m_pMinerData;
		bool m_bBlockFound, m_bNewBlock, m_bReady;
		LLP::Thread_t* m_pTHREAD;
		unsigned int m_unHashes;
		double total_mhashes_done;
		boost::mutex* m_clLock;
		bool m_bShutown;
		bool m_bDidShutDown;

		HashFuncPtrType m_hashFunPtr;

	public:			
		
		MinerThread();
		MinerThread(MinerData* pData);
		MinerThread(const MinerThread& miner);
		MinerThread& operator=(const MinerThread& miner);
		~MinerThread();
                void DelMinerThread();
		
		//Main Miner Thread. Bound to the class with boost. Might take some rearranging to get working with OpenCL.
		void Miner() { }

		void Lock()		{ if (m_clLock) { m_clLock->lock(); } }
		void Unlock()	{ if (m_clLock)	{ m_clLock->unlock(); } }
			
		///////////////////////////////////////////////////////////////////////////////
		//Accessors
		///////////////////////////////////////////////////////////////////////////////
		const bool				GetIsShuttingDown() const	{	return this->m_bShutown;			}	
		const bool				GetDidShutDown()	const	{	return this->m_bDidShutDown;		}
		const bool				GetIsBlockFound()	const	{	return this->m_bBlockFound;			}
		const bool				GetIsNewBlock()		const	{	return this->m_bNewBlock;			}
		const bool				GetIsReady()		const	{	return this->m_bReady;				}
		const unsigned int		GetHashes()			const	{	return this->m_unHashes;			}
		MinerData*				GetMinerData()		const	{	return this->m_pMinerData;			}
		
		///////////////////////////////////////////////////////////////////////////////
		//Mutators
		///////////////////////////////////////////////////////////////////////////////
		void    SetIsShuttingDown(bool bIsShuttingDown)		{	this->m_bShutown = bIsShuttingDown; }
		void	SetIsBlockFound(bool bFoundBlock)			{	this->m_bBlockFound = bFoundBlock;	}
		void	SetIsNewBlock(bool bNewBlock)				{	this->m_bNewBlock = bNewBlock;		}
		void	SetIsReady(bool bReady)						{	this->m_bReady = bReady;			}
		void	SetHashes(unsigned int unHashes)			{	this->m_unHashes = unHashes;		}
		void	SetMinerData(MinerData* pMinerData)			{	this->m_pMinerData = pMinerData;	}
		void	SetHashFunc(HashFuncPtrType hashFunc)		{	this->m_hashFunPtr = hashFunc;		}

};

#endif //_MINERTHREAD_H_
