#include "matrix.h"

#include <iostream>
#include <iomanip>

// constructors

// default constructor
Matrix::Matrix()
    : m_rows(0), m_cols(0)
{
}

// copy constructor
Matrix::Matrix(const Matrix &mat)
    : m_rows(mat.m_rows), m_cols(mat.m_cols), m_channels(channels), m_data(mat.m_data)
{
}

// parameterized constructor
Matrix::Matrix(size_t rows, size_t cols, size_t channels)
    : m_rows(rows), m_cols(cols), m_channels(std::max(channels, 1UL)), m_data(rows * cols * m_channels)
{
}

// parameterized constructor with matrix elements initialization value
Matrix::Matrix(size_t rows, size_t cols, size_t channels, int initValue)
    : m_rows(rows), m_cols(cols), m_channels(std::max(channels, 1UL)), m_data(rows * cols * m_channels, initValue)
{
}

// OpenCV methods
void Matrix::display() const
{
    cv::imshow("Display image", toOpenCV());
    cv::waitKey(0);

}

void Matrix::saveImage(const std::string &image_name) const
{
    cv::imwrite(image_name + ".png", toOpenCV());
}

// overloaded assignment operator
Matrix &Matrix::operator=(const Matrix &mat)
{
    if (this != &mat)
    {
        m_rows = mat.m_rows;
        m_cols = mat.m_cols;
        m_channels = mat.m_channels;
        m_data.assign(mat.m_data.begin(), mat.m_data.end());
    }
    return *this;
}

// methods for matrix arithmatic operations
void Matrix::add(Matrix &res, int val) const
{
    for (size_t i = 0; i < m_data.size(); ++i)
    {
        res.m_data[i] = m_data[i] + val;
    }
}

void Matrix::multiply(Matrix &res, int val) const
{
    for (size_t i = 0; i < m_data.size(); ++i)
    {
        res.m_data[i] = m_data[i] * val;
    }
}

void Matrix::subtract(Matrix &res, int val) const
{
    for (size_t i = 0; i < m_data.size(); ++i)
    {
        res.m_data[i] = m_data[i] - val;
    }
}
