const addon = require("../build/Release/addon");
import { promisify } from "util";

export const unicodeUpSync = (unicode: string) =>
  addon.unicodeUpSync(`0x${unicode}`);
export const unicodeUp = (unicode: string) =>
  promisify(addon.unicodeUpAsync)(`0x${unicode}`);
