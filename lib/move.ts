const addon = require("../build/Release/addon");
import { promisify } from "util";
import { getMousePosition } from "./get-mouse-position";
import { Point } from "./point";
import { sleep } from "./sleep";

export async function move(
  this: { delay: number } | void,
  ...points: Point[]
): Promise<void> {
  const sleepFor = this?.delay ?? 0.000001;
  for (let i = 0; i < points.length; i++) {
    promisify(addon.mouseMoveAsync)(points[i].x, points[i].y);
    if (i !== points.length - 1) {
      await sleep(sleepFor);
    }
  }
}

export const moveRight = (px: number): void => {
  const point = getMousePosition();
  promisify(addon.mouseMoveAsync)(point.x + px, point.y);
};

export const moveLeft = (px: number): void => {
  const point = getMousePosition();
  promisify(addon.mouseMoveAsync)(point.x - px, point.y);
};

export const moveUp = (px: number): void => {
  const point = getMousePosition();
  promisify(addon.mouseMoveAsync)(point.x, point.y - px);
};

export const moveDown = (px: number): void => {
  const point = getMousePosition();
  promisify(addon.mouseMoveAsync)(point.x, point.y + px);
};

export const moveSync = (point: Point): void =>
  addon.mouseMoveSync(point.x, point.y);

export const moveRightSync = (px: number): void => {
  const point = getMousePosition();
  addon.mouseMoveAsync(point.x + px, point.y);
};

export const moveLeftSync = (px: number): void => {
  const point = getMousePosition();
  addon.mouseMoveAsync(point.x - px, point.y);
};

export const moveUpSync = (px: number): void => {
  const point = getMousePosition();
  addon.mouseMoveAsync(point.x, point.y - px);
};

export const moveDownSync = (px: number): void => {
  const point = getMousePosition();
  addon.mouseMoveAsync(point.x, point.y + px);
};
