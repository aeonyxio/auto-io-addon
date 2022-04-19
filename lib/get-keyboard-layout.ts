import { KeyboardLayout } from "./keyboard-layout";

const addon = require("../build/Release/addon");

export const getKeyboardLayout = (): { layout: KeyboardLayout; raw: string } =>
  addon.getKeyboardLayoutSync();
