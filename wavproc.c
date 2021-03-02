//mode1 & mode2 & mode3 & mode4
#include <stdio.h>
#define MODE 1
//#define MODE 2
//#define MODE 3
//#define MODE 4
int main(void) {
     int  ch, sum, SizeOfFile, format; 
     int WAVEformat ,MonoStereo ,SampleRate ,BytesPerSec ,BlockAlign ,BitsPerSample ,SizeOfData, temp,Mask; 
     int ch1,ch2,ch3,ch4,test;
     Mask = 0xFF;
//------------------------------------------------------------------------------------------------------------------------------------------                  
    ch1 = getchar();                      
    ch2 = getchar();      //1 RIFF CHECK
    ch3 = getchar();                                                           
    ch4 = getchar();
	if (MODE == 2 || MODE == 3||MODE == 4){            //if mode is 2 or 3 or 4 then insert the ch (characters of RIFF ) to the new wav file
		putchar(ch1);
		putchar(ch2);
		putchar(ch3);
		putchar(ch4);
	}
	
     if ( ch1 != 'R' || ch2 != 'I'|| ch3 != 'F' || ch4 != 'F' ){     //ch1 is not R ch2 is not I if ch3 is not F and ch4 is not F    
         fprintf (  stderr, "Error! \"RIFF\" not found\n" );          //the it will print Error \"RIFF\" not found                                                             
         return 1; 

	 }   
//---------------------------------------------------------------------------------------------------------------------------------------                                                                           
    ch1 = getchar();                   
    ch2 = getchar();                              //2  SIZE OF FILE 
    ch3 = getchar();
    ch4 = getchar();
	if (MODE == 2 || MODE == 3){
		putchar(ch1);
		putchar(ch2);                                //if mode is 2 or 3 then insert the ch (characters of size of file) to the new wav file
		putchar(ch3);
		putchar(ch4);
	}
      SizeOfFile = ch4 * 256 * 256 * 256 + ch3 * 256 * 256 + ch2 * 256 + ch1;  //LITLE INDIAN  because the wav file is saved in ram in 16 bits and we want to trasfer in demecial number we use the litle endian type 
     if (MODE==4){
        temp = (SizeOfFile /2)+ ((SizeOfFile%100)/2);                      //if mode  is 4  
        fprintf(stderr, "ii%d\n", temp );                                     //transfer ch to the new wive files
        ch1 = temp & Mask;
        putchar(ch1);
        ch2 = (temp >> 8) & Mask;                                   //DEM TO HEX and insert to the new file
        putchar(ch2);
        ch3 = (temp >> 16) & Mask;
        putchar(ch3);
        ch4 = (temp  >> 24) & Mask;
       putchar(ch4);
     }
     
      fprintf ( stderr, "size of file: %d\n", SizeOfFile );             
//---------------------------------------------------------------------------------------------------------------------------------------
    ch1 = getchar();                   
    ch2 = getchar();                             //3 WAVE CHECK
    ch3 = getchar();
    ch4 = getchar();
	if (MODE == 2 || MODE == 3 || MODE == 4){                                // mode is  2 or 3 or 4 insert the new wav file
		putchar(ch1);
		putchar(ch2);
		putchar(ch3);
		putchar(ch4);
	}                                                                      //again we chek evry character if it is the leter of the word WAVE
      if( ch1 != 'W' || ch2 != 'A'|| ch3 != 'V' || ch4 != 'E' ){                    // and if it doesn't much 
           fprintf ( stderr, "Error! \"WAVE\" not found\n" );                       // the programm will print Error WAVE not found
          return 3;
	  }    
//--------------------------------------------------------------------------------------------------------------------------------------   
    ch1 = getchar();                   //4 'fmt ' check
    ch2 = getchar();
    ch3 = getchar();
    ch4 = getchar();  
	if (MODE == 2 || MODE == 3 || MODE == 4){
		putchar(ch1);
		putchar(ch2);                                                                   // mode is  2 or 3 or 4 insert the new wav file
		putchar(ch3);
		putchar(ch4);
	}                                                                               // same think that we cheked for the RIFF and for the WAVE we chek now for the 'FMT '  
      if ( ch1 != 'f' || ch2 != 'm'|| ch3 != 't' || ch4 != ' ' ){
           fprintf ( stderr, "Error! \"fmt\" not found\n" );                     //print again error FMT not found 
             return 4;      
	  }  
//--------------------------------------------------------------------------------------------------------------------------------------
    ch1 = getchar();
    ch2 = getchar();                             //5format chunk chek
    ch3 = getchar();                                          
    ch4 = getchar();
	if (MODE == 2 || MODE == 3 || MODE == 4){
		putchar(ch1);
		putchar(ch2);
		putchar(ch3);
		putchar(ch4);                                             // mode is  2 or 3 or 4 insert the new wav file
	}
      format = ch4 * 256 * 256 * 256 + ch3 * 256 * 256 + ch2 * 256 + ch1; //litle endian again so we can translate from 16 bits in to demetial 
      fprintf ( stderr,"size of format chunck: %d\n", format );
      if ( format != 16 ){                                                //the size of format it can be only 16 bites  
           fprintf ( stderr, "Error! size of format chunck should be 16\n" );     //so evrithink else is an Error
             return 5;
	  }
//---------------------------------------------------------------------------------------------------------------------------------------
      ch1 = getchar();                                            //6 wave type chek
      ch2 = getchar();
	  if (MODE == 2 || MODE == 3 || MODE == 4){
		putchar(ch1);
		putchar(ch2);                                              // mode is  2 or 3 or 4 insert the new wav file       
	} 
      WAVEformat = ch2 * 256 + ch1;                                
      fprintf ( stderr, "WAVE type format: %d\n", WAVEformat );                           
      if ( WAVEformat != 1 ){                                      //the format of wave can be only 1 bite
          fprintf ( stderr, "Error! WAVE type format should be 1 \n" );   //again print ERROR
            return 6;
	  }      
//----------------------------------------------------------------------------------------------------------------------------------
      ch1 = getchar();                                                //7 Mono or stereo check
      ch2 = getchar();
	  if (MODE == 2 || MODE == 3){
		putchar(ch1);                                                          // mode is  2 or 3 or  insert the new wav file 
		putchar(ch2);
	}
      MonoStereo = ch2 * 256 + ch1;
      if ( MonoStereo == 1 ||MonoStereo ==2 ) {                         
      fprintf ( stderr, "mono/stereo: %d\n", MonoStereo);  
      }
      if (MonoStereo == 2 && MODE==4 ) {                    
             temp = MonoStereo / 2;                      //devide by 2 because we donot want stereo we want mono so 1
              ch1 = temp & Mask;
              putchar(ch1);                                        //DEM TO HEX and insert to the new file
              ch2 = (temp >> 8) & Mask;
             putchar(ch2);  
      }
      if ( MonoStereo != 1 && MonoStereo != 2 ){                                         //if Monostereo isn't 1 or 2 
          fprintf ( stderr, "Error! mono/stereo should be 1 or 2 \n" );                    // print ERROR
         return 7;
	  }
//--------------------------------------------------------------------------------------------------------------------------------------
    ch1 = getchar();                      //8 sample rate chek
    ch2 = getchar();                                                   
    ch3 = getchar();
    ch4 = getchar();
      SampleRate = ch4 * 256 * 256 * 256 + ch3 * 256 * 256 + ch2 * 256 + ch1;    //same think  with size of file     
	  fprintf ( stderr, "sample rate: %d\n",  SampleRate ); //print sample rate
    if (MODE == 4){
       putchar(ch1);
		   putchar(ch2);                     //if mode == 4 insert 
		   putchar(ch3);
		   putchar(ch4);
    }
     
	  if (MODE ==2){
        temp = SampleRate /2;
        ch1 = temp & Mask;
        putchar(ch1);                               //if mode == 2 devide sample rate by 2 because we want the new song to play slower      
        ch2 = (temp >> 8) & Mask;
        putchar(ch2);
        ch3 = (temp >> 16) & Mask;
        putchar(ch3);
        ch4 = (temp >> 24) & Mask;
       putchar(ch4);
     }
	 if (MODE == 3){
		temp = SampleRate * 2;
        ch1 = temp & Mask;                                 //if mode == 3 multipli sample rate by 2 because the new song we want to play faster
        putchar(ch1);
        ch2 = (temp >> 8) & Mask;
        putchar(ch2);                                  
        ch3 = (temp >> 16) & Mask;
        putchar(ch3);
        ch4 = (temp >> 24) & Mask;
        putchar(ch4);
	 }
	                   
//------------------------------------------------------------------------------------------------------------------------------------------
    ch1 = getchar();                    //9 bytes per sec chek
    ch2 = getchar();
    ch3 = getchar();
    ch4 = getchar();
      BytesPerSec = ch4 * 256 * 256 * 256 + ch3 * 256 * 256 + ch2 * 256 + ch1;   //same think with size of rate     
       fprintf ( stderr, "bytes/sec: %d\n",  BytesPerSec );       //print of byte/sec
        if (MODE == 2|| MODE == 4){
        temp = BytesPerSec /2;
	      ch1 = temp & Mask;
        putchar(ch1);
        ch2 = (temp >> 8) & Mask;                           //if mode is 2 or 4 we want to devide bytes per sec by 2 so the file size it will
        putchar(ch2);                                        // corect
        ch3 = (temp >> 16) & Mask;
        putchar(ch3);
        ch4 = (temp >> 24) & Mask;
       putchar(ch4);
     }
	     if (MODE == 3){
	     temp = BytesPerSec *2;
	     ch1 = temp & Mask;
        putchar(ch1);
        ch2 = (temp >> 8) & Mask;                       //same think with 2 and 4 but multiplied by 2 for the same reason
        putchar(ch2);
        ch3 = (temp >> 16) & Mask;
        putchar(ch3);
        ch4 = (temp >> 24) & Mask;
       putchar(ch4);
	  }
//----------------------------------------------------------------------------------------------------------------------------------------
      ch1 = getchar();                                                //10 block aligment chek
      ch2 = getchar();
	  if (MODE == 2 || MODE == 3){
		putchar(ch1);                    //if mode is 2 or 3 insert char to the new wav file
		putchar(ch2);
	}
      BlockAlign = ch2 * 256 + ch1;   //same think with size of file
      fprintf ( stderr, "block alignment: %d\n", BlockAlign );
        if (MODE == 4){
          temp = BlockAlign/2;
          ch1 = temp & Mask;                              
          putchar(ch1);
          ch2 = (temp >> 8) & Mask;
          putchar(ch2);
        }
            
      if ( BytesPerSec != SampleRate * BlockAlign ){      //if BytePersec != sampleRate * BlockAlign           
           fprintf ( stderr, "Error! bytes/second should be sample rate x block alignment\n" ); //then  print Error
            return 10;
	  }
//----------------------------------------------------------------------------------------------------------------------------------------
       ch1 = getchar();                                                //11 bits per sample chek
       ch2 = getchar();
	   if (MODE == 2 || MODE == 3 || MODE == 4){
		putchar(ch1);
		putchar(ch2);
	}
       BitsPerSample = ch2 * 256 + ch1; // same think with size of file
       fprintf ( stderr, "bits/sample: %d\n",  BitsPerSample );
       if (  BitsPerSample !=8 &&  BitsPerSample !=16 ){           //bitsPerSample !=8 and !=16
           fprintf ( stderr, "Error! bits/sample should be 8 or 16\n" );                    //prin Error
            return 11;
	   }
       if ( BlockAlign !=BitsPerSample / 8*MonoStereo ){              
            fprintf ( stderr, "Error! block alignment should be bits per sample / 8 x mono/stereo\n" );
           return 11;
	   }
//------------------------------------------------------------------------------------------------------------------------------------------  
    ch1 = getchar();                 //12 data chek 
    ch2 = getchar();
    ch3 = getchar();
    ch4 = getchar();      //same think with wave & RIFF & FMT        
    if (MODE == 2 || MODE == 3 || MODE == 4){
		putchar(ch1);
		putchar(ch2);
		putchar(ch3);
		putchar(ch4);
	}
	  if ( ch1 != 'd' || ch2 != 'a'|| ch3 != 't' || ch4 != 'a' ){
            fprintf ( stderr, "Error! \"data\" not found\n" );
          return 12;
	  }  
//---------------------------------------------------------------------------------------------------------------------------------------------      
    ch1 = getchar();                   
    ch2 = getchar();                   //13 size of data chek
    ch3 = getchar();
    ch4 = getchar();
	if (MODE == 2 || MODE == 3){
		putchar(ch1);
		putchar(ch2);
		putchar(ch3);
		putchar(ch4);
	}
      SizeOfData = ch4 * 256 * 256 * 256 + ch3 * 256 * 256 + ch2 * 256 + ch1;
      fprintf ( stderr, "size of data chunk: %d\n", SizeOfData );
        if (MODE == 4){
          temp = SizeOfData/2;
          ch1 = temp & Mask;
          putchar(ch1);
          ch2 = (temp >> 8) & Mask;
          putchar(ch2);
          ch3 = (temp >> 16) & Mask;
          putchar(ch3);
          ch4 = (temp >> 24) & Mask;
          putchar(ch4);
        }
        
//----------------------------------------------------------------------------------------------------------------------------------------------    
      ch = getchar();                                //14 & 15 chek for bad file size & insufficient data
      sum = 0;                                    
      while (ch != EOF ){
		  if (MODE == 2|| MODE==3 || MODE == 4 ){
			  putchar(ch);
		  }
           sum++;                                    
           ch = getchar();
      }
      if ( sum <  SizeOfData  ){                            
           fprintf ( stderr, "Error! insufficient data\n" ) ;
           return 14;
	  }
      else if (sum >  SizeOfData ){                                      
            if ( SizeOfFile  != 36 +  SizeOfData  + (sum -  SizeOfData  ) ){   
                  fprintf ( stderr, "Error! bad file size\n");
                  return 15;
			}
      }
return 0;
}
