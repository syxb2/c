#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


// 定义 Windows 风格的文件句柄
#define INVALID_HANDLE_VALUE -1
typedef int     HANDLE;


/**
 * @brief Create a File object
 * 
 * @param filename 
 * @param access 
 * @param shareMode 
 * @param securityAttributes 
 * @param creationDisposition 
 * @param flagsAndAttributes 
 * @param templateFile 
 * @return HANDLE 
 */
extern HANDLE CreateFile(
    const char *filename, // 文件名
    int access, // 访问模式
    int shareMode, // 共享模式（忽略）
    void *securityAttributes, // 安全属性（忽略）
    int creationDisposition, // 文件创建方式
    int flagsAndAttributes, // 文件属性（忽略）
    HANDLE templateFile // 模板文件句柄（忽略）
);

/**
 * @brief read file
 * 
 * @param file 
 * @param buffer 
 * @param bytesToRead 
 * @param bytesRead 
 * @param overlapped 
 * @return int 
 */
extern int ReadFile(
    HANDLE file, // 文件句柄
    void *buffer, // 读取缓冲区
    unsigned int bytesToRead, // 要读取的字节数
    unsigned int *bytesRead,  // 实际读取的字节数
    void *overlapped // 重叠结构（在这个示例中忽略）
);

/**
 * @brief write file
 * 
 * @param file 
 * @param buffer 
 * @param bytesToWrite 
 * @param bytesWritten 
 * @param overlapped 
 * @return int 
 */
extern int WriteFile(
    HANDLE file, // 文件句柄
    const void *buffer, // 写入缓冲区
    unsigned int bytesToWrite, // 要写入的字节数
    unsigned int *bytesWritten, // 实际写入的字节数
    void *overlapped // 重叠结构（在这个示例中忽略）
);

/**
 * @brief close file
 * 
 * @param file 
 * @return int 
 */
extern int CloseHandle(HANDLE file);
