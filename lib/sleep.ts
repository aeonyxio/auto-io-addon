const addon = require("../build/Release/addon");
import { promisify } from "util";

export const sleep = (s: number) => promisify(addon.sleepAsync)(s * 1000000);

export const sleepSync = (s: number) => {
  addon.sleepSync(s * 1000000);
};
