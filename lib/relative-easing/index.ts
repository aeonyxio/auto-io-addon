import { getMousePosition } from "../binding";
import { Point } from "../point";
import { Bresenham } from "./bresenham";

export const straightTo = (to: Point) =>
  Bresenham.compute(getMousePosition(), to);
