const addon = require("../build/Release/addon");
import { promisify } from "util";
import { Rectangle } from "./rectangle";

export const highlightRectangleSync = (
  rectangle: Rectangle,
  options?: {
    duration?: number;
    opacity?: number;
  }
): void =>
  addon.highlightScreenSync(
    rectangle.x,
    rectangle.y,
    rectangle.width,
    rectangle.height,
    (options?.duration ?? 5) * 1000,
    options?.opacity ?? 1
  );

export const highlightRectangle = (
  rectangle: Rectangle,
  options?: {
    duration?: number;
    opacity?: number;
  }
): Promise<void> =>
  promisify(addon.highlightScreenAsync)(
    rectangle.x,
    rectangle.y,
    rectangle.width,
    rectangle.height,
    (options?.duration ?? 5) * 1000,
    options?.opacity ?? 1
  );
