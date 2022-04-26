// Copyright 2022 Mironova Ekaterina

#include "include/polygon_area.h"
#include <string>
#include <utility>
#include <cmath>

Polygon::Polygon() { vertex_num = 0; }

void Polygon::addVertex(std::pair <double, double> new_vertex) {
    for (int i = 0; i < vertex_num; i++)
        if (vertexes[i] == new_vertex)
            throw std::string("This vertex already exists");
    vertexes.push_back(new_vertex);
    vertex_num++;
}

void Polygon::deleteVertex(std::pair <double, double> vertex) {
    bool f = 0;
    for (int i = 0; i < vertex_num; i++)
        if (vertexes[i] == vertex) {
            vertexes.erase(vertexes.begin() + i);
            vertex_num--;
            f = 1;
            break;
        }
    if (f == 0)
        throw std::string("This vertex doesn't exist");
}

void Polygon::deleteVertexByNumber(int number) {
    if (number < 0 || number > vertex_num || vertex_num == 0) {
        throw std::string("This vertex doesn't exist");
    } else {
        vertexes.erase(vertexes.begin() + number);
        vertex_num--;
    }
}

double Polygon::countPolygonArea() {
    if (vertex_num < 3)
        throw std::string("It's not a polygon. Add more points");
    // use the Gauss area formula
    double s = 0, sum1 = 0, sum2 = 0;
    vertexes.push_back(vertexes[0]);
    for (int i = 0; i < vertex_num; i++) {
        sum1 += vertexes[i].first * vertexes[i + 1].second;
        sum2 += vertexes[i].second * vertexes[i + 1].first;
    }
    vertexes.pop_back();
    s = fabs(sum1 - sum2) / 2;
    return s;
}
