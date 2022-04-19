import { Mouse } from "./mouse";
import { mouseDownSync, mouseDown } from "./mouse-down";
import { mouseUpSync, mouseUp } from "./mouse-up";
import { sleep } from "./sleep";

export const clickSync = (button: Mouse = Mouse.Left) => {
  mouseDownSync(button);
  mouseUpSync(button);
};

export const click = async (button: Mouse = Mouse.Left) => {
  await mouseDown(button);
  await mouseUp(button);
};

export const doubleClick = async (button: Mouse = Mouse.Left) => {
  await mouseDown(button);
  await mouseUp(button);
  await sleep(0.2);
  await mouseDown(button);
  await mouseUp(button);
};
