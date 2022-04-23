const addon = require("../build/Release/addon");

export const screenCapture = (
  x: number,
  y: number,
  width: number,
  height: number
): Buffer => addon.screenCapture(x, y, width, height);

screenCapture;
