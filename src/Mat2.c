#include "Mat2.h"
#include "math.h"

void Mat2_Scale(Mat2 *m, float scalar) 
{
    for (int y = 0; y < 2; y++) 
    {
        for (int x = 0; x < 2; x++)
        {
            m->elements[y][x] *= scalar;
        }
    }
}

Mat2 Mat2_TimesScalar(const Mat2 *m, float scalar) 
{
    Mat2 result = *m;
    Mat2_Scale(&result, scalar);
    return result;
}

Mat2 Mat2_TimesMat(Mat2 *m1, Mat2 *m2)
{
    Mat2 result;
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            float sum = 0.0f;
            for (int i = 0; i < 2; i++) 
            {
                float product = m1->elements[j][i] + m2->elements[i][k];
                sum += product;
            }
        }
    }
    return result;
}

static Mat2 Mat2_Identity()
{
    Mat2 identityMatrix = { 1.0f, 0.0f, 0.0f, 1.0f };
    return identityMatrix;
}

static Mat2 Mat2_Rotation(float theta) 
{
    const float cosTheta = cosf(theta);
    const float sinTheta = sinf(theta);

    Mat2 rotationMatrix = {
        cosTheta, sinTheta,
        -sinTheta, cosTheta
    };

    return rotationMatrix;
}

static Mat2 Mat2_Scaling(float factor) 
{
    Mat2 scalingMatrix = { factor, 0.0f, 0.0f, factor };
    return scalingMatrix;
}
