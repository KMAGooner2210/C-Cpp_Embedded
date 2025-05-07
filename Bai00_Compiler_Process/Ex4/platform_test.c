#include <stdio.h>

#if defined(_WIN32)
#define PLATFORM_NAME "Windows"
#elif defined(__linux__)
#define PLATFORM_NAME "Linux"
#elif defined(__APPLE__)
#define PLATFORM_NAME "macOS"
#else
#define PLATFORM_NAME "Unknown"
#endif

int main() {
    printf("Platform: %s\n", PLATFORM_NAME);
    return 0;
}