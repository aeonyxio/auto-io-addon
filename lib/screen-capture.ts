const addon = require("../build/Release/addon");

export const screenCapture = (
  x: number,
  y: number,
  width: number,
  height: number
): {
  width: number;
  height: number;
  byteWidth: number;
  bitsPerPixel: number;
  bytesPerPixel: number;
  image: Buffer;
} => addon.screenCapture(x, y, width, height);

screenCapture;
