const addon = require("../build/Release/addon");
import { promisify } from "util";
import { Code } from "./key-codes";

export const keyDownSync = (key: Code) => addon.keyDownSync(key);
export const keyDown = (key: Code) => promisify(addon.keyDownAsync)(key);
