const addon = require("../build/Release/addon");
import { promisify } from "util";
import { Mouse } from "./mouse";

export const mouseUpSync = (button: Mouse) => addon.mouseUpSync(button);
export const mouseUp = (button: Mouse) => promisify(addon.mouseUpAsync)(button);
