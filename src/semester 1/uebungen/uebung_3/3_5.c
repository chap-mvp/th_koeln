#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CNT_HEIGHT 3
#define CNT_WIDTH 3
#define PRIMARY_COLORS 3

// yellow when intensity over 220 out of 255

float checkYellow(float arrayImage[CNT_HEIGHT][CNT_WIDTH][PRIMARY_COLORS])
{
    float sumAveragedArray[CNT_HEIGHT][CNT_WIDTH];
    float pixels = CNT_WIDTH * CNT_HEIGHT * PRIMARY_COLORS;

    for (int i = 0; i < PRIMARY_COLORS; i++)
    {
        if (i == 0)
        {
            printf("RED:\n");
        }
        if (i == 1)
        {
            printf("GREEN:\n");
        }
        if (i == 2)
        {
            printf("BLUE:\n");
        }
        for (int j = 0; j < CNT_HEIGHT; j++)
        {
            for (int k = 0; k < CNT_WIDTH; k++){
                printf("[%d] ", arrayImage[k][j][i]);
            }
            printf("\n");
        }
    }

    // for (int i = 0; i < CNT_HEIGHT; i++)
    // {
    //     for (int j = 0; j < CNT_WIDTH; j++)
    //     {
    //         for (int k = 0; k < PRIMARY_COLORS; k++)
    //         {
    //             sumAveragedArray[i][j] += arrayImage[i][j][k];
    //         }
    //     }
    // }

    float yellowPixelCount = 0;

    // for (int i = 0; i < CNT_HEIGHT; i++)
    // {
    //     for (int j = 0; j < CNT_WIDTH; j++)
    //     {
    //         sumAveragedArray[j][i] /= 3;
    //         printf("[%.2f] ", sumAveragedArray[j][i]);
    //         if (sumAveragedArray[j][i] >= 220)
    //             yellowPixelCount++;
    //     }
    //     printf("\n");
    // }

    printf("%.2f", yellowPixelCount);

    return yellowPixelCount / 3;
}

int main()
{

    float arrayImage[CNT_HEIGHT][CNT_WIDTH][PRIMARY_COLORS] =
        {
            {{220, 220, 220}, {220, 220, 220}, {220, 220, 220}},
            {{220, 220, 220}, {220, 220, 220}, {220, 220, 220}},
            {{220, 220, 220}, {220, 220, 220}, {220, 220, 220}}};

    srand(time(NULL));

    float *p = &arrayImage[0][0][0];
    float pixels = CNT_HEIGHT * CNT_WIDTH * PRIMARY_COLORS;

    checkYellow(arrayImage);
}




//     for (int j = 0; j < CNT_WIDTH; j++)
//     {
//         for (int k = 0; k < CNT_HEIGHT; k++)
//         {
//             printf("[%.2f] ", arrayImage[k][j][i]);
//         }
//         printf("\n");
//     }
// }

// for (int i = 0; i < pixels; i++)
// {
//     float randomValue = (rand() % 255) + 1;
//     *(p + i) = randomValue;
// }

// if (checkYellow(arrayImage) >= 0.4)
// {
//     printf("Its a DHL postcard!\n");
// }
// else
// {
//     printf("ew\n");
// }