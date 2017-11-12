#include <VirtualWire.h>

void setup() { Serial.begin(9600);
      vw_setup(2000); 
      vw_set_rx_pin(A0);
      vw_rx_start(); 
      pinMode(13, OUTPUT);
}
void loop() { int Permiresuesi = 0; digitalWrite(13, LOW);
      byte buf[VW_MAX_MESSAGE_LEN]; 
      byte buflen = VW_MAX_MESSAGE_LEN;
      char MesazhiP [100];
      
      if( vw_get_message(buf, &buflen) ) {

            
            for (int i = 1; i < buflen - 1; i++) { Permiresuesi++;
                MesazhiP [i-1] = (char)buf[i]; }
                
                String MesazhiPstring = MesazhiP;
                String MesazhiPermiresuar = MesazhiPstring.substring(-1, Permiresuesi);
                
                Serial.println(MesazhiPermiresuar);
      }
  }
