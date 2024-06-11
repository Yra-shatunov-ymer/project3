#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/**
@brief Высчитывает площадь квадрата.
@param Длина стороны квадрата.
@param Высота стороны квадрата.
@return Площадь квадрата.
*/
int calculate_area(int width, int height) {
  if (width < 0 || height < 0) {
    return -1;
  }
  return width * height;
}

#endif