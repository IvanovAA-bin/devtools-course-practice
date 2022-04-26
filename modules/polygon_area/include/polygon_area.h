// Copyright 2022 Mironova Ekaterina

#ifndef MODULES_POLYGON_AREA_INCLUDE_POLYGON_AREA_H_
#define MODULES_POLYGON_AREA_INCLUDE_POLYGON_AREA_H_

#include <vector>
#include <utility>

/* This class describes an arbitrary polygon on the plane,
defined by the coordinates of its vertices.
The function countPolygonArea() allows you to calculate its area.
The vertices should be set in order in the counterclockwise direction 
of traversal */

class Polygon {
 public:
    int vertex_num;
    std::vector<std::pair <double, double>> vertexes;
    Polygon();
    void addVertex(std::pair <double, double> new_vertex);
    void deleteVertex(std::pair <double, double> vertex);
    void deleteVertexByNumber(int number);
    double countPolygonArea();
};

#endif  // MODULES_POLYGON_AREA_INCLUDE_POLYGON_AREA_H_
