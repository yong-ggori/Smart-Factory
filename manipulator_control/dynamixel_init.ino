void dxl_init() {
  const char *log;
  bool result = false;

  for(int idx = 0; idx < sizeof(dxl_id)/sizeof(uint8_t); idx++)
    dxl_id[idx] = idx+1;

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);

  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to init");
  }
  else
  {
    Serial.print("Succeeded to init : ");
    Serial.println(BAUDRATE);  
  }

  //dxl ping 설정
  for(int idx = 0; idx < sizeof(dxl_id)/sizeof(uint8_t); idx++)
    result_num[idx] = dxl_wb.ping(dxl_id[idx], model_number+idx, &log);
    
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to ping");
  }

  //dxl jointMode 설정
  for(int idx = 0; idx < sizeof(dxl_id)/sizeof(uint8_t); idx++)
    result_num[idx] = dxl_wb.jointMode(dxl_id[idx], 0, 0, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to change joint mode");
  }
  else
  {
    Serial.println("Succeed to change joint mode");
    Serial.println("Dynamixel is moving...");
  }
}
