#ifndef __CONFIG_H__
#define __CONFIG_H__

// =================== 仿真功能配置面板 =================== //

// =================== 大小限制配置 =================== //
// Trace 环形缓冲区：最多保留最近 N 行，每行最大 M 字节
// 超过行数时自动丢弃最旧的记录，程序结束时一次性写入文件
#define CONFIG_TRACE_BUF_LINES  4096   // 环形缓冲区行数上限
#define CONFIG_TRACE_LINE_LEN   256    // 每行最大字节数（含 '\0'）

// 波形文件：超过指定字节数时截断并重新开始记录
// 旧波形数据将被丢弃，保留最新的波形
#define CONFIG_WAVE_MAX_BYTES        (32 * 1024 * 1024)  // 32 MB
#define CONFIG_WAVE_CHECK_INTERVAL  4096                 // 每 4096 个半周期检查一次

/*************  WAVE *************/ 
// #define CONFIG_WAVE

/************* SDB ***************/ 
 #define CONFIG_SDB

/************ DIFFTEST ***********/ 
// #define CONFIG_DIFFTEST

/************ ITRACE *************/ 
 #define CONFIG_ITRACE   

/************ MTRACE *************/ 
 #define CONFIG_MTRACE

/************ DTRACE *************/ 
//#define CONFIG_DTRACE

/************ ETRACE *************/ 
// #define CONFIG_ETRACE

/************ FTRACE *************/ 
 #define CONFIG_FTRACE

/************ DEVICE *************/ 
 #define CONFIG_DEVICE    

#endif