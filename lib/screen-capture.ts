const addon = require("../build/Release/addon");
import { promisify } from "util";

export const screenCaptureSync = (
  x: number,
  y: number,
  width: number,
  height: number
): Buffer => addon.screenCaptureSync(x, y, width, height);

export const screenCapture = (
  x: number,
  y: number,
  width: number,
  height: number
): Promise<Buffer> => promisify(addon.screenCapture)(x, y, width, height);
