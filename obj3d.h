
typedef struct point3d{
    float x,y,z;
};

typedef struct face{
int isTri, x,y,z;
};

typedef struct Object3d{

int nvert;
int nface;

point3d *vertices;
face *faces;


}Object3d;



