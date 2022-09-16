void dxl_degree_set(String mode) {
  if(mode == "init")
  {  
    dxl_wb.goalPosition(dxl_id[1], degree(180));
    delay(100);
    dxl_wb.goalPosition(dxl_id[0], degree(90));
    delay(100);
    dxl_wb.goalPosition(dxl_id[2], degree(100));
    delay(100);
    dxl_wb.goalPosition(dxl_id[3], degree(210));
    delay(100);
  }
  else if(mode.equals("Blue\n"))
  {
    // 집게부 벌림
    for(uint8_t i = 110; i < 170; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    delay(300);
    dxl_degree_set(dxl_pos_init);
  
    delay(500);
  
    digitalWrite(CONVEYOR, LOW);
    
    dxl_wb.goalPosition(dxl_id[0], degree(90));
    for(int deg = 180; deg > 157; deg--)
    {
      dxl_wb.goalPosition(dxl_id[1], degree(deg));
      delay(5);
    }
    for(int deg = 210; deg <= 237; deg++)
    {
      dxl_wb.goalPosition(dxl_id[3], degree(deg));
      delay(5);
    }
    dxl_wb.goalPosition(dxl_id[2], degree(100));
  
    // 집게부 오므림
    for(uint8_t i = 200; i < 250; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    delay(300);
    dxl_wb.goalPosition(dxl_id[1], degree(183));
    for(int deg = 100; deg < 120; deg++)
    {
      dxl_wb.goalPosition(dxl_id[2], degree(deg));
      delay(5);
    }
    for(int deg = 90; deg > 0; deg--){
      dxl_wb.goalPosition(dxl_id[0], degree(deg));
      delay(10);
    }
    for(int deg = 230; deg < 260; deg++)
    {
      dxl_wb.goalPosition(dxl_id[3], degree(deg));
      delay(5);
    }
    for(int deg = 120; deg > 100; deg--)
    {
      dxl_wb.goalPosition(dxl_id[2], degree(deg));
      delay(5);
    }
    // 집게부 벌림
    for(uint8_t i = 110; i < 170; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    for(int deg = 100; deg < 135; deg++)
    {
      dxl_wb.goalPosition(dxl_id[2], degree(deg));
      delay(5);
    }
    delay(300);
    
    dxl_degree_set(dxl_pos_init);
  }
  else if(mode.equals("Red\n"))
  {
    // 집게부 벌림
    for(uint8_t i = 110; i < 170; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    delay(300);
    dxl_degree_set(dxl_pos_init);
  
    delay(500);
  
    digitalWrite(CONVEYOR, LOW);
    
    dxl_wb.goalPosition(dxl_id[0], degree(90));
    for(int deg = 180; deg > 157; deg--)
    {
      dxl_wb.goalPosition(dxl_id[1], degree(deg));
      delay(5);
    }
    for(int deg = 210; deg <= 237; deg++)
    {
      dxl_wb.goalPosition(dxl_id[3], degree(deg));
      delay(5);
    }
    dxl_wb.goalPosition(dxl_id[2], degree(100));
  
    // 집게부 오므림
    for(uint8_t i = 200; i < 250; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    delay(300);
    dxl_wb.goalPosition(dxl_id[1], degree(183));
    for(int deg = 100; deg < 130; deg++)
    {
      dxl_wb.goalPosition(dxl_id[2], degree(deg));
      delay(5);
    }
    for(int deg = 90; deg > 45; deg--){
      dxl_wb.goalPosition(dxl_id[0], degree(deg));
      delay(10);
    }
    for(int deg = 230; deg < 240; deg++)
    {
      dxl_wb.goalPosition(dxl_id[3], degree(deg));
      delay(5);
    }
    for(int deg = 183; deg > 160; deg--)
    {
      dxl_wb.goalPosition(dxl_id[1], degree(deg));
      delay(5);
    }
    for(int deg = 120; deg > 110; deg--)
    {
      dxl_wb.goalPosition(dxl_id[2], degree(deg));
      delay(5);
    }
    // 집게부 벌림
    for(uint8_t i = 110; i < 170; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    for(int deg = 160; deg < 182; deg++)
    {
      dxl_wb.goalPosition(dxl_id[1], degree(deg));
      delay(5);
    }
    for(int deg = 100; deg > 120; deg++)
    {
      dxl_wb.goalPosition(dxl_id[2], degree(deg));
      delay(5);
    }
    delay(300);
    
    dxl_degree_set(dxl_pos_init);
  }
  else
  {
    for(uint8_t i = 110; i < 170; i++)
    {
      analogWrite(GRAP, i);
      delay(10);
    }
    delay(300);
    dxl_degree_set(dxl_pos_init);
  
    delay(500);
  
    digitalWrite(CONVEYOR, LOW);
    delay(800);
  }
}
