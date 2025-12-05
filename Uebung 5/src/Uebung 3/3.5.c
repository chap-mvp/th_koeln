#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CNT_HEIGHT 10
#define CNT_WIDTH 20
#define PRIMARY_COLORS 3

// yellow when intensity over 220 out of 255

float checkYellow(float arrayImage[CNT_HEIGHT][CNT_WIDTH][PRIMARY_COLORS])
{
    float pixels = CNT_WIDTH * CNT_HEIGHT * PRIMARY_COLORS;
    float yellowPixelCount = 0;
    for (int i = 0; i < CNT_HEIGHT; i++)
    {
        for (int j = 0; j < CNT_WIDTH; j++)
        {
            float red = arrayImage[i][j][0];
            float green = arrayImage[i][j][1];
            float blue = arrayImage[i][j][2];

            // Check if pixel is yellow (Red and Green > 220, Blue < 80)
            if (red > 220 && green > 220 && blue < 80)
            {
                yellowPixelCount++;
            }
        }
    }
    // If there are any yellow pixels, return true, otherwise false
    printf("Percentage of yellow pixels: %.2f\n", yellowPixelCount / pixels * 100.0f);
    return yellowPixelCount / pixels;
}

int main()
{
    // Random number generation
    srand(time(NULL));

    // Array for the image with a pointer
    float arrayImage[CNT_HEIGHT][CNT_WIDTH][PRIMARY_COLORS];
    float *p = &arrayImage[0][0][0];

    // pixel size of RGB pixels
    float pixels = CNT_HEIGHT * CNT_WIDTH * PRIMARY_COLORS;

    for (int i = 0; i < pixels; i++)
    {
        float randomValue = (rand() % 255) + 1;
        *(p + i) = randomValue;
    }

    // for (int i = 0; i < PRIMARY_COLORS; i++) {
    //     if (i == 0) {
    //         printf("RED:\n");
    //     }
    //     if (i == 1) {
    //         printf("GREEN:\n");
    //     }
    //     if (i == 2) {
    //         printf("BLUE:\n");
    //     }

    //     for (int j = 0; j < CNT_WIDTH; j++) {
    //         for (int k = 0; k < CNT_HEIGHT; k++) {
    //             printf("[%d] ", arrayImage[k][j][i]);
    //         }
    //         printf("\n");
    //     }

    // }
    float yellowPercentage = checkYellow(arrayImage);
    printf("Percentage of yellow pixels: %.2f\n", yellowPercentage * 100.0f);

    if (checkYellow(arrayImage) >= 0.4)
    {
        printf("Its a DHL postcard!\n");
    }
    else
    {
        printf("ew\n");
    }
}
