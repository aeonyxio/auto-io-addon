const addon = require("../build/Release/addon");

export const sleep = (ms: number) => {
  return new Promise((resolve) => setTimeout(resolve, ms));
};

export const sleepSync = (s: number) => {
  addon.sleepSync(s * 1000000);
};
