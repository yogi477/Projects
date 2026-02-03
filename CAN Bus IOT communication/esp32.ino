
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
      Serial.print("[Voltage Task] ");
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
      Serial.print("[Temp Task] ");
      Serial.println(temp);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("MCP2515 Initialized...");
  SPI.begin();

  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) {
    Serial.println("MCP2515 Init OK");
  } else {
    Serial.println("MCP2515 Init Fail");
    //while (1);
  }

  // Set Normal Mode
  CAN0.setMode(MCP_NORMAL);

  Serial.println("Normal Mode Enabled");

  pinMode(CAN_INT,INPUT);
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


