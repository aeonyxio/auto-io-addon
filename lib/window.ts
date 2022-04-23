const addon = require("../build/Release/addon");

export const getActiveWindow = (): number => addon.getActiveWindow();
export const setActiveWindow = (windowId: number): void =>
  addon.setActiveWindow(windowId);
export const getWindows = (): number[] => addon.getWindows();
export const getWindowRect = (
  windowId: number
): { x: number; y: number; width: number; height: number } =>
  addon.getWindowRect(windowId);
export const getWindowTitle = (windowId: number): string =>
  addon.getWindowTitle(windowId);
