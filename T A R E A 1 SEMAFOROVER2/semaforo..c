#include <16F877a.h>
#device ADC = 10
#use delay(crystal = 20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP, HS

//Directiva para utilizar puerto USART
#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)
#use STANDARD_IO(B)
#use STANDARD_IO(C)


#define BOTONC PIN_C0



void main()
{
 
   
  while(1)              //bucle infinito
   {
      
               
              //Encender el led verde por 5 segundos y apagarlo.
               output_high(pin_b0);        
               int cont_verde = 0;         //variable contador verde
               do{
                  if(input(pin_c0)) break; //rompe el ciclo cuando el boton se presiona
                  delay_ms(1000);
                  cont_verde++;
               }while(cont_verde < 5);             
               output_low(pin_b0);
               
               
               //Encender y apagar el led amarillo 4 veces a lo largo de 3 segundos.
               int cont_amarillo = 0;       //variable contador amarrillo
               do {
                  output_high(pin_b1);
                  delay_ms(350);
                  output_low(pin_b1);
                  delay_ms(350);
                  cont_amarillo++;
               } while(cont_amarillo < 4);
               
               
               //Encender el led rojo por 8 segundos y apagarlo.
               output_high(pin_b2);
               int cont_rojo = 0;            //variable contador rojo
               do{
                  if(input(pin_c0)){         //reinicia el contador de segundos
                     cont_rojo = 0;
                  }
                  delay_ms(1000);
                  cont_rojo++;
               }while(cont_rojo < 8);
               output_low(pin_b2);
      
     
   }




}
