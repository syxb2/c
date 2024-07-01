#include "FileOperation.h"


HANDLE CreateFile(
    const char *filename, // 文件名
    int access, // 访问模式
    int shareMode, // 共享模式（忽略）
    void *securityAttributes, // 安全属性（忽略）
    int creationDisposition, // 文件创建方式
    int flagsAndAttributes, // 文件属性（忽略）
    HANDLE templateFile // 模板文件句柄（忽略）
) {
    int flags = 0;

    // 解析访问模式
    if (access & O_WRONLY) { // O_WRONLY - 0000000001 - 只写
    // & - 按位与运算符，两个操作数中位都为1，结果才为1，否则结果为0
        flags |= O_WRONLY;
    }
    else if (access & O_RDWR) { // O_RDWR - 0000000010 - 读写
        flags |= O_RDWR;
    }
    else {
        flags |= O_RDONLY; // O_RDONLY - 0000000000 - 只读
    }

    // 解析创建方式
    if (creationDisposition == 1) { // CREATE_NEW - 创建新文件。如果文件已经存在，则操作失败。
        flags |= O_CREAT | O_EXCL; // O_CREAT - 1000000000 - 文件不存在时创建，O_EXCL - 0100000000 - 文件存在时失败
    }
    else if (creationDisposition == 2) { // CREATE_ALWAYS - 无论文件是否存在，都会创建一个新文件。如果文件已经存在，那么它的内容将被清空。
        flags |= O_CREAT | O_TRUNC; // O_TRUNC - 0000100000 - 打开文件并截断到零长度
    }
    else if (creationDisposition == 3) { // OPEN_EXISTING - 打开文件。如果文件不存在，则操作失败。
    // Do nothing
    }
    else if (creationDisposition == 4) { // OPEN_ALWAYS - 打开文件。如果文件不存在，则创建一个新文件。
        flags |= O_CREAT; // `O_CREAT` - 0001000000 - 文件不存在时创建
    }
    else if (creationDisposition == 5) { // TRUNCATE_EXISTING - 打开文件并截断到零长度。如果文件不存在，则操作失败。
        flags |= O_TRUNC; // O_TRUNC - 0000100000 - 打开文件并截断到零长度
    }

    // 打开文件
    HANDLE file = open(filename, flags, 0666);
    if (file == -1) {
        return INVALID_HANDLE_VALUE;
    }

    return file;
}

int ReadFile(
    HANDLE file, // 文件句柄
    void *buffer, // 读取缓冲区
    unsigned int bytesToRead, // 要读取的字节数
    unsigned int *bytesRead,  // 实际读取的字节数
    void *overlapped // 重叠结构（在这个示例中忽略）
) {
    int result = read(file, buffer, bytesToRead);
    if (result == -1) {
        return 0; // 失败
    }

    if (bytesRead) {
        *bytesRead = result;
    }

    return 1; // 成功
}

int WriteFile(
    HANDLE file, // 文件句柄
    const void *buffer, // 写入缓冲区
    unsigned int bytesToWrite, // 要写入的字节数
    unsigned int *bytesWritten, // 实际写入的字节数
    void *overlapped // 重叠结构（在这个示例中忽略）
) {
    int result = write(file, buffer, bytesToWrite);
    if (result == -1) {
        return 0; // 失败
    }

    if (bytesWritten) {
        *bytesWritten = result;
    }

    return 1; // 成功
}

int CloseHandle(HANDLE file) {
    return close(file) == 0 ? 1 : 0;
}
