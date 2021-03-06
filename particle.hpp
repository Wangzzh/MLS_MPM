#pragma once

#include <iostream>
#include <vector>

#include "Eigen/Dense"
#include "GL/gl.h"
#include "GL/glut.h"

#include "material.hpp"

class Particle
{
public:
    void render();
    static bool renderFE;
    static bool renderV;
    static bool renderF;
    static bool renderB;

    double mass;
    // double density;
    double volume = 1.0;
    MaterialParameters* material;
    Eigen::Vector3d color;

    Eigen::Vector2d position;
    Eigen::Vector2d velocity;
    
    Eigen::Matrix2d FE = Eigen::Matrix2d::Identity();
    Eigen::Matrix2d FP = Eigen::Matrix2d::Identity();
    Eigen::Matrix2d B = Eigen::Matrix2d::Zero();

    // intermediate results
    int xLeft, yLeft;
    double xDiff, yDiff;
    std::vector<double> xWeight, yWeight;
    std::vector<double> xWeightGradient, yWeightGradient;

    void calculateWeights();
};

