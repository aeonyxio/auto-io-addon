const addon = require("../build/Release/addon");

export const getMousePosition = (): { x: number; y: number } =>
  addon.getMousePositionSync();
