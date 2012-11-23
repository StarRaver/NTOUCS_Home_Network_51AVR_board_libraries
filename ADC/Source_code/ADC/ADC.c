/* 
ADC.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	#include <reg51.h>
		/* for port aliases */
	#include "ADC.h"
		/* for ADC signal alias */
	#include "../Project_configurations/Common_definitions.h"
		/* for LOGIC signal definitions */
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
	
/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
unsigned char adcGetValue(
	/* 獲取 ADC 的數值 */
	void){
	unsigned char recieve;
		
	adc_read_bar_cs_bar = LOGIC_LOW;
	recieve = ADC_SOURCE;
	adc_read_bar_cs_bar = LOGIC_HIGH;
		
	return recieve;
}