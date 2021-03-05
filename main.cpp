
#include <stdio.h>
#include <stdlib.h>
#include "obj3d.h"


 void readOFFFile(struct Object3d *object3d)
{


 char Fname[]="bone.off";
//printf("Type the file to be open: ");
//scanf("%s",Fname);

int dump;
char isOFF[3];

char ch;


    FILE *myFile;
    myFile = fopen(Fname, "r");
//if(myFile!=NULL){printf("File opened!\n");}

fscanf(myFile,"%s",&isOFF);


fscanf(myFile,"%d %d",&object3d->nvert,&object3d->nface);
printf("%d %d\n",object3d->nvert,object3d->nface);


fscanf(myFile,"%d",& dump);


	object3d->vertices = (point3d*)malloc(object3d->nvert * sizeof(point3d));
	object3d->faces = (face*)malloc(object3d->nface * sizeof(face));


  ch=fgetc(stdin);
    for(int i=0; i<object3d->nvert; i++){
float isTri, x,y,z;
        fscanf(myFile,"%f %f %f",&x,&y,&z);

        object3d->vertices[i].x=x;
        object3d->vertices[i].y=y;
        object3d->vertices[i].z=z;


        if(ch==0x0A)
		{
		    printf("%f %f %f\n",object3d->vertices[i].x,object3d->vertices[i].y,object3d->vertices[i].z);

		}

    }


 ch=fgetc(stdin);
    for(int i=0; i<object3d->nface; i++){
int isTri, x,y,z;
        fscanf(myFile,"%d %d %d %d",&isTri,&x,&y,&z);
        object3d->faces[i].isTri=isTri;
        object3d->faces[i].x=x;
        object3d->faces[i].y=y;
        object3d->faces[i].z=z;


        if(ch==0x0A)
		{
		      printf("%d %d %d\n",object3d->faces[i].x,object3d->faces[i].y,object3d->faces[i].z);

		}

 }


}

int main()
{
struct Object3d object3d;
readOFFFile(&object3d);

}
