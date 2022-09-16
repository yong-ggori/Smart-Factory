#include <DynamixelWorkbench.h>
#include <string.h>

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   

#define BAUDRATE  57600
#define CONVEYOR  8
#define GRAP  3

uint8_t dxl_id[4];
uint16_t model_number[sizeof(dxl_id)/sizeof(uint8_t)];
bool result_num[sizeof(dxl_id)/sizeof(uint8_t)];

DynamixelWorkbench dxl_wb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial1.begin(9600);
  pinMode(CONVEYOR, OUTPUT);
  
  dxl_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  String mode = Serial1.readString();

  digitalWrite(CONVEYOR, HIGH);
  
  dxl_degree_set(mode);
}
