/**
  ******************************************************************************
  * @file    stm32f4xx.h
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for STM32F4xx devices.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The device used in the target application
  *              - To use or not the peripheral?s drivers in application code(i.e.
  *                code will be based on direct access to peripheral?s registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_STDPERIPH_DRIVER"
  *              - To change few application-specific parameters such as the HSE
  *                crystal frequency
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral?s registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f4xx
  * @{
  */

#ifndef __STM32F4xx_H
#define __STM32F4xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/* Uncomment the line below according to the target STM32 device used in your
   application
  */

#if !defined (STM32F40_41xxx) && !defined (STM32F427_437xx) && !defined (STM32F429_439xx) && !defined (STM32F401xx) && !defined (STM32F411xE)
 /*#define STM32F446xx */
#endif

#if !defined  (USE_STDPERIPH_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
  /*#define USE_STDPERIPH_DRIVER */
#endif /* USE_STDPERIPH_DRIVER */

/**
 * @brief In the following line adjust the value of External High Speed oscillator (HSE)
   used in your application

   Tip: To avoid modifying this file each time you need to use different HSE, you
        can define the HSE value in your toolchain compiler preprocessor.
  */

#if !defined  (HSE_VALUE)
  #define HSE_VALUE    ((uint32_t)24000000) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup
   Timeout value
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
  #define HSE_STARTUP_TIMEOUT    ((uint16_t)0x8000)   /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/**
 * @brief STM32F4XX Standard Peripherals Library version number V1.4.0
   */
#define __STM32F4XX_STDPERIPH_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __STM32F4XX_STDPERIPH_VERSION_SUB1   (0x04) /*!< [23:16] sub1 version */
#define __STM32F4XX_STDPERIPH_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __STM32F4XX_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32F4XX_STDPERIPH_VERSION        ((__STM32F4XX_STDPERIPH_VERSION_MAIN << 24)\
                                             |(__STM32F4XX_STDPERIPH_VERSION_SUB1 << 16)\
                                             |(__STM32F4XX_STDPERIPH_VERSION_SUB2 << 8)\
                                             |(__STM32F4XX_STDPERIPH_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
 */
#define __CM4_REV                 0x0001  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1       /*!< STM32F4XX provides an MPU                     */
#define __NVIC_PRIO_BITS          4       /*!< STM32F4XX uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1       /*!< FPU present                                   */

/** @addtogroup Device_Included
  * @{
  */

#if defined(STM32F405xx)
  #include "stm32f405xx.h"
#elif defined(STM32F415xx)
  #include "stm32f415xx.h"
#elif defined(STM32F407xx)
  #include "stm32f407xx.h"
#elif defined(STM32F417xx)
  #include "stm32f417xx.h"
#elif defined(STM32F427xx)
  #include "stm32f427xx.h"
#elif defined(STM32F437xx)
  #include "stm32f437xx.h"
#elif defined(STM32F429xx)
  #include "stm32f429xx.h"
#elif defined(STM32F439xx)
  #include "stm32f439xx.h"
#elif defined(STM32F401xC)
  #include "stm32f401xc.h"
#elif defined(STM32F401xE)
  #include "stm32f401xe.h"
#elif defined(STM32F411xE)
  #include "stm32f411xe.h"
#elif defined(STM32F446xx)
  #include "stm32f446xx.h"
#else
 #error "Please select first the target STM32F4xx device used in your application (stm32f4xx.h)"
#endif

/** @addtogroup Exported_types
  * @{
  */

typedef enum {
	RESET = 0,
	SET = !RESET
} FlagStatus, ITStatus;

typedef enum {
	DISABLE = 0,
	ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {
	SUCCESS = 0,
	ERROR,
	BUSY,
	TIMEOUT
} ErrorStatus;

/** @addtogroup Exported_macro
  * @{
  */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

#ifdef USE_STDPERIPH_DRIVER
#include "stm32f4xx_conf.h"
#endif /* USE_STDPERIPH_DRIVER */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32F4xx_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
