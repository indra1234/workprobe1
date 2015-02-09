/**
 *  @file      src
 *  @brief     In here RC5 decoder coding is very useful. One remote is used and a rc5 receiver or sensor used and the
               output of the sensor is digital.In here we take this value and decoded as stanrad using by c programming.
               Here one micoconterller used for storage the decoder value and also connected the sensor  with PC through a 
               serial cable or USB cable for better callibrate the decoded value.I have described the coding also in wp1.C 
 *  @author    Indrajit Paul <indra.p21@gmail.com>
 *  @version   1.00, 
 *             programming language "C",
 *             development tool chain "keil "
 *             and "Microelectronika "
 *             and "Code composer studio"
 *  @date      2015-01-31
 *  @copyright Apache License, Version 2.0
 *
 *  
 *
 *  Copyright 1988-2015 Indrajit Paul
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 *  either express or implied.
 *  See the License for the specific language governing permissions
 *  and limitations under  the License. .....*/
#include<reg52.h>
#include "8051.h"
// #include "justmisra.H"
void main (void)
{ 
#ifndef P89V51RD2
    BUZZER=0;
        led1=0;
        led2=0;
        led3=0;
        led4=0;
        led5=0;
 #endif 
        while(1)
        {
                switch(RC5_Read())
                {
                case 32: led1=~led1;Delay(1000);break;
                case 33: led2=~led2;Delay(1000);break;
                case 16: led3=~led3;Delay(1000);break;
                case 17: led4=~led4;Delay(1000);break;
                case 18: led5=~led5;Delay(1000);break;
                }
        }  // Embedded Program never Ends //
}