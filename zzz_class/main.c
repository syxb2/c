#include "FileOperation.h"


int main(int argc, char **argv) {
    const char *data = argv[1];
    if (data == NULL) {
        printf("Usage: %s <data>\n", argv[0]);
        return 0;
    }

    // 打开或创建文件
    HANDLE file = CreateFile("test.txt", O_RDWR, 0, NULL, 4, 0, 0);

    if (file == INVALID_HANDLE_VALUE) { // 如果文件句柄无效，也就是文件打开失败
        perror("Failed to open or create file");
        return 0;
    }

    // 写入数据
    unsigned int bytesWritten;
    int GetLastError;

    GetLastError = WriteFile(file, data, strlen(data), &bytesWritten, NULL);
    if (GetLastError == 0) { // 如果写入失败
        perror("Failed to write to file");
        CloseHandle(file);
        return 0;
    }

    printf("Wrote %u bytes to the file.\n", bytesWritten);

    lseek(file, 0, SEEK_SET); /* 重新定位文件指针到开头 */

    // 读取数据
    char buffer[256];
    unsigned int bytesRead;

    GetLastError = ReadFile(file, buffer, sizeof(buffer) - 1, &bytesRead, NULL);

    if (GetLastError == 0) { // 如果读取失败
        perror("Failed to read from file");
        CloseHandle(file);
        return 0;
    }

    printf("Read %u bytes from the file: %s\n", bytesRead, buffer);

    // 关闭文件
    GetLastError = CloseHandle(file);

    if (GetLastError == 0) { // 如果关闭失败
        perror("Failed to close file");
        return 0;
    }

    return 0;
}
