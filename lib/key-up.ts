const addon = require("../build/Release/addon");
import { promisify } from "util";
import { Code } from "./key-codes";

export const keyUpSync = (key: Code) => addon.keyUpSync(key);
export const keyUp = (key: Code) => promisify(addon.keyUpAsync)(key);
