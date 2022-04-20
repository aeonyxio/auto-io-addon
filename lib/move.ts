const addon = require("../build/Release/addon");
import { promisify } from "util";

export const move = (x: number, y: number): Promise<void> =>
  promisify(addon.mouseMoveAsync)(x, y);
export const moveSync = (x: number, y: number): void =>
  addon.mouseMoveSync(x, y);
