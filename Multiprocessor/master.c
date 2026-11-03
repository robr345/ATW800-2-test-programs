/*
  -- --------------------------------------------------------------
  -- MODULE: Simple Parallel C example (Multiple Processors). 
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
  #include <misc.h>
  
  int main( void )
  {
  	Channel *ToWorker;
    Channel *FromWorker;
    int c;
    int Going = 1;
    
    /*  -- Access the external configuration channels.  */
    FromWorker = (Channel *)get_param( 3 );
    ToWorker   = (Channel *)get_param( 4 );

	/*  - Intro */
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
    printf( "Master C Process ENDING\n" );  /* Shake the needles */
    exit_terminate( EXIT_SUCCESS );            /* from your back */
}


  
  