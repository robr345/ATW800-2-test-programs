/*
  -- --------------------------------------------------------------
  -- MODULE: Simple Parallel C example.
  --
  -- FILE : worker.c
  --
  -- NAME : Richard Onyett (RTC, Santa Clara)
  --
  -- PURPOSE:
  --   To receive a stream of ascii characters on a channel and
  --   convert them to upper case, whether they want to be or not!!
  -- --------------------------------------------------------------
  */
  
#include <stdiored.h>
#include <ctype.h>
#include <channel.h>
#include <misc.h>

int main( void )
{
	int key;
  	int Going = 1;
  	
  	Channel *FromMaster;
  	Channel *ToMaster;
  	
  	FromMaster = (Channel *)get_param( 1 );
    ToMaster   = (Channel *)get_param( 2 );
    
    while ( Going ) {
    	key = ChanInInt( FromMaster );/* Get a key from the master */
      	if ( key == EOF ) {
        	Going = 0;
      	} else {
        	ChanOutInt( ToMaster , toupper( key ));  /* Pass it back */
		}
	}
}

