const {
  Code,
  keyUp,
  keyDown,
  type,
  getKeyboardLayout,
  setKeyboardLayout,
  KeyboardLayout,
  sleep,
  getKeyboardLayoutList,
  unicodeDown,
  unicodeUp,
} = require("../dist/binding.js");

const test = async () => {
  await unicodeDown("2665");
  await unicodeUp("2665");
};

test().catch(console.error);
