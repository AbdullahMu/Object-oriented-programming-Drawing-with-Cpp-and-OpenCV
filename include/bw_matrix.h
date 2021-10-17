#ifndef BW_MATRIX_H
#define BW_MATRIX_H

#include "matrix.h"
#include "color.h"
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"

class BWMatrix : public Matrix
{
public:
    BWMatrix();
    BWMatrix(const BWMatrix &mat);
    BWMatrix(size_t rows, size_t cols);
    BWMatrix(size_t rows, size_t cols, int initVal);

    inline size_t getRows() const { return m_rows; }

    inline size_t getCols() const { return m_cols; }

    inline int& at(size_t row, size_t col, size_t channel)
    {
        return m_data[row * m_cols * m_channels + col * m_channels + channel];
    }

    inline const int &at(size_t row, size_t col) const
    {
        return m_data[row * m_cols * m_channels + col * m_channels];
    }

    inline int &at(int row, int col) 
    {
        return m_data[row * m_cols * m_channels + col * m_channels];
    }

    
    void print() const override;
    void fromOpenCV(const cv::Mat &mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string &path) override;

    BWMatrix invert() const;

    BWMatrix add(int val) const;
    BWMatrix multiply(int val) const;
    BWMatrix subtract(int val) const;

    BWMatrix operator+(int val) const;
    BWMatrix operator-(int val) const;
    BWMatrix operator*(int val) const;
    BWMatrix &operator=(const BWMatrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const BWMatrix &mat);

    void draw(Shape shape);
};

#endif // BW_MATRIX_H
