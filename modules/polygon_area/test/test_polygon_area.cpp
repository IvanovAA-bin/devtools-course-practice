// Copyright 2022 Mironova Ekaterina

#include <gtest/gtest.h>
#include <utility>
#include "include/polygon_area.h"

TEST(Mironova_Ekaterina_PolygonAreaTest, can_create_polygon) {
    ASSERT_NO_THROW(Polygon p);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, new_polygon_has_0_vertex) {
    Polygon p;
    EXPECT_EQ(0, p.vertex_num);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, can_add_vertex) {
    Polygon p;
    double x = 1.5, y = 2.5;
    std::pair <double, double> vertex(x, y);
    ASSERT_NO_THROW(p.addVertex(vertex));
}

TEST(Mironova_Ekaterina_PolygonAreaTest, add_vertex_change_vertex_num) {
    Polygon p;
    double x = 1.5, y = 2.5;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    EXPECT_EQ(1, p.vertex_num);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, cant_add_existing_vertex) {
    Polygon p;
    double x = 1.5, y = 2.5;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    ASSERT_ANY_THROW(p.addVertex(vertex));
}

TEST(Mironova_Ekaterina_PolygonAreaTest, can_delete_existing_vertex) {
    Polygon p;
    double x = 1.5, y = 2.5;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    ASSERT_NO_THROW(p.deleteVertex(vertex));
}

TEST(Mironova_Ekaterina_PolygonAreaTest, delete_vertex_change_vertex_num) {
    Polygon p;
    double x = 1.5, y1 = 2.5, y2 = 3.5;
    std::pair <double, double> vertex1(x, y1);
    std::pair <double, double> vertex2(x, y2);
    p.addVertex(vertex1);
    p.addVertex(vertex2);
    p.deleteVertex(vertex1);
    EXPECT_EQ(1, p.vertex_num);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, cant_delete_not_existing_vertex) {
    Polygon p;
    double x1 = 1.5, x2 = 1.4, y = 2.5;
    std::pair <double, double> vertex(x1, y);
    p.addVertex(vertex);
    vertex = std::make_pair(x2, y);
    ASSERT_ANY_THROW(p.deleteVertex(vertex));
}

TEST(Mironova_Ekaterina_PolygonAreaTest,
    can_delete_existing_vertex_by_number) {
    Polygon p;
    double x = 1.5, y = 2.5;
    int n = 0;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    ASSERT_NO_THROW(p.deleteVertexByNumber(n));
}

TEST(Mironova_Ekaterina_PolygonAreaTest,
    cant_delete_not_existing_vertex_by_number) {
    Polygon p;
    double x = 1.5, y = 2.5;
    int n = 4;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    ASSERT_ANY_THROW(p.deleteVertexByNumber(n));
}

TEST(Mironova_Ekaterina_PolygonAreaTest,
    cant_delete_not_existing_vertex_by_negative_number) {
    Polygon p;
    double x = 1.5, y = 2.5;
    int n = -1;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    ASSERT_ANY_THROW(p.deleteVertexByNumber(n));
}

TEST(Mironova_Ekaterina_PolygonAreaTest,
    cant_delete_empty_vertex) {
    Polygon p;
    int n = 0;
    ASSERT_ANY_THROW(p.deleteVertexByNumber(n));
}

TEST(Mironova_Ekaterina_PolygonAreaTest, can_count_polygon_area) {
    Polygon p;
    double x1 = 3.0, x2 = 5.5, x3 = 8.7, x4 = 2.1, s;
    double y1 = 2.0, y2 = 3.0, y3 = 6.0, y4 = 8.0;
    std::pair <double, double> vertex1(x1, y1);
    std::pair <double, double> vertex2(x2, y2);
    std::pair <double, double> vertex3(x3, y3);
    std::pair <double, double> vertex4(x4, y4);
    p.addVertex(vertex1);
    p.addVertex(vertex2);
    p.addVertex(vertex3);
    p.addVertex(vertex4);
    ASSERT_NO_THROW(p.countPolygonArea());
}

TEST(Mironova_Ekaterina_PolygonAreaTest, cant_count_area_of_one_point) {
    Polygon p;
    double x = 1.5, y = 2.5;
    std::pair <double, double> vertex(x, y);
    p.addVertex(vertex);
    ASSERT_ANY_THROW(p.countPolygonArea());
}

TEST(Mironova_Ekaterina_PolygonAreaTest, cant_count_area_of_two_points) {
    Polygon p;
    double x1 = 1.5, x2 = 1.4, y = 2.5;
    std::pair <double, double> vertex(x1, y);
    p.addVertex(vertex);
    vertex = std::make_pair(x2, y);
    p.addVertex(vertex);
    ASSERT_ANY_THROW(p.countPolygonArea());
}

TEST(Mironova_Ekaterina_PolygonAreaTest, correct_count_square_area) {
    Polygon p;
    double x1 = 0, y1 = 0, x2 = 2.5, y2 = 2.5, s;
    std::pair <double, double> vertex1(x1, y1);
    std::pair <double, double> vertex2(x2, y1);
    std::pair <double, double> vertex3(x2, y2);
    std::pair <double, double> vertex4(x1, y2);
    p.addVertex(vertex1);
    p.addVertex(vertex2);
    p.addVertex(vertex3);
    p.addVertex(vertex4);
    s = p.countPolygonArea();
    EXPECT_DOUBLE_EQ((x2 - x1) * (x2 - x1), s);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, correct_count_rectangle_area) {
    Polygon p;
    double x1 = 1.5, y1 = 1.5, x2 = 2.5, y2 = 5.5, s;
    std::pair <double, double> vertex1(x1, y1);
    std::pair <double, double> vertex2(x2, y1);
    std::pair <double, double> vertex3(x2, y2);
    std::pair <double, double> vertex4(x1, y2);
    p.addVertex(vertex1);
    p.addVertex(vertex2);
    p.addVertex(vertex3);
    p.addVertex(vertex4);
    s = p.countPolygonArea();
    EXPECT_DOUBLE_EQ((x2 - x1)*(y2 - y1), s);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, correct_count_triangle_area) {
    Polygon p;
    double x1 = 0.0, y1 = 0.0, x2 = 2.0, y2 = 3.5, s;
    std::pair <double, double> vertex1(x1, y1);
    std::pair <double, double> vertex2(x2, y1);
    std::pair <double, double> vertex3(x1, y2);
    p.addVertex(vertex1);
    p.addVertex(vertex2);
    p.addVertex(vertex3);
    s = p.countPolygonArea();
    EXPECT_DOUBLE_EQ((x2 - x1) * (y2 - y1)/2, s);
}

TEST(Mironova_Ekaterina_PolygonAreaTest, correct_count_trapezoid_area) {
    Polygon p;
    double x1 = 0.0, y1 = 0.0, x2 = 2.5, x3 = 1.5, y2 = 1.5, s;
    std::pair <double, double> vertex1(x1, y1);
    std::pair <double, double> vertex2(x2, y1);
    std::pair <double, double> vertex3(x3, y2);
    std::pair <double, double> vertex4(x1, y2);
    p.addVertex(vertex1);
    p.addVertex(vertex2);
    p.addVertex(vertex3);
    p.addVertex(vertex4);
    s = p.countPolygonArea();
    EXPECT_DOUBLE_EQ((y2 - y1)*(x2 - x1 + x3 - x1)/2, s);
}
