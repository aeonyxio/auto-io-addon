const addon = require("../build/Release/addon");

export const getKeyboardLayoutList = (): string[] =>
  addon.getKeyboardLayoutListSync();
