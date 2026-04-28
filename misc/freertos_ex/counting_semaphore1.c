#include "main.h"
#include "cmsis_os.h"

SemaphoreHandle_t binSemHandle;

void TaskGive(void *argument);
void TaskTake(void *argument);


int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_FREERTOS_Init(); // If using CubeMX auto code

  /* Create binary semaphore */
  binSemHandle = xSemaphoreCreateCounting();
  
  
  
}



