#include <I2Cdev.h>
#include <MPU6050.h>
#include <VirtualWire.h>
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include <Wire.h>
#endif
#define OUTPUT_READABLE_ACCELGYRO

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

char* MesazhiD;
int i=0;

void setup() { Serial.begin(9600); 
      
    vw_set_tx_pin(A0);
    vw_setup(2000); 
     
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    accelgyro.initialize();
}

void loop() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    if (ay < 3000) { MesazhiD = ("NNgrituu");   }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));
    if (ay > 3000) { MesazhiD = ("UUluu");      }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));
    if (ay < -10000) { MesazhiD = ("PParaa");     }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));
    if (ay > -3000 && ay < 3000) { MesazhiD = ("NNdaluu");    }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));
    if (ax < -6000) { MesazhiD = ("MMajtass");   }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));
    if (ax > -6000 && ax < 6000 ) { MesazhiD = ("DDrejtt");    }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));
    if (ax >  6000) { MesazhiD = ("DDjathtass"); }
    vw_send((byte *)MesazhiD, strlen(MesazhiD));

}

