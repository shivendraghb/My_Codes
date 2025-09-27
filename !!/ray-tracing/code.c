#include <stdio.h>
#include <stdlib.h>  // For system()
#include <math.h>
#ifdef _WIN32
    #include <windows.h>  // For Sleep() and keyboard input
    #include <conio.h>    // For _kbhit() and _getch() on Windows
#else
    #include <time.h>     // For nanosleep() on Linux/macOS
    #include <termios.h>  // For manual key handling
    #include <fcntl.h>
    #include <unistd.h>   // For usleep()
#endif

#define WIDTH 40
#define HEIGHT 20
#define SPHERE_RADIUS 5.0
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

// Sphere Position
float sphereX = 0.0f, sphereY = 0.0f;

// Ray-Sphere Intersection
int intersect(float ox, float oy, float radius) {
    float dist = sqrt((ox - sphereX) * (ox - sphereX) + (oy - sphereY) * (oy - sphereY));
    return dist <= radius;
}

// Render Frame
void render() {
    #ifdef _WIN32
        system("cls"); // Clear Console for Windows
    #else
        system("clear"); // Clear Console for Linux/macOS
    #endif

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float rayX = (float)x - WIDTH / 2;
            float rayY = (float)y - HEIGHT / 2;

            if (intersect(rayX, rayY, SPHERE_RADIUS)) {
                printf("@"); // Sphere Pixel
            } else {
                printf("."); // Background Pixel
            }
        }
        printf("\n");
    }
}

// Check for key press (Linux/macOS support)
#ifndef _WIN32
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}
#endif

// Control Sphere Movement
void moveSphere() {
    char key;
    #ifdef _WIN32
        if (_kbhit()) { // Windows key detection
            key = _getch();
    #else
        if (kbhit()) { // Linux/macOS key detection
            key = getchar();
    #endif
        switch (key) {
            case KEY_UP:    sphereY -= 1.0f; break;
            case KEY_DOWN:  sphereY += 1.0f; break;
            case KEY_LEFT:  sphereX -= 1.0f; break;
            case KEY_RIGHT: sphereX += 1.0f; break;
        }
    }
}

int main() {
    printf("Move the sphere using WASD keys. Press Ctrl + C to quit.\n");
    while (1) {
        render();
        moveSphere();
        #ifdef _WIN32
            Sleep(50); // Windows delay
        #else
            usleep(50000); // 50 ms delay for Linux/macOS
        #endif
    }
    return 0;
}
