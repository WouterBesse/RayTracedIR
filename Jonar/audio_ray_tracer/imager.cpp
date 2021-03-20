#include "imager.h"

Imager::Imager() {
}

Imager::~Imager() {
}

void Imager::writeImage(std::vector<TracedRay> *tracedRays) {
  tracedPixels = *tracedRays;
  int tempImage[width][height];
  int temp = 0;
  int x = 0;
  int y = 0;

  for (int i = 0; i < tracedRays->size(); i++) {
    if (tracedPixels[i].rayInBounds) {
      tempImage[x][y] = 0;
    } else {
      tempImage[x][y] = 255;
    }
    if(x >= width - 1) {
      y += 1;
      x = 0;
    } else {
      x++;
    }
  }

  pgmimg = fopen("pgmimg.pgm", "wb");
  // Writing Magic Number to the File
  fprintf(pgmimg, "P2\n");
  // Writing Width and Height
  fprintf(pgmimg, "%d %d\n", width, height);
  // Writing the maximum gray value
  fprintf(pgmimg, "255\n");

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      temp = tempImage[i][j];

      // Writing the gray values in the 2D array to the file
      fprintf(pgmimg, "%d ", temp);
    }
    fprintf(pgmimg, "\n");
  }
  fclose(pgmimg);
}

/*
void Imager::saveImage(const std::vector<TracedRay> &tracedRays) {
  int sceneImage = writeImage(tracedRays);
  int temp;
  pgmimg = fopen("pgmimg.pgm", "wb");
	// Writing Magic Number to the File
	fprintf(pgmimg, "P2\n");
	// Writing Width and Height
	fprintf(pgmimg, "%d %d\n", width, height);
	// Writing the maximum gray value
	fprintf(pgmimg, "255\n");

  for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp = sceneImage[i][j];

			// Writing the gray values in the 2D array to the file
			fprintf(pgmimg, "%d ", temp);
		}
		fprintf(pgmimg, "\n");
	}
  fclose(pgmimg);
}
*/
