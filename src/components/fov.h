#ifndef RAYROG_COMPONENTS_FOV_H
#define RAYROG_COMPONENTS_FOV_H


enum class FovShape {
    SQUARE,
    LOSANGE
}

struct Fov: public Component {
    int distance;
    FovShape shape;

    Fov() {
        distance = 2;
        shape = FovShape::LOSANGE;
    }

    Fov(int distance): distance(distance) {
        shape = FovShape::LOSANGE;
    }

    Fov(int distance, FovShape fov_shape): distance(distance), shape(fov_shape) {

    }
};

#endif