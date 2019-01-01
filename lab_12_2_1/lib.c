
/**
 \file
 */




 /**
 * \brief эта функция выполняет смещение массива arr влево на k
 * \param len длина массива
 * \param k количество смещений
 * \param *arr массив целых чисел
 */

int shift(int len, int k, int *arr)
{
    int count = 0;
    const int last = len - 1;
    if (len < 1 || !arr)
    {
        return 1;
    }
    k = k % len;
    while (count < k)
    {
        int temp = arr[0];
        for (int curr = 0; curr < last; curr++)
        {
            arr[curr] = arr[curr + 1];
        }
        arr[last] = temp;
        count += 1;
    }
    return 0;
}

/**
* \brief эта функция выполняет возведение в квадрат всех чисел их массива arr1 и запись в arr2
* \param len длина массива
* \param *arr1 массив с исходными числами
* \param *arr2 массив с выходными числами
*/



int squares(int len, int *arr1, int *arr2)
{
    if (len < 1 || !arr1 || !arr2)
    {
        return 1;
    }
    for (int elem = 0; elem < len; elem++)
    {
        arr2[elem] = (arr1[elem] * arr1[elem]);
    }
    return 0;
}
