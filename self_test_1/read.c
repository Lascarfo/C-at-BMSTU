#include <stdio.h>
#include "const.h"

int readar(FILE *file,int *ar,int *len)
{
  int error = OK;
  fscanf(file, "%d", len);
  if (*len > 0)
  {
      for (int i = 0; i < *len; i++)
      {
        fscanf(file, "%d", ar);
        ar = ar + sizeof(int);
      }
  }
  else
  {
    error = ERR_R;
  }
  return error;
}
