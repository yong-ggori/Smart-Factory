#include <DynamixelWorkbench.h>

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   

#define BAUDRATE  57600

uint8_t dxl_id[4];
uint16_t model_number[sizeof(dxl_id)/sizeof(uint8_t)];
bool result_num[sizeof(dxl_id)/sizeof(uint8_t)];

DynamixelWorkbench dxl_wb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  
  dxl_init();

  
  dxl_wb.goalPosition(dxl_id[0], degree(90));
  delay(1000);
  dxl_wb.goalPosition(dxl_id[1], degree(120));
  delay(1000);
  dxl_wb.goalPosition(dxl_id[2], degree(150));
  delay(1000);
  dxl_wb.goalPosition(dxl_id[3], degree(260));
  delay(2000);
  dxl_wb.goalPosition(dxl_id[0], degree(180));
  delay(1000);
  dxl_wb.goalPosition(dxl_id[1], degree(180));
  delay(1000);
  dxl_wb.goalPosition(dxl_id[2], degree(180));
  delay(1000);
  dxl_wb.goalPosition(dxl_id[3], degree(180));
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
