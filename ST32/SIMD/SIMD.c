#include "main.h"
/*
 *  Interleave 1: Pairwise interleaving.
 *  Interleave 2: Every 2 elements.
 *  Interleave 3: Every 3 elements.
 *  Interleave 4: Every 4 elements (e.g., RGBA format).
 *
 *
 * */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
#define SIZE 50

uint8_t ArrA[SIZE][SIZE];
uint8_t ArrB[SIZE][SIZE];
uint32_t result[SIZE][SIZE];

void initializeMatrix(uint8_t matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 256; // Random value between 0 and 255
        }
    }
}

void MatrixMulti(int8_t matrix[SIZE][SIZE], int8_t matrix2[SIZE][SIZE], uint32_t result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }
}




void matrix_multiply_simd(uint8_t *matrix, uint8_t *matrix2, uint32_t *result)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
        	uint32_t sum = 0;
            for (int k = 0; k < SIZE; k += 2) // Process 2 elements at a time
            {
            	uint32_t a = *((int16_t *)(matrix + i * SIZE + k));  // Load 2 elements from matrix A
            	uint32_t b = *((int16_t *)(matrix2 + k * SIZE + j)); // Load 2 elements from matrix B
                sum = __SMLAD(a, b, sum); // SIMD Multiply-Accumulate
            }
            *(result + i * SIZE + j) = sum; // Store result in output matrix
        }
    }
}



int main(void)
{
HAL_Init();
SystemClock_Config();
MX_GPIO_Init();
initializeMatrix(ArrA);
initializeMatrix(ArrB);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1,1);

	//MatrixMulti(ArrA, ArrB, result);  //normal multiplocation
	matrix_multiply_simd(&ArrA, &ArrB, &result);  //SIMD multiplocation

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1,0);



  while (1)
  {
	  
  }


  /* USER CODE END 3 */
}
