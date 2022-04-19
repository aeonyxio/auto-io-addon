const addon = require("../build/Release/addon");
import { promisify } from "util";
import { Mouse } from "./mouse";

export const mouseDownSync = (button: Mouse) => addon.mouseDownSync(button);
export const mouseDown = (button: Mouse) =>
  promisify(addon.mouseDownAsync)(button);
