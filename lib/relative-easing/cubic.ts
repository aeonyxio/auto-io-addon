import { getMousePosition } from "../binding";
import { Point } from "../point";

const getBezier = (t: number, n1: number, n2: number): number => {
  return (
    (1 - t) * (1 - t) * (1 - t) * 0 +
    3 * ((1 - t) * (1 - t)) * t * n1 +
    3 * (1 - t) * (t * t) * n2 +
    t * t * t * 1
  );
};

export const cubicRoute = (targetPoint: Point, polySteps = 100): Point[] => {
  const currPoint = getMousePosition();
  const increment = 1 / polySteps;
  let coordinates = [];
  for (let i = 0; i <= 1; i += increment) {
    coordinates.push({
      x: getBezier(i, currPoint.x, targetPoint.x),
      y: getBezier(i, currPoint.y, targetPoint.y),
    });
  }
  const roundedCoordinates = coordinates.map(
    (obj: { x: number; y: number }) => new Point(obj.x, obj.y)
  );
  return roundedCoordinates;
};
