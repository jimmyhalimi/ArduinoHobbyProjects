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

char Ax[7];
char Ay[7];
char Az[7];
String MesazhiX;
String MesazhiY;
String MesazhiZ;
char* MesazhiD;

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

    MesazhiD = "KKoordinatat";
    vw_send((byte *)MesazhiD, strlen(MesazhiD));    
    
    MesazhiX=String(ax); MesazhiX.toCharArray(Ax,10);
    vw_send((byte *)Ax, strlen(Ax));
    
    MesazhiY=String(ay); MesazhiZ.toCharArray(Ay,10);
    vw_send((byte *)Ay, strlen(Ay));
    
    MesazhiZ=String(az); MesazhiY.toCharArray(Az,10);
    vw_send((byte *)Az, strlen(Az));
    
}

