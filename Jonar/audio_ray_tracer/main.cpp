#include "rayTracer.h"

int main(int argc, char const *argv[]) {
  ShapeSet scene;

  Point coordA;
  Point coordB;
  Point coordC;

  // triangle1
  coordA.x = 0.0f;
  coordA.y = 0.0f;
  coordA.z = 4.0f;
  coordB.x = 1.5f;
  coordB.y = 0.0f;
  coordB.z = 4.0f;
  coordC.x = 0.0f;
  coordC.y = 1.0f;
  coordC.z = 4.0f;


  Plane triangle1(coordA, coordB, coordC);
	scene.addPlane(&triangle1);

  coordA.x = 0.0f;
  coordA.y = 0.0f;
  coordA.z = 3.0f;
  coordB.x = -1.5f;
  coordB.y = 0.0f;
  coordB.z = 3.0f;
  coordC.x = 0.0f;
  coordC.y = 1.0f;
  coordC.z = 3.0f;

  Plane triangle2(coordA, coordB, coordC);
	scene.addPlane(&triangle2);

  Point coordD;
  Point coordE;
  Point coordF;
  Point coordG;
  Point coordH;

  //roomABCDEFGH
  coordA.x = 3.0f;
  coordA.y = -3.0f;
  coordA.z = -6.0f;

  coordB.x = -3.0f;
  coordB.y = -3.0f;
  coordB.z = -6.0f;

  coordC.x = -3.0f;
  coordC.y = -3.0f;
  coordC.z = 6.0f;

  coordD.x = 3.0f;
  coordD.y = -3.0f;
  coordD.z = 6.0f;

  coordE.x = 3.0f;
  coordE.y = 3.0f;
  coordE.z = -6.0f;

  coordF.x = -3.0f;
  coordF.y = 3.0f;
  coordF.z = -6.0f;

  coordG.x = -3.0f;
  coordG.y = 3.0f;
  coordG.z = 6.0f;

  coordH.x = 3.0f;
  coordH.y = 3.0f;
  coordH.z = 6.0f;

  Plane triangleABE(coordA, coordB, coordE);
  scene.addPlane(&triangleABE);
  Plane triangleBFE(coordB, coordF, coordE);
  scene.addPlane(&triangleBFE);

  Plane triangleDCH(coordD, coordC, coordH);
  scene.addPlane(&triangleDCH);
  Plane triangleCGH(coordC, coordG, coordH);
  scene.addPlane(&triangleCGH);

  Plane triangleBCG(coordB, coordC, coordG);
  scene.addPlane(&triangleBCG);
  Plane triangleBGF(coordB, coordG, coordF);
  scene.addPlane(&triangleBGF);

  Plane triangleADH(coordA, coordD, coordH);
  scene.addPlane(&triangleADH);
  Plane triangleAHE(coordA, coordH, coordE);
  scene.addPlane(&triangleAHE);

  Plane triangleABD(coordA, coordB, coordD);
  scene.addPlane(&triangleABD);
  Plane triangleBCD(coordB, coordC, coordD);
  scene.addPlane(&triangleBCD);

  Plane triangleFGH(coordF, coordG, coordH);
  scene.addPlane(&triangleFGH);
  Plane triangleEFH(coordE, coordF, coordH);
  scene.addPlane(&triangleEFH);

  RayTracer rayTracer;
  rayTracer.traceScene(&scene);
  return 0;
}
