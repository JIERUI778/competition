#include "stm32f10x.h"
#include "sys.h"
#include "timer.h"
#include "usart.h"
#include "encoder.h"
#include "oled.h"
#include "mpu6050.h"
#include "math.h"
#include "delay.h"


float Pitch,Roll,Yaw;
int main(void)
{

    // Encoder_Init();
    uart_init(9600);
    // // Vofa_Serial_init(9600);
    delay_init();
	
		//MPU6050初始化
		IIC_Init();
		MPU6050_initialize();
		DMP_Init();
		TIM2_Getsample_Int();
	
	
	
	
    // TIM1_PWM_Init(4500, 0); // 10Khz的PWM频率
    // TIM_SetCompare1(TIM1, 1000); // 0%占空比
    // TIM_SetCompare4(TIM1, 4000);
    // int value;

          OLED_Init(); // OLED初始化
       //                 //    OLED_DisplayTurn(1); // 屏幕旋转

     
       // float t;
//       int temp;
       while (1) {

           // t += 0.1;
           // printf("demo:%f,%f,%f,%f\n", sin(t), sin(2 * t), sin(3 * t), sin(4 * t));
           // FireWater_Send('demo', 1, 1, 1, 1);
           // temp=Read_Encoder(4);
           // printf("%d\n",temp);
           // delay_ms(100);
				 
				 
					 printf("pitch:%.2f,Roll:%.2f,Yaw:%.2f\r\n",Pitch,Roll,Yaw);
           delay_ms(1000);
             
					 OLED_ShowSignedNum(1, 0, Pitch*100, 5, 16, 1);
					 OLED_ShowSignedNum(1, 24, Roll*100, 5, 16, 1);
					 OLED_ShowSignedNum(1, 48, Yaw*100, 5, 16, 1);

					 OLED_Refresh();

           // OLED_ShowNum(uint8_t x, uint8_t y, uint32_t Number, uint8_t Length, uint8_t size1, uint8_t mode);

           // OLED_DrawLine(8, 1, 12, 30, 1);
           // OLED_DrawPoint(120, 6, 1);
           //        OLED_DrawCircle(33, 33, 10, 1);
           // OLED_ShowChar(8, 8, 65, 16, 1);
           //        OLED_ShowString(1, 1, "charting", 16, 1);
           // OLED_ShowNum(1, 1, 6888, 4, 16, 0);
           // OLED_ShowChinese(0, 0, 0, 64, 1);  // 中
           // OLED_ShowChinese(0, 0, 1, 32, 1);  // 景
           // OLED_ShowChinese(36, 0, 2, 16, 1); // 园
           // OLED_ShowChinese(54, 0, 3, 16, 1); // 电
           // OLED_ShowChinese(72, 0, 4, 16, 1); // 子
           // OLED_ShowChinese(90, 0, 5, 16, 1); // 技

           // value = (short)Read_Encoder(4);
           // printf("%d\n",value);
           // printf()
           //        OLED_ColorTurn(1);
           // OLED_ShowString(1, 1, "666");
    }
}

