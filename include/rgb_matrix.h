#ifndef RGB_MATRIX_H
#define RGB_MATRIX_H

#include "matrix.h"
#include "bw_matrix.h"
#include "shape.h"

class RGBMatrix : public Matrix
{
public:
    RGBMatrix();
    RGBMatrix(const RGBMatrix &mat);
    RGBMatrix(size_t rows, size_t cols);
    RGBMatrix(size_t rows, size_t cols, int initVal);

    inline size_t getRows() const { return m_rows; }

    inline size_t getCols() const { return m_cols; }

    inline const int &at(size_t row, size_t col, size_t channel) const
    {
        return m_data[row * m_cols * m_channels + col * m_channels + channel];
    }

    inline int &at(size_t row, size_t col, size_t channel)
    {
        return m_data[row * m_cols * m_channels + col * m_channels + channel];
    }

    void print() const override;
    void fromOpenCV(const cv::Mat &mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string &path) override;

    BWMatrix toBW() const;

    RGBMatrix add(int val) const;
    RGBMatrix multiply(int val) const;
    RGBMatrix subtract(int val) const;

    RGBMatrix operator+(int val) const;
    RGBMatrix operator-(int val) const;
    RGBMatrix operator*(int val) const;
    RGBMatrix &operator=(const RGBMatrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const RGBMatrix &mat);

    void draw(Shape shape);
};

#endif // RGB_MATRIX_H