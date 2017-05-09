#include <main.h>
#define preload 65458
int Intcount;
int duty;
short direction = 0;
#INT_TIMER1
void  TIMER1_isr(void) 
{
   set_timer1(preload); 
   if (Intcount < 255) 
    { 
      if (Intcount == duty) 
       { 
         output_low(LED);
         output_low(LED2);
       }    
    } 
    else if(Intcount == 255) 
    { 
      Intcount = 0; 
      output_high(LED);  
      output_high(LED2);
    }    
    if (Intcount % 255 == 0 && direction == 0)
    {
      duty++;
    }
    if (Intcount % 255 == 0 && direction == 1)
    {
      duty--;
    }
    if (duty == 255)
      direction = ~direction;
    else if (duty == 1)
      direction = ~direction;
    Intcount++; 
}

void main()
{
   //setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);      //65.5 ms overflow

   //enable_interrupts(INT_TIMER1);
   //enable_interrupts(GLOBAL);
   int iii = 0;
   int jjj = 0;
   duty = 2; 
   Intcount = 0; 
   while(TRUE)
   {
      for (iii = 5; iii < 255; iii++){
         for(jjj = 5; jjj < 255;){
            if (jjj <= iii){
               output_high(LED);
               output_high(LED2);
            }
            else{
               output_low(LED);
               output_low(LED2);
            }
            jjj += 2;
         }
         delay_us(100);
      }
      for (iii = 5; iii < 255; iii++){
         for(jjj = 5; jjj < 255; jjj++){
            if (jjj <= iii){
               output_low(LED);
               output_low(LED2);
            }
            else{
               output_high(LED);
               output_high(LED2);
            }
         }
         delay_us(200);
      }
   }

}
