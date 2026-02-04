
#include <SPI.h>
#include <mcp_can.h>

#define CAN_CS 5
#define CAN_INT 4

MCP_CAN CAN0(CAN_CS);

QueueHandle_t voltageQueue;
QueueHandle_t tempQueue;

void canRxTask(void *pvParameters)
{
  long unsigned int rxId;
  unsigned char len;
  unsigned char buf[8];

  while (1)
  {
    if (!digitalRead(CAN_INT))
    {
      CAN0.readMsgBuf(&rxId, &len, buf);

      if (rxId == 0x200)
      {
        int volt = (buf[0] << 8) | buf[1];
        xQueueSend(voltageQueue, &volt, 0);
      }
      else if (rxId == 0x100)
      {
        int temp = (buf[0] << 8) | buf[1];
        xQueueSend(tempQueue, &temp, 0);
      }
    }
    vTaskDelay(5 / portTICK_PERIOD_MS);
  }
}
void voltageTask(void *pvParameters)
{
  int volt;
  while (1)
  {
    if (xQueueReceive(voltageQueue, &volt, portMAX_DELAY))
    {
      Serial.print("Voltage Task -> ");
      Serial.println(volt / 100.0);
    }
  }
}
void tempTask(void *pvParameters)
{
  int temp;
  while (1)
  {
    if (xQueueReceive(tempQueue, &temp, portMAX_DELAY))
    {
      Serial.print("Temperature Task -> ");
      Serial.println(temp);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("MCP2515 Initialized...");
  SPI.begin();

  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) {  //MCP2515 works on 16MHZ
    Serial.println("MCP2515 Init OK");
  } else {
    Serial.println("MCP2515 Init Fail");
    //while (1);
  }

  // Set Normal Mode
  CAN0.setMode(MCP_NORMAL);

  Serial.println("Normal Mode Enabled");

  //pinMode(CAN_INT,INPUT);
  voltageQueue = xQueueCreate(5, sizeof(int));
  tempQueue    = xQueueCreate(5, sizeof(int));

  if (voltageQueue == NULL || tempQueue == NULL)
  {
    Serial.println("Queue creation failed!");
    while (1);
  }
  
  xTaskCreate(canRxTask,"Canrxtask",2048,NULL,2,NULL);
  xTaskCreate(tempTask,"temp_uno",1024,NULL,1,NULL);
  xTaskCreate(voltageTask,"volt_nano",1024,NULL,1,NULL);

}

void loop() {

  
}

// //receiver node
// #include <SPI.h>
// #include <mcp_can.h>

// #define CAN_CS 5      // Chip Select pin for MCP2515
// #define CAN_INT 4     // Interrupt pin from MCP2515 to ESP32

// MCP_CAN CAN0(CAN_CS);

// void setup() {
//   Serial.begin(115200);
//   SPI.begin();
//   // Initialize MCP2515 at 500 Kbps
//   while (CAN_OK != CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ)) {
//     Serial.println("CAN BUS init Failed");
//     delay(100);
//   }
//   Serial.println("CAN BUS init OK!");
//   CAN0.setMode(MCP_NORMAL); // Set to normal mode to receive data
// }

// void loop() {
//   unsigned char len = 0;
//   unsigned char buf[8];
//   unsigned long canId = 0;

//   if (CAN_MSGAVAIL == CAN0.checkReceive()) { // Check if data is received
    
//     CAN0.readMsgBuf(&canId,&len,buf);              // Read data

//     Serial.print("Received ID: 0x");
//     Serial.println(canId, HEX);

//     if (canId == 0x100) { // Temperature data
//       int temp = (buf[0] << 8) | buf[1];
//       Serial.print("Temperature: ");
//       Serial.print(temp);
//       Serial.println(" °C");
//     } 
//     else if (canId == 0x200) { // Voltage data
//       int voltage = (buf[0] << 8) | buf[1];
//       Serial.print("Voltage: ");
//       Serial.print(voltage / 100.0);
//       Serial.println(" V");
//     }
//   }
// }
