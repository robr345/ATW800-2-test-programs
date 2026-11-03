/*
  -- --------------------------------------------------------------
  -- MODULE: Simple Parallel C example (Multiple Processes).
  --
  -- FILE : master.c
  --
  -- NAME : Richard Onyett (RTC, Santa Clara)
  --
  -- PURPOSE:
  --   To generate a stream of ascii characters on a channel and
  --   pass them to the upper case worker process.
  -- --------------------------------------------------------------
  */
  
  #include <stdio.h>
  #include <stdlib.h>
  #include <channel.h>
  #include <process.h>
  
  /*.  -- Declare a procedure called MASTER */
  void Master( Process *p, Channel *FromWorker, Channel *ToWorker )
  {
    
    int c;
    int Going = 1;
    p = p;              /* Takes care of unused variable warning */
    
    /*. -- Intro */
	printf( "Master C Process STARTING\n" );
	printf( "Enter some text and it will be upper cased\n" );
	printf( "\nTo quit type EOF (CTRL-Z)\n" );
	
	while ( Going ) {
  		c = getchar();           /* Get a character from the stdin */
  		ChanOutInt( ToWorker, c );
  		
  		if ( c == EOF ) {
    		Going = 0;
  		} else {
    		c = ChanInInt( FromWorker );
    		putchar( c );
		} 
	}
	
    /* Pass to the worker */
	/* Get the character back */
  	/* Output to the screen */
    printf( "Master C Process ENDING\n" );  /* Shake the needles from your back */
}


