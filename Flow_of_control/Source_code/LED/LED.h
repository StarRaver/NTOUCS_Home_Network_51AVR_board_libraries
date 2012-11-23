/* LED.h
程式名稱 | Program name
	8 位元 LED 控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	8 位元 LED 控制函式庫 is part of NTOU_W78E58B_libraries
	NTOU_W78E58B_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOU_W78E58B_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOU_W78E58B_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef LED_H_INCLUDED
	#define LED_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
		#include <reg51.h>
	/*||||| 常數與巨集 | Constants & Macros |||||*/
		/* port definitions */
			#define LED P1
				/* LED is connected from P1 */
		/* LED position definitions */
			#define LED_HIGHEST 0x80
			#define LED_LOWEST 0x1
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		void ledDisplayValue(unsigned char value);
			/* 顯示數值至 LED
				 　value
				 　　要顯示的 8 位元數值，LOGIC_HIGH 代表發光 */
			
		/* 輪轉(rotate)相關函式 */
			#define LED_ROTATE_UP 1
				/* 往高位數輪轉 */
			#define LED_ROTATE_DOWN 0
				/* 往低位數輪轉 */
			void ledRotateOneWay(
				/* 讓 LED 從一邊亮到另外一邊 */
				unsigned char initial_position
					/* 初始位置 */, 
				bit direction
					/* 輪動方向 */, 
				void (*delay)(unsigned)
					/* 用來當作輪動周期的時間延遲函式 */, 
				unsigned interval
					/* 輪動週期（從一個 LED 跳到下一個 LED 的時間） */);
			void ledRotateTwoWay(
				/* 讓 LED 從一邊亮到另外一邊...再亮回來 */
				bit initial_direction
					/* 第一次輪轉的轉動方向 */, 
				void (*delay)(unsigned)
					/* 用來當作輪動周期的時間延遲函式 */, 
				unsigned interval
					/* 輪動週期（從一個 LED 跳到下一個 LED 的時間） */);
				
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* LED_H_INCLUDED */