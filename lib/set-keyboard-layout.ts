import { promisify } from "util";
import { KeyboardLayout } from "./keyboard-layout";

const addon = require("../build/Release/addon");

export const setKeyboardLayout = (layout: KeyboardLayout): Promise<void> => {
  console.log("switch ", layout);
  return promisify(addon.setKeyboardLayoutAsync)(layout);
};

export const setKeyboardLayoutSync = (layout: KeyboardLayout): void =>
  addon.setKeyboardLayoutSync(layout);
