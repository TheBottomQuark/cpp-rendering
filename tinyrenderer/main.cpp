#include "tgaimage.h"
#include "model.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
    bool steep = false;

    if (std::abs(x1 - x0) < std::abs(y1 - y0)) {
        steep = true;
        std::swap(x0, y0);
        std::swap(x1, y1);
    }

    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    int cy = 2 * std::abs(dy);
    int err = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        if (steep)
            image.set(y, x, color);
        else
            image.set(x, y, color);

        if ((err += cy) >= dx) {
            err -= 2 * dx;
            y += y1 > y0 ? 1 : -1;
        }
    }
}

int main(int argc, char** argv)
{
    Model *model = new Model(argv[1]);

    int w = 1024, h = 1024;
    TGAImage image(w, h, TGAImage::RGB);

    for (int i=0; i<model->nfaces(); i++) { 
        std::vector<int> face = model->face(i); 
        for (int j=0; j<3; j++) { 
            Vec3f v0 = model->vert(face[j]); 
            Vec3f v1 = model->vert(face[(j+1)%3]); 
            int x0 = (v0.x+1.)*w/2.; 
            int y0 = (v0.y+1.)*h/2.; 
            int x1 = (v1.x+1.)*w/2.; 
            int y1 = (v1.y+1.)*h/2.; 
            line(x0, y0, x1, y1, image, white); 
        } 
    }

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}
