import { Point } from "./point";

const addon = require("../build/Release/addon");

export const getMousePosition = (): Point => {
  const pos = addon.getMousePositionSync();
  return new Point(pos.x, pos.y);
};
