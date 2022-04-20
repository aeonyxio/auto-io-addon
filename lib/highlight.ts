const addon = require("../build/Release/addon");
import { promisify } from "util";

export const highlightRectangleSync = (
  x: number,
  y: number,
  width: number,
  height: number,
  options?: {
    duration?: number;
    opacity?: number;
  }
): void =>
  addon.highlightScreenSync(
    x,
    y,
    width,
    height,
    (options?.duration ?? 5) * 1000,
    options?.opacity ?? 1
  );

export const highlightRectangle = (
  x: number,
  y: number,
  width: number,
  height: number,
  options?: {
    duration?: number;
    opacity?: number;
  }
): Promise<void> =>
  promisify(addon.highlightScreenAsync)(
    x,
    y,
    width,
    height,
    (options?.duration ?? 5) * 1000,
    options?.opacity ?? 1
  );
