#include "delta.h"
#include "unit_step.h"
#include "normal_distribution.h"
#include <stdio.h>
#include <math.h>

const int n0 = 4;

const float A1 = 1;
const float A2 = 2;
const float f1 = 100;
const float f2 = 200;
const float pi = 3.141;



void harmonic_signal(FILE* plot, float tmax, float dt)
{
  float x;
  for(float t = 0; t < tmax; t+=dt)
  {
    x = A1 * cos(2*pi * f1 * t) + A2 * cos(2*pi * f2 * t); 
    fprintf(plot, "%f %f\n", t, x);
  }
}


int main(void)
{
  /* Задание 1 - генерация делта функции и ступеньки */
  FILE* plot1 = fopen("data/plot1.txt", "wb");
  int y1, y2, y3, y4;

  for(int i = 0; i < 50; i++)
  {
    y1 = delta(i - n0);
    y2 = unit_step(i - n0);
    y3 = 3 * delta(i - n0) + delta(i - 2);
    y4 = unit_step(i - n0) - 2 * unit_step(i);

    fprintf(plot1, "%d %d %d %d %d\n", i, y1, y2, y3, y4);
  }

  fclose(plot1);

  /* Задание 3 - генерация гармонического сигнала */
  FILE* plot2 = fopen("data/plot2.txt", "wb");
  FILE* plot3 = fopen("data/plot3.txt", "wb");
  FILE* plot4 = fopen("data/plot4.txt", "wb");
  
  float fd    = 2 * fmax(f1, f2);        /* Период дискретизации */
  float tmax  = 2 * 1/fmin(f1,f2);
  float dt    = 1/fd;
  harmonic_signal(plot2, tmax, dt);

  float fd_5 = fd * 5;
  dt = 1/fd_5;
  harmonic_signal(plot3, tmax, dt);

  float fd_2 = fd/2;
  dt = 1/fd_2;
  harmonic_signal(plot4, tmax, dt);

  fclose(plot2);
  fclose(plot3);
  fclose(plot4);
  
  /* Задание 4 - создание зашумленного сигнала */
  FILE* plot5 = fopen("data/plot5.txt", "wb");
  float x;

  for(float t = 0; t < 5; t+=0.01)
  {
    x = sin(2*pi * 0.5 * t);
    x += normal_distribution(0, sqrt(0.05));
    fprintf(plot5, "%f %f\n", t, x);
  }

  fclose(plot5);
  return 0;
}

