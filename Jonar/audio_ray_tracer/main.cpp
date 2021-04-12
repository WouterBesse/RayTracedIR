/*
#
# 2021 Jonar Verbart
# Part of RayTracedIR by Wouter Besse, Nino Saglia and Jonar Verbart
#
*/

#include "rayTracer.h"

int main(int argc, char const *argv[]) {
  ShapeSet scene;

  // hardcoded test scene data, to be replaced with blender import function
  Point coordA;
  Point coordB;
  Point coordC;

  // triangle1
  coordA.x = 0.0f;
  coordA.y = 4.0f;
  coordA.z = 0.0f;
  coordB.x = 1.5f;
  coordB.y = 4.0f;
  coordB.z = 0.0f;
  coordC.x = 0.0f;
  coordC.y = 4.0f;
  coordC.z = 1.0f;


  Plane triangle1(coordA, coordB, coordC);
	scene.addPlane(&triangle1);

  coordA.x = 0.0f;
  coordA.y = 3.0f;
  coordA.z = 0.0f;
  coordB.x = -1.5f;
  coordB.y = 3.0f;
  coordB.z = 0.0f;
  coordC.x = 0.0f;
  coordC.y = 3.0f;
  coordC.z = 1.0f;

  Plane triangle2(coordA, coordB, coordC);
	scene.addPlane(&triangle2);

  Point coordD;
  Point coordE;
  Point coordF;
  Point coordG;
  Point coordH;

  //roomABCDEFGH
  coordA.x = 3.0f;
  coordA.y = -6.0f;
  coordA.z = -3.0f;

  coordB.x = -3.0f;
  coordB.y = -6.0f;
  coordB.z = -3.0f;

  coordC.x = -3.0f;
  coordC.y = 6.0f;
  coordC.z = -3.0f;

  coordD.x = 3.0f;
  coordD.y = 6.0f;
  coordD.z = -3.0f;

  coordE.x = 3.0f;
  coordE.y = -6.0f;
  coordE.z = 3.0f;

  coordF.x = -3.0f;
  coordF.y = -6.0f;
  coordF.z = 3.0f;

  coordG.x = -3.0f;
  coordG.y = 6.0f;
  coordG.z = 3.0f;

  coordH.x = 3.0f;
  coordH.y = 6.0f;
  coordH.z = 3.0f;

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
  // end of hardcoded test scene data

  RayTracer rayTracer;
  rayTracer.traceScene(&scene);
  return 0;
}
