/*
  -- --------------------------------------------------------------
  -- MODULE: Upper Casing Example All in C, using icc.
  --
  -- FILE : system.c
  --
  -- NAME : Richard Onyett (Santa Clara, RTC)
  --
  -- PURPOSE:
  --   To create and run two parallel processes to perform the
  --   upper casing function.
  -- --------------------------------------------------------------
  */

#include <stdlib.h>
#include <stdio.h>
#include <channel.h>
#include <process.h>

/* New headers for the channel IO */
/* New headers for the processes  */
/*
-- The Master and worker processes are in different files.
*/

extern void Worker( Process *p, Channel *FromMaster, Channel *ToMaster );
extern void Master( Process *p, Channel *FromWorker, Channel *ToWorker );

int main ( void )
{
	Process *WorkerPtr, *MasterPtr; /* Declare some processes */
  	Channel *ToWorker, *FromWorker; /* Connect ’em up with channels */
  	printf( "Upper Casing EXAMPLE - STARTS\n" );
  	
  	/*	-- Allocate and initialise some channels. */
  	if (( ToWorker = ChanAlloc()) == NULL )
  	{
    	printf( "ERROR- Cannot allocate space for channel ToWorker\n" );
    	exit( EXIT_FAILURE );
	}

	if (( FromWorker = ChanAlloc()) == NULL )
	{
    	printf( "ERROR- Cannot allocate space for channel FromWorker\n" );
      	exit( EXIT_FAILURE );
	}

    /*  -- Allocate the processes needed. */
    if (( WorkerPtr = ProcAlloc( Worker, 0, 2, ToWorker, FromWorker )) == NULL )
    {
    	printf( "ERROR- Cannot allocate space for process Worker\n" );
      	exit( EXIT_FAILURE );
    }
    
    if (( MasterPtr = ProcAlloc( Master, 0, 2, FromWorker, ToWorker )) == NULL )
    {
    	printf( "ERROR- Cannot allocate space for process Master\n" );
      	exit( EXIT_FAILURE );
    }
    
    /*
    -- Now we have some processes, lets run ’em all in parallel...
    -- This will not return until ALL of the processes have finished.
    */
    ProcPar( MasterPtr, WorkerPtr, NULL );
    
    /*. -- All processes have successfully terminated, lets say so.. */
    printf( "Upper Casing EXAMPLE - ENDS\n" );
    exit( EXIT_SUCCESS ); /* I’m Outta here */
}


  