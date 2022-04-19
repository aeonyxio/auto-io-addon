const addon = require("../build/Release/addon");
import { promisify } from "util";

export const unicodeDownSync = (unicode: string) =>
  addon.unicodeDownSync(`0x${unicode}`);
export const unicodeDown = (unicode: string) =>
  promisify(addon.unicodeDownAsync)(`0x${unicode}`);
